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
	dangnhap();
 	menu();
	QuanlyMenu();
	return 0;
}

/*
NGAY 26/11/2021 - 3901 dòng
define-text: 105
dohoa: 208
menu: 723
timkiem: 594
sapxep: 443
capnhat: 1038
header: 768
main: 22
*/