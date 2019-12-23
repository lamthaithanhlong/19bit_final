#include<stdio.h>
#include<conio.h>
#include"MainMenu.h"
#include"extend.h"
#include <ctype.h>
int main() 
{
	FILE* data,* data1;
	char create;
	head_disp();
	data1 = fopen("employeeRecord1.txt", "r+");
	data = fopen("employeeRecord.txt", "r+");
	if (data == NULL)
	{
		printf("\n\t Employee Database Not Found!\n Press N key to create new Database.");
		printf("\n\tTo EXIT, press Enter key\n");
		create = _getche();
		if (tolower(create) == 'n')
		{
			data = fopen("employeeRecord.txt", "w+");
			printf("\n\tEmployee Record Database has been created in the current directory.\n");
			printf("\n\tYou must Restart the Application\nPress Enter key to continue.\n");
			char x;
			x = _getch();
			exit(0);
		}
		else
		{
			printf("\n\n\tThank You for using this Application.\n");
			printf("\n\n\tApplication will EXIT Now.");
			exit(0);
		}
	}
	if (data1 == NULL)
	{
		printf("\n\t Department Database Not Found!\n Press N key to create new Database.");
		printf("\n\tTo EXIT, press Enter key\n");
		create = _getche();
		if (tolower(create) == 'n')
		{
			data1 = fopen("employeeRecord1.txt", "w+");
			printf("\n\tEmployee Record Database has been created in the current directory.\n");
			printf("\n\tYou must Restart the Application\nPress Enter key to continue.\n");
			char x;
			x = _getch();
			exit(0);
		}
		else
		{
			printf("\n\n\tThank You for using this Application.\n");
			printf("\n\n\tApplication will EXIT Now.");
			exit(0);
		}
	}
	while (1)
	{
		MainMenu();
	}
	return 0;
}