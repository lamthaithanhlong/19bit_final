#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include"fort.h"
#define DATA_SIZE 1000

void ThemPhongBan() 
{
	FILE* fp;
	char c;
	printf("File Handling\n");
	fp = fopen("file1.txt", "w");
	while ((c = getchar()) != EOF) {
		putc(c, fp);
	}
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
	char buffer[30], c;

	file_pointer = fopen("file1.txt", "r");
	printf("----read a line----\n");
	fgets(buffer, 50, file_pointer);
	printf("%s\n", buffer);

	printf("----read and parse data----\n");
		
	file_pointer = fopen("file1.txt", "r");
	while ((c = getc(file_pointer)) != EOF) printf("%c", c);

	fclose(file_pointer);
}