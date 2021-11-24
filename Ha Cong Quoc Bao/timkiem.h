#include <string.h>

typedef struct SinhVien2
{
	char MaLop[40];
	char MaSV[10];
    char HoTen[40];
    char NS[20];
	char DiemTB[10];
	char GhiChu[25];
};

//tao mang bang cach nhap tu file trong folder data
void taomang2(SinhVien a[], int *n, int b)
{
	FILE *f;
	switch (b)
	{
        case 1: f = fopen("data/dsMaLop.txt", "rb"); break;
        case 2: f = fopen("data/dsMaSV.txt", "rb"); break;
        case 3: f = fopen("data/dsHoTen.txt", "rb"); break;
        case 4: f = fopen("data/dsNS.txt", "rb"); break;
        case 5: f = fopen("data/dsDiemTB.txt", "rb"); break;
        case 6: f = fopen("data/dsGhiChu.txt", "rb"); break;
	    default: return;
	}
	*n = 0;
	SinhVien sv;
	while (feof(f) == 0)
	{
		fread(&sv, sizeof(SinhVien), 1, f);
		if (feof(f) == 0)
		{
			a[*n] = sv;
			(*n)++;
		}
	}
	fclose(f);
}

// Chuyen so sang chuoi
void chuyenngay(Date a, char s[])
{
	char s1[10], s2[10], s3[10];
	_itoa(a.day, s1, 10); 
	_itoa(a.month, s2, 10);
	_itoa(a.year, s3, 10);
	s[0] = 0;
	strcat(s, s1);
	strcat(s, "/");
	strcat(s, s2);
	strcat(s, "/");
	strcat(s, s3);
	strcat(s, "\0");
}

// Ham chuyen all SinhVien --> all char trong SinhVien2 struct
void chuyen(SinhVien a[], SinhVien2 b[], int n)
{
	for (int i = 0; i < n; i++)
	{
        strcpy(b[i].MaLop, a[i].MaLop);
		strcpy(b[i].MaSV, a[i].MaSV);
        strcpy(b[i].HoTen, a[i].HoTen);
        chuyenngay(a[i].NS, b[i].NS);
		snprintf(b[i].DiemTB, 20, "%f", a[i].DiemTB);
		strcpy(b[i].GhiChu, a[i].GhiChu);
	}
}

int tim1(SinhVien2 a, char s[], int k)
{
	switch (k)
	{
	case 1:	
		chuanhoaMaLop(s);
		if (strstr(a.MaLop, s) != NULL) return 1;
		else return 0;
	case 2: chuanhoaMaSV(s);
		if (strstr(a.MaSV, s) != NULL)  return 1;
		else return 0;
    case 3:
        chuanhoaHoTen(s);
		if (strstr(a.HoTen, s) != NULL) return 1;
		else return 0;
    case 4:	if (strstr(a.NS, s) != NULL) return 1;
			else return 0;    
	case 5:	if (strstr(a.DiemTB, s) != NULL) return 1; 
			else return 0;
	case 6: chuanhoaAll(s);
		if (strstr(a.GhiChu, s) != NULL)  return 1;
		else return 0;	
		
	default: return 0;
	}
	return 0;
}


