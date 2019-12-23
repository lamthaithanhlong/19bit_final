#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define size 1
#define max_data 10

static struct phongban_data
{
	char name[100];
	char emp_id[100];
}pb;

struct list {
	phongban_data a[max_data];
	int n;
};

int avlrollno(char rno[100])
{
	FILE* fp;
	int c = 0;
	fp = fopen("employeeRecord.txt", "r");
	while (!feof(fp))
	{
		fread(&pb, sizeof(pb), 1, fp);

		if(strcpy(pb.emp_id,rno))
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
	scanf("%s", pb.emp_id);
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
		printf("\n\n\temployee id:\t%s", pb.emp_id);
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
	int found = 0, search_choice; 
	char search_emp_id[100];
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
	int found = 0;
	char del_emp_id[100];
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
		scanf("%s", del_emp_id);
		while ((fread(&pb, sizeof(pb), size, data) == size))
		{
			if (strcmp(pb.emp_id, del_emp_id))
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
	char s[100], r[100];
	int ch;
	printf("enter roll number to update:");
	scanf("%s", r);
	avl = avlrollno(r);
	if (avl == 0)
	{
		printf("roll number %s is not available in the file", r);
	}
	else
	{
		fpo = fopen("employeerecord.txt", "r");
		fpt = fopen("temp_data.txt", "w");
		while (fread(&pb, sizeof(pb), size, fpo) == size)
		{
			strcpy(s,pb.emp_id);
			if (strcmp(s,r) != 0)
				fwrite(&pb, sizeof(pb), size, fpt);
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
					scanf("%s", &pb.name);
					break;
				default:
					printf("invalid selection");
					break;
				}
				fwrite(&pb, sizeof(pb), 1, fpt);
			}
		}
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("employeerecord.txt", "w");
		fpt = fopen("temp_data.txt", "r");
		while (fread(&pb, sizeof(pb), 1, fpt))
		{
			fwrite(&pb, sizeof(pb), 1, fpo);
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


//void emp_modify()
//{
//	FILE* data;
//	char id[100]; int found = 0;
//	data = fopen("employeeRecord.txt", "r+");
//	printf("\n\tEnter Employee ID to Edit Record:\t");
//	scanf("%s", id);
//	while(fread(&pb, sizeof(pb), size, data) == size)
//	{
//		if(strcmp(pb.emp_id, id) == 0)
//		{
//			found = 1;
//			printf("\n\tEXISTING RECORD IS......");
//			printf("\n\n\tEMPLOYEE ID:\t%s", pb.emp_id);
//			printf("\n\tEMPLOYEE NAME:\t%s", pb.name);
//			printf("\n\n************MODIFYING EMPLOYEE RECORD**************\n");
//			printf("\n\tEnter New Employee Name:\t");
//			scanf("%s", pb.name);
//			printf("\n\tEnter New Employee Position:\t");
//			fseek(data, -sizeof(pb), SEEK_CUR);
//			fwrite(&pb, sizeof(pb), size, data);
//			printf("\n\n\tEmployee Record Successfuly Written.");
//		}
//		break;
//	}
//	if (found == 0)
//	{
//		printf("\n\tRECORD NOT FOUND...");
//	}
//	fclose(data);
//	printf("\n\n\tPress 1 to Continue and 0 to EXIT");
//	printf("\n\n\tINPUT:\t");
//	int exit_status;
//	scanf("%d", &exit_status);
//	if (exit_status != 1)
//	{
//		printf("\n\n\tThank You for Using this Application.\n");
//		exit(0);
//	}
//}
