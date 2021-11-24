void input(char s[40]) {
    int i = 0;
    int temp = 1;
    while(1) {
        fflush(stdin);
        int n = _getch();

        if(n == 27) {
            XoaManHinh();
            DrawLine(27, 6, "Ban da nhap dung du lieu", 14);
            DrawLine(27, 6, "Moi ban tiep tuc su dung chuowng trinh!", 14);
            return;
        }

        if(n == 13) {
            if(i == 0) {
                s[i] = NULL;
            }
            return;
        }

        if(n == 8) {
            if(i == 0) {
                continue;
            }
            printf("%c %c", 8, 8);
            i--;
            s[i] = NULL;
        }

        if(n == 0 || n == 224) {
            temp = 0;
            continue;
        }

        if(n >= 32 && n <= 126 && temp == 1) {
            s[i] = n;
            printf("%c", n);
            i++;
            s[i]=NULL;
        }
        temp= 1;
    } // end while(1)
}

void inputSE(char s[40],int &escape)
{
	int i = 0;
    int temp = 1;
	while (1)
	{
		fflush(stdin);
		int n = _getch();
		if (n == 27) {
			XoaManHinh();
			DrawLine(27,6,"Ban da dung nhap du lieu",14);
			DrawLine(27,7,"Bam LEFT de tiep tuc su dung",14);
			escape=1;
			return;
		}
	
		if (n == 13)
		{
			if (i == 0) s[i] = NULL;
			return;
		}
		if (n == 8)
		{
			if (i == 0) continue;
			printf("%c %c", 8, 8);
			i--;
			s[i] = NULL;
		}
		if (n == 0 || n == 224)
		{
			temp = 0;
			continue;
		}
		if (n >= 32 && n <= 126 && temp == 1)
		{
			s[i] = n;
			printf("%c", n);
			i++;
			s[i] = NULL;
		}
		temp = 1;
	} // end while(1)
}

void inputNhapSV(char s[40],int &escape,int &position)
{
	int i = 0;
    int temp = 1;
	if(position!=0) {
	    i=position; 
	}
	while (1)
	{
		fflush(stdin);
		int n = _getch();
		if (n == 27) {
			XoaManHinh();
			DrawLine(27,6,"Ban da dung nhap du lieu",14);
			DrawLine(27,7,"Moi ban tiep tuc su dung chuong trinh",14);
			escape=1;
			return;
		}

	    // Phim Enter
		if (n == 13) 
		{ 
			position=i;
			if (i == 0) s[i] = ' ';
			return;
		}
        // Phim BackSpace
		if (n == 8) 
		{	 
			if (i == 0) continue;
			printf("%c %c", 8, 8);
			i--; 
			s[i] = ' ';
		}

		if(n ==224){
			temp = 0;
			n=getch();
            //DOWN
			if(n==80) {
                position=i;
                return;
            }
            //UP
			if(n==72) {
                position=i;
                return;
            }
		}

		if (n == 0 || n == 224)
		{
			temp = 0;
			continue;
		}

		if (n >= 32 && n <= 126 && temp == 1)
		{
			s[i] = n;
			printf("%c", n);
			i++;
			s[i] = NULL;
		}
		temp = 1;
	} //end while(1)
}

// Xoa dau cach thua VD: ha   cong quoc     bao --> ha cong quoc bao
void daucach(char s[40])
{
	for (int i = 0; i < strlen(s); i++) if (s[i] == '\n') s[i] = NULL;
	int i = 0;
	do
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
        {
            // dich chuyen mang s
		    for (int k = i + 1; k < strlen(s); k++) {
                s[k] = s[k + 1];
            }
        } 
		else {
            i++;
        }
	} while (s[i] != NULL);

	if (s[0] == ' ') {
        for (int k = 0; k < strlen(s); k++) {
            s[k] = s[k + 1];
        }
    }
    
	if (s[strlen(s) - 1] == ' ') {
        s[strlen(s) - 1] = NULL;
    }
}

