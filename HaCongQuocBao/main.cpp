#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
#include "dohoa.h"
#include "header.h"


int main()
{
	resizeConsole();
	setFontSize();
	login();
 	menu();
	QuanlyMenu();
	return 0;
}

/*
Ngày 10/12/2021 - 4009 dòng
- Sửa phần đăng nhập - đăng kí

define-text: 104
dohoa: 208
menu: 723
timkiem: 594
sapxep: 443
capnhat: 1038
header: 877
main: 22
*/