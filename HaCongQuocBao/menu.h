#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int PointScreen=1;  
int SortTypeScreen=1;  
int SearchTypeScreen=1;  
int DeleteScreen=1;
int StatisticalTypeScreen=1;


void menuTrangChu(){
	XoaManHinh(); 
	VeKhungHinh(6);
	MenuHuongDan();
	MenuHuongDan222(1);
	Ancontro();
}
void menuTypeFocused_Reverse(int getkey1,int toadoX1,int toadoY1,string textMenu1[],int focus1,int toadoY2,int focus2){
	if(getkey1==80){  DrawLine(toadoX1,toadoY1,textMenu1[focus1],14);
					  DrawLine(toadoX1,toadoY2,textMenu1[focus2],30);	
				   } 
	if(getkey1==72){  DrawLine(toadoX1,toadoY1,textMenu1[focus1],14);
					  DrawLine(toadoX1,toadoY2,textMenu1[focus2],30);	
				   } 
}
void menuTypeFocused(int getkey1,int toadoX1,int &toadoY1,string textMenu1[],int &focus1,int plus1,int plus2){
	if(getkey1==80){  DrawLine(toadoX1,toadoY1,textMenu1[focus1],14);toadoY1+=plus2;focus1+=plus1;
					  DrawLine(toadoX1,toadoY1,textMenu1[focus1],30);	
				   } 
	if(getkey1==72){  DrawLine(toadoX1,toadoY1,textMenu1[focus1],14);	toadoY1-=plus2;	focus1-=plus1;
					  DrawLine(toadoX1,toadoY1,textMenu1[focus1],30);						
				   } 
}
void menuManagement(int type,int row,int rowMenu,int rowMenuCon,int toadoX,int dodaiText,int i1,int i2,int i3){

	gotoxy(23,rowMenu); printf("%c",16); // Ham ve MuiTen xo ra menu capnhat
	
	DrawCorner111(toadoX,rowMenu-1,toadoX+dodaiText, rowMenu+rowMenuCon);

	gotoxy(25,rowMenu-1);	for(int ii=0;ii<dodaiText-1;ii++){	printf("%c",196);} // Ve dong ke ngang dau tien
			
	row=rowMenu+1;	for (int i=0; i<i1;i++){	gotoxy(toadoX+1,row);	row+=2;	for(int ii=0;ii<dodaiText-1;ii++){	printf("%c",196);}	} // Ham ve dong ke ngang
	row=rowMenu;	for (int i=0; i<i2;i++){	gotoxy(toadoX,row);	row++;	printf("%c",179);	} // Ham ve cot doc ben trai
	row=rowMenu;	for (int i=0; i<i2;i++){	gotoxy(toadoX+dodaiText,row);	row++;	printf("%c",179);	} // Ham ve cot doc ben phai
	switch(type){
		case 1:	row=rowMenu;		for (int i=1; i<=i3;i++){	gotoxy(toadoX+1,row);	row+=2;	cout<<textMenuCapNhat[i];} break; // Ve textMenu
		case 2: break;
		case 3:row=rowMenu;		for (int i=1; i<=i3;i++){	gotoxy(toadoX+1,row);	row+=2;	cout<<textMenuSapXep[i];}break;
		case 4:row=rowMenu;		for (int i=1; i<=i3;i++){	gotoxy(toadoX+1,row);	row+=2;	cout<<textMenuTimKiem[i];}break;
		case 5:row=rowMenu;		for (int i=1; i<=i3;i++){	gotoxy(toadoX+1,row);	row+=2;	cout<<textMenuThongKe[i];}break;
	}
}
void menuCapNhat(){		XoaManHinh();
	
	if(PointScreen==1) {
		menuManagement(1,0,8,7,24,19,4,7,4);
	}
	if(PointScreen==2) {
		menuManagement(1,0,8,7,24,19,4,7,4);
		DrawLine(25,8,"Them moi sinh vien", 30);
	}
	Ancontro();
}