// Xoa toan bo dau cach VD: ha cong quoc bao --> hacongquocbao dung trong MaSV
void daucach2(char s[10]) // Xoa toan bo dau cach VD: hoang quoc trong --> hoangquoctrong use For MaSV
{
	for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '\n') {
            s[i] = NULL;
        }
    }
	int i = 0;
	do
	{
		if (s[i] == ' ') {
            for (int j = i; j < strlen(s); j++) {
                s[j] = s[j + 1];
            }
        }
		else i++;
	} while (s[i] != NULL);

	if (s[0] == NULL) {
        for (int j = 0; j < strlen(s); j++) {
            s[j] = s[j + 1];
        }
    }
}

void chuanhoaMaLop(char s[40])
{
	daucach(s);
	int n = strlen(s);
	if (s[0] >= 'a') {
        s[0] = s[0] - 32;
    }
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == ' ' && s[i + 1] >= 'a') {
            s[i + 1] = s[i + 1] - 32;
        }
		if (s[i] != ' ' && s[i + 1] != ' ' && s[i + 1] <= 'Z') {
            s[i + 1] = s[i + 1] + 32;
        }
	}
}

void chuanhoaMaSV(char a[10])
{	a[9]=NULL;
	daucach2(a);
	int n = strlen(a);
	for (int i = 0; i < n; i++) if (a[i] >= 'a' && a[i] <= 'z') a[i] = a[i] - 32;
		a[9]=NULL;
}

void chuanhoaHoTen(char s[40])
{
	daucach(s);
	int n = strlen(s);
	if (s[0] >= 'a') {
        s[0] = s[0] - 32;
    }
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == ' ' && s[i + 1] >= 'a') {
            s[i + 1] = s[i + 1] - 32;
        }
		if (s[i] != ' ' && s[i + 1] != ' ' && s[i + 1] <= 'Z') {
            s[i + 1] = s[i + 1] + 32;
        }
	}
}

// GHI LA ALL DE DE PHAT TRIEN THEM TINH NANG
void chuanhoaAll(char s[20])
{
	daucach(s);
	int n = strlen(s);
	if (s[0] >= 'a') {
        s[0] = s[0] - 32;
    }
	s[19]=NULL;
}

int namnhuan(int a)
{
	if (a % 400 == 0) return 1;
	if (a % 4 == 0 && a % 100 != 0) return 1;
	return 0;
}

int ktDate(Date a)
{	
	if (a.day > 31) {
        return 0;
    }
	switch (a.month)
	{
	case 4: case 6: case 9: case 11: if (a.day > 30) return 0; break;
	case 2:
		{
			  if (namnhuan(a.year) == 1)
			  {
				  if (a.day > 29) return 0;
			  }
			  else if (a.day > 28) return 0;
			  break;
		}
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: if (a.day > 31) return 0; break;
	default: return 0;
	}
	return 1;
}

int inputDate(Date &c, char s[])
{
						
	char  a[15];
	int n, i, j, k = 0, h, p = 0, b[5];
	daucach(s);		
	n = strlen(s);
	for (i = 0; i <= n; i++)
	{
		if (s[i] >= '0' && s[i] <= '9') {
            k++;
        }
		if (s[i]<'0' || s[i]>'9' || s[i] == NULL)
		{
			for (h = 0, j = i - k; h < k, j < i; h++, j++) {
                a[h] = s[j];
            }
			a[k] = NULL;
			b[p] = atoi(a);
			k = 0;
			p++;
		}
	}
	if (p != 3) {
        return 0;
    }
	c.day = b[0];
	c.month = b[1];
	c.year = b[2];
	if (ktDate(c) == 0) {
        return 2;
    }
	return 1;
}

int ktMaLop(char s[40])
{
	int n = strlen(s);
	for (int i = 0; i < n; i++) if ((s[i]>' ' && s[i]<'A') || (s[i]>'Z' && s[i]<'a') || s[i]>'z') return 0;
	return 1;
}

int ktMaSV(char a[10])
{
	int n = strlen(a);
	for (int i = 0; i < n; i++) if ((a[i]>' ' && a[i]< '0') || (a[i]>'9' && a[i]<'A') || (a[i]>'Z' && a[i]<'a') || a[i]>'z') return 0;
	return 1;
}

int ktHoTen(char s[40])
{
	int n = strlen(s);
	for (int i = 0; i < n; i++) if ((s[i]>' ' && s[i]<'A') || (s[i]>'Z' && s[i]<'a') || s[i]>'z') return 0;
	return 1;
}

