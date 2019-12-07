#include<stdio.h>
#include<conio.h>
#include"NhanVienMenu.h"

void NhanVienMenuView()
{
	printf("\t1.Them nhan vien");
	printf("\n\t2.Thay doi nhan vien");
	printf("\n\t3.Xoa nhan vien");
	printf("\n\t4.Xem danh sach nhan vien");
	printf("\n\t5.Tro lai Menu chinh");
};

void NhanVienMenu() 
{
	int n;
	printf("\nLua chon mot trong cac chuc nang sau day cua nhan vien: \n");
	NhanVienMenuView();
	printf("\n\nNhap so tuong ung tren menu: ");
	scanf("%d", &n);
	switch (n)
	{
	case 1: ;
		break;
	case 2: ;
		break;
	default:
		break;
	}
};