// Bat dau menu EDITTING ===================
void menuEditting( ){
	XoaManHinh();
	DrawLine(27,7,"Chon truong de chinh sua:",14);
	row=8;	for(int i=1; i<=9;i++){
			DrawLine(27,row,textMenuSortField[i],14);
			row++;
			}
	DrawLine(27,8,textMenuSortField[1],30);DrawFrameMenuChoice();MenuHuongDan222(1);
	while(1)
	{ 
		int getkeyDelete=getch();
		if(getkeyDelete==224)
		{
			getkeyDelete=getch();
			if(getkeyDelete==80)
			{
				if(focusSortField==9){ toadoYDelete=16; 	}
				else	menuTypeFocused(80,27,toadoYSortField,textMenuSortField,focusSortField, 1,1);
			}
			if(getkeyDelete==72)
			{	
				if(focusSortField==1){ toadoYDelete=8; 	}
				else	menuTypeFocused(72,27,toadoYSortField,textMenuSortField,focusSortField, 1,1);
			}
		}
		if(getkeyDelete==13){
			SwitchEdittingField();
			PointScreen=1;
			return;
		}
		if(getkeyDelete==8){
			XoaManHinh();
			DrawLine(26,6,"Moi ban tiep tuc su dung chuong trinh!",14);
			return;
		}
		if(getkeyDelete==27){
			XoaManHinh();
			DrawLine(26,6,"Moi ban tiep tuc su dung chuong trinh!",14);
			return;
		}
	}
}
// Ket thuc menu EDITTING =======================



// Bat dau menu Delete ===================
void menuDelete( ){XoaManHinh();
	DrawLine(27,7,"Chon cach xoa:",14);
	row=8;	for(int i=1; i<=2;i++){	DrawLine(27,row,textMenuDelete[i],14);	row++;	}	
	DrawLine(27,8,textMenuDelete[1],30);
	while(1)
	{
	int getkeyDelete=getch();
		if(getkeyDelete==224)
		{
			getkeyDelete=getch();
			if(getkeyDelete==80)
			{
				if(focusDelete==2){ toadoYDelete=9; 	}
				else	menuTypeFocused(80,27,toadoYDelete,textMenuDelete,focusDelete, 1,1);
			}
			if(getkeyDelete==72)
			{
				if(focusDelete==1){ toadoYDelete=8; 	}
			 	else		menuTypeFocused(72,27,toadoYDelete,textMenuDelete,focusDelete, 1,1);
			}
		}
		if(getkeyDelete==13){
			if(focusDelete==2) { XoaManHinh();
				DrawLine(27,7,"Ban co chac chan muon xoa tat ca du lieu?",207);
				DrawLine(27,8,"Bam Enter de xoa ",14);
				DrawLine(27,9,"Bam phim khac de thoat ra ",14);
				int getkeyDeleteAll=getch();
				if(getkeyDeleteAll==13)	XoaSinhVien(2,1); 
				else {
					XoaManHinh(); 
					DrawLine(27,8,"Bam phim LEFT de vao MENU <-",14);
				}
				return;
			}
				
			else	break;
		}
		if(getkeyDelete==8){
			XoaManHinh();
			DrawLine(26,6,"Moi ban tiep tuc su dung chuong trinh!",14);
			return;
		}
		if(getkeyDelete==27){
			XoaManHinh();
			DrawLine(26,6,"Moi ban tiep tuc su dung chuong trinh!",14);
			return;
		}
	} //end While
	XoaManHinh();
	DrawLine(27,7,"Chon truong de xoa:",14);
	row=8;	for(int i=1; i<=9;i++){
			DrawLine(27,row,textMenuSortField[i],14);
			row++;
	}
	DrawLine(27,8,textMenuSortField[1],30); 
	DrawFrameMenuChoice();
	MenuHuongDan222(1);
	while(1)
	{ 
		int getkeyDelete=getch();
		if(getkeyDelete==224)
		{
			getkeyDelete=getch();
			if(getkeyDelete==80)
			{
				if(focusSortField==9){ toadoYDelete=16; 	}
				else	menuTypeFocused(80,27,toadoYSortField,textMenuSortField,focusSortField, 1,1);
			}
			if(getkeyDelete==72)
			{
				if(focusSortField==1){ toadoYDelete=8; 	}
				else	menuTypeFocused(72,27,toadoYSortField,textMenuSortField,focusSortField, 1,1);
			}
		}
		if(getkeyDelete==13){
			SwitchfocusDelete();
			PointScreen=1;
			return;
		}
		if(getkeyDelete==8){
			XoaManHinh();
			DrawLine(26,6,"Moi ban tiep tuc su dung chuong trinh!",14);
		
			return;
		}
		if(getkeyDelete==27){
			XoaManHinh();
			DrawLine(26,6,"Moi ban tiep tuc su dung chuong trinh!",14);
			return;
		}
	}
}
// Ket thuc menu Delete =======================
void menuInDanhSach111(){
	gotoxy(23,10); printf("%c",16); // Ham ve mui ten xo ra menu capnhat
	DrawCorner(24,9,46,9,24,11,46,11);

	gotoxy(25,9);	for(int ii=0;ii<21;ii++){	printf("%c",196);} // Ve dong ke ngang dau tien
	row=11;	for (int i=0; i<1;i++){	gotoxy(25,row);	row+=2;	for(int ii=0;ii<21;ii++){	printf("%c",196);}	} // Ham ve dong ke ngang
	row=10;	for (int i=0; i<1;i++){	gotoxy(24,row);	row++;	printf("%c",179);	} // Ham ve cot doc ben trai
	row=10;	for (int i=0; i<1;i++){	gotoxy(46,row);	row++;	printf("%c",179);	} // Ham ve cot doc ben phai
	row=10;	for (int i=1; i<=1;i++){	gotoxy(25,row);	row+=2;	cout<<textMenuInList[i];} // Ve textMenu
}

