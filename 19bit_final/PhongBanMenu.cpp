#include<stdio.h>
#include<conio.h>
#include"PhongBanMenu.h"
#include"PhongBan.h"
#include"MainMenu.h"
#include"extend.h"

void PhongBanMenuView()
{
	printf("\n\t1.Them phong ban");
	printf("\n\t2.Thay doi phong ban");
	printf("\n\t3.Xoa phong ban");
	printf("\n\t4.Xem danh sach phong ban");
	printf("\n\t5.Tro lai Menu chinh");
}

void PhongBanMenu() 
{
	int n;
	printf("\nLua chon mot trong cac chuc nang sau day cua phong ban: \n");
	PhongBanMenuView();
	printf("\n\nNhap so tuong ung tren menu: ");
	scanf("%d", &n);
	switch (n)
	{
	case 1: emp_append();
		break;
	case 2: clrscr(), emp_displayAll(), emp_modify();
		break;
	case 3:emp_delete();
		break;
	case 4: emp_displayAll();
		break;
	case 5: clrscr(), head_disp(), MainMenu();
		break;
	default:
		break;
	}
}
