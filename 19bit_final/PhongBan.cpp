﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define size 1
#define max_data 10

static struct phongban_data
{
	char name[100];
	int emp_id;
}pb;

struct list {
	phongban_data a[max_data];
	int n;
};

int avlrollno(int rno)
{
	FILE* fp;
	int c = 0;
	fp = fopen("employeeRecord.txt", "r");
	while (!feof(fp))
	{
		fread(&pb, sizeof(pb), 1, fp);

		if (rno == pb.emp_id)
		{
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}

void inputvalue(phongban_data& data)
{
	printf("\n");
	printf("\n \temployee id:\t");
	scanf("%d", &pb.emp_id);
	printf("\n \temployee name:\t");
	scanf("%s", pb.name);
}

void emp_append()
{
	FILE* data;
	list l;
	char filename[] = "employeeRecord.txt";
	data = fopen(filename, "a");
	printf("input number of input: ");
	scanf("%d", &l.n);
	for (int i = 0; i < l.n; i++)
	{
		inputvalue(pb);
		if (fwrite(&pb, sizeof(pb), size, data) != size)
		{
			printf("\n\terror in writing to file.");
			exit(0);
		}
		else
		{
			printf("\n\temployee record successfully written.");
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

void emp_displayAll()
{
	FILE* data;
	char filename[] = "employeeRecord.txt";
	data = fopen(filename, "r");
	int totalemployee = 0;
	int i = 0;
	printf("\n\n\t**********************all employees information*********************\n\n");
	while ((fread(&pb, sizeof(pb), size, data) == size))
	{
		i++;
		printf("\n\n\temployee id:\t%d", pb.emp_id);
		printf("\n\temployee name:\t%s", pb.name);
	}
	totalemployee += i;
	printf("\n\n\ttotal employees: %d\n\n", totalemployee);
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

void emp_search()
{
	FILE* data;
	char filename[] = "employeeRecord.txt";
	data = fopen(filename, "r");
	int found = 0, search_choice, search_emp_id;
	char search_name[100], ch = 'y';
	printf("\n\twhat do you know about the employee?");
	printf("\n\temployee id: enter 1");
	printf("\n\temployee name: enter 2");
	printf("\n\tinput:\t");
	scanf("%d", &search_choice);
	switch (search_choice)
	{
	case 1:
		printf("\n\tenter employee id:\t");
		scanf("%d", &search_emp_id);
		break;
	case 2:
		printf("\n\tenter employee name:\t");
		scanf("%s", search_name);
		break;
	default:
		ch = 'n';
		printf("\n\twrong choice.\n");
	}
	while (fread(&pb, sizeof(pb), size, data) == size)
	{
		if (pb.emp_id == search_emp_id || strcmp(pb.name, search_name) == 0)
		{
			found = 1;
			printf("\n\t******************employee record is......");
			printf("\n\n\temployee id:\t%d", pb.emp_id);
			printf("\n\temployee name:\t%s", pb.name);
		}
	}
	if (found == 0 && ch != 'n')
	{
		printf("\n\tno such employee record found.");
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


void emp_delete()
{
	int ret,rname;
	char filename[] = "DZZZ.txt";
	int found = 0, del_emp_id;
	FILE* data, * temp;
	data = fopen("employeeRecord.txt", "r");
	temp = fopen("temp_data.txt", "w");
	if (data == NULL)
	{
		printf("\n\terror in opening file");
		exit(0);
	}
	else
	{
		printf("\n\tenter employee id to delete it's record:\t");
		scanf("%d", &del_emp_id);
		while ((fread(&pb, sizeof(pb), size, data) == size))
		{
			if (pb.emp_id != del_emp_id)
				fwrite(&pb, sizeof(pb), size, temp);
		}
		fclose(data);
		fclose(temp);
	}
	data = fopen("employeeRecord.txt", "w");
	temp = fopen("temp_data.txt", "r");
	while (fread(&pb, sizeof(pb), 1, temp))
		fwrite(&pb, sizeof(pb), 1, data);
	fclose(data);
	fclose(temp);
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

void emp_modify()
{
	int avl;
	FILE* fpt;
	FILE* fpo;
	int s, r, ch;
	printf("Enter roll number to update:");
	scanf("%d", &r);
	avl = avlrollno(r);
	if (avl == 0)
	{
		printf("Roll number %d is not Available in the file", r);
	}
	else
	{
		fpo = fopen("employeeRecord.txt", "r");
		fpt = fopen("temp_data.txt", "w");
		while (fread(&pb, sizeof(pb), 1, fpo))
		{
			s = pb.emp_id;
			if (s != r)
				fwrite(&pb, sizeof(pb), 1, fpt);
			else
			{
				printf("\n\t1. Update Name of Roll Number %d", r);
				printf("\n\t2. Update Mark of Roll Number %d", r);
				printf("\n\t3. Update both Name and Mark of Roll Number %d", r);
				printf("\nEnter your choice:");
				scanf("%d", &ch);
				switch (ch)
				{
				case 1:
					printf("Enter Name:");
					scanf("%s", &pb.name);
					break;
				default:
					printf("Invalid Selection");
					break;
				}
				fwrite(&pb, sizeof(pb), 1, fpt);
			}
		}
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("employeeRecord.txt", "w");
		fpt = fopen("temp_data.txt", "r");
		while (fread(&pb, sizeof(pb), 1, fpt))
		{
			fwrite(&pb, sizeof(pb), 1, fpo);
		}
		fclose(fpo);
		fclose(fpt);
		printf("RECORD UPDATED");
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