void menuInDanhSach(){	
	XoaManHinh();
	gotoxy(25,6); int row;
	if(PointScreen==1) {
		menuInDanhSach111();
	}
	
	if(PointScreen==2) {
		menuInDanhSach111();
		DrawLine(25,10,textMenuInList[1], 30);
	}
	Ancontro();
}

void menuSapXep(int isReturn){	XoaManHinh();
	if(PointScreen==1) 
	{
		menuManagement(3,0,12,7,24,19,4,7,4);	
	}
	if(PointScreen==2) {
		if(SortTypeScreen==1)
		{
			menuManagement(3,0,12,7,24,19,4,7,4);	
			DrawLine(25,12,textMenuSapXep[1], 30);
		}
		if(SortTypeScreen==0)
		{
			DrawLine(27,7,"Chon truong de sap xep:",14);
			row=8;	for(int i=1; i<=9;i++)
					{
						DrawLine(27,row,textMenuSortField[i],14);
						row++;
					}
			DrawLine(27,isReturn+7,textMenuSortField[isReturn],30);
			DrawFrameMenuChoice();
		}
	}
	Ancontro();
}

void menuTimKiem(int isReturn){XoaManHinh();
	if(PointScreen==1) 	menuManagement(4,0,14,3,24,24,2,3,2);	
	if(PointScreen==2) {
		if(SearchTypeScreen==1){
			menuManagement(4,0,14,3,24,24,2,3,2);
			DrawLine(25,14,textMenuTimKiem[1], 30);	
		}
		if(SearchTypeScreen==0){
			DrawLine(27,7,"Chon truong de tim kiem:",14);
			row=8;	for(int i=1; i<=9;i++){
					DrawLine(27,row,textMenuSortField[i],14);
					row++;
					}
			DrawLine(27,isReturn+7,textMenuSortField[isReturn],30);
			DrawFrameMenuChoice();MenuHuongDan222(2);
		}
	}
}

