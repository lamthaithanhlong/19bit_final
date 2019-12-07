#include<stdio.h>
#include<conio.h>
#include"PhongBanMenu.h"
#include"PhongBan.h"
#include"MainMenu.h"
#include"extend.h"

void PhongBanMenuView()
{
	printf("\t1.Xuat Phong Ban");
	printf("\n\t2.Nhap Phong Ban");
	printf("\n\t3.Tro lai Menu chinh");
}

void PhongBanMenu() 
{
	int n;
	PhongBanMenuView();
	printf("\nLua chon mot trong cac chuc nang sau day cua phong ban: ");
	scanf("%d", &n);
	switch (n)
	{
	case 1: XuatPhongBan();
		break;
	case 3: clrscr(), MainMenu();
		break;
	default:
		break;
	}
}
