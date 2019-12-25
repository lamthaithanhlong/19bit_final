#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PhongBan.h"

#define size 1
#define max_data 10

struct Date {
	int day;
	int month;
	int year;
} date;

static struct nhanvien_data
{
	char name[100];
	char nhanvien_id[100];
	char phongbanname[100];
	int luong;
	int dem_nu;
	char gender[100];
	int day;
	int month;
	int year;
}nv;

struct nhanvien_list {
	nhanvien_data a[max_data];
	int n;
};

void nhapngay(Date d) {
	printf("\n");
	printf("\n\tnhap ngay :");
	scanf("%d", &d.day);
	printf("\t\nnhap thang :");
	scanf("%d", &d.month);
	printf("\n\tnhap nam :");
	scanf("%d", &d.year);
}

void xuatngay(Date d) {
	printf("ngay %d", d.day);
	printf("thang %d", d.month);
	printf("nam %d", d.year);
}

int nhanvien_phongbanty(char rno[100])
{
	FILE* fp;
	int c = 0;
	fp = fopen("NhanVien.txt", "r");
	while (!feof(fp))
	{
		fread(&nv, sizeof(nv), 1, fp);

		if (strcpy(nv.nhanvien_id, rno))
		{
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}

void nhanvien_displayAll()
{
	FILE* data;
	int n;
	char filename[] = "NhanVien.txt";
	data = fopen(filename, "r");
	int totalnhanvienloyee = 0;
	int i = 0;
	printf("\n\n\t**********************all nhanvienloyees information*********************\n\n");

	while ((fread(&nv, sizeof(nv), size, data) == size))
	{
		i++;
		printf("\n\n\tnhanvienloyee id:\t%s", nv.nhanvien_id);
		printf("\n\tnhanvienloyee name:\t%s", nv.name);
		printf("\n\tphong ban name:\t%s", nv.phongbanname);
		printf("\n\tluong cua nhan vien la :\t%d",nv.luong);
		printf("\n\tgioi tinh cua nhan vien la: \t%s", nv.gender);
		printf("\n\t");
		printf("%d-", nv.day);
		printf("%d-", nv.month);
		printf("%d", nv.year);
	}
	totalnhanvienloyee += i;
	printf("\n\n\ttotal nhanvienloyees: %d\n\n", totalnhanvienloyee);
	fclose(data);
}

void nhanvien_inputvalue(char* id)
{
	FILE* data,*tphongban;
	int i = 0;
	char n[100], check[100], nhanvien_gender[100];
	char filename1[] = "PhongBan.txt";
	char filename[] = "NhanVien.txt";
	data = fopen(filename, "r");
	tphongban = fopen(filename1, "r");
	printf("\n");
	nhanvien_displayAll();
	printf("\n \tnhap ma id nhan vien:\t");
	scanf("%s", id);
	while ((fread(&nv, sizeof(nv), 1, data))) {
		if (strcmp(nv.nhanvien_id, id) == 0)
		{
			printf("\n \tnhap lai ma id cua nhan vien:\t");
			scanf("%s", id);
		}
	}
	strcpy(nv.nhanvien_id, id);
	printf("\n \tnhap ho ten nhan vien:\t");
	rewind(stdin);
	gets_s(nv.name);
	phongban_displayAll();
	printf("\n");
	printf("nhap vao ma phong ban nhan vien can vao: ");
	scanf("%s", check);
	while (fread(&pb, sizeof(pb), size, tphongban) == size)
	{
		if (strcmp(pb.name, check) == 0)
		{
			i = 1;
			printf("\n\t******************nhanvienloyee record is......");
			printf("\n\n\tnhanvienloyee id:\t%s", pb.phongban_id);
			printf("\n\tnhanvienloyee name:\t%s", pb.name);
			strcpy(nv.phongbanname, check);
		}
	}
	if (i == 0)
	{
		printf("\n\tno such nhanvienloyee record found.");
	}
	else 
	{
		printf("\n");
		printf("gioi tinh (M la nam, F la nu) :");
		scanf("%s", &nhanvien_gender);
		if(strcmp(nhanvien_gender,"M") == 0) 
		{
			printf("chon nam");
			strcpy(nv.gender,"Nam");
		}
		else if (strcmp(nhanvien_gender, "F") == 0) {
			printf("chon nu");
			strcpy(nv.gender, "Nu");
		}
		else 
		{
			exit(0);
		}
		printf("\t\nnNhap luong cua nhan vien %s :", nv.name);
		scanf("%d", &nv.luong);
		printf("\n");
		printf("\n\t=====Vui Long cung cap thong tin ngay sinh========");
		printf("\n\tnhap ngay :");
		scanf("%d", &nv.day);
		printf("\t\nnhap thang :");
		scanf("%d", &nv.month);
		printf("\n\tnhap nam :");
		scanf("%d", &nv.year);
	}
	fclose(data);
	fclose(tphongban);
}

void nhanvien_append()
{
	FILE* data;
	nhanvien_list l;
	char id[100];
	char filename[] = "NhanVien.txt";
	data = fopen(filename, "a");
	printf("input number of input: ");
	scanf("%d", &l.n);
	nhanvien_inputvalue(id);
	for (int i = 0; i < l.n; i++)
	{
		if (fwrite(&nv, sizeof(nv), size, data) != size)
		{
			printf("\n\terror in writing to file.");
			exit(0);
		}
		else
		{
			printf("\n\tnhanvienloyee record successfully written.");
		}
	}
	fclose(data);
	printf("\n\n\tpress 1 to continue and 0 to exit");
	printf("\n\n\tinput:\t");
	int exit_status;
	scanf("%d", &exit_status);
	if (exit_status != 1)
	{
		printf("\n\n\tthank you for using this application.\n");
		exit(0);
	}
}

int count_nhan_vien(char check[100])
{
	FILE* data;
	int i=0;
	char filename[] = "NhanVien.txt";
	data = fopen(filename, "r");
	while ((fread(&nv, sizeof(nv), size, data) == size))
	{
		if (strcmp(nv.phongbanname,check) == 0)
		{
			i++;
			printf("\n\n\tnhanvienloyee id:\t%s", nv.nhanvien_id);
			printf("\n\tnhanvienloyee name:\t%s", nv.name);
			printf("\n\tphong ban name:\t%s", nv.phongbanname);
		}
	}
	fclose(data);
	return i;
}

void nhanvien_delete()
{
	int ret, rname;
	int found = 0;
	char del_nhanvien_id[100];
	FILE* data, * tnhanvien;
	data = fopen("NhanVien.txt", "r");
	tnhanvien = fopen("temp_data.txt", "w");
	if (data == NULL)
	{
		printf("\n\terror in opening file");
		exit(0);
	}
	else
	{
		printf("\n\tenter nhanvienloyee id to delete it's record:\t");
		scanf("%s", del_nhanvien_id);
		while ((fread(&nv, sizeof(nv), size, data) == size))
		{
			if (strcmp(nv.nhanvien_id, del_nhanvien_id) != 0)
				fwrite(&nv, sizeof(nv), size, tnhanvien);
		}
		fclose(data);
		fclose(tnhanvien);
	}
	data = fopen("NhanVien.txt", "w");
	tnhanvien = fopen("temp_data.txt", "r");
	while (fread(&nv, sizeof(nv), 1, tnhanvien))
		fwrite(&nv, sizeof(nv), 1, data);
	fclose(data);
	fclose(tnhanvien);
	printf("\n\n\tpress 1 to continue and 0 to exit");
	printf("\n\n\tinput:\t");
	int exit_status;
	scanf("%d", &exit_status);
	if (exit_status != 1)
	{
		printf("\n\n\tthank you for using this application.\n");
		exit(0);
	}
}

void nhanvien_modify()
{
	int avl;
	FILE* fpt;
	FILE* fpo;
	char s[100], r[100];
	int ch;
	printf("enter roll number to update:");
	scanf("%s", r);
	avl = nhanvien_phongbanty(r);
	if (avl == 0)
	{
		printf("roll number %s is not available in the file", r);
	}
	else
	{
		fpo = fopen("NhanVien.txt", "r");
		fpt = fopen("temp_data.txt", "w");
		while (fread(&nv, sizeof(nv), size, fpo) == size)
		{
			strcpy(s, nv.nhanvien_id);
			if (strcmp(s, r) != 0)
				fwrite(&nv, sizeof(nv), size, fpt);
			else
			{
				printf("\n\t1. update name of roll number %s", r);
				printf("\n\t2. update mark of roll number %s", r);
				printf("\n\t3. update both name and mark of roll number %s", r);
				printf("\nenter your choice:");
				scanf("%d", &ch);
				switch (ch)
				{
				case 1:
					printf("enter name:");
					scanf("%s", &nv.name);
					break;
				default:
					printf("invalid selection");
					break;
				}
				fwrite(&nv, sizeof(nv), 1, fpt);
			}
		}
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("NhanVien.txt", "w");
		fpt = fopen("temp_data.txt", "r");
		while (fread(&nv, sizeof(nv), 1, fpt))
		{
			fwrite(&nv, sizeof(nv), 1, fpo);
		}
		fclose(fpo);
		fclose(fpt);
		printf("record updated");
	}
	printf("\n\n\tpress 1 to continue and 0 to exit");
	printf("\n\n\tinput:\t");
	int exit_status;
	scanf("%d", &exit_status);
	if (exit_status != 1)
	{
		printf("\n\n\tthank you for using this application.\n");
		exit(0);
	}
}

void PhongTraLuongItNhat()
{
	int a[20], count = 0, i, j, t, c;
	FILE* fpo;
	fpo = fopen("NhanVien.txt", "r");
	while (fread(&nv, sizeof(nv), 1, fpo))
	{
		a[count] = nv.luong;
		count++;
	}
	c = count;
	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (a[i] < a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	printf("Id nhan vien.\tTen\t\tLuong\n\n");
	count = c;
	for (i = 0; i < count; i++)
	{
		rewind(fpo);
		while (fread(&nv, sizeof(nv), 1, fpo))
		{
			if (a[i] == nv.luong)
				printf("\n %s\t%s\t%d\t%s", nv.nhanvien_id, nv.name, nv.luong, nv.phongbanname);
		}

	}
	printf("\t\n Phong tra luong it nhat la phong: %s", nv.phongbanname);
}

void count_nam_nu()
{
	FILE* data;
	int i = 0;
	char check[100];
	char filename[] = "NhanVien.txt";
	data = fopen(filename, "r");
	printf("Nhap vao gioi tinh (M la Nam , F la Nu): ");
	scanf("%s", check);
	if (strcmp(check, "M") == 0)
	{
		strcpy(check, "Nam");
		printf("chon nam");
	}
	else if (strcmp(check, "F") == 0) {
		strcpy(check, "Nu");
		printf("chon nu");
	}
	else
	{
		exit(0);
	}
	while ((fread(&nv, sizeof(nv), size, data) == size))
	{
		if (strcmp(nv.gender, check) == 0)
		{
			i++;
			printf("\n\n\tnhanvienloyee id:\t%s", nv.nhanvien_id);
			printf("\n\tnhanvienloyee name:\t%s", nv.name);
			printf("\n\tphong ban name:\t%s", nv.phongbanname);
		}
	}
	fclose(data);
	printf("\n\tSo nhan vien %s duoc dem la %d",nv.gender ,i);
}

int count_nu()
{
	FILE* data;
	int i = 0;
	char check[100];
	char check_nu[] = "*";
	char filename[] = "NhanVien.txt";
	data = fopen(filename, "r");
	while ((fread(&nv, sizeof(nv), size, data) == size))
	{
		if (strcmp(nv.gender, "Nu") == 0 && strcmp(nv.phongbanname, check_nu) == 0)
		{
			i++;
		}
	}
	printf("\n\tSo nhan vien %s duoc dem la %d", nv.gender, i);
	fclose(data);
	return i;
}


int count_nu_phong_ban(char check_nu[100])
{
	FILE* data;
	int i = 0;
	char check[100];
	char filename[] = "NhanVien.txt";
	data = fopen(filename, "r");
	while ((fread(&nv, sizeof(nv), size, data) == size))
	{
		if (strcmp(nv.gender, "Nu") == 0 && strcmp(nv.phongbanname, check_nu) == 0)
		{
			i++;
		}
	}
	printf("\n\tSo nhan vien %s duoc dem la %d", nv.gender, i);
	fclose(data);
	return i;
}

void PhongCoNhieuNuNhat()
{
	int a[20], count = 0, i, j, t, c;
	FILE* fpo;
	fpo = fopen("NhanVien.txt", "r");
	while (fread(&nv, sizeof(nv), 1, fpo))
	{
		a[count] = count_nu();
		count++;
	}
	c = count;
	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (a[i] < a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	printf("Id nhan vien.\tTen\t\tLuong\n\n");
	count = c;
	for (i = 0; i < count; i++)
	{
		rewind(fpo);
		while (fread(&nv, sizeof(nv), 1, fpo))
		{
			if (a[i] == count_nu());
			{
				printf("\n %s\t%s\t%s", nv.nhanvien_id, nv.name, nv.phongbanname);
			}
		}

	}
	printf("\t\n Phong co nhieu nu nhat la phong: %s", nv.phongbanname);
}

