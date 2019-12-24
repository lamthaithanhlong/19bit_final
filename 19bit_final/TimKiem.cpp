#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nhanvien.h"

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


void PhongTraLuongItNhat()
{
	int a[20], count = 0, i, j, t, c;
	FILE* fpo;
	fpo = fopen("employeeRecord1.txt", "r");
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
				printf("\n %s\t\t %s \t\t %d \t %s", nv.nhanvien_id, nv.name, nv.luong, nv.phongbanname);
		}

	}
	printf("\t\n Phong tra luong it nhat la phong: %s", nv.phongbanname);
}
