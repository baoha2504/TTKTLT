int focus[10]={1,1,1,1,1,1,1,1,1,1};
int toadoY[10]={1,1,1,1,1,1,1,1,1};
#define focusMenu focus[0] 
#define focusTrangChu focus[1] 
#define focusCapNhat focus[2] 
#define focusInList focus[3] 
#define focusSapXep focus[4] 	
#define focusTimKiem focus[5] 
#define focusThongKe focus[6] 
#define focusSortField focus[7] 
#define focusDelete focus[8]

#define toadoYMenu toadoY[0] 
#define toadoYTrangChu toadoY[1] 
#define toadoYCapNhat toadoY[2] 
#define toadoYInList toadoY[3] 
#define toadoYSapXep toadoY[4] 
#define toadoYTimKiem toadoY[5] 
#define toadoYThongKe toadoY[6] 
#define toadoYSortField toadoY[7] 
#define toadoYDelete toadoY[8] 

int toadoXNextPage,focusNextPage;
void Khoitaobien()
{
	focusCapNhat=1;	toadoYCapNhat=8;
	focusSapXep=1;	toadoYSapXep=12;
	focusSortField=1;	toadoYSortField=8;
	focusTimKiem=1;	toadoYTimKiem=14;
	focusThongKe=1;	toadoYThongKe=16;
	focusDelete=1;	toadoYDelete=8;
	focusNextPage=1;toadoXNextPage=40;
}

//Khai bao text
string textMenu[10];
string textMenuCapNhat[5];
string textMenuInList[3];
string textMenuSapXep[5];
string textMenuSortField[10];
string textMenuTimKiem[4];
string textMenuThongKe[6];
string textMenuDelete[3];
string textNextPage[7];

void CreateTextMenu(){
	textMenu[1]= " TRANG CHU     ";
	textMenu[2]= " CAP NHAT      "; 
	textMenu[3]= " IN DANH SACH  ";
	textMenu[4]= " SAP XEP       ";
	textMenu[5]= " TIM KIEM      ";
	textMenu[6]= " THONG KE      ";
	textMenu[7]= " THOAT         ";

	textMenuCapNhat[1]="Them moi sinh vien";
	textMenuCapNhat[2]="Sua sinh vien     ";
	textMenuCapNhat[3]="Xoa sinh vien     ";
	textMenuCapNhat[4]="Nhap tu File      ";
	
	textMenuDelete[1]="Xoa 1 sinh vien     ";
	textMenuDelete[2]="Xoa tat ca sinh vien";
	
	textMenuInList[1]="In tat ca sinh vien  ";
	
	textMenuSapXep[1]="Sap xep chon      ";
	textMenuSapXep[2]="Sap xep chen      ";
	textMenuSapXep[3]="Sap xep noi bot   ";
	textMenuSapXep[4]="Sap xep nhanh     ";

	
	textMenuSortField[1]="1. Ten Lop";
	textMenuSortField[2]="2. Ma SV";
	textMenuSortField[3]="3. Ho Ten";
	textMenuSortField[4]="4. Ngay Sinh";
	textMenuSortField[5]="5. Diem TB ";
	textMenuSortField[6]="6. Ghi chu";

	
	textMenuTimKiem[1]="Tim kiem tuan tu       ";
	textMenuTimKiem[2]="Tim kiem nhi phan      ";
	
	textMenuThongKe[1]="Phan loai ket qua    ";
	textMenuThongKe[2]="Bao cao so luong     ";

	
	textNextPage[1]="Trang truoc";
	textNextPage[2]="Trang sau";
	textNextPage[3]="Thoat";
	textNextPage[4]="LEFT";
	textNextPage[5]="RIGHT";
	textNextPage[6]="BACKSPACE(THOAT)";
}

string textNhapSV[12];
void KhoiTaoTextNhapSV(){
	textNhapSV[1]="Nhap ma lop:";
	textNhapSV[2]="Nhap ma sv:";
	textNhapSV[3]="Nhap ten:";
	textNhapSV[4]="Nhap ngay sinh:";
	textNhapSV[5]="Nhap diem TB:";
	textNhapSV[6]="Nhap ghi chu:";
	textNhapSV[7]="Them";
	textNhapSV[8]="Thoat";
}