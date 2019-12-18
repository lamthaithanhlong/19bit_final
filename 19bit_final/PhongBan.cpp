#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define size 1
#define max_data 10

////#include<stdio.h>
////#include<conio.h>
////#include <stdlib.h>
////#include"fort.h"
////#define DATA_SIZE 1000
////#define PHONG_BAN_MAX_SIZE 10
////
////struct PhongBan
////{
////	int mspb;
////	char ten[60];
////};
////typedef PhongBan phongban;
////struct DanhSach
////{
////	phongban a[PHONG_BAN_MAX_SIZE];
////	int n;
////};
////typedef DanhSach danhsach;
////
////void ThongTinPhongBan(phongban &pb) {
////	printf("\nnhap vao msnv: ");
////	scanf("%d", &pb.mspb);
////	printf("\nnhap vao ho: ");
////	fflush(stdin);
////	rewind(stdin);
////	gets_s(pb.ten);
////}
////
////void ThemPhongBan() 
////{
////	FILE* fp;
////	char c;
////	int a, b,k;
////	phongban pb;
////	danhsach ds;
////	printf("\nnhap so luong nhan vien: ");
////	scanf("%d", &ds.n);
////	printf("\n\t\t\tnhap thong tin nhan vien");
////	printf("File Handling\n");
////	fp = fopen("file1.txt", "w");
////	for (int i = 0; i < ds.n; i++)
////	{
////		ThongTinPhongBan(pb);
////		fprintf(fp, "\n%-15s %-15s", "|| string 1 ||", "|| string 2 ||");
////		fprintf(fp, "\n%-15s %-15s", "||==========||", "||==========||");
////		fprintf(fp, "\n%-15d %-25s", pb.mspb, pb.ten);
////		fprintf(fp, "\n%-15s %-15s", "||==========||", "||==========||");
////	}
////	fclose(fp);
////	printf("Du lieu da nhap vao:\n");
////	fp = fopen("file1.txt", "r");
////	while ((c = getc(fp)) != EOF) {
////		printf("%c", c);
////	}
////	fclose(fp);
////}
////
////void XuatPhongBan() 
////{
////	FILE* file_pointer;
////	char buffer[1000], c;
////
////	file_pointer = fopen("file1.txt", "r");
////	while ((c = getc(file_pointer)) != EOF) printf("%c", c);
////	fclose(file_pointer);
////}
//
//static struct employee_data
//{
//	char name[100], position[100], qualification[100];
//	int age, emp_id, work_exp;
//	float salary;
//	long int phone;
//	char certifications[200];
//	char prog_lang[100];
//}personal;
//
//void emp_append()
//{
//	FILE* data;
//	data = fopen("employeeRecord.txt", "a");
//	printf("\n \tEmployee ID:\t");
//	scanf("%d", &personal.emp_id);
//	printf("\n \tEmployee Name:\t");
//	scanf("%s", personal.name);
//	printf("\n \tEmployee Position:\t");
//	scanf("%s", personal.position);
//	printf("\n \tEmployee Age:\t");
//	scanf("%d", &personal.age);
//	printf("\n \tEmployee Work Experience:\t");
//	scanf("%d", &personal.work_exp);
//	printf("\n \tEmployee Salary:\t");
//	scanf("%f", &personal.salary);
//	printf("\n \tEmployee Phone Number:\t");
//	scanf("%ld", &personal.phone);
//	printf("\n \tEmployee Qualifications:\t");
//	scanf("%s", personal.qualification);
//	printf("\n \tEmployee Certifications:\t");
//	scanf("%s", personal.certifications);
//	printf("\n \tProgramming languages Known:\t");
//	scanf("%s", personal.prog_lang);
//	if (fwrite(&personal, sizeof(personal), size, data) != size)
//	{
//		printf("\n\tError in Writing to File.");
//		exit(0);
//	}
//	else
//	{
//		printf("\n\tEmployee Record Successfully Written.");
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
//
//void emp_displayAll()
//{
//	FILE* data;
//	data = fopen("employeeRecord.txt", "r");
//	int totalemployee = 0;
//	int i = 0;
//	printf("\n\n\t**********************ALL EMPLOYEES INFORMATION*********************\n\n");
//	while ((fread(&personal, sizeof(personal), size, data) == size))
//	{
//		i++;
//		printf("\n\n\tEMPLOYEE ID:\t%d", personal.emp_id);
//		printf("\n\tEMPLOYEE NAME:\t%s", personal.name);
//		printf("\n\tEMPLOYEE POSITION:\t%s", personal.position);
//		printf("\n\tEMPLOYEE AGE:\t%d", personal.age);
//		printf("\n\tEMPLOYEE QUALIFICATIONS:\t%s", personal.qualification);
//		printf("\n\tEMPLOYEE CERTIFICATIONS:\t%s", personal.certifications);
//		printf("\n\tEMPLOYEE WORK EXPERIENCE:\t%d", personal.work_exp);
//		printf("\n\tEMLOYEE SALARY:\t%.2f", personal.salary);
//		printf("\n\tEMPLOYEE PHONE NUMBER:\t%ld", personal.phone);
//		printf("\n\tPROGRAMMING LANGUAGES KNOWN:\t%s\n\n\n", personal.prog_lang);
//	}
//	totalemployee += i;
//	printf("\n\n\tTOTAL EMPLOYEES: %d\n\n", totalemployee);
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
//
//}
//
//void emp_search()
//{
//	FILE* data;
//	data = fopen("employeeRecord.txt", "r");
//	int found = 0, search_choice, search_emp_id;
//	char search_name[100], ch = 'Y';
//	printf("\n\tWhat Do You Know about the Employee?");
//	printf("\n\tEmployee ID: Enter 1");
//	printf("\n\tEmployee Name: Enter 2");
//	printf("\n\tINPUT:\t");
//	scanf("%d", &search_choice);
//	switch (search_choice)
//	{
//	case 1:
//		printf("\n\tEnter Employee ID:\t");
//		scanf("%d", &search_emp_id);
//		break;
//	case 2:
//		printf("\n\tEnter Employee Name:\t");
//		scanf("%s", search_name);
//		break;
//	default:
//		ch = 'N';
//		printf("\n\tWRONG CHOICE.\n");
//	}
//	while (fread(&personal, sizeof(personal), size, data) == size)
//	{
//		if (personal.emp_id == search_emp_id || strcmp(personal.name, search_name) == 0)
//		{
//			found = 1;
//			printf("\n\t******************EMPLOYEE RECORD IS......");
//			printf("\n\n\tEMPLOYEE ID:\t%d", personal.emp_id);
//			printf("\n\tEMPLOYEE NAME:\t%s", personal.name);
//			printf("\n\tEMPLOYEE POSITION:\t%s", personal.position);
//			printf("\n\tEMPLOYEE AGE:\t%d", personal.age);
//			printf("\n\tEMPLOYEE QUALIFICATIONS:\t%s", personal.qualification);
//			printf("\n\tEMPLOYEE CERTIFICATIONS:\t%s", personal.certifications);
//			printf("\n\tEMPLOYEE WORK EXPERIENCE:\t%d", personal.work_exp);
//			printf("\n\tEMLOYEE SALARY:\t%.2f", personal.salary);
//			printf("\n\tEMPLOYEE PHONE NUMBER:\t%ld", personal.phone);
//			printf("\n\tPROGRAMMING LANGUAGES KNOWN:\t%s", personal.prog_lang);
//		}
//	}
//	if (found == 0 && ch != 'N')
//	{
//		printf("\n\tNO SUCH EMPLOYEE RECORD FOUND.");
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
//
//
//void emp_delete()
//{
//	int found = 0, del_emp_id;
//	FILE* data, * temp;
//	data = fopen("employeeRecord.txt", "r");
//	temp = fopen("temp_data.txt", "w");
//	if (data == NULL)
//	{
//		printf("\n\tError in Opening File");
//		exit(0);
//	}
//	printf("\n\tEnter Employee ID to delete it's Record:\t");
//	scanf("%d", &del_emp_id);
//	while ((fread(&personal, sizeof(personal), size, data) == size))
//	{
//		if (personal.emp_id != del_emp_id)
//			fwrite(&personal, sizeof(personal), size, temp);
//	}
//	fclose(data);
//	fclose(temp);
//	remove("employeeRecord.txt");
//	rename("temp_data.txt", "employeeRecord.txt");
//	data = fopen("employeeRecord.txt", "r");
//	printf("\n\tRecord successfully deleted.\n\n");
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
//
//void emp_modify()
//{
//	FILE* data;
//	int id, found = 0;
//	data = fopen("employeeRecord.txt", "r+");
//	printf("\n\tEnter Employee ID to Edit Record:\t");
//	scanf("%d", &id);
//	while (fread(&personal, sizeof(personal), size, data) == size)
//	{
//		if (personal.emp_id == id)
//		{
//			found = 1;
//			printf("\n\tEXISTING RECORD IS......");
//			printf("\n\n\tEMPLOYEE ID:\t%d", personal.emp_id);
//			printf("\n\tEMPLOYEE NAME:\t%s", personal.name);
//			printf("\n\tEMPLOYEE POSITION:\t%s", personal.position);
//			printf("\n\tEMPLOYEE AGE:\t%d", personal.age);
//			printf("\n\tEMPLOYEE QUALIFICATIONS:\t%s", personal.qualification);
//			printf("\n\tEMPLOYEE CERTIFICATIONS:\t%s", personal.certifications);
//			printf("\n\tEMPLOYEE WORK EXPERIENCE:\t%d", personal.work_exp);
//			printf("\n\tEMLOYEE SALARY:\t%.2f", personal.salary);
//			printf("\n\tEMPLOYEE PHONE NUMBER:\t%ld", personal.phone);
//			printf("\n\tPROGRAMMING LANGUAGES KNOWN:\t%s", personal.prog_lang);
//			printf("\n\n************MODIFYING EMPLOYEE RECORD**************\n");
//			printf("\n\tEnter New Employee Name:\t");
//			scanf("%s", personal.name);
//			printf("\n\tEnter New Employee Position:\t");
//			scanf("%s", personal.position);
//			printf("\n\tEnter New Employee Age:\t");
//			scanf("%d", &personal.age);
//			printf("\n\tEnter New Employee Qualifications:\t");
//			scanf("%s", personal.qualification);
//			printf("\n\tEnter New Employee Certifications:\t");
//			scanf("%s", personal.certifications);
//			printf("\n\tEnter New Employee Work Experience:\t");
//			scanf("%d", &personal.work_exp);
//			printf("\n\tEnter new Employee Salary:\t");
//			scanf("%f", &personal.salary);
//			printf("\n\tEnter new Employee Phone Number:\t");
//			scanf("%ld", &personal.phone);
//			printf("\n\tEnter new Employee Programming languages Known:\t");
//			scanf("%s", personal.prog_lang);
//			fseek(data, -sizeof(personal), SEEK_CUR);
//			fwrite(&personal, sizeof(personal), size, data);
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


