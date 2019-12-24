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
