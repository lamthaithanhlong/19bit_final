#ifndef __PhongBan_H_
#define __PhongBan_H_
#pragma once

#include<stdio.h>
#include<conio.h>


#define size 1
#define max_data 10

static struct phongban_data
{
	char name[100];
	char phongban_id[100];
}pb;

struct list {
	phongban_data a[max_data];
	int n;
};

void ThphongbanhongBan();
void XuatPhongBan();

void phongban_append();
void phongban_displayAll();
void phongban_delete();
void phongban_modify();
void phongban_search();
void count_nu_nhanvien();

#endif // !__PhongBan_H_