void menuThongKe111(){
	gotoxy(23,16); printf("%c",16); // Ham ve mui ten xo ra menu capnhat
	DrawCorner111(24,15,46,19);
	gotoxy(25,15);	for(int ii=0;ii<21;ii++){	printf("%c",196);} // Ve dong ke ngang dau tien
	row=17;	for (int i=0; i<=1;i++){	gotoxy(25,row);	row+=2;	for(int ii=0;ii<21;ii++){	printf("%c",196);}	} // Ham ve dong ke ngang
	row=16;	for (int i=0; i<=2;i++){	gotoxy(24,row);	row++;	printf("%c",179);	} // Ham ve cot doc ben trai
	row=16;	for (int i=0; i<=2;i++){	gotoxy(46,row);	row++;	printf("%c",179);	} // Ham ve cot doc ben phai
	
	row=16;		for (int i=1; i<=2;i++){	gotoxy(25,row);	row+=2;	cout<<textMenuThongKe[i];} // Ve textMenu
}
void menuThongKe(){	
	XoaManHinh();
	gotoxy(25,16); int row;
	if(PointScreen==1) {
		menuThongKe111();
	}
	
	if(PointScreen==2) {
		menuThongKe111();
		DrawLine(25,16,textMenuThongKe[1], 30);	
	}
	Ancontro();
}

void menuThoat(){
	XoaManHinh();
	gotoxy(25,6);	printf("Ban co thuc su muon thoat?? ");
 	gotoxy(25,7);	printf("Bam ESC de Thoat chuong trinh ");
}
void MenuFocus(int focus){
	if(focus==1) menuTrangChu();
	if(focus==2) menuCapNhat();
	if(focus==3) menuInDanhSach();
	if(focus==4) menuSapXep(1);
	if(focus==5) menuTimKiem(1);
	if(focus==6) menuThongKe();
	if(focus==7) menuThoat();				
}

void dangki() {
	fstream fileDN;
	fileDN.open("DangNhap.txt", ios::in | ios::app);
	string TK[100];
	string MK[100];
	string tk;
	string mk;
	string mkXacNhan;
	int xacnhan=0;
	int dem;
	int n=0;
	while(!fileDN.eof()){
		fflush(stdin); getline(fileDN, TK[n]);
		fflush(stdin); getline(fileDN, MK[n]);
		n++;
	}
	fileDN.close();
	fileDN.open("DangNhap.txt", ios::out | ios::app);
	XoaManHinh3();
	DrawFrameInput(10, 3, 80, 19);
	textcolor(78);
	gotoxy(35,5);printf("TAO TAI KHOAN DANG NHAP");
	textcolor(14);
	DrawLine(12,8,"TEN DANG NHAP",14);
	DrawFrameInput(30,7,79,9);
	DrawLine(12,11,"MAT KHAU",14);
	DrawFrameInput(30,10,79,12);
	DrawLine(12,14,"NHAP LAI MAT KHAU",14);
	DrawFrameInput(30,13,79,15);
	Hiencontro();
	gotoxy(31, 8); fflush(stdin); cin >> tk; 
	gotoxy(31, 11); fflush(stdin); cin >> mk;
	do {
		Hiencontro();
		ClearLine(31, 17, 45);
		ClearLine(31, 14, 45);
		gotoxy(31, 14); fflush(stdin); cin >> mkXacNhan;
		for(int i=0; i<mkXacNhan.size(); i++) {
			gotoxy(31+i, 14); printf("%c", 42);
		}
		if(mkXacNhan==mk) {
			dem=0;
			for(int i=0; i<n; i++){
				if(tk == TK[i] && mk == MK[i]) {
					dem++;
				}
			}
			if(dem==0) 
			{
				xacnhan=1;
				fileDN << "\n" << tk;
				fileDN << "\n" << mk;
				Ancontro();
				gotoxy(31, 17);
				cout << "Tao tai khoan thanh cong!";
				sleep(2);
				XoaManHinh3();
			} else {
				Ancontro();
				gotoxy(31, 17);
				cout << "Tai khoan hoac mat khau da ton tai!";
				sleep(2);
				ClearLine(31, 8, 45);
				ClearLine(31, 11, 45);
				ClearLine(31, 14, 45);
				ClearLine(31, 17, 45);
				Hiencontro();
				gotoxy(31, 8); fflush(stdin); cin >> tk; 
				gotoxy(31, 11); fflush(stdin); cin >> mk;
			}
		} else {
			Ancontro();
			gotoxy(31, 17); cout << "Mat khau xac nhan khong chinh xac!";
			sleep(2);
		}
	} while(xacnhan==0);
	fileDN.close();
}

