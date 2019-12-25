#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nhanvien.h"
#include "PhongBan.h"
#include"extend.h"
void clrscr()
{
	system("@cls||clear");
}

void head_disp()
{
	printf("\n\n\t\t\t\t*************************************************");
	printf("\n\t  \t\t\t**                                             **");
	printf("\n\t  \t\t\t**        Company Managmenet Program           **");
	printf("\n\t  \t\t\t**             Team Huan Vinh Long             **");
	printf("\n\t  \t\t\t**                                             **");
	printf("\n\t\t\t\t*************************************************\n");
}

void finalize() 
{
	FILE* fpo, * fpt;
	fpo = fopen("PhongBan.txt", "r");
	fpt = fopen("temp_data_memory.txt", "w");
	while (fread(&pb, sizeof(pb), 1, fpo))
	{
			fprintf(fpt, "\nPB%s", pb.phongban_id);
			fprintf(fpt, "\n%s", pb.name);
	}
	fpt = fopen("temp_data_memory.txt", "r");
	fpo = fopen("PhongBan.txt", "w");
	fclose(fpo);
	fclose(fpt);
	printf("\t\n\ da save xong");
}