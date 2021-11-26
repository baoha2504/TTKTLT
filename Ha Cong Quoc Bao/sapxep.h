#include <string.h>

int row=11;
void NewLineOutput2() {
    gotoxy(26, row++);
}

void rutgonText(char s[], int len) {
    if(strlen(s) > len) {
        s[len]=NULL;
        s[len-1]=' ';
		s[len-2]=' ';
    }
}

void output2(SinhVien b)
{	
    SinhVien a; a=b;
	rutgonText(a.MaLop,20);
	rutgonText(a.MaSV,10);
	rutgonText(a.HoTen,25);
	rutgonText(a.GhiChu,15);
	
	char Scores[20];
	sprintf(Scores,"%f",a.DiemTB);
	rutgonText(Scores,5);
	
	
	NewLineOutput2();
 	printf("\xb3                    \xb3               \xb3                         \xb3           \xb3        \xb3               \xb3\n");
	
	NewLineOutput2();	
	printf("\xb3%-20s\xb3%-15s\xb3%-25s\xb3%.2d-%.2d-%.4d \xb3%-8s\xb3%-15s\xb3\n", a.MaLop, a.MaSV, a.HoTen, (a.NS).day, (a.NS).month,(a.NS).year,Scores ,a.GhiChu );

	NewLineOutput2();
	printf("\xb3____________________\xb3_______________\xb3_________________________\xb3___________\xb3________\xb3_______________\xb3\n");
}

void output3()
{	row=11; 
	gotoxy(26,7);	printf("____________________________________________________________________________________________________");	
	gotoxy(26,8);	printf("\xb3                    \xb3               \xb3                         \xb3           \xb3        \xb3               \xb3");
 	gotoxy(26,9);	printf("\xb3       MA LOP       \xb3 MA SINH VIEN  \xb3          HO TEN         \xb3 NGAY SINH \xb3  DIEM  \xb3    GHI CHU    \xb3");
    gotoxy(26,10);	printf("\xb3____________________\xb3_______________\xb3_________________________\xb3___________\xb3________\xb3_______________\xb3");
}

void taomang(SinhVien a[], int *n)
{
	*n = 0;
	SinhVien b;
	FILE *g = fopen("danhsachSV.txt", "rb");
	while (feof(g) == 0)
	{
		fread(&b, sizeof(SinhVien), 1, g); 
		if (feof(g) == 0)
		{
			a[*n] = b;
			(*n)++;
		}
	}
}

void xuatmang(SinhVien a[], int n,int MenuType)
{	
    int dem=0;
	XoaManHinh();
    // MenuType In danh sach
	if(MenuType==1){ 
		DrawLine(70,5," DANH SACH TAT CA SINH VIEN",78);
	}
    // MenuType In danh sach
	if(MenuType==2){ 
		DrawLine(70,5,"DANH SACH SINH VIEN SAP XEP",78);
	}
	output3();
	
	for (int i = 0; i < n; i++)
	{
		output2(a[i]);
	}
	getch();
}