void dangnhap() {
	ifstream fileDN;
	fileDN.open("DangNhap.txt", ios::in);
	string TK[100];
	string MK[100];
	string tk;
	string mk;
	int dem=0;
	int n=0;
	bool dn = false;
	while(!fileDN.eof()){
		fflush(stdin); getline(fileDN, TK[n]);
		fflush(stdin); getline(fileDN, MK[n]);
		n++;
	}
	textcolor(14);
	while(!dn) {
		XoaManHinh3();
		DrawFrameInput(10, 3, 75, 16);
		textcolor(78);
		gotoxy(35,5);printf("DANG NHAP TAI KHOAN");
		textcolor(14);
		DrawLine(12,8,"TEN DANG NHAP",14);
		DrawFrameInput(26,7,74,9);
		DrawLine(12,11,"MAT KHAU",14);
		DrawFrameInput(26,10,74,12);
		Hiencontro();
		gotoxy(27, 8); fflush(stdin); cin >> tk;
		gotoxy(27, 11); fflush(stdin); cin >> mk;
		for(int i=0; i<n; i++){
			if(tk == TK[i] && mk == MK[i]) {
				XoaManHinh3();
				dn = true;
				return;
			}
		}
		dem++;
		if(dem==3) {
			Ancontro();
			gotoxy(12, 14); printf("Ban da dang nhap sai 3 lan!");
			sleep(2);
			XoaManHinh3();
			printf("Tu dong thoat chuong trinh do nhap sai qua 3 lan!");
			exit(0);
		}
		Ancontro();
		gotoxy(12, 14); printf("Tai khoan hoac mat khau da sai. Xin nhap lai!");
		sleep(2);
	}
	fileDN.close();
}

void login() {
	DrawFrameInput(10, 4, 110, 20);
	textcolor(78);
	Ancontro();
	gotoxy(39,5);printf("CHUONG TRINH QUAN LY HOC VIEN VA SINH VIEN");
	gotoxy(46,6);printf("HOC VIEN KY THUAT QUAN SU");
	textcolor(14);
	DrawFrameInput(20, 12, 44, 16);
	gotoxy(28, 14); printf("DANG NHAP");
	DrawFrameInput(76, 12, 100, 16);
	gotoxy(85, 14); printf("DANG KI");
	int n=0;
	while(n==0) {
		ClearLine(49, 7, 21);
		gotoxy(49, 7); printf("Editted"); gotoxy(45, 8); printf("Email:"); sleep(1);
		gotoxy(49, 7); printf("Editted by"); gotoxy(45, 8); printf("Email: hacongquoclun@gmail"); sleep(1);
		gotoxy(49, 7); printf("Editted by QUOC BAO"); gotoxy(45, 8); printf("Email: hacongquoclun@gmail.com"); sleep(1);
		textcolor(78);
		gotoxy(49, 7); printf("Editted by QUOC BAO");
		gotoxy(45, 8); printf("Email: hacongquoclun@gmail.com");
		textcolor(14);
		n = getch();
	}
	while(1) 
	{
		n=getch();
		switch(n) 
		{
			case 75:
				textcolor(78);
				for(int i=13; i<16; i++) {
					gotoxy(21, i);
					printf("                       ");
				}
				gotoxy(28, 14); printf("DANG NHAP");
				textcolor(14);
				n=getch();
				if(n==13) {
					dangnhap();
					return;
				}
				else {
					for(int i=13; i<16; i++) {
						gotoxy(21, i);
						printf("                       ");
					}
					gotoxy(28, 14); printf("DANG NHAP");
					break;
				}
			case 77: 
				textcolor(78);
				for(int i=13; i<16; i++) {
					gotoxy(77, i);
					printf("                       ");
				}
				gotoxy(85, 14); printf("DANG KI");
				textcolor(14);
				n=getch();
				if(n==13) {
					dangki();
					XoaManHinh3();
					dangnhap();
					return;
				}
				else {
					for(int i=13; i<16; i++) {
						gotoxy(77, i);
						printf("                       ");
					}
					gotoxy(85, 14); printf("DANG KI");
					break;
				}
		}
	}
}