//Nhap thong tin SINH VIEN
void FieldNhapSV(){
	int x1=27;
    int y1=8;
	for(int i=1;i<=6;i++)
	{
		DrawLine(x1,y1,textNhapSV[i],14);
		DrawFrameInput(x1+20,y1-1,x1+80,y1+1);
		y1+=4;
	}
		
	DrawLine(x1+40,44,textNhapSV[7],14);
	DrawFrameInput(x1+39,43,x1+39+7,45);
	DrawLine(x1+50,44,textNhapSV[8],14);
	DrawFrameInput(x1+49,43,x1+49+7,45);
}

void FieldNhapSVFocused(int focus,int color)
{	int y[7]={0,8,12,16,20,24,28};	
	if(focus==7) {  
        DrawLine(27+40,44,textNhapSV[focus],color);
        return;
    }

	if(focus==8) {
        DrawLine(27+50,44,textNhapSV[focus],color); 
        return;  
    }
	DrawLine(27,y[focus],textNhapSV[focus],color);
}

//ham nhap rieng MA LOP
void nhapMaLop(SinhVien &a,int &escape,int &position)
{	
	const int lineFieldMaLop=8;
	if(position==0)	gotoxy(48,lineFieldMaLop);
	else gotoxy(48+position,lineFieldMaLop);	
	Hiencontro(); 
	inputNhapSV(a.MaLop,escape,position);
	if(escape==1) return;
	while (ktMaLop(a.MaLop) == 0)
	{
		DrawLine(27,lineFieldMaLop+2,"Ma Lop khong duoc chua ky tu dac biet va so. Moi nhap lai:",207);
		position=0;
		ClearLine(48,lineFieldMaLop,40);
				
		if(position==0)	gotoxy(48,lineFieldMaLop);
		else gotoxy(48+position,lineFieldMaLop);

		inputNhapSV(a.MaLop,escape,position);
		if(escape==1) return;
		ClearLine(27,lineFieldMaLop+2,70);
	}
	chuanhoaMaLop(a.MaLop);
	DrawLine(47,lineFieldMaLop+2,"Ma Lop phu hop",10);
	ClearLine(48,lineFieldMaLop,40);
	gotoxy(48,lineFieldMaLop);	printf("%s", a.MaLop);
//	Ancontro();
}

//ham nhap rieng MA SINH VIEN
void nhapMaSV(SinhVien &a,int &escape,int &position)
{ 
	const int lineFieldMaSV=12;

	if(position==0)	gotoxy(48,lineFieldMaSV);
	else gotoxy(48+position,lineFieldMaSV);
	inputNhapSV(a.MaSV,escape,position);
	if(escape==1) return;
	while (ktMaSV(a.MaSV) == 0)
	{
		DrawLine(27,lineFieldMaSV+2,"Ma Sinh Vien khong duoc chua ky tu dac biet. Moi nhap lai:",207);
		position=0;
		ClearLine(48,lineFieldMaSV,40);// Xoa texting

		if(position==0)	gotoxy(48,lineFieldMaSV);
		else gotoxy(48+position,lineFieldMaSV);	
		
		inputNhapSV(a.MaSV,escape,position);
		if(escape==1) return;
		
		ClearLine(27,lineFieldMaSV+2,70); // xoa notice
	}
	chuanhoaMaSV(a.MaSV);
	DrawLine(47,lineFieldMaSV+2,"Ma Sinh Vien phu hop",10);
	ClearLine(48,lineFieldMaSV,40);
	gotoxy(48,lineFieldMaSV);	printf("%s", a.MaSV);
}

//ham nhap rieng HO TEN
void nhapHoTen(SinhVien &a,int &escape,int &position)
{	
	const int lineFieldHoTen=16;

	if(position==0)	gotoxy(48,lineFieldHoTen);
	else gotoxy(48+position,lineFieldHoTen);	
	Hiencontro(); 
	inputNhapSV(a.HoTen,escape,position);
	if(escape==1) return;

	while (ktHoTen(a.HoTen) == 0)
	{
		DrawLine(27,lineFieldHoTen+2,"Ho Ten khong duoc chua ky tu dac biet va so. Moi nhap lai:",207);
		position=0;
		ClearLine(48,lineFieldHoTen,40);
				
		if(position==0)	gotoxy(48,lineFieldHoTen);
		else gotoxy(48+position,lineFieldHoTen);

		inputNhapSV(a.HoTen,escape,position);
		if(escape==1) return;
		ClearLine(27,lineFieldHoTen+2,70);
	}
	chuanhoaHoTen(a.HoTen);
	DrawLine(47,lineFieldHoTen+2,"Ho Ten phu hop",10);
	ClearLine(48,lineFieldHoTen,40);
	gotoxy(48,lineFieldHoTen);	printf("%s", a.HoTen);
}

