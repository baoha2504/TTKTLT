#include <string>
#include "define-text.h"
#define N 2000

struct Date{
  	int day,month,year;
};

typedef struct SinhVien
{
	char MaLop[40];
	char MaSV[10];
    char HoTen[40];
    Date NS;
	float DiemTB;
	char GhiChu[25];
};

int haveYouAddorEditorDelete=2; // Binary lan FIRST

//Khai bao ham
void NhapFile();
void NhapSV(SinhVien &editItem,int choice);
void indanhsach();
void ThongKe(int dateThongKe);
void SapXep(int dataSort, int dataSortType);
void SwitchfocusSapXep();
void SwitchfocusTimKiem();
void SwitchfocusThongKe();
void SwitchEdittingField();
void SwitchfocusDelete();

int timcx(SinhVien x, char s[],int a);
int timMaLopcx(SinhVien x, char s[]);
int timMaSVcx(SinhVien x, char a[]);
int timHoTencx(SinhVien x, char s[]);
void XoaSinhVien(int dataDelete, int dataDeleteType);
//Ket thuc khai bao ham


// Khai bao thu vien ""
#include "sapxep.h"
#include "capnhat.h"
#include "timkiem.h"
#include "menu.h"
// Ket thuc khai bao thu vien ""

void DateToString(SinhVien &editItem,char s[], Date x){
	char temp1[2];
	char temp2[2];
	char temp3[4];
	// DAY --> S
	// Int --> char []
	sprintf(temp1,"%d",x.day); 
	// Them so 0. VD: NGay 7 --> Ngay 07
	if(strlen(temp1)<2) strcat(s,"0");   	
	strcat(s,temp1);strcat(s,"/");

	//MONTH --> S
	sprintf(temp2,"%d",x.month);
	if(strlen(temp2)<2) strcat(s,"0");
	strcat(s,temp2);strcat(s,"/");

	// YEAR --> S
	sprintf(temp3,"%d",x.year);
	for(int j=2;j<=4;j++)	if(strlen(temp3)<j) strcat(s,"0"); 
	strcat(s,temp3);
}