static struct phongban_data
{
	char name[100];
	int emp_id;
}pb;

struct list {
	phongban_data a[max_data];
	int n;
};

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
	data = fopen("employeerecord.txt", "a");
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
	data = fopen("employeerecord.txt", "r");
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
	data = fopen("employeerecord.txt", "r");
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
	int found = 0, del_emp_id;
	FILE* data, * temp;
	data = fopen("employeerecord.txt", "r");
	temp = fopen("temp_data.txt", "w");
	if (data == NULL)
	{
		printf("\n\terror in opening file");
		exit(0);
	}
	printf("\n\tenter employee id to delete it's record:\t");
	scanf("%d", &del_emp_id);
	while ((fread(&pb, sizeof(pb), size, data) == size))
	{
		if (pb.emp_id != del_emp_id)
			fwrite(&pb, sizeof(pb), size, temp);
	}
	fclose(data);
	fclose(temp);
	remove("employeerecord.txt");
	rename("temp_data.txt", "employeerecord.txt");
	data = fopen("employeerecord.txt", "r");
	printf("\n\trecord successfully deleted.\n\n");
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
	FILE* data;
	int id, found = 0;
	data = fopen("employeerecord.txt", "r+");
	printf("\n\tenter employee id to edit record:\t");
	scanf("%d", &id);
	while (fread(&pb, sizeof(pb), size, data) == size)
	{
		if (pb.emp_id == id)
		{
			found = 1;
			printf("\n\texisting record is......");
			printf("\n\n\temployee id:\t%d", pb.emp_id);
			printf("\n\temployee name:\t%s", pb.name);
			printf("\n\n************modifying employee record**************\n");
			printf("\n\tenter new employee name:\t");
			scanf("%s", pb.name);
			fseek(data, -sizeof(pb), SEEK_CUR);
			fwrite(&pb, sizeof(pb), size, data);
			printf("\n\n\temployee record successfuly written.");
		}
		break;
	}
	if (found == 0)
	{
		printf("\n\trecord not found...");
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
