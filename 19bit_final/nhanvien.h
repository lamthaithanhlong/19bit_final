#ifndef __NhanVien_H_
#define __NhanVien_H_
#pragma once

#include<stdio.h>
#include<conio.h>


#define size 1
#define max_data 10

static struct NhanVien_data
{
	char name[100];
	char nhanvien_id[100];
}pb;

struct list {
	NhanVien_data a[max_data];
	int n;
};

void ThemNhanVien();
void XuatNhanVien();

void nhanvien_append();
void nhanvien_displayAll();
void nhanvien_delete();
void nhanvien_modify();
void nhanvien_search();
void count_nhan_vien();

#endif // !__NhanVien_H_

