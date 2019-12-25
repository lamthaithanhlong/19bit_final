#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nhanvien.h"
#include "PhongBan.h"

int phongbanty(char rno[100])
{
	FILE* fp;
	int c = 0;
	fp = fopen("PhongBan.txt", "r");
	while (!feof(fp))
	{
		fread(&pb, sizeof(pb), 1, fp);

		if(strcpy(pb.phongban_id,rno))
		{
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}

void phongban_displayAll()
{
	FILE* data;
	char filename[] = "PhongBan.txt";
	data = fopen(filename, "r");
	int totalphongbanloyee = 0;
	int i = 0;
	printf("\n\n\t**********************Thong Tin PHong Ban*********************\n\n");
	while ((fread(&pb, sizeof(pb), size, data) == size))
	{
		i++;
		printf("\n\t");
		printf("\n\n\tPhong Ban id:\t%s", pb.phongban_id);
		printf("\n\tTen Phong Ban:\t%s", pb.name);
	}
	totalphongbanloyee += i;
	printf("\n\n\tTong so phong ban: %d\n\n", totalphongbanloyee);
	fclose(data);
}

void inputvalue(char *id)
{
	FILE* data;
	int i = 0;
	char filename[] = "PhongBan.txt";
	data = fopen(filename, "r");
	printf("\n");
	printf("\n \tphong ban id:\t");
	scanf("%s", id);
	while ((fread(&pb, sizeof(pb), 1, data))) {
		
		if (strcmp(pb.phongban_id,id) == 0)
		{
			printf("\n \tNhap lai phong ban id:\t");
			scanf("%s", id);
		}
	}
	strcpy(pb.phongban_id, id);
	printf("\n \tTen phong ban:\t");
	scanf("%s", pb.name);
}

void count_nu_nhanvien() 
{
	FILE* fe;
	char check[100];
	fe = fopen("NhanVien.txt", "r");
	printf("\n \tTen phong ban:\t");
	scanf("%s", check);
	while ((fread(&nv, sizeof(nv), 1, fe))) {
		strcpy(nv.name, check);
		if (count_nu_phong_ban(nv.name) != 0)
		{
			printf("\n \tso luong nu trong phong ban: %d\t", count_nu_phong_ban(nv.name));
			nv.dem_nu == count_nu_phong_ban(nv.name);
		}
	}
}

void phongban_append()
{
	FILE* data;
	//list l;
	char id[100];
	char filename[] = "PhongBan.txt";
	data = fopen(filename, "a");
	phongban_displayAll();
	inputvalue(id);
	if (fwrite(&pb, sizeof(pb), size, data) != size)
	{
		printf("\n\tLoi phat sinh. khong doc duoc file.");
		exit(0);
	}
	else
	{
		printf("\n\tDa luu thanh cong phong ban.");
	}
	fclose(data);
}

void phongban_delete()
{
	int ret,rname;
	int found = 0;
	char del_phongban_name[100];
	FILE* data, * tphongban;
	data = fopen("PhongBan.txt", "r");
	tphongban = fopen("temp_data.txt", "w");
	phongban_displayAll();
	printf("\n\tNhap ten phong ban can xoa:\t");
	scanf("%s", del_phongban_name);
	if (count_nhan_vien(del_phongban_name) == 0) {
		if (data == NULL)
		{
			printf("\n\tLoi phat sinh. Khong mo duoc file");
			exit(0);
		}
		else
		{
			while ((fread(&pb, sizeof(pb), size, data) == size))
			{
				if (strcmp(pb.name, del_phongban_name) != 0)
					fwrite(&pb, sizeof(pb), size, tphongban);
			}
			fclose(data);
			fclose(tphongban);
		}
		data = fopen("PhongBan.txt", "w");
		tphongban = fopen("temp_data.txt", "r");
		while (fread(&pb, sizeof(pb), 1, tphongban))
			fwrite(&pb, sizeof(pb), 1, data);
		fclose(data);
		fclose(tphongban);
		printf("Xoa thanh cong");
	}
	else 
	{
		printf("\t\n loi phat sinh. Nhan vien van con trong phong la %d",count_nhan_vien(del_phongban_name));
	}
}

void phongban_modify()
{
	int avl;
	FILE* fpt;
	FILE* fpo;
	char s[100], r[100];
	int ch;
	phongban_displayAll();
	printf("Vui long nhap id phong ban can thay doi:");
	scanf("%s", r);
	avl = phongbanty(r);
	if (avl == 0)
	{
		printf("Phong Ban ID so %s khong hop le", r);
	}
	else
	{
		fpo = fopen("PhongBan.txt", "r");
		fpt = fopen("temp_data.txt", "w");
		while (fread(&pb, sizeof(pb), size, fpo) == size)
		{
			strcpy(s,pb.phongban_id);
			if (strcmp(s,r) != 0)
				fwrite(&pb, sizeof(pb), size, fpt);
			else
			{
				printf("\n\t1. Nhap nhat lai ten voi phong ban co so id la %s", r);
				printf("\nenter your choice:");
				scanf("%d", &ch);
				switch (ch)
				{
				case 1:
					printf("nhap ten:");
					scanf("%s", pb.name);
					break;
				default:
					printf("Lua chon khong hop le");
					break;
				}
				fwrite(&pb, sizeof(pb), 1, fpt);
			}
		}
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("PhongBan.txt", "w");
		fpt = fopen("temp_data.txt", "r");
		while (fread(&pb, sizeof(pb), 1, fpt))
		{
			fwrite(&pb, sizeof(pb), 1, fpo);
		}
		fclose(fpo);
		fclose(fpt);
		printf("\t\t\n Cap Nhat Thanh Cong");
	}
}