//ham nhap rieng NGAY/THANG/NAM SINH
void nhapNS(SinhVien &a,int &escape,int &position, char s[])
{
	const int lineFieldNS=20;

	if(position==0)	gotoxy(48,lineFieldNS);
	else gotoxy(48+position,lineFieldNS);
	fflush(stdin);
	inputNhapSV(s,escape,position);

	if(escape==1) return;
	while (inputDate(a.NS, s) == 0 || inputDate(a.NS, s) == 2)
	{
		if (inputDate(a.NS, s) == 0)
		{
			ClearLine(48,lineFieldNS+2,50);
			DrawLine(48,lineFieldNS+2,"Moi nhap du ngay thang nam!",207);	position=0;
			ClearLine(48,lineFieldNS,20);		
	
			if(position==0)	gotoxy(48,lineFieldNS);
			else gotoxy(48+position,lineFieldNS);
			fflush(stdin);		
			inputNhapSV(s,escape,position);
			if(escape==1) return;

			ClearLine(48,lineFieldNS+2,50);
		}
		
		
		if (inputDate(a.NS, s) == 2)
		{
			DrawLine(48,lineFieldNS+2,"Khong co ngay nay. Moi nhap lai!",207);	position=0;
		
			ClearLine(48,lineFieldNS,20);	
			
			if(position==0)	gotoxy(48,lineFieldNS);
			else gotoxy(48+position,lineFieldNS);	

			fflush(stdin);	
			inputNhapSV(s,escape,position);
			if(escape==1) return;
			
			ClearLine(27,lineFieldNS+2,50);// Xoa dong chu canh bao
		}
	}
	DrawLine(47,lineFieldNS+2,"NS phu hop",10);
	inputDate(a.NS, s);
}

//ham nhap rieng diem trung binh
void nhapDiemTB(SinhVien &a,char s[],int &escape,int &position)
{ 
	const int lineFieldDiemTB=24;
	SinhVien b[N];
	int n = 0;
	taomang(b, &n);
	if(position==0)	gotoxy(48,lineFieldDiemTB);
	else gotoxy(48+position,lineFieldDiemTB);

	inputNhapSV(s,escape,position);
	if(escape==1) return;
	DrawLine(47,lineFieldDiemTB+2,"Diem trung binh phu hop",10);
	a.DiemTB=atof(s);
}

// GHI LA ALL DE DE PHAT TRIEN THEM TINH NANG
void input_WHAT(SinhVien &a,int &escape,int &position,int line)
{
	if(line==28)	inputNhapSV(a.GhiChu,escape,position);
}

void TheTail_WHAT(SinhVien &a,int line)
{
	if(line==28)
	{
		chuanhoaAll(a.GhiChu);
		DrawLine(47,line+2,"Ghi chu phu hop",10);
		ClearLine(48,line,40);
		gotoxy(48,line);
		printf("%s", a.GhiChu);
	}
}
void nhapAllElse(SinhVien &a,int &escape,int &position,int line)
{	
	const int lineField=line;

	if(position==0)	gotoxy(48,lineField);
	else gotoxy(48+position,lineField);
	input_WHAT(a,escape,position,line);
	if(escape==1) return;
	while (ktMaSV(a.MaSV) == 0)
	{
		DrawLine(27,lineField+2,"Khong duoc chua ky tu dac biet. Moi nhap lai:",207);
		position=0;
		ClearLine(27,lineField+2,46);

		if(position==0)	gotoxy(48,lineField);
		else gotoxy(48+position,lineField);	
		input_WHAT(a,escape,position,line);
		if(escape==1) return;
		
		ClearLine(27,lineField+2,60);
	}
	TheTail_WHAT(a,lineField);
}