//ham nhap sinh  vien
void NhapSV(SinhVien &editItem,int choice)
{	
	KhoiTaoTextNhapSV();
	Hiencontro();
	MenuHuongDan();
	gotoxy(67,6);	printf(" NHAP THONG TIN SINH VIEN:");

	//Khai bao bien
	// Bien chua gia tri NSX nhap vao
	char stringDateNS[20]=""; 
	//Bien chua gia tri String cua DIEM TB nhap vao
	char stringInteger[17]; 
	SinhVien a;
	int escape=0;	
	int focusTemp=1;
	//Bien chua vi tri khi nhap text
	int position[12]={0};
	//Ket thuc khai bao bien

	FieldNhapSV();
	FieldNhapSVFocused(1,30);
	gotoxy(48,8);

	//XU ly Sua sinh vien
	// Can xu ly cac POSITION khi Editting
	if(choice!=(-24)){
		position[1]= (strlen(editItem.MaLop)); 
		position[2]=(strlen(editItem.MaSV));
		position[3]= (strlen(editItem.HoTen));
			DateToString(editItem,stringDateNS,editItem.NS);
		position[4]=10;
			sprintf(stringInteger,"%f",editItem.DiemTB);
		position[5]=(strlen(stringInteger));
		position[6]=(strlen(editItem.GhiChu));	
		//Hien thi Field Editting
		a=editItem;
		gotoxy(48,8);	printf("%s", a.MaLop); 
		gotoxy(48,12);	printf("%s", a.MaSV);
		gotoxy(48,16);	printf("%s", a.HoTen);
		gotoxy(48,20);	printf("%s", stringDateNS);
		gotoxy(48,24);	printf("%s", stringInteger);
		gotoxy(48,28);	printf("%s", a.GhiChu);
		
		gotoxy(48+position[1],8);
		// End of Hien thu Field Editting == End
	}//Ket thuc XU ly Sua sinh vien ====END
	
	int flag=0;
	while(1){
		int getkeyNhapSV=getch();
		switch(getkeyNhapSV)
		{
			case 224:
				getkeyNhapSV=getch();
				//Phim DOWN
				if(getkeyNhapSV==80){
					if(focusTemp==9){  
						break;
					}
					else{
						fflush(stdin);
						FieldNhapSVFocused(focusTemp,14);
						focusTemp++;
						FieldNhapSVFocused(focusTemp,30);
					}
				}

				//Phim UP
				if(getkeyNhapSV==72){
					if(focusTemp==1){  
						break;
					}
					else{
						fflush(stdin);
						FieldNhapSVFocused(focusTemp,14);
						focusTemp--;
						FieldNhapSVFocused(focusTemp,30);
					}
				}
				break;
			case 27:
				XoaManHinh();
				flag=1;
				return;
				break;
			case 13:
				if(focusTemp>=1 && focusTemp <=6){
					if(focusTemp==8){  
						break;
					}
					else{
						FieldNhapSVFocused(focusTemp,14);
						focusTemp++;
						FieldNhapSVFocused(focusTemp,30);
					}
				}

				if(focusTemp==7) {
				
					if(choice!=-24)
					{		
						DrawLine(28,43,"SUA SINH VIEN THANH CONG!",14); 
						haveYouAddorEditorDelete=1;
						SinhVien New[N];
						int n=0;
						taomang(New,&n);
						New[choice]=a;
						ghifile(New, n);
					}
					else
					{		
						DrawLine(28,43,"NHAP DU LIEU THANH CONG!!!!",14);
						haveYouAddorEditorDelete=1;
						FILE *f = fopen("danhsachSV.txt", "a+b");
						fwrite(&a, sizeof(SinhVien), 1, f);
						fclose(f);
					}
					_getch();
				}

				if(focusTemp==8) {
					XoaManHinh();
					DrawLine(27,6,"Da thoat Nhap du lieu",14);
					DrawLine(27,7,"Bam LEFT de tiep tuc su dung",14);
					return;
				}
				break;
		} // end switch(getkeyNhapSV)
		
		if(focusTemp==1) 	nhapMaLop(a,escape,position[1]);	if(escape==1) return;
		if(focusTemp==2)	nhapMaSV(a,escape,position[2]);	if(escape==1) return;
		if(focusTemp==3) 	nhapHoTen(a,escape,position[3]);	if(escape==1) return;
		if(focusTemp==4)	nhapNS(a,escape,position[4],stringDateNS);	if(escape==1) return;
		if(focusTemp==5)	nhapDiemTB(a,stringInteger,escape,position[5]);if(escape==1) return;
		if(focusTemp==6)	nhapAllElse(a,escape,position[6],28);if(escape==1) return;
		if(flag==1) break;
	} // end while(1)
} // end void NhapSV



// HAM SINH VIEN CHINH SUA ==============================
void EditSinhVien(int dataDeleteType){
	int escape=0;
	SinhVien a[N], b[N];
	int c[N], n = 0, p = 0, k;
	int *ptr=&c[0];
	taomang(a, &n);
	if (n == 0)
	{
		XoaManHinh();
		DrawLine(27,7,"DANH SACH KHONG CO SINH VIEN",14);	
	}
	else
	{	
		int getkeyDelete=getch();
		if(getkeyDelete==13){
			XoaManHinh();
			char s[40];
			DrawLine(26,7,"Nhap thong tin sinh vien:",14);
			Hiencontro();
			inputSE(s,escape); 
		 	if(escape==1) return;
			// Vong While bat dau xu ly sua sinh vien and MakeFieldChoice
		 	while(1){ 
				TK(b,ptr,p,dataDeleteType,s);
				if(p==0){
					XoaManHinh();
					DrawLine(27,7,"KHONG TIM THAY THONG TIN PHU HOP DE XOA",14);
					return;	
				}
				MenuHuongDan();
				k=MakeFieldChoice(0,p,b);
				// p dung de in danh sach da tim kiem
				p=0; 
				if (k == -24) break;
				else XoaManHinh();
				//Xu ly Sua sinh vien
				Hiencontro();
				fflush(stdin);
				VeKhungHinh(7);
				NhapSV(a[c[k]],c[k]);
				return;
				Ancontro();
				//Ket thuc xu ly Sua sinh vien
			} // end while(1)
		}
	}
} // end HAM SINH VIEN CHINH SUA

