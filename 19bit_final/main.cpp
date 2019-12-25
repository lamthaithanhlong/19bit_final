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
	data1 = fopen("NhanVien.txt", "r+");
	data = fopen("PhongBan.txt", "r+");
	if (data == NULL)
	{
		printf("\n\t Phong Ban Database khong tim thay!\n Nhan N de tao moi.");
		printf("\n\tDe Thoat, Nhan Enter\n");
		create = _getche();
		if (tolower(create) == 'n')
		{
			data = fopen("PhongBan.txt", "w+");
			printf("\n\tDatabase phong ban da duoc tao o thu muc.\n");
			printf("\n\tVui long khoi dong lai chuong trinh\nNhan Enter de tiep tuc.\n");
			char x;
			x = _getch();
			exit(0);
		}
		else
		{
			printf("\n\n\tCam on da su dung chuong trinh.\n");
			printf("\n\n\tChuong trinh se thoat.");
			exit(0);
		}
	}
	if (data1 == NULL)
	{
		printf("\n\t Phong Ban Database khong tim thay!\n Nhan N de tao moi.");
		printf("\n\tDe Thoat, Nhan Enter\n");
		create = _getche();
		if (tolower(create) == 'n')
		{
			data1 = fopen("NhanVien.txt", "w+");
			printf("\n\tDatabase phong ban da duoc tao o thu muc.\n");
			printf("\n\tVui long khoi dong lai chuong trinh\nNhan Enter de tiep tuc.\n");
			char x;
			x = _getch();
			exit(0);
		}
		else
		{
			printf("\n\n\tCam on da su dung chuong trinh.\n");
			printf("\n\n\tChuong trinh se thoat.");
			exit(0);
		}
	}
	while (1)
	{
		MainMenu();
	}
	return 0;
}