//GHI FILE VA TIM KIEM
int row3=11;
int lastLine=12;
void ghifile(SinhVien a[], int n)
{
	FILE *f = fopen("danhsachSV.txt", "wb");
	for (int i = 0; i < n; i++) fwrite(&a[i], sizeof(SinhVien), 1, f);
	fclose(f);
}

int timMaLop(SinhVien a, char s[])
{
	chuanhoaMaLop(s);
	if (strstr(a.MaLop, s) != NULL) return 1;
	return 0;
}

int timMaSV(SinhVien a, char s[])
{
	chuanhoaMaSV(s);
	if (strstr(a.MaSV, s) != NULL) return 1;
	return 0;
}

int timHoTen(SinhVien a, char s[])
{
	chuanhoaHoTen(s);
	if (strstr(a.HoTen, s) != NULL) return 1;
	return 0;
}

// GHI LA ALL DE DE PHAT TRIEN THEM TINH NANG
int timAllElse(SinhVien a, char s[],int k)
{
	if(k==6){
		if (strstr(a.GhiChu, s) != NULL) return 1;
		return 0;
	}
}

//ham TimKiem
int TK(SinhVien b[], int *ptr, int &p,int dataFieldType,char s[])
{	
	SinhVien a[N];
	int n;
	taomang(a, &n);
	int k = dataFieldType;
	switch (k)
	{
	case 1:
		for (int i = 0; i < n; i++)
		if (timMaLop(a[i], s) == 1)
		{
			b[p] = a[i];
			*(ptr+p) = i;
			p++;
		}
		break;
	case 2: 
		for (int i = 0; i < n; i++)
		if (timMaSV(a[i], s) == 1)
		{
			b[p] = a[i];
			*(ptr+p) = i;
			p++;
		}
		break;
	case 3:
		for (int i = 0; i < n; i++)
		if (timHoTen(a[i], s) == 1)
		{
			b[p] = a[i];
			*(ptr+p) = i;
			p++;
		}
		break;
	case 4: case 5:
		for (int i = 0; i < n; i++)
		{
			if (timcx(a[i], s, k) == 0)
			{
				b[p] = a[i];
				*(ptr+p)= i;
				p++;
			}
		}
		break;
	case 6:
		for (int i = 0; i < n; i++)
		{
			if (timAllElse(a[i], s, k) == 1)
			{
				b[p] = a[i];
				*(ptr+p)= i;
				p++;
			}
		}
		break;
	default: return 0;
	}
	return 1;
}

void NewLineOutput3(){
	gotoxy(26,row3++);
}

void Printf111(SinhVien b)
{
	SinhVien a; a=b;
	rutgonText(a.MaLop,20);
	rutgonText(a.MaSV,10);
	rutgonText(a.HoTen,25);
	rutgonText(a.GhiChu,15);
	
	char Scores[20];
	sprintf(Scores,"%f",a.DiemTB);
	rutgonText(Scores,5);
	
	NewLineOutput3();
 	printf("\xb3                    \xb3               \xb3                         \xb3           \xb3        \xb3               \xb3\n");

	lastLine=row3; 
	NewLineOutput3();	
	printf("\xb3%-20s\xb3%-15s\xb3%-25s\xb3%.2d-%.2d-%.4d \xb3%-8s\xb3%-15s\xb3\n", a.MaLop, a.MaSV, a.HoTen, (a.NS).day, (a.NS).month,(a.NS).year,Scores ,a.GhiChu );

	NewLineOutput3();
	printf("\xb3____________________\xb3_______________\xb3_________________________\xb3___________\xb3________\xb3_______________\xb3\n");
}