// HAM XOA SINH VIEN ======================================
void XoaSinhVien(int optionDelete, int dataDeleteType)
{	
	int escape=0;int choiceNow=0;int FIRST_TIME_DELETE=1;
	SinhVien a[N], b[N];
	int c[N], n = 0, p = 0, k;
	int *ptr=&c[0];
	taomang(a, &n);
	if (n == 0)
	{
		XoaManHinh();
		DrawLine(27,7,"DANH SACH KHONG CO SINH VIEN",14);	
	}
	else
	{	
		int getkeyDelete=getch();

		if(getkeyDelete==13) {
			switch(optionDelete) {
				case 1: 
					char s[40];
					XoaManHinh();
					DrawLine(26,7,"Nhap thong tin Sinh Vien:",14);
					Hiencontro();
					inputSE(s,escape); 
					if(escape==1) return;
					while(1){
						TK(b,ptr,p,dataDeleteType,s);
						if(p==0){
							XoaManHinh();
							DrawLine(27,7,"KHONG TIM THAY THONG TIN PHU HOP",14);
							return;	
						}
						// Chuyen choice ve vitri dau tien cua Page
						choiceNow=choiceNow-(choiceNow%10); 
						k=MakeFieldChoice111(choiceNow,p,b,FIRST_TIME_DELETE);
						FIRST_TIME_DELETE=0;
						p=0; 
						if (k == -24) break;
						for (int i = c[k]; i < n - 1; i++) a[i] = a[i + 1];
						// n dung de ghi all file
						n--; 
						ghifile(a, n);
						haveYouAddorEditorDelete=1;
					}
					break;
					// end case 1
				case 2:	
					ghifile(a, 0);
					XoaManHinh();
					DrawLine(27,7,"Ban da xoa tat ca du lieu",24);
					haveYouAddorEditorDelete=1;
					break;
			} //endl switch(optionDelete)
		} // end if (getkeyDelete == 13)
	} // end if else
}// end void XoaSinhVien


//ham nhap FILE
void NhapFile()
{
	SinhVien a;
	char s1[15],s2[15];
	FILE *f = fopen("danhsachSV.txt", "wb");
	FILE *g = fopen("Database.txt", "rt");
	while (feof(g) == 0)
	{
		fgets(a.MaLop, 40, g);
		if (feof(g) == 0)
		{
			chuanhoaMaLop(a.MaLop);
			
			fgets(a.MaSV, 10, g);
			chuanhoaMaSV(a.MaSV);

			fgets(a.HoTen, 40, g);
			chuanhoaHoTen(a.HoTen);
	
			fgets(s1, 15, g);	
			inputDate(a.NS, s1);

			fscanf(g, "%f\n", &a.DiemTB);
			
			fgets(a.GhiChu, 20, g);	
			chuanhoaAll(a.GhiChu);
			
			fwrite(&a, sizeof(SinhVien), 1, f);
			haveYouAddorEditorDelete=1;
		}
		else break;
	}
	_fcloseall();
}// end ham nhap FILE

void indanhsach()
{	
	textcolor(7);
	SinhVien a[N];
	int n = 0;
	taomang(a, &n);
	if (n == 0)
	{
		DrawLine(26,6,"KHONG CO SINH VIEN TRONG DANH SACH",207);
	}
	else
	{
		VeKhungHinh(8);
		xuatmangPage(a, n,1);
	}
}