//bat dau TIM KIEM TUAN TU
void timtuantu(SinhVien b[], SinhVien2 a[], int n, char s[], int k, int &p)
{	int dem=0;
	SinhVien c[N];
    int c_point=0;
	for (int i = 0; i<n; i++)
	{
		if (tim1(a[i], s, k) == 1)
		{
            if(p==0)	p++;
            if (p == 1)
            {
                output3();
            }
            c[c_point]=b[i];
            c_point++;
		}
	}
	quick_sort(c, 0,c_point, k);

	// Xu ly TIMKIEM IN RA
	int flag=0;
	if(p>0)
	{
		int page =0;
        int PagePrint=page+10;
        if(PagePrint>c_point) PagePrint=c_point;
        int numberPage=1;
		int numberAllPage=c_point/10 +1;
        if(c_point%10==0) numberAllPage--;

        gotoxy(27,42); printf("Page %d/%d   ",numberPage,numberAllPage);
		output3();
	
        for (int i = page; i < PagePrint; i++)
        {
            output2(c[i]);
        }
	    toadoXNextPage=70;
	    for(int i=1;i<=3;i++) { 
            DrawLine(toadoXNextPage,42,textNextPage[i],14);
            toadoXNextPage+=15; 
        }
	    DrawLine(70,42,textNextPage[1],30) ;
        toadoXNextPage=70;
        while(1){
            int getkeyNextPage=getch();
            switch(getkeyNextPage)
            {
                case 224: getkeyNextPage=getch();
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
                // phim ENTER
                case 13:
                    if(focusNextPage==1)
                    {
                        if(page==0) break;
                        else{
                            XoaManHinh2(41);
                            page-=10;
                            PagePrint=page+10;
                        }
                    }
                    if(focusNextPage==2)
                    {
                        if(PagePrint==c_point) {
                            break;
                        }
                        else{
                            XoaManHinh2(41);
                            page+=10;
                            if((page+10)>c_point)	PagePrint=c_point;
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
            numberAllPage=c_point/10 +1;
            if(c_point%10==0) numberAllPage--;

            gotoxy(27,42); 
            printf("Page %d/%d   ",numberPage,numberAllPage);
            for (int i = page; i < PagePrint; i++)
            {
                output2(c[i]);
            }
            if(flag==1) {
                XoaManHinh();
                return;
            }
        }// end while(1)
    }
}
// KET THUC XU LY TIM KIEM VA IN RA


// bat dau ham tim kiem
// Tim Kiem MA LOP
int timMaLopcx(SinhVien x, char s[])
{
	chuanhoaMaLop(s);
	if (strcmp(x.MaLop, s) == 0) return 0;
	else if (strcmp(x.MaLop,s) > 0) return 1;
	else return -1;
}

// Tim Kiem MA SINH VIEN
int timMaSVcx(SinhVien x, char a[])
{
	chuanhoaMaSV(a);
	if (strcmp(x.MaSV, a) == 0) return 0;
	else if (strcmp(x.MaSV, a) > 0) return 1;
	else return -1;
}

// Tim Kiem HO TEN
int timHoTencx(SinhVien x, char s[])
{
	chuanhoaHoTen(s);
	if (strcmp(x.HoTen, s) == 0) return 0;
	else if (strcmp(x.HoTen,s) > 0) return 1;
	else return -1;
}

// Tim Kiem NGAY SINH
int timNScx(SinhVien x, char s[])
{
	Date b;
	Date a = x.NS;
	if(inputDate(b, s) == 0) return 1000;
	inputDate(b, s);
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

// Tim Kiem DIEM TRUNG BINH
int timDiemTBcx(SinhVien x, char s[])
{
    // Chuyen chuoi sang int
	float a = atof(s); 
	if (x.DiemTB > a) return 1;
	else if (x.DiemTB < a) return -1;
	else return 0;
}

// Tim Kiem GHI CHU
int timGhiChucx(SinhVien x, char s[])
{
	chuanhoaAll(s);
	if (strcmp(x.GhiChu, s) == 0) return 0;
	else if (strcmp(x.GhiChu,s) > 0) return 1;
	else return -1;
}


// MAIN TIM KIEM CX
int timcx(SinhVien x, char s[], int a)
{
	switch (a)
	{
	case 1: return timMaLopcx(x, s); break;
	case 2: return timMaSVcx(x, s); break;
	case 3: return timHoTencx(x, s); break;
	case 4: return timNScx(x, s); break;
	case 5: return timDiemTBcx(x, s); break;
	case 6: return timGhiChucx(x, s); break;
	
	default: return 0;
	}
}

//Khai bao Mang sinh vien de in nhi phan
SinhVien arraySV[N]; int arr_point=0; 
// Bien chi so luong cua Sinh Vien tim dc
int ppp=0; 
int timnhiphan(SinhVien a[], char s[], int l, int r, int b, int &k)
{
	int m;
	if (l>r) return -1;
	else
	{
		m = (l + r) / 2;
		if (timcx(a[m], s, b) == 0) //  means sinh vien a[m] == s
		{
			ppp++; 
            k++;
			arraySV[arr_point]=a[m];
			arr_point++;
			
			int pos1 = m, pos2 = m;
		
			while (timcx(a[pos1 - 1], s, b) == 0)
			{	
				arraySV[arr_point]=a[pos1- 1];
				arr_point++;
				pos1--;
			}
			while (timcx(a[pos2 + 1], s, b) == 0)
			{	
				arraySV[arr_point]=a[pos1+ 1];
				arr_point++;
				pos2++;
			}
		}
		else if (timcx(a[m], s, b) == 1) return timnhiphan(a, s, l, m - 1, b, k); //means(co nghia) sinh vien a[m] > s
		else if(timcx(a[m], s, b) == -1) return timnhiphan(a, s, m + 1, r, b, k);// means sinh vien a[m] < s
	} 
}


// Xu ly TIM KIEM IN RA
void InNhiphan(){
	int flag=0;
	if(ppp>0)
	{
		int page =0;
		int PagePrint=page+10;
		if(PagePrint>arr_point) PagePrint=arr_point;
		int numberPage=1;
		int numberAllPage=arr_point/10 +1;
		if(arr_point%10==0) numberAllPage--;
		gotoxy(27,42); printf("Page %d/%d   ",numberPage,numberAllPage);
		output3();
	
		for (int i = page; i < PagePrint; i++)
		{
			output2(arraySV[i]);
		}
		toadoXNextPage=70;
		for(int i=1;i<=3;i++) { 
			DrawLine(toadoXNextPage,42,textNextPage[i],14);
			toadoXNextPage+=15; 
		}
		DrawLine(70,42,textNextPage[1],30) ;
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
						if(focusNextPage==1) {toadoXNextPage=70; break;}
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
						if(focusNextPage==3) {toadoXNextPage=70+15+15; break;}
						else
						{
							DrawLine(toadoXNextPage,42,textNextPage[focusNextPage],14) ;
							focusNextPage+=1; toadoXNextPage+=15;
							DrawLine(toadoXNextPage,42,textNextPage[focusNextPage],30) ;
						}
					}
					break;
				case 13:
					if(focusNextPage==1)
					{
						if(page==0) break;
						else{
							XoaManHinh2(41);
							page-=10;
							PagePrint=page+10;
						}
					}
					if(focusNextPage==2)
					{
						if(PagePrint==arr_point) {
							break;
						}
						else{
							XoaManHinh2(41);
							page+=10;
							if((page+10)>arr_point)	PagePrint=arr_point;
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
			} //end switch(getkeyNextPage) 
			output3();
			numberPage=(page/10)+1;
			numberAllPage=arr_point/10 +1;
			if(arr_point%10==0) numberAllPage--;
			gotoxy(27,42); printf("Page %d/%d   ",numberPage,numberAllPage);
			for (int i = page; i < PagePrint; i++)
			{
				output2(arraySV[i]);
			}
			if(flag==1) {
				XoaManHinh();
				arr_point=0; ppp=0;
				return;
			}
		}// end while(1)
	}// end if(ppp > 0)
}// KET THUC XU LY TIM KIEM IN RA

void timkiemtuantu(SinhVien a[], int n,int dataSearchType)
{
	taomang(a, &n);
	if (n == 0)
	{
		XoaManHinh();
		DrawLine(27,7,"KHONG CO SINH VIEN TRONG DANH SACH ",14);
	}
	else
	{    
		int escape=0;
		SinhVien2 b[N];
		char s[40];
		chuyen(a, b, n);
		int p = 0;
		XoaManHinh();
		switch(dataSearchType){
			case 1: 	
				DrawLine(27,8,"Nhap Ma Lop: ",14);
				Hiencontro();
				inputSE(s,escape);	if(escape==1) return;
				Ancontro();
				timtuantu(a, b, n, s, 1, p);
				break;
			case 2: 	
				DrawLine(27,8,"Nhap Ma SV: ",14);
				Hiencontro();
				inputSE(s,escape);	if(escape==1) return;
				Ancontro();	
				timtuantu(a, b, n, s, 2, p);
				break;
			case 3: 	
				DrawLine(27,8,"Nhap Ho Ten: ",14);
				Hiencontro();
				inputSE(s,escape);	if(escape==1) return;
				Ancontro();
				timtuantu(a, b, n, s, 3, p);
				break;
			case 4: 	
				DrawLine(27,8,"Nhap Ngay Sinh ",14);
				Hiencontro();
				inputSE(s,escape);	if(escape==1) return;
				Ancontro();	
				timtuantu(a, b, n, s, 4, p);
				break;
			case 5: 	
				DrawLine(27,8,"Nhap Diem TB: ",14);
				Hiencontro();
				inputSE(s,escape);	if(escape==1) return;	
				Ancontro();
				timtuantu(a, b, n, s, 5, p);
				break;
			case 6: 	
				DrawLine(27,8,"Nhap Ghi chu: ",14);
				Hiencontro();
				inputSE(s,escape);	if(escape==1) return;
				Ancontro();	
				timtuantu(a, b, n, s, 6, p);
				break;
		} // end switch(dataSearchType)
		if (p == 0) printf("     Khong tim thay sinh vien phu hop\n");
		getch();
	} // end if else
} // end void

int timkiemnhiphan(SinhVien a[], int n,int dataSearchType)
{		
	char s[40];
	int dem = 0;
	taomang2(a, &n, dataSearchType);
	if (n == 0)
	{
		XoaManHinh();
		DrawLine(27,7,"KHONG SINH VIEN TRONG DANH SACH ",14);
	}
	else
	{	
		int escape=0;
		XoaManHinh();
		switch(dataSearchType){
			case 1: 	
				DrawLine(27,8,"Nhap Ma Lop: ",14);
				Hiencontro();
				inputSE(s,escape);	if(escape==1) return -1;
				Ancontro();	
				timnhiphan(a, s, 0, n - 1, 1, dem);
				InNhiphan();
				break;
			case 2: 	
				DrawLine(27,8,"Nhap Ma SV: ",14);
				Hiencontro();
				inputSE(s,escape);	if(escape==1) return -1;
				Ancontro();
				timnhiphan(a, s, 0, n - 1, 2, dem);
				InNhiphan();
			 	break;
			case 3: 	
				DrawLine(27,8,"Nhap Ho Ten: ",14);
				Hiencontro();
				inputSE(s,escape);	if(escape==1) return -1;
				Ancontro();
				timnhiphan(a, s, 0, n - 1, 3, dem);
				InNhiphan();
			 	break;	
			case 4: 	
				DrawLine(27,8,"Nhap Ngay Sinh: ",14);
				Hiencontro();
				inputSE(s,escape);	if(escape==1) return -1;
				Ancontro();
				timnhiphan(a, s, 0, n - 1, 4, dem);
				InNhiphan();
				break;
			case 5: 	
				DrawLine(27,8,"Nhap Diem TB: ",14);
				Hiencontro();
				inputSE(s,escape);	if(escape==1) return -1;
				Ancontro();
				timnhiphan(a, s, 0, n - 1, 5, dem);
				InNhiphan();
				break;	 
			case 6: 	
				DrawLine(27,8,"Nhap Ghi chu: ",14);
				Hiencontro();
				inputSE(s,escape);	if(escape==1) return -1;
				Ancontro();
				timnhiphan(a, s, 0, n - 1, 6, dem);
				InNhiphan();
				break;	 
				 
		}
		if (dem == 0) printf("     Khong co sinh vien co thong tin phu hop\n");
		getch();
	}
}