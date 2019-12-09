#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include"fort.h"
#define DATA_SIZE 1000

void ThemPhongBan() 
{
	FILE* fp;
	char c;
	int a, b, c1,d;
	printf("File Handling\n");
	printf("Enter a:");
	scanf("%d", &a);
	printf("Enter b:");
	scanf("%d", &b);
	printf("Enter c:");
	scanf("%d", &c1);
	printf("Enter d:");
	scanf("%d", &d);
	fp = fopen("file1.txt", "w");
	//while ((c = getchar()) != EOF) {
		fprintf(fp, "\n%-15s %-15s %-15s %-15s", "|| string 1 ||", "|| string 2 ||", "|| string 3 ||", "|| string 4 ||");
		fprintf(fp, "\n%-15s %-15s %-15s %-15s", "||==========||", "||==========||", "||==========||", "||==========||");
		fprintf(fp, "\n|| %-50 %-20d %-15d %-15d %-20d ", a , b, c1, d);
		fprintf(fp, "\n%-15s %-15s %-15s %-15s", "||==========||", "||==========||", "||==========||", "||==========||");
	//}
	fclose(fp);
	printf("Data Entered:\n");
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