void Printf(SinhVien b,int x,int y,int focus)
{

	if(focus==0){
		gotoxy(x,y);
		textcolor(14); 
	}
	if(focus==1){
		gotoxy(x,y);
		textcolor(73); 
	}
	SinhVien a; a=b;
	rutgonText(a.MaLop,20);
	rutgonText(a.MaSV,10);
	rutgonText(a.HoTen,25);
	rutgonText(a.GhiChu,15);
	
	char Scores[20];
	sprintf(Scores,"%f",a.DiemTB);
	rutgonText(Scores,5);
	

 	gotoxy(x,y-1);
 	printf("\xb3                    \xb3               \xb3                         \xb3           \xb3        \xb3               \xb3\n");
 	gotoxy(x,y);
	printf("\xb3%-20s\xb3%-15s\xb3%-25s\xb3%.2d-%.2d-%.4d \xb3%-8s\xb3%-15s\xb3\n", a.MaLop, a.MaSV, a.HoTen, (a.NS).day, (a.NS).month,(a.NS).year,Scores ,a.GhiChu );
 	gotoxy(x,y+1);
 	printf("\xb3____________________\xb3_______________\xb3_________________________\xb3___________\xb3________\xb3_______________\xb3\n");
 	
	textcolor(14);
}


int page=0;
int PagePrint=page+10;
int MakeFieldChoice(int choice,int p, SinhVien a[]){
	XoaManHinh(); 
	int x=25,y=12;
	choice =0;
	page =0; 
	PagePrint=page+10;
	int numberPage=1;
	int numberAllPage=p/10 +1;
	if(p%10==0) numberAllPage--;

	gotoxy(27,42); printf("Page %d/%d   ",numberPage,numberAllPage);
	if(PagePrint>p) PagePrint=p;
	
	output3(); 
	row3=11; 

	for (int i = page; i < PagePrint; i++)
	{
		Printf111(a[i]);
	}
	Printf(a[page],26,12,1);

	// lastLine is 12 + 3*9 = 39
	toadoXNextPage=70;
	for(int i=4;i<=6;i++) { 
		DrawLine(toadoXNextPage,42,textNextPage[i],14) ;
		toadoXNextPage+=15 ; 
	}

	toadoXNextPage=70;
	
	x=26;y=12;
	int flag=0;
	
	while (1)
	{	
		int	c = getch();	
		// PHIM ENTER
		if(c==13) {  
			row3=11;
			
			return choice;
		}
		// PHim BACKSPACE
		if(c==8) { 
			XoaManHinh();
			DrawLine(27,7,"Tiep tuc bam LEFT de su dung Chuong Trinh",14);
			return -24;
		}
		// PHIM ESC
		if(c==27){ 
			XoaManHinh();
			DrawLine(27,7,"Tiep tuc bam LEFT de su dung Chuong Trinh",14);
			return -24;
		}
		if(c==224) {
			
			c=getch();
			switch(c){
				case 72:  // Up
					Printf(a[choice],x,y,0);
					choice--;
					if(choice>=page) {	
						y-=3;	
						Printf(a[choice],x,y,1);
					}		
					if (choice < page) {
						choice = PagePrint-1; 
						y=lastLine; 
						Printf(a[choice],x,y,1);
					}
					break;
				case 80://Down
					Printf(a[choice],x,y,0);
					choice++;
					if(choice<PagePrint) {
						y+=3;
						Printf(a[choice],x,y,1)	;
					}		
					if (choice > PagePrint-1) {
						choice = page; 
						y=12; 
						Printf(a[choice],x,y,1);
					}
					break;
				case 75: //LEFT
					if(page==0) {
						Printf(a[choice],x,y,0);
						choice=page;
						y=12;
						Printf(a[choice],x,y,1);
						flag=0;break;
					}
					else{
						XoaManHinh2(41);
						flag=1;
						page-=10;	
						choice=page;	
						y=12;
						PagePrint=page+10;
					}
					break;
				case 77://RIGHT
					if(PagePrint==p) {   
						flag=0;
						break;
					}
					else
					{	
						XoaManHinh2(41);
						flag=1;
						page+=10;	
						if((page+10)>p)	PagePrint=p;
						else PagePrint=page+10;
						choice=page;	
						y=12;
					}
					break;	
					
			}//end of Switch(c)
		} //end if(c==224)
		
		if(flag==1)	
		{
			output3(); 
			row3=11; 
			numberPage=(page/10)+1;
			numberAllPage=p/10 +1;
			if(p%10==0) numberAllPage--;
			gotoxy(27,42); 
			printf("Page %d/%d    ",numberPage,numberAllPage);
			for (int i = page; i < PagePrint; i++)
			{
				Printf111(a[i]);
			}
			Printf(a[page],26,12,1);
			flag=0;
		}
	} //end while(1)
	return choice;
}

