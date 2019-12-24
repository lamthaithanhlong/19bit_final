#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PhongBan.h"

#define size 1
#define max_data 10

static struct nhanvien_data
{
	char name[100];
	char nhanvien_id[100];
	char phongbanname[100];
}nv;

struct nhanvien_list {
	nhanvien_data a[max_data];
	int n;
};

int nhanvien_avlrollno(char rno[100])
{
	FILE* fp;
	int c = 0;
	fp = fopen("employeeRecord1.txt", "r");
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
	char filename[] = "employeeRecord1.txt";
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
	}
	totalnhanvienloyee += i;
	printf("\n\n\ttotal nhanvienloyees: %d\n\n", totalnhanvienloyee);
	fclose(data);
}

void nhanvien_inputvalue(char* id)
{
	FILE* data,*temp;
	int i = 0;
	char n[100], check[100];
	char filename1[] = "employeeRecord.txt";
	char filename[] = "employeeRecord1.txt";
	data = fopen(filename, "r");
	temp = fopen(filename1, "r");
	printf("\n");
	nhanvien_displayAll();
	printf("\n \tnhanvienloyee id:\t");
	scanf("%s", id);
	while ((fread(&nv, sizeof(nv), 1, data))) {
		if (strcmp(nv.nhanvien_id, id) == 0)
		{
			printf("\n \tnhanvienloyee id:\t");
			scanf("%s", id);
		}
	}
	strcpy(nv.nhanvien_id, id);
	printf("\n \tnhanvienloyee name:\t");
	scanf("%s", nv.name);
	emp_displayAll();
	printf("\n");
	printf("nhap vao ma phong ban nhan vien can vao: ");
	scanf("%s", check);
	while (fread(&pb, sizeof(pb), size, temp) == size)
	{
		if (strcmp(pb.name, check) == 0)
		{
			i = 1;
			printf("\n\t******************nhanvienloyee record is......");
			printf("\n\n\tnhanvienloyee id:\t%s", pb.emp_id);
			printf("\n\tnhanvienloyee name:\t%s", pb.name);
			strcpy(nv.phongbanname, check);
		}
	}
	if (i == 0)
	{
		printf("\n\tno such nhanvienloyee record found.");
		int exit_status;
		scanf("%d", &exit_status);
		if (exit_status != 1)
		{
			printf("\n\n\tthank you for using this application.\n");
			exit(0);
		}
	}
	fclose(data);
	fclose(temp);
}

void nhanvien_append()
{
	FILE* data;
	nhanvien_list l;
	char id[100];
	char filename[] = "employeeRecord1.txt";
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

void count_nhan_vien()
{
	FILE* data;
	int i=0;
	char check[100];
	char filename[] = "employeeRecord1.txt";
	data = fopen(filename, "r");
	printf("\nnhap phong ban can dem so luong :");
	scanf("%s", &check);
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
	printf("\n\t so luong sau khi dem la: %d", i);
}

void nhanvien_search()
{
	FILE* data;
	char filename[] = "employeeRecord1.txt";
	data = fopen(filename, "r");
	int found = 0, search_choice;
	char search_nhanvien_id[100];
	char search_name[100], ch = 'y';
	printf("\n\twhat do you know about the nhanvienloyee?");
	printf("\n\tnhanvienloyee id: enter 1");
	printf("\n\tnhanvienloyee name: enter 2");
	printf("\n\tinput:\t");
	scanf("%d", &search_choice);
	switch (search_choice)
	{
	case 1:
		printf("\n\tenter nhanvienloyee id:\t");
		scanf("%s", &search_nhanvien_id);
		break;
	case 2:
		printf("\n\tenter nhanvienloyee name:\t");
		scanf("%s", search_name);
		break;
	default:
		ch = 'n';
		printf("\n\twrong choice.\n");
	}
	while (fread(&nv, sizeof(nv), size, data) == size)
	{
		if (strcmp(nv.nhanvien_id, search_nhanvien_id) == 0 || strcmp(nv.name, search_name) == 0)
		{
			found = 1;
			printf("\n\t******************nhanvienloyee record is......");
			printf("\n\n\tnhanvienloyee id:\t%s", nv.nhanvien_id);
			printf("\n\tnhanvienloyee name:\t%s", nv.name);
		}
	}
	if (found == 0 && ch != 'n')
	{
		printf("\n\tno such nhanvienloyee record found.");
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


void nhanvien_delete()
{
	int ret, rname;
	int found = 0;
	char del_nhanvien_id[100];
	FILE* data, * tnhanvien;
	data = fopen("employeeRecord1.txt", "r");
	tnhanvien = fopen("tnhanvien_data.txt", "w");
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
			if (strcmp(nv.nhanvien_id, del_nhanvien_id))
				fwrite(&nv, sizeof(nv), size, tnhanvien);
		}
		fclose(data);
		fclose(tnhanvien);
	}
	data = fopen("employeeRecord1.txt", "w");
	tnhanvien = fopen("tnhanvien_data.txt", "r");
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
	avl = nhanvien_avlrollno(r);
	if (avl == 0)
	{
		printf("roll number %s is not available in the file", r);
	}
	else
	{
		fpo = fopen("employeeRecord1.txt", "r");
		fpt = fopen("tnhanvien_data.txt", "w");
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
		fpo = fopen("employeeRecord1.txt", "w");
		fpt = fopen("tnhanvien_data.txt", "r");
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