// MAIN CHINH SUA SINH VIEN
void SwitchEdittingField(){
	switch (focusSortField)
	{
		case 1: EditSinhVien(1);break;
		case 2: EditSinhVien(2);break;
		case 3: EditSinhVien(3);break;
		case 4: EditSinhVien(4);break;
		case 5: EditSinhVien(5);break;
		case 6: EditSinhVien(6);break;
	}
}


//MAIN XOA SINH VIEN
void SwitchDeleteField(int SortType){
	switch (focusSortField)
	{
		case 1: XoaSinhVien(SortType,1);break;
		case 2: XoaSinhVien(SortType,2);break;
		case 3: XoaSinhVien(SortType,3);break;
		case 4: XoaSinhVien(SortType,4);break;
		case 5: XoaSinhVien(SortType,5);break;
		case 6: XoaSinhVien(SortType,6);break;
	}
}

//DIEU KHIEN MAI XOA SINH VIEN
void SwitchfocusDelete(){
	switch (focusDelete)
	{
		case 1: SwitchDeleteField(1); break;
		case 2: SwitchDeleteField(2);break;
	}
}

//ham sap xep SINH VIEN
void SapXep(int dataSort,int dataSortType)
{
	SinhVien a[N];
	int n = 0;
	taomang(a, &n);
	if (n == 0)
	{
		XoaManHinh();
		DrawLine(26,7,"DANH SACH KHONG CO SINH VIEN",207);
		getch();
	}
	else
	{	int getkeydataSort=getch();
		if(getkeydataSort==13)
		{
			if(dataSort==1) seclection_sort(a, n, dataSortType);
			if(dataSort==2) insertion_sort(a, n, dataSortType); 
			if(dataSort==3) bubble_sort(a, n, dataSortType); 
			if(dataSort==4) quick_sort(a, 0, n - 1, dataSortType); 
			VeKhungHinh(9);	
			xuatmangPage(a, n,2);
		}
	}
}


//Ham SAP XEP
void SwitchSortField(int SortType){
	switch (focusSortField)
	{
		case 1: SapXep(SortType,1);break;
		case 2: SapXep(SortType,2);break;
		case 3: SapXep(SortType,3);break;
		case 4: SapXep(SortType,4);break;
		case 5: SapXep(SortType,5);break;
		case 6: SapXep(SortType,6);break;
	}
}
//MAIN SAP XEP
void SwitchfocusSapXep(){
	switch (focusSapXep)
	{
		case 1: SwitchSortField(1);break;
		case 2: SwitchSortField(2);break;
		case 3: SwitchSortField(3);break;
		case 4: SwitchSortField(4);break;
	}
}

//HAM TIM KIEM =============================================================
void TimKiem(int dataSearch, int dataSearchType)
{
	SinhVien a[N];
	int n = 0, dem = 0;
		
	int getkeydataSort=getch();
	if(getkeydataSort==13){
		if(dataSearch==1)  timkiemtuantu(a, n,dataSearchType);
		
		if(dataSearch==2) {
			int k=0;
			taomang(a, &k);
			if(haveYouAddorEditorDelete==1 || haveYouAddorEditorDelete==2)
			{
				for (int j=1;j<=6;j++)
				insertion_sortBinaryTree(a,k,j);
				haveYouAddorEditorDelete=0;
			}
			timkiemnhiphan(a, n,dataSearchType);
		}
	}
}

void SwitchSearchField(int SearchType){
	switch (focusSortField)
	{
		case 1: TimKiem(SearchType,1);break;
		case 2: TimKiem(SearchType,2);break;
		case 3: TimKiem(SearchType,3);break;
		case 4: TimKiem(SearchType,4);break;
		case 5: TimKiem(SearchType,5);break;
		case 6: TimKiem(SearchType,6);break;
	}
}
// MAIN TIM KIEM
void SwitchfocusTimKiem(){
	switch (focusTimKiem)
	{
		case 1: SwitchSearchField(1); break;
		case 2: SwitchSearchField(2);break;
	}
}