// Xuat mang theo Page Numberize(so trang)
void xuatmangPage(SinhVien a[], int n,int MenuType)
{	
    int flag=0; 
    int numberPage=1;
	XoaManHinh();

    // MenuType In danh sach
	if(MenuType==1){ 
		DrawLine(70,6," DANH SACH TAT CA SINH VIEN",78);
	}

    // MenuType In danh sach
	if(MenuType==2){ 
		DrawLine(70,6,"DANH SACH SINH VIEN SAP XEP",78);
	}
	
	int page =0;
	int PagePrint=page+10;

	if(PagePrint>n) PagePrint=n;
	output3();
	
	for (int i = page; i < PagePrint; i++)
	{
		output2(a[i]);
	}
	toadoXNextPage=70;
	int numberAllPage=n/10 +1;
	if(n%10==0) numberAllPage--;
	gotoxy(27,42); printf("Page %d/%d",numberPage,numberAllPage);

	for(int i=1;i<=3;i++) { 
        DrawLine(toadoXNextPage,42,textNextPage[i],14) ;
        toadoXNextPage+=15 ; 
    }
	DrawLine(70,42,textNextPage[1],30);
    toadoXNextPage=70;

	while(1){
		int getkeyNextPage=getch();
        switch(getkeyNextPage)
        {
            case 224: 
                getkeyNextPage=getch();
                //LEFT
                if(getkeyNextPage==75) 
                {
                    if(focusNextPage==1) {
                        toadoXNextPage=70; 
                        break;
                    }
                    else
                    {
                        DrawLine(toadoXNextPage,42,textNextPage[focusNextPage],14) ;
                        focusNextPage-=1; toadoXNextPage-=15;
                        DrawLine(toadoXNextPage,42,textNextPage[focusNextPage],30) ;
                    }
                }
                //RIGHT
                if(getkeyNextPage==77) 
                {
                    if(focusNextPage==3) {
                        toadoXNextPage=70+15+15; 
                        break;
                    }
                    else
                    {
                        DrawLine(toadoXNextPage,42,textNextPage[focusNextPage],14) ;
                        focusNextPage+=1; toadoXNextPage+=15;
                        DrawLine(toadoXNextPage,42,textNextPage[focusNextPage],30) ;
                    }
                }
                break;
            // phim Enter
            case 13:
                if(focusNextPage==1)
                {
                    if(page==0) break;
                    else{XoaManHinh2(41);
                        page-=10;
                        PagePrint=page+10;
                    }
                }
                if(focusNextPage==2)
                {
                    if(PagePrint==n) {
                        break;
                    }
                    else{
                        XoaManHinh2(41);
                        page+=10;
                        if((page+10)>n)	PagePrint=n;
                        else PagePrint=page+10;
                    }
                }	
                if(focusNextPage==3) 
                { 
                    flag=1;
                    focusNextPage=1;			
                    break;
                }
                break;
        } // end switch(getkeyNextPage)
        output3();
        numberPage=(page/10)+1;
        numberAllPage=n/10 +1;
        if(n%10==0) numberAllPage--;
        gotoxy(27,42); printf("Page %d/%d  ",numberPage,numberAllPage);

        for (int i = page; i < PagePrint; i++)
        {
            output2(a[i]);
        }

        if(flag==1) {
            XoaManHinh();
            return;
        }
    }// end while(1)
}

// Cac ham so sanh 
//So sanh MA LOP
int ssMaLop(SinhVien a, SinhVien b)
{
	char s1[40], s2[40];
	strcpy(s1, a.MaLop);
	strcpy(s2, b.MaLop);
	if (strcmp(s1, s2) > 0) return 1;
	else if (strcmp(s1, s2) < 0) return -1;
	return 0;
}

//So sanh MA SINH VIEN
int ssMaSV(SinhVien a, SinhVien b)
{
	char s1[10], s2[10];
	strcpy(s1, a.MaSV);
	strcpy(s2, b.MaSV);
	if (strcmp(s1, s2) > 0) return 1;
	else if (strcmp(s1, s2) < 0) return -1;
	return 0;
}

//So sanh TEN SINH VIEN
int ssHoTen(SinhVien a, SinhVien b)
{
	char s1[40], s2[40];
	strcpy(s1, a.HoTen);
	strcpy(s2, b.HoTen);
	if (strcmp(s1, s2) > 0) return 1;
	else if (strcmp(s1, s2) < 0) return -1;
	return 0;
}

//So sanh NGAY SINH
int ssNS(SinhVien x, SinhVien y)
{
	Date a = x.NS;
	Date b = y.NS;
	if (a.year > b.year) return 1;
	else if (a.year < b.year) return -1;
	else
	{
		if (a.month > b.month) return 1;
		else if (a.month < b.month) return -1;
		else
		{
			if (a.day > b.day) return 1;
			else if (a.day < b.day) return -1;
			else return 0;
		}
	}
}
//So sanh DIEM TRUNG BINH
int ssDiemTB(SinhVien a, SinhVien b)
{
	float i = a.DiemTB;
	float j = b.DiemTB;
	if (i > j) return 1;
	else if (i < j) return -1;
	else return 0;
}

//So sanh GHI CHU
int ssAllElse(SinhVien a, SinhVien b,int type)
{	
    char s1[20], s2[20];
	if(type == 6) {	
        strcpy(s1, a.GhiChu);	
        strcpy(s2, b.GhiChu); 
    }
	
	if (strcmp(s1, s2) > 0) return 1;
	else if (strcmp(s1, s2) < 0) return -1;
	return 0;
}