int numberPage=1;
int numberAllPage=10;
int MakeFieldChoice111(int &choice,int p, SinhVien a[],int FIRST_TIME_DELETE){
	XoaManHinh(); 
	int x=25,y=12;
	numberAllPage=p/10 +1;
	if(numberAllPage<numberPage) numberPage--;
	if(FIRST_TIME_DELETE==1){
		numberPage=1;
		numberAllPage=p/10 +1;
		choice =0;
		page =0; 
		PagePrint=10;
	}

	if(p%10==0) numberAllPage--;

	gotoxy(27,42); 
	printf("Page %d/%d   ",numberPage,numberAllPage);
	if(PagePrint>p) PagePrint=p;
	
	output3(); row3=11; 
	
	if(page==PagePrint){
		page=page-10;
	}
	
	for (int i = page; i < PagePrint; i++)
	{
		Printf111(a[i]);
	}
	Printf(a[page],26,12,1);
	// lastLine is 12 + 3*9 = 39
	toadoXNextPage=70;
	for(int i=4;i<=6;i++) { 
		DrawLine(toadoXNextPage,42,textNextPage[i],14) ;
		toadoXNextPage+=15 ; 
	}
	toadoXNextPage=70;
	
	
	x=26;y=12;
	int flag=0;
	while (1)
	{	
		int	c = getch();	
		if(c==13) {  // PHIM ENTER
			row3=11;
			if(PagePrint==page+1)  choice-=10;
			gotoxy(1,30); printf("choice e = %d   ",choice);
			gotoxy(1,31); printf("page e = %d   ",page);
			gotoxy(1,32); printf("pagePrint e = %d   ",PagePrint);
			return choice;
		}
		if(c==8) { // PHim BACKSPACE
			XoaManHinh();
			DrawLine(27,7,"Tiep tuc bam LEFT de su dung Chuong Trinh",14);
			return -24;
		}
		if(c==27){ // PHIM ESC
			XoaManHinh();
			DrawLine(27,7,"Tiep tuc bam LEFT de su dung Chuong Trinh",14);
			return -24;
		}
		if(c==224) {
			c=getch();
			switch(c){
				case 72:  // Up
					Printf(a[choice],x,y,0);
					choice--;
					if(choice>=page) {	
						y-=3;	
						Printf(a[choice],x,y,1);
					}		
					if (choice < page) {
						choice = PagePrint-1; 
						y=lastLine; 
						Printf(a[choice],x,y,1);
					}
					gotoxy(1,31); printf("choice = %d  ",choice);
					break;
				case 80://Down
					Printf(a[choice],x,y,0);
					choice++;
					if(choice<PagePrint) {	
						y+=3;
						Printf(a[choice],x,y,1)	;
					}		
					if (choice > PagePrint-1) {
						choice = page; y=12; 
						Printf(a[choice],x,y,1);
					}
					gotoxy(1,33); 
					printf("choice d = %d  ",choice);
					break;
				case 75: //LEFT
					if(page==0) {
						Printf(a[choice],x,y,0);
						choice=page;y=12;
						Printf(a[choice],x,y,1);
						flag=0;break;
					}
					
					else{
						XoaManHinh2(41);
						flag=1;
						page-=10;	
						choice=page;	
						y=12;
						PagePrint=page+10;
					}
					break;
				case 77://RIGHT
					if(PagePrint==p) {   
						flag=0;
						break;
					}
					else
					{	
						XoaManHinh2(41);
						flag=1;
						page+=10;	
						if((page+10)>p)	PagePrint=p;
						else PagePrint=page+10;
						choice=page;	
						y=12;
					}
					break;	
				}	//end of Switch
			} //end if(c==224)
		
		if(flag==1)	
		{
			output3(); row3=11; 
			numberPage=(page/10)+1;
			numberAllPage=p/10 +1;
				
			if(p%10==0) {  	
				numberAllPage--;
			}
			if(numberAllPage<numberPage) numberPage--;
			gotoxy(27,42); 
			printf("Page %d/%d    ",numberPage,numberAllPage);
			for (int i = page; i < PagePrint; i++)
			{
				Printf111(a[i]);
			}
			Printf(a[page],26,12,1);
			flag=0;
		}//end if(flag==1)
	} //end while(1)
	return choice;
}