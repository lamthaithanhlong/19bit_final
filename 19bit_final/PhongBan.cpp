#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define size 1

//#include<stdio.h>
//#include<conio.h>
//#include <stdlib.h>
//#include"fort.h"
//#define DATA_SIZE 1000
//#define PHONG_BAN_MAX_SIZE 10
//
//struct PhongBan
//{
//	int mspb;
//	char ten[60];
//};
//typedef PhongBan phongban;
//struct DanhSach
//{
//	phongban a[PHONG_BAN_MAX_SIZE];
//	int n;
//};
//typedef DanhSach danhsach;
//
//void ThongTinPhongBan(phongban &pb) {
//	printf("\nnhap vao msnv: ");
//	scanf("%d", &pb.mspb);
//	printf("\nnhap vao ho: ");
//	fflush(stdin);
//	rewind(stdin);
//	gets_s(pb.ten);
//}
//
//void ThemPhongBan() 
//{
//	FILE* fp;
//	char c;
//	int a, b,k;
//	phongban pb;
//	danhsach ds;
//	printf("\nnhap so luong nhan vien: ");
//	scanf("%d", &ds.n);
//	printf("\n\t\t\tnhap thong tin nhan vien");
//	printf("File Handling\n");
//	fp = fopen("file1.txt", "w");
//	for (int i = 0; i < ds.n; i++)
//	{
//		ThongTinPhongBan(pb);
//		fprintf(fp, "\n%-15s %-15s", "|| string 1 ||", "|| string 2 ||");
//		fprintf(fp, "\n%-15s %-15s", "||==========||", "||==========||");
//		fprintf(fp, "\n%-15d %-25s", pb.mspb, pb.ten);
//		fprintf(fp, "\n%-15s %-15s", "||==========||", "||==========||");
//	}
//	fclose(fp);
//	printf("Du lieu da nhap vao:\n");
//	fp = fopen("file1.txt", "r");
//	while ((c = getc(fp)) != EOF) {
//		printf("%c", c);
//	}
//	fclose(fp);
//}
//
//void XuatPhongBan() 
//{
//	FILE* file_pointer;
//	char buffer[1000], c;
//
//	file_pointer = fopen("file1.txt", "r");
//	while ((c = getc(file_pointer)) != EOF) printf("%c", c);
//	fclose(file_pointer);
//}

static struct employee_data
{
	char name[100], position[100], qualification[100];
	int age, emp_id, work_exp;
	float salary;
	long int phone;
	char certifications[200];
	char prog_lang[100];
}personal;

void emp_append()
{
	FILE* data;
	data = fopen("employeeRecord.txt", "a");
	printf("\n \tEmployee ID:\t");
	scanf("%d", &personal.emp_id);
	printf("\n \tEmployee Name:\t");
	scanf("%s", personal.name);
	printf("\n \tEmployee Position:\t");
	scanf("%s", personal.position);
	printf("\n \tEmployee Age:\t");
	scanf("%d", &personal.age);
	printf("\n \tEmployee Work Experience:\t");
	scanf("%d", &personal.work_exp);
	printf("\n \tEmployee Salary:\t");
	scanf("%f", &personal.salary);
	printf("\n \tEmployee Phone Number:\t");
	scanf("%ld", &personal.phone);
	printf("\n \tEmployee Qualifications:\t");
	scanf("%s", personal.qualification);
	printf("\n \tEmployee Certifications:\t");
	scanf("%s", personal.certifications);
	printf("\n \tProgramming languages Known:\t");
	scanf("%s", personal.prog_lang);
	if (fwrite(&personal, sizeof(personal), size, data) != size)
	{
		printf("\n\tError in Writing to File.");
		exit(0);
	}
	else
	{
		printf("\n\tEmployee Record Successfully Written.");
	}
	fclose(data);
	printf("\n\n\tPress 1 to Continue and 0 to EXIT");
	printf("\n\n\tINPUT:\t");
	int exit_status;
	scanf("%d", &exit_status);
	if (exit_status != 1)
	{
		printf("\n\n\tThank You for Using this Application.\n");
		exit(0);
	}
}

void emp_displayAll()
{
	FILE* data;
	data = fopen("employeeRecord.txt", "r");
	int totalemployee = 0;
	int i = 0;
	printf("\n\n\t**********************ALL EMPLOYEES INFORMATION*********************\n\n");
	while ((fread(&personal, sizeof(personal), size, data) == size))
	{
		i++;
		printf("\n\n\tEMPLOYEE ID:\t%d", personal.emp_id);
		printf("\n\tEMPLOYEE NAME:\t%s", personal.name);
		printf("\n\tEMPLOYEE POSITION:\t%s", personal.position);
		printf("\n\tEMPLOYEE AGE:\t%d", personal.age);
		printf("\n\tEMPLOYEE QUALIFICATIONS:\t%s", personal.qualification);
		printf("\n\tEMPLOYEE CERTIFICATIONS:\t%s", personal.certifications);
		printf("\n\tEMPLOYEE WORK EXPERIENCE:\t%d", personal.work_exp);
		printf("\n\tEMLOYEE SALARY:\t%.2f", personal.salary);
		printf("\n\tEMPLOYEE PHONE NUMBER:\t%ld", personal.phone);
		printf("\n\tPROGRAMMING LANGUAGES KNOWN:\t%s\n\n\n", personal.prog_lang);
	}
	totalemployee += i;
	printf("\n\n\tTOTAL EMPLOYEES: %d\n\n", totalemployee);
	fclose(data);
	printf("\n\n\tPress 1 to Continue and 0 to EXIT");
	printf("\n\n\tINPUT:\t");
	int exit_status;
	scanf("%d", &exit_status);
	if (exit_status != 1)
	{
		printf("\n\n\tThank You for Using this Application.\n");
		exit(0);
	}

}

void emp_delete()
{
	int found = 0, del_emp_id;
	FILE* data, * temp;
	data = fopen("employeeRecord.txt", "r");
	temp = fopen("temp_data.txt", "w");
	if (data == NULL)
	{
		printf("\n\tError in Opening File");
		exit(0);
	}
	printf("\n\tEnter Employee ID to delete it's Record:\t");
	scanf("%d", &del_emp_id);
	while ((fread(&personal, sizeof(personal), size, data) == size))
	{
		if (personal.emp_id != del_emp_id)
			fwrite(&personal, sizeof(personal), size, temp);
	}
	fclose(data);
	fclose(temp);
	remove("employeeRecord.txt");
	rename("temp_data.txt", "employeeRecord.txt");
	data = fopen("employeeRecord.txt", "r");
	printf("\n\tRecord successfully deleted.\n\n");
	printf("\n\n\tPress 1 to Continue and 0 to EXIT");
	printf("\n\n\tINPUT:\t");
	int exit_status;
	scanf("%d", &exit_status);
	if (exit_status != 1)
	{
		printf("\n\n\tThank You for Using this Application.\n");
		exit(0);
	}
}