//main SO SANH
int ss(SinhVien a, SinhVien b, int p)
{
	switch (p)
	{	
	case 1: return ssMaLop(a, b); break;
	case 2: return ssMaSV(a, b); break;
	case 3: return ssHoTen(a, b); break;
	case 4: return ssNS(a, b); break;
    case 5: return ssDiemTB(a, b); break;
	case 6: return ssAllElse(a,b,6); break;
	
	default: break;
	}
}

// Nhap du lieu file de tim kie nhi phan Binary Tree
//Nhap MA LOP nhi phan
void NhapFileMaLop(SinhVien a[],int n)
{
	FILE *f = fopen("data/dsMaLop.txt", "wb");
	for(int i=0;i<n;i++)	fwrite((&a[i]), sizeof(SinhVien), 1, f);
	fclose(f);
}

//Nhap file nhi phan MA SINH VIEN
void NhapFileMaSV(SinhVien a[],int n)
{
	FILE *f = fopen("data/dsMaSV.txt", "wb");
	for(int i=0;i<n;i++)	fwrite((&a[i]), sizeof(SinhVien), 1, f);
	fclose(f);
}

//Nhap file nhi phan HO TEN
void NhapFileHoTen(SinhVien a[],int n)
{
	FILE *f = fopen("data/dsHoTen.txt", "wb");
	for(int i=0;i<n;i++)	fwrite((&a[i]), sizeof(SinhVien), 1, f);
	fclose(f);
}

//Nhap file nhi phan NGAY SINH
void NhapFileNS(SinhVien a[],int n)
{	
	FILE *f = fopen("data/dsNS.txt", "wb");
	for(int i=0;i<n;i++)	fwrite((&a[i]), sizeof(SinhVien), 1, f);
	fclose(f);
}

//Nhap file nhi phan DIEM TRUNG BINH
void NhapFileDiemTB(SinhVien a[],int n)
{
	FILE *f = fopen("data/dsDiemTB.txt", "wb");
	for(int i=0;i<n;i++)	fwrite((&a[i]), sizeof(SinhVien), 1, f);
	fclose(f);
}

//Nhap file nhi phan GHI CHU
void NhapFileGhiChu(SinhVien a[],int n)
{
	FILE *f = fopen("data/dsGhiChu.txt", "wb");
	for(int i=0;i<n;i++)	fwrite((&a[i]), sizeof(SinhVien), 1, f);
	fclose(f);
}

void NhapFileBinaryTree(SinhVien a[],int n, int p){
	if(p==1)	NhapFileMaLop(a,n);	
	if(p==2)	NhapFileMaSV(a,n);	
	if(p==3)	NhapFileHoTen(a,n);
	if(p==4)	NhapFileNS(a,n);
	if(p==5)	NhapFileDiemTB(a,n);	
	if(p==6)	NhapFileGhiChu(a,n);	
}

void insertion_sortBinaryTree(SinhVien a[], int n, int p)
{
	for (int i = 1; i<n; i++)
	{
		SinhVien temp = a[i];
		int j = i - 1;
		while (j >= 0 && ss(temp, a[j], p) < 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
    NhapFileBinaryTree(a,n, p);
}

//Cac ham sap xep ==== Selection_Sort - Inserttion_Sort - Bubble_Sort -  Quick_Sort=====
void seclection_sort(SinhVien a[], int n,int p)
{
	for (int i = 0; i<n; i++)
	{
		int k = i;
		for (int j = i + 1; j<n; j++)
		if (ss(a[j], a[k], p) == -1)   k = j;
		if (k != i)
		{
			SinhVien temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
		
	}

}

void insertion_sort(SinhVien a[], int n, int p)
{
	for (int i = 1; i<n; i++)
	{
		SinhVien temp = a[i];
		int j = i - 1;
		while (j >= 0 && ss(temp, a[j], p) < 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

void bubble_sort(SinhVien a[], int n, int p)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		if (ss(a[j], a[j - 1], p) < 0)
		{
			SinhVien temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
		}
	}
}

int quick_sort(SinhVien a[], int l, int r, int p)
{
	if (l >= r) return 1;
	SinhVien key = a[(l + r) / 2];
	int i = l;
	int j = r;
	do
	{
		while (ss(a[i], key, p) < 0) i++;
		while (ss(a[j], key, p) > 0) j--;
		if (i <= j)
		{
			SinhVien temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	quick_sort(a, l, j, p);
	quick_sort(a, i, r, p);
}