void menu()
{	
	char n[]="CHUONG TRINH QUAN LY SINH VIEN MTA",z[]="Editted by QUOC BAO";
	textcolor(78);
	gotoxy(65,2);printf("%s",n);
	gotoxy(72,3);printf("%s",z);

	CreateTextMenu();
	textcolor(14);
	int j; // Vi tri 
	DrawCorner(6,5,22,5,6,19,22,19);
	gotoxy(7,5);	for(int ii=0;ii<15;ii++){	printf("%c",196);} // Ve dong ke ngang dau tien
	j=7;	for (int i=0; i<7;i++){		gotoxy(7,j);	j+=2;	for(int ii=0;ii<15;ii++){	printf("%c",196);}	} //Ve dong ke ngang
	j=6;	for (int i=1; i<8;i++){		gotoxy(7,j);	j+=2;	cout<<textMenu[i];} // Ve textMenu
	j=6;	for (int i=0; i<13;i++){	gotoxy(6,j);	j++;	printf("%c",179);	} 
	j=6;	for (int i=0; i<13;i++){	gotoxy(22,j);	j++;	printf("%c",179);	}// Hai ham ve~ cot doc cua Menu
	DrawLine(7,6,textMenu[1],78);
	menuTrangChu();
	textcolor(14);
}
void menuFocused(int getkeymenuFocused){
	if(getkeymenuFocused==80){ 
			DrawLine(7,toadoYMenu,textMenu[focusMenu],14);toadoYMenu+=2; 	focusMenu+=1;
			DrawLine(7,toadoYMenu,textMenu[focusMenu],78);
			MenuFocus(focusMenu);					
			}
	if(getkeymenuFocused==72) {
			DrawLine(7,toadoYMenu,textMenu[focusMenu],14);	toadoYMenu-=2;	focusMenu-=1;
			DrawLine(7,toadoYMenu,textMenu[focusMenu],78);
			MenuFocus(focusMenu);	
			} //end if getkey==72 PonintScreen ==1
}


