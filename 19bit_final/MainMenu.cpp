//_CRT_SECURE_NO_WARNINGS
#include"MainMenu.h"
#include"PhongBanMenu.h"
#include"NhanVienMenu.h"
#include"TimKiemMenu.h"
#include"extend.h"
void MainMenuView() 
{
	printf("\n\t1.Phong Ban");
	printf("\n\t2.Nhan Vien");
	printf("\n\t3.Tim Kiem");
	printf("\n\t4.Cap Nhat Du Lieu Bang Tay");
	printf("\n\t5.Thoat va luu Chuong Trinh");
}

void MainMenu() 
{
	int n;
	MainMenuView();
	printf("\n");
	printf("\nLua chon chuc nang: ");
	scanf("%d", &n);
	switch (n)
	{
	case 1: clrscr(),PhongBanMenu();
		break;
	case 2: clrscr(),NhanVienMenu();
		break;
	case 3: clrscr(),TimKiemMenu();
		break;
	case 5: exit(10);
	default: 
		break;
	}
	_getch();
}