// THONG KE ===============================THONG KE=======================================THONG KE
void ThongKe(int dataThongKe){
	SinhVien a[N];
	int n=0; 
	int k=0;
	taomang(a, &n);

	char something[20];
	int dem=1; int x; float y, yMAX;
	int ThongKeRow=11; int TYPE; int MAX=-1; int MAXIMUM=1;
	int demXS=0; int demG=0; int demK=0; int demTB=0; int demY=0;
	int xbieudo, ybieudo;
	int vebieudo, vesolieu;
	if (dataThongKe==1) 
	{
		if (n == 0)
		{
			XoaManHinh();
			DrawLine(26,7,"Khong co sinh vien trong danh sach",14);
		}
		
		else{
			gotoxy(26,7);	printf("______________________________________________________________________________________________________");	
			gotoxy(26,8);	printf("\xb3                    \xb3              \xb3            \xb3            \xb3            \xb3            \xb3            \xb3");
			gotoxy(26,9);	printf("\xb3       MA LOP       \xb3 SO SINH VIEN \xb3  XUAT SAC  \xb3    GIOI    \xb3    KHA     \xb3 TRUNG BINH \xb3    YEU     \xb3");
			gotoxy(26,10);	printf("\xb3____________________\xb3______________\xb3____________\xb3____________\xb3____________\xb3____________\xb3____________\xb3");
			textcolor(14);

			// ve các trục của đồ thị
			xbieudo=135;
			ybieudo=55;
			gotoxy(xbieudo-2, ybieudo); printf("0");
			gotoxy(xbieudo-2, ybieudo-5); printf("10 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-10); printf("20 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-15); printf("30 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-20); printf("40 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-25); printf("50 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-30); printf("60 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-35); printf("70 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-40); printf("80 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-45); printf("90 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-5, ybieudo-49); printf("100%c  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _", 37);
			gotoxy(xbieudo+10, ybieudo+8); textcolor(78); printf("   ");
			gotoxy(xbieudo+10, ybieudo+11);textcolor(56); printf("   ");
			textcolor(14);
			gotoxy(xbieudo+15, ybieudo+5); printf("BIEU DO PHAN LOAI HOC SINH KHA GIOI XUAT SAC");
			gotoxy(xbieudo+15, ybieudo+8); printf("Hoc Sinh Kha, Gioi, Xuat Sac");
			gotoxy(xbieudo+15, ybieudo+11); printf("Hoc Sinh Con Lai");
			//truc Oy
			for(int i=ybieudo-1; i>5; i--) 
			{
				gotoxy(xbieudo, i);
				printf("%c", 179);
			} 
			gotoxy(xbieudo, 5); printf("%c",30);
			//truc Ox
			gotoxy(xbieudo+1, ybieudo); printf("_________________________________________________________________________%c", 16);
			gotoxy(xbieudo, ybieudo); printf("%c", 192);

			quick_sort(a, 0, n - 1, 1); //SAP XEP MA LOP
			strcpy(something,a[0].MaLop);

			if(a[0].DiemTB > 9) {
				demXS++;
			}
			else if(a[0].DiemTB > 8) {
				demG++;
			}
			else if(a[0].DiemTB > 7) {
				demK++;
			}
			else if (a[0].DiemTB > 5) {
				demTB++;
			}
			else demY++;


			// Thong ke SINH VIEN====================
			for(int i=1;i<n;i++){
			
				if(strcmp(a[i].MaLop, something)== 0)
				{
					dem++;
					if(a[i].DiemTB >= 9) {
						demXS++;
					}
					else if(a[i].DiemTB >= 8) {
						demG++;
					}
					else if(a[i].DiemTB >= 7) {
						demK++;
					}
					else if (a[i].DiemTB >= 5) {
						demTB++;
					}
					else demY++;
				}
				else 
				{	
					x = (100*demXS+100*demG+100*demK)/dem;
					if(x > MAX){
						MAX=x;
						TYPE=i;
					}
					rutgonText(something,20);
					gotoxy(26,ThongKeRow++);	printf("\xb3                    \xb3              \xb3            \xb3            \xb3            \xb3            \xb3            \xb3");
					gotoxy(26,ThongKeRow++);	printf("\xb3 %-18s \xb3 %-12d \xb3 %-10d \xb3 %-10d \xb3 %-10d \xb3 %-10d \xb3 %-10d \xb3",something,dem, demXS, demG, demK, demTB, demY);
					gotoxy(26,ThongKeRow++);	printf("\xb3____________________\xb3______________\xb3____________\xb3____________\xb3____________\xb3____________\xb3____________\xb3");
					// vẽ các cột biểu đồ
					xbieudo+=10; vebieudo=x/2;
					gotoxy(xbieudo, ybieudo+2); printf("%s", something);
					for(int i=ybieudo-vebieudo-1; i<=ybieudo; i++) 
					{
						textcolor(78);
						gotoxy(xbieudo, i); printf("   ");
						textcolor(14);
					}
					for(int i=7; i<=ybieudo-vebieudo; i++) 
					{
						textcolor(56);
						gotoxy(xbieudo, i); printf("   ");
						textcolor(14);
					}
					strcpy(something,a[i].MaLop);
					dem=1;
					demXS=0; demG=0; demK=0; demTB=0; demY=0;
					if(a[i].DiemTB >= 9) {
						demXS++;
					}
					else if(a[i].DiemTB >= 8) {
						demG++;
					}
					else if(a[i].DiemTB >= 7) {
						demK++;
					}
					else if (a[i].DiemTB >= 5) {
						demTB++;
					}
					else demY++;
				}
			}
			rutgonText(something,20);
			gotoxy(26,ThongKeRow++);	printf("\xb3                    \xb3              \xb3            \xb3            \xb3            \xb3            \xb3            \xb3");
			gotoxy(26,ThongKeRow++);	printf("\xb3 %-18s \xb3 %-12d \xb3 %-10d \xb3 %-10d \xb3 %-10d \xb3 %-10d \xb3 %-10d \xb3",something,dem, demXS, demG, demK, demTB, demY);
			gotoxy(26,ThongKeRow++);	printf("\xb3____________________\xb3______________\xb3____________\xb3____________\xb3____________\xb3____________\xb3____________\xb3");
			gotoxy(26,ThongKeRow++);	printf("\xb3                                                                                                    \xb3");
			gotoxy(26,ThongKeRow++);	printf("\xb3LOP CO SO LUONG KHA, GIOI, XUAT SAC NHIEU NHAT LA LOP %-7s VOI TI LE %-3d%c                        \xb3",a[TYPE-1].MaLop,MAX, 37);
			gotoxy(26,ThongKeRow++);	printf("\xb3____________________________________________________________________________________________________\xb3");
			// vẽ cột biểu đồ cuối
			xbieudo+=10; vebieudo=(100*demXS+100*demG+100*demK)/(dem*2);
			gotoxy(xbieudo, ybieudo+2); printf("%s", something);
			for(int i=ybieudo-vebieudo-1; i<=ybieudo; i++) 
			{
				textcolor(78);
				gotoxy(xbieudo, i); printf("   ");
				textcolor(14);
			}
			for(int i=7; i<=ybieudo-vebieudo; i++) 
			{
				textcolor(56);
				gotoxy(xbieudo, i); printf("   ");
				textcolor(14);
			}
		}
	}

	if(dataThongKe==2)
	{
		if (n == 0)
		{
			XoaManHinh();
			DrawLine(26,7,"Khong co sinh vien trong danh sach",14);
		}
		
		else{
			gotoxy(26,7);	printf("______________________________________________________________________");	
			gotoxy(26,8);	printf("\xb3                           \xb3                    \xb3                   \xb3");
			gotoxy(26,9);	printf("\xb3          MA LOP           \xb3    SO SINH VIEN    \xb3       TI LE       \xb3");
			gotoxy(26,10);	printf("\xb3___________________________\xb3____________________\xb3___________________\xb3");
		
			xbieudo=100;
			ybieudo=55;
			gotoxy(xbieudo-2, ybieudo); printf("0");
			gotoxy(xbieudo-2, ybieudo-5); printf("10 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-10); printf("20 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-15); printf("30 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-20); printf("40 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-25); printf("50 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-30); printf("60 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-35); printf("70 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-40); printf("80 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-2, ybieudo-45); printf("90 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
			gotoxy(xbieudo-5, ybieudo-49); printf("100%c  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _", 37);
			gotoxy(xbieudo+15, ybieudo+5); printf("BIEU DO PHAN TRAM HOC SINH CUA CAC LOP");

			//truc Oy
			gotoxy(xbieudo, ybieudo); printf("%c", 192);
			for(int i=ybieudo-1; i>5; i--) 
			{
				gotoxy(xbieudo, i);
				printf("%c", 179);
			} 
			gotoxy(xbieudo, 5); printf("%c",30);

			//truc Ox
			gotoxy(xbieudo+1, ybieudo); printf("___________________________________________________________________________________%c", 16);

			quick_sort(a, 0, n - 1, 1); //SAP XEP MA LOP
			strcpy(something,a[0].MaLop);

			// Thong ke SINH VIEN====================
			for(int i=1;i<n;i++){
			
				if(strcmp(a[i].MaLop, something)== 0)
				{
					dem++;
				}
				else 
				{	
					y=100*dem;
					if(MAXIMUM<dem){
						yMAX=100*dem;
						MAXIMUM=dem;
						TYPE=i;
					}
					rutgonText(something,20);
					gotoxy(26,ThongKeRow++);	printf("\xb3                           \xb3                    \xb3                   \xb3");
					gotoxy(26,ThongKeRow++);	printf("\xb3  %-23s  \xb3         %-10d \xb3      %.2f%c       \xb3",something,dem,y/n,37);
					gotoxy(26,ThongKeRow++);	printf("\xb3___________________________\xb3____________________\xb3___________________\xb3");
					// vẽ các cột biểu đồ
					xbieudo+=10; vebieudo=y/(2*n);
					gotoxy(xbieudo, ybieudo+2); printf("%s", something);
					for(int i=ybieudo-vebieudo+1; i<=ybieudo; i++) 
					{
						textcolor(78);
						gotoxy(xbieudo, i); printf("   ");
						textcolor(14);
					}
					
					strcpy(something,a[i].MaLop);
					dem=1;
				}
			}
			rutgonText(something,20);
			gotoxy(26,ThongKeRow++);	printf("\xb3                           \xb3                    \xb3                   \xb3");
			gotoxy(26,ThongKeRow++);	printf("\xb3  %-23s  \xb3         %-10d \xb3      %.2f%c       \xb3",something,dem,y/n,37);
			gotoxy(26,ThongKeRow++);	printf("\xb3___________________________\xb3____________________\xb3___________________\xb3");
			gotoxy(26,ThongKeRow++);	printf("\xb3                           \xb3                    \xb3                   \xb3");
			gotoxy(26,ThongKeRow++);	printf("\xb3           TONG            \xb3         %-10d \xb3       %d%c        \xb3",n,100,37);
			gotoxy(26,ThongKeRow++);	printf("\xb3___________________________\xb3____________________\xb3___________________\xb3");
			gotoxy(26,ThongKeRow++);	printf("\xb3                                                                    \xb3");
			gotoxy(26,ThongKeRow++);	printf("\xb3LOP CO SO LUONG SINH VIEN NHIEU NHAT LA LOP %-7sVOI TI LE %.2f%c \xb3",a[TYPE-1].MaLop,yMAX/n, 37);
			gotoxy(26,ThongKeRow++);	printf("\xb3____________________________________________________________________\xb3");
			// vẽ cột biểu đồ cuối cùng
			xbieudo+=10; vebieudo=y/(2*n);
			gotoxy(xbieudo, ybieudo+2); printf("%s", something);
			for(int i=ybieudo-vebieudo+1; i<=ybieudo; i++) 
			{
				textcolor(78);
				gotoxy(xbieudo, i); printf("   ");
				textcolor(14);
			}
		}
	}
}