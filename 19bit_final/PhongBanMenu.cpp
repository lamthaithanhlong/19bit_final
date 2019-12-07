#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include"PhongBanMenu.h"
#include"PhongBan.h"

void clrscr()
{
	system("@cls||clear");
}

void PhongBanMenuView()
{
	printf("\t1.Xuat Phong Ban");
	printf("\n\t2.Nhap Phong Ban");
}

void PhongBanMenu() 
{
	int n;
	PhongBanMenuView();
	printf("Lua chon mot trong cac chuc nang sau day cua phong ban: \n");
	scanf("%d", &n);
	switch (n)
	{
	case 1: XuatPhongBan();
	default:
		break;
	}
}
