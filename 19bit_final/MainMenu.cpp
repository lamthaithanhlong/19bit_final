//_CRT_SECURE_NO_WARNINGS
#include"MainMenu.h"
#include"PhongBanMenu.h"
void MainMenu() 
{
	int n;
	printf("Lua chon chuc nang: ");
	scanf("%d", &n);
	switch (n)
	{
	case 1: PhongBanMenu();
	case 2: printf("Lua chon chuc nang nhan vien ");
	default: 
		break;
	}
	_getch();
}