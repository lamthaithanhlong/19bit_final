#include<stdio.h>
#include<conio.h>
#include"TimKiemMenu.h"

void TimKiemMenuView()
{
	printf("\t1.Tim Phong co nhieu nhan vien nhat");
	printf("\n\t2.Tim Phong tra luong it nhat");
	printf("\n\t3.Tim So luong nam nu trong cong ty");
	printf("\n\t4.Tim Phong co nhieu nu nhat");
	printf("\n\t5.Tim Phong nao co nhan vien lon tuoi va nho tuoi");
	printf("\n\t6.Tro lai Menu chinh");
};
void TimKiemMenu()
{
	int n;
	printf("\nLua chon mot trong cac chuc nang sau day cua nhan vien: \n");
	TimKiemMenuView();
	printf("\n\nNhap so tuong ung tren menu: ");
	scanf("%d", &n);
	switch (n)
	{
	case 1:;
		break;
	case 2:;
		break;
	default:
		break;
	}
};