//MAIN XU LY MENU==========================
int QuanlyMenu(){
	int TuChoiMenu=0;
	int n=getch();
	toadoYMenu=6;
	//Bat dau vong while trong menu 
	while(1){
	
	int getkey=getch();
	switch (getkey){
		case 224:
			getkey=getch();
			if(getkey==75 ){ // getkey == Mui ten LEFT
				XoaManHinh();
				TuChoiMenu=0;
				PointScreen=1; 	MenuFocus(focusMenu); 
				SortTypeScreen=1;
				SearchTypeScreen=1;
			}
			if(getkey==77 ) { // getkey == Mui ten RIGHT
				TuChoiMenu=0;
				PointScreen=2; 	
				MenuFocus(focusMenu); 
				Khoitaobien(); 
			}
			if(PointScreen==1){
				if(getkey==80){ 
					if(focusMenu==7) break;
						else{
							menuFocused(80);	
						}
				} 
				if(getkey==72) {
					if(focusMenu==1) break;
					else{
						menuFocused(72);
					}
						// end else
				} //end if getkey==72 PonintScreen ==1
			} //End of Point Screen 1
			if(PointScreen==2){
				if(focusMenu==2) // focusMenu dang o void cua CAPNHAT=======================================
					{
					if(getkey==80){  
						if(focusCapNhat==4) { 
							toadoYCapNhat=14; 
							break;
						}
						else {
							if(TuChoiMenu==0)	menuTypeFocused(80,25, toadoYCapNhat,textMenuCapNhat,focusCapNhat,1,2);
						}
					} 
					if(getkey==72) { 
						if(focusCapNhat==1) {
							toadoYCapNhat=8; 
							break;
						}
						else{
							if(TuChoiMenu==0)	menuTypeFocused(72,25,toadoYCapNhat,textMenuCapNhat,focusCapNhat,1,2);
						}	
					} // end of if focusMenu ==2 cua Cap Nhat 
				}
				if(focusMenu==4) // focusMenu dang o void cua SAP XEP=======================================
					{
					if(SortTypeScreen==1)	// man hinh chon MENU de sap xep
					{

						if(getkey==80){  
							if(focusSapXep==4) {
								toadoYSapXep=16; 
								break;
							}
							else {	
								menuTypeFocused(80,25, toadoYSapXep,textMenuSapXep,focusSapXep,1,2);
							}
						} 
						if(getkey==72) { 
							if(focusSapXep==1) {
								toadoYSapXep=10;
								break;
							}
							else{	
								menuTypeFocused(72,25, toadoYSapXep,textMenuSapXep,focusSapXep,1,2);
							}	
						}
					}

					if(SortTypeScreen==0) // Man hinh chon TRUONG de sap xep
					{
						if(getkey==80){  
							if(focusSortField==9) { 
								menuTypeFocused_Reverse(80,27,16,textMenuSortField,9,8,1);
								DrawFrameMenuChoice();
								toadoYSortField=8;
								focusSortField=1;
								break;
							}

							else {	
								menuTypeFocused(80,27, toadoYSortField,textMenuSortField,focusSortField,1,1);
								DrawFrameMenuChoice();
							}
							
						} 

						if(getkey==72) { 
							if(focusSortField==1) {
								menuTypeFocused_Reverse(80,27,8,textMenuSortField,1,16,9);
								DrawFrameMenuChoice();
								toadoYSortField=16;
								focusSortField=9;
								break;
							}
							else{	
								menuTypeFocused(72,27, toadoYSortField,textMenuSortField,focusSortField,1,1);
								DrawFrameMenuChoice();
							}	
						}
					}
				} // end focusMenu dang o void cua SAP XEP
				if(focusMenu==5) // focusMenu dang o void cua TIM KIEM=======================================
					{
					if(SearchTypeScreen==1)	// man hinh chon MENU de Tim kiem
					{

						if(getkey==80){  
							if(focusTimKiem==3) { 
								toadoYTimKiem=18; 
								break;
							}
							else {	
								menuTypeFocused(80,25, toadoYTimKiem,textMenuTimKiem,focusTimKiem,1,2);
							}
						} 
								
						if(getkey==72) { 
							if(focusTimKiem==1) {
								toadoYTimKiem=14; 
								break;
							}
							else{	
								menuTypeFocused(72,25, toadoYTimKiem,textMenuTimKiem,focusTimKiem,1,2);
							}	
						}
					}
						
					if(SearchTypeScreen==0) // Man hinh chon TRUONG de Tim kiem
					{
						if(getkey==80){  
							if(focusSortField==9) { 
								toadoYSortField=16; 
								break;
							}
							else {	
								menuTypeFocused(80,27, toadoYSortField,textMenuSortField,focusSortField,1,1);
								DrawFrameMenuChoice();
								MenuHuongDan222(2);
							}
						} 
						if(getkey==72) { 
							if(focusSortField==1) {
								toadoYSortField=8; 
								break;
							}
							else{	
								menuTypeFocused(72,27, toadoYSortField,textMenuSortField,focusSortField,1,1);
								DrawFrameMenuChoice();
								MenuHuongDan222(2);
							}	
						}
					}
				}

				if (focusMenu==6) 
				{
					if(StatisticalTypeScreen==1) 
					{
						if(getkey==80){  
							if(focusThongKe==3) { 
								toadoYThongKe=20; 
								break;
							}
							else {	
								menuTypeFocused(80,25, toadoYThongKe,textMenuThongKe,focusThongKe,1,2);
							}
						} 
								
						if(getkey==72) { 
							if(focusThongKe==1) {
								toadoYThongKe=16; 
								break;
							}
							else{	
								menuTypeFocused(72,25, toadoYThongKe,textMenuThongKe,focusThongKe,1,2);
							}	
						}
					}
				}
				
			}	 // end of Pointscreen 2
			break; // break of case 224
			
		case 13:  // Getkey phim ENTER====================================================GetKey phim ENTER====Enter
			if(focusMenu==7) // THoat ra khi an Enter tai menu Thoat
				{
					system("cls");
					printf("Ban da thoat chuong trinh");
					return 0;
				}
			if(focusMenu==2){// Menu Cap Nhat Enter
				if(focusCapNhat==1){	// FocusCapNhat tai ThemMoiSinhVien
					XoaManHinh();
					VeKhungHinh(7);
					SinhVien a;
					NhapSV(a,-24);
					PointScreen=1;
				}
				if(focusCapNhat==2){	// FocusCapNhat tai SuaSinhVien
					XoaManHinh();
				
					menuEditting();
					PointScreen=1;
				}
				if(focusCapNhat==3) { // FocusCapNhat tai XoaSinhVien
					XoaManHinh();
					VeKhungHinh(7);
					menuDelete();
					PointScreen=1;
				}
				if(focusCapNhat==4){	// FocusCapNhat tai Nhap TB tu FIle
					XoaManHinh();
					NhapFile();
					PointScreen=1;
				}
			}//End Menu Cap Nhat Enter

			// menu InDanhSach Enter
			if(focusMenu==3){ 
				if(focusInList==1){
					XoaManHinh();
					indanhsach();
					PointScreen=1;
				}
			}

			// menu SapXep Enter
			if(focusMenu==4){ 
				if(SortTypeScreen==1)
					{
						SortTypeScreen=0;
						XoaManHinh();
						menuSapXep(1);
					}
				if(SortTypeScreen==0)
					{	
						SwitchfocusSapXep();
						SortTypeScreen=0;
						menuSapXep(focusSortField);
					}
			}

			// menu TimKiem Enter
			if(focusMenu==5){ 
				if(SearchTypeScreen==1)
					{
						SearchTypeScreen=0;
						XoaManHinh();
						menuTimKiem(1);
					}
				if(SearchTypeScreen==0)
					{	
						SwitchfocusTimKiem();
						SearchTypeScreen=0;
						menuTimKiem(focusSortField);	
					}
			}
			if(focusMenu==6){ // menu ThongKe Enter
				if(focusThongKe==1){
					XoaManHinh();
					ThongKe(1);
					PointScreen=1;
				}
				if(focusThongKe==2){
					XoaManHinh();
					ThongKe(2);
					PointScreen=1;
				}
			}
		break;

		// Getkey phim BACKSPACE
		case 8: 
			XoaManHinh();
			PointScreen=1;
			TuChoiMenu=1;
			break;
		
		// Getkey phim ESC
		case 27:  
			XoaManHinh();
			DrawLine(27,7,"Ban muon thoat chuong trinh?? Bam enter!",14);
			int enter=getch();
			if(enter==13) 
			{
				system("cls");
				printf("Ban da thoat chuong trinh");
				return 0;
			}
			else{
				XoaManHinh();
				PointScreen=1;
			}
			break;
		} //end switch
	} // end while
} // end void QuanlyMenu