#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

HANDLE hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);

void Ancontro() {
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(hConsoleColor,&info);
    info.bVisible=false;
    SetConsoleCursorInfo(hConsoleColor,&info);
}

void Hiencontro() {
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(hConsoleColor,&info);
    info.bVisible=true;
    SetConsoleCursorInfo(hConsoleColor,&info);
}

//ham cai font size va size font
void setFontSize() {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 8;
    cfi.dwFontSize.Y = 12;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Raster Fonts");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}


//handle de ghi len console
HANDLE wHnd;
//handle de doc tu console
HANDLE rHnd;

void resizeConsole() {
    //khoi tao gia tri doc va ghi cho handle
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);

    //Thay doi tieu de cho console
    SetConsoleTitle(TEXT("CHUONG TRINH QUAN LY SINH VIEN MTA"));

    // thiet lap ve kich thuoc moi
    SMALL_RECT windowSize = {0, 0, 500, 300};

    //Thay doi kich thuoc cho console
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    //kich thuoc bo dem
    COORD bufferSize = {500, 300};

    SetConsoleScreenBufferSize(wHnd, bufferSize);
}
// Ham to mau.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Ham dich chuyen con tro den toa do x, y.
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// Ham xoa man hinh.
void XoaManHinh(){
	string Delete="                                                                                                                                                                                                  ";
	for(int i=66;i>=4;i--){
		gotoxy(23,i); cout<<Delete;
	}
	gotoxy(	1,1); Ancontro();
}
// Ham xoa manhinh 2
void XoaManHinh2(int line){
	string Delete="                                                                                                                                 ";
	for(int i=line;i>=4;i--){
		gotoxy(23,i); cout<<Delete;
	}
	gotoxy(	1,1); Ancontro();
}

void XoaManHinh3(){
	string Delete="                                                                                                                                 ";
	for(int i=100;i>=1;i--){
		gotoxy(1,i); cout<<Delete;
	}
	gotoxy(	1,1); Ancontro();
}

//Ham xoa 1 dong
void ClearLine(int x,int y,int length){
	string Delete=" ";
	gotoxy(x,y); 
	for(int i=0;i<length;i++)
	cout<<Delete;
}

//ham viet len 1 dong voi toa do(x, y) va mau sac chu
// x, y la toa do con tro can nhay den de viet
// a la chuoi can truyen vao, color la mau truyen vao.
void DrawLine(int x, int y, string a, int color) 
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(14);
}

//tao 4 goc cua khung 4 toa do khac nhau
void DrawCorner(int x1,int y1, int x2, int y2,int x3,int y3, int x4, int y4){
	gotoxy(x1,y1); printf("%c",218); //goc trai ben tren
	gotoxy(x2,y2); printf("%c",191); // goc phai ben tren
	gotoxy(x3,y3); printf("%c",192);// goc trai ben duoi
	gotoxy(x4,y4); printf("%c",217);// goc phai ben duoi
}
void DrawCorner111(int x1,int y1, int x2,int y2){
	gotoxy(x1,y1); printf("%c",218); //goc trai ben tren
	gotoxy(x2,y1); printf("%c",191); // goc phai ben tren
	gotoxy(x1,y2); printf("%c",192);// goc trai ben duoi
	gotoxy(x2,y2); printf("%c",217);// goc phai ben duoi
}


void DrawFrameInput(int x1,int y1, int x2,int y2){ // Ve khung hinh optional

	DrawCorner111(x1,y1,x2,y2);
	gotoxy(x1+1,y1);	for(int ii=0;ii<(x2-x1-1);ii++){	printf("%c",196);}
	
	for(int ii=y1+1;ii<y2;ii++) { gotoxy(x1,ii); printf("%c",179);	}
	for(int ii=y1+1;ii<y2;ii++) { gotoxy(x2,ii); printf("%c",179);	}

	gotoxy(x1+1,y2);	for(int ii=0;ii<(x2-x1-1);ii++){	printf("%c",196);}

}
void DrawFrameInput2(){ // Ve khung hinh cho menu huong dan tim kiem
	DrawFrameInput(54,6,81,17);
}
void DrawFrameInput3(){ // For textField in Searching
	DrawFrameInput(1,2,3,4);
}
void DrawFrameMenuChoice(){ // ve khung hinh cho textMenuSortFiedld
	DrawFrameInput(26,6,52,18);
}

void VeKhungHinh(int focusMenuX){ //Ve khung hinh all page
	int row;
	gotoxy(23,focusMenuX); printf("%c",16); // Ham ve MuiTen xo ra menu capnhat
		
	DrawCorner111(24,5,145,46); // Draw
		
	gotoxy(25,5);	for(int ii=0;ii<120;ii++){	printf("%c",196);} // Ve dong ke ngang dau tien cua Khung
	gotoxy(25,46);	for(int ii=0;ii<120;ii++){	printf("%c",196);} // Ve dong ke ngang cuoi cung cua KHung
	row=6;	for (int i=0; i<40;i++){	gotoxy(24,row);	row++;	printf("%c",179);	} // Ham ve cot doc ben trai
	row=6;	for (int i=0; i<40;i++){	gotoxy(145,row);	row++;	printf("%c",179);	} // Ham ve cot doc ben phai
	
}


void MenuHuongDan() {
    DrawFrameInput(110, 7, 143, 30);
    int k = 10;

    DrawLine(117,k-2," Huong dan Nhap/Sua: ",78);
	DrawLine(111,k,"-Bam Enter lan 1: Chuong trinh ",14);
	DrawLine(111,k+1,"kiem tra loi sai",14);
	DrawLine(111,k+3,"-Bam Enter lan 2 hoac Up/Down",14);
	DrawLine(111,k+4,"de chuyen toi textbox tiep theo",14);
	DrawLine(111,k+6,"-Up/Down: Di chuyen giua cac o",14);
	DrawLine(111,k+7,"nhap du lieu",14);
	DrawLine(111,k+9,"-Bam ESC khi dang nhap de thoat",14);
	DrawLine(111,k+11,"*Luu y:",78);
	DrawLine(111,k+13,"+Khong nhap ki tu la: !@#*()..",14);
	DrawLine(111,k+15,"+Ten sinh vien chi bao gom chu",14);
	DrawLine(111,k+17,"+Du lieu nhap o danhsachSV.txt",14);
}

void MenuHuongDan222(int TYPE) {
    DrawFrameInput2();
    int k = 9;
    DrawLine(64, k-2, " Notice: ", 78);
    if(TYPE == 1) {
        DrawLine(55,k,"-Nhap ngay thang nam cach ",14);
		DrawLine(55,k+1,"nhau boi bat ki dau gi ",14);
		DrawLine(55,k+2,"-Vi du:",8);
		DrawLine(55,k+3,"  30/11/2021 or 30 11 2021",8); 
		DrawLine(55,k+5,"-Bam BACKSPACE de quay lai",14);
		DrawLine(55,k+7,"-Bam ESC de thoat toan bo",14);
    }
    if(TYPE == 2) {
        DrawLine(55,k,"-Nhap ngay thang nam cach ",14);
		DrawLine(55,k+1,"nhau boi dau (/) ",14);
		DrawLine(55,k+2,"-Vi du:",8);
		DrawLine(55,k+3,"  30/11/2021",8);
		DrawLine(55,k+5,"-Bam BACKSPACE de quay lai",14);
		DrawLine(55,k+7,"-Bam ESC de thoat toan bo",14);
    }
}