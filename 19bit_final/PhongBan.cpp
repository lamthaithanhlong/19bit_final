#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include"fort.h"
#define DATA_SIZE 1000
#define PHONG_BAN_MAX_SIZE 10

struct PhongBan
{
	int mspb;
	char ten[60];
};
typedef PhongBan phongban;
struct DanhSach
{
	phongban a[PHONG_BAN_MAX_SIZE];
	int n;
};

void ThongTinPhongBan(phongban &pb) {
	printf("\nnhap vao msnv: ");
	scanf("%d", &pb.mspb);
	printf("\nnhap vao ho: ");
	fflush(stdin);
	rewind(stdin);
	gets_s(pb.ten);
}

void ThemPhongBan() 
{
	FILE* fp;
	char c;
	int a, b,k;
	phongban pb;
	//printf("\n\tvi tri them: ");
	//scanf("%d", &k);
	ThongTinPhongBan(pb);
	printf("File Handling\n");
	fp = fopen("file1.txt", "w");
	//while ((c = getchar()) != EOF) {
		fprintf(fp, "\n%-15s %-15s", "|| string 1 ||", "|| string 2 ||");
		fprintf(fp, "\n%-15s %-15s", "||==========||", "||==========||");
		fprintf(fp, "\n%-15d %-25s", pb.mspb , pb.ten);
		fprintf(fp, "\n%-15s %-15s", "||==========||", "||==========||");
	//}
	fclose(fp);
	printf("Du lieu da nhap vao:\n");
	fp = fopen("file1.txt", "r");
	while ((c = getc(fp)) != EOF) {
		printf("%c", c);
	}
	fclose(fp);
}

void XuatPhongBan() 
{
	FILE* file_pointer;
	char buffer[1000], c;

	file_pointer = fopen("file1.txt", "r");
	while ((c = getc(file_pointer)) != EOF) printf("%c", c);
	fclose(file_pointer);
}
