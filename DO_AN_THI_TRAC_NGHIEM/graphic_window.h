#include <graphics.h> 
#include <bits/stdc++.h>
#include "xu_ly_login.h"
#include "ham_lop.h"
#include "dslop_dslkdon.h"
#include "mon_hoc.h"
#include "cauhoithi.h"
#include "ham_nhap.h"
#include "thread.h"
#include "diem_dslkd.h"
using namespace std;

void trang1(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht);//man hinh dang nhap
void trang2(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check);//trang chu
void trang3(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk, int dksearch);//danh sach lop
void trang4(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk);//danh sach sinh vien
void trang4_tach(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk);
void trang5(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk, int dk_search);//danh sach mon hoc
void trang6(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk, int vitriclick, int dk_search);//thong tin bai thi
void trang6_5(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk);
void trang7(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, treeCAUHOITHI p,int &check, int page,char MonHoc[],int SoCHT,int phut,int a[],char dapan[]); //bat dau thi
void trang7_tach(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, treeCAUHOITHI p,int &check, int page,char MonHoc[],int SoCHT,int phut,int a[],char dapan[]);
void trang8(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, treeCAUHOITHI p,int &check, int page,char MonHoc[],int SoCHT,int a[],char dapan[]);//ket thuc bai thi
void trang9_khung(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, treeCAUHOITHI p,int &check, int page,char MonHoc[],int SoCH,int a[], char dapan[], char diemthi[]);
void trang9_in(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, treeCAUHOITHI p,int &check, int page,char MonHoc[],int SoCH,int a[],char dapan[]);
void Khung_ho_tro(int page,int ht);
void Print_SV(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int page);
void Khung_ho_tro_cau_hoi_thi(int page);
void huong_dan_su_dung(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check);
void Search_realtime_dsMON(int n, int x_chuan, int y_chuan, char str[],int page);
void Search_realtime_dssv(int n, int x, int y, char str[],int page);
void vehcn(int x1, int y1, int x2, int y2, int color, int bkcolor, int bdcolor, char *text, int textsize){
	setcolor(bdcolor);
    setfillstyle(SOLID_FILL, bkcolor); 
    setlinestyle(SOLID_LINE, 1, 3);
    bar(x1, y1, x2, y2);
    rectangle(x1, y1, x2, y2);
    floodfill(x1+(x2-x1-5), y1+(y2-y1-5), bdcolor);
    settextstyle(BOLD_FONT, HORIZ_DIR, textsize);
    setcolor(color);
    setbkcolor(bkcolor);
    outtextxy((x1+x2)/2-textwidth(text)/2, (y1+y2)/2-textheight(text)/2, text);
}

bool VT(int x1, int x2, int y1, int y2,int x, int y)
{
	if(x >= x1 && x <= x2 && y >= y1 && y <= y2) 
		return 1;
	else return 0;
}
bool checkxoa(PTRSV psv);

int x,y,check,vi_tri_lop_sua;
char ma_lop[15] = "Nhap ma lop";
char malop_sua_xoa[15]="\0";
char nienkhoa[10];
PTRSV psv;
PTRSV psv_tmp;
char ma_sv_sua[15];
int trung = -1;
char ma_sv_xem[15];
char MonHoc[15];
char MaMon[15];
char TenMon[51];
PTRSV psv_login;
int IndexClass;
char tendangnhap[15];
PTRSV p_tim;
int back = -1;
int back4_3 = -1;
bool checkxoasua = 0;
//	x=mousex(),y=mousey();
//DIEU KHIEN CHUOT TRANG MAN HINH DANG NHAP
void click_1(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht)
{
 	char tmp;
 	strcpy(tendangnhap,"\0");
 	char matkhau[20]="\0";
 	int x_xoa_chu = 575 +textwidth("TEN DANG NHAP: ") ;
    while (1)
	{
		
// check tu thua 	
      
		if(kbhit())
		{
			while(kbhit())
			{
				tmp = getch();									
			}			
		}
		
		if(ismouseclick(WM_MOUSEMOVE)) {
			getmouseclick(WM_MOUSEMOVE,x,y);
	        clearmouseclick(WM_MOUSEMOVE);
	        if (VT(695,845,470,520,x,y)) {
	        	vehcn(695,470,845,520,BLACK,LIGHTGREEN,BLACK,"DANG NHAP",1);
			} else{
				vehcn(695,470,845,520,BLACK,GREEN,BLACK,"DANG NHAP",1);
			}
	        if (VT(1350,1450,700,750,x,y)) { 
	        	vehcn(1350,700,1450,750,BLACK,LIGHTRED,BLACK,"THOAT",1);
	        } else{
	        	vehcn(1350,700,1450,750,BLACK,RED,BLACK,"THOAT",1);
			}
    	}

// tai khoan, mat khau

		if(ismouseclick(WM_LBUTTONDOWN))	
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
	   		clearmouseclick(WM_LBUTTONDOWN);
			if(VT(565,965,355,400,x,y))
			{
				setcolor(WHITE);
				setbkcolor(BLACK);
				x_xoa_chu = 805 - textwidth("TEN DANG NHAP")/2;
				y_xoa_chu = 375;
				NhapMa(10,x_xoa_chu,y_xoa_chu,tendangnhap);
				
			}
			if(VT(565,965,410,455,x,y))
			{
				strcpy(matkhau,"\0");
				setcolor(WHITE);
				setbkcolor(BLACK);
				x_xoa_so = 725 - textwidth("MAT KHAU")/2;
				y_xoa_so = 405; 
		  		NhapSoThanhSao(8,x_xoa_so,y_xoa_so,matkhau);
			}
			
// kiem tra dang nhap			
			
			if(VT(695,845,470,520,x,y))
			{
				check = KiemTraDangNhap(dslop,tendangnhap,matkhau,IndexClass,psv_login);
				moveto((1530)/2-textwidth("  Ten dang nhap hoac mat khau sai!   ")/2,530);
				setbkcolor(WHITE);
				if (check != 0 )
				{
					setbkcolor(WHITE);
					outtext("Dang nhap thanh cong. Vui long cho...");
					delay(2000);
		            break;
				}
				else 
				{
					setbkcolor(WHITE);
					outtext("  Ten dang nhap hoac mat khau sai!   ");
					setbkcolor(BLACK);
					strcpy(tendangnhap,"\0");
					outtextxy(x_xoa_chu,y_xoa_chu,"          ");
					outtextxy(x_xoa_so,y_xoa_so,"        ");
				}
        	}

// thoat   		
    	
    		if(VT(1350,1450,700,750,x,y))
					{
						FreeMemory(dsmon,dslop,dscht);
			            closegraph();
			            break;
		         	} 
		}	
	    delay(50);
    }
	if(check!=0){
		cleardevice();
		trang2(dsmon,dslop,dscht,check);
	}	
}

//DIEU KHIEN CHUOT TRANG CHU
void click_2(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check)
{
	while(1)
	{
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,x,y);
	        clearmouseclick(WM_MOUSEMOVE);
	        if (VT(1250,1400,670,720,x,y)) { 
	            vehcn(1250,670,1400,720,BLACK,LIGHTRED,BLACK,"DANG XUAT",1);
	        }
	        else if (VT(100,350,150,200,x,y)) {
	        	vehcn(100,150,350,200,BLACK,LIGHTGREEN,BLACK,"DANH SACH LOP",1);
			}
			else if(VT(100,350,250,300,x,y)){
				vehcn(100,250,350,300,BLACK,LIGHTGREEN,BLACK,"DANH SACH SINH VIEN",1);
			}
			else if(VT(100,350,350,400,x,y)){
				vehcn(100,350,350,400,BLACK,LIGHTGREEN,BLACK,"DANH SACH MON HOC", 1);
			}
			else if(VT(100,350,450,500,x,y)){
				char *name;
				if(check==1) name="CAU HOI THI";
				if(check==2) name="LAM BAI THI";
				vehcn(100,450,350,500,BLACK,LIGHTGREEN,BLACK,name,1);
			}
			else if(VT(100,350,550,600,x,y)){
				vehcn(100,550,350,600,BLACK,LIGHTGREEN,BLACK,"HUONG DAN SU DUNG",1);
			}
			else{
				vehcn(100,150,350,200,BLACK,GREEN,BLACK,"DANH SACH LOP",1);
				vehcn(100,250,350,300,BLACK,GREEN,BLACK,"DANH SACH SINH VIEN",1);
				vehcn(100,350,350,400,BLACK,GREEN,BLACK,"DANH SACH MON HOC", 1);
				char *name;
				if(check==1) name="CAU HOI THI";
				if(check==2) name="LAM BAI THI";
				vehcn(100,450,350,500,BLACK,GREEN,BLACK,name,1);
				vehcn(100,550,350,600,BLACK,GREEN,BLACK,"HUONG DAN SU DUNG",1);
				vehcn(1250,670,1400,720,BLACK,RED,BLACK,"DANG XUAT",1);
			}
	    }
		
		if(ismouseclick(WM_LBUTTONDOWN)) 
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
	   		clearmouseclick(WM_LBUTTONDOWN);
        	if(VT(1250,1400,670,720,x,y)||VT(100,350,150,200,x,y)||VT(100,350,250,300,x,y)||VT(100,350,350,400,x,y)||VT(100,350,450,500,x,y)||VT(100,350,550,600,x,y))
            break;
        }
    delay(50);
	}
	if(VT(1250,1400,670,720,x,y)){
		cleardevice();
        trang1(dsmon,dslop,dscht);	
	}
	if(VT(100,350,150,200,x,y))
	{//NUT XEM DS LOP
         		cleardevice();
         		strcpy(nienkhoa,"\0");
         		vi_tri_lop_sua=-1;
         		trang3(dsmon,dslop,dscht,check, 1, 0, 0);
    }
	if(VT(100,350,250,300,x,y))
	{//NUT XEM DS SINH VIEN
    	cleardevice();
       	trang4(dsmon,dslop,dscht,check,1,0);
	}
    if(VT(100,350,350,400,x,y))
	{//NUT XEM DS MON HOC
        cleardevice();
        trang5(dsmon,dslop,dscht,check,1,0,1);
    }
	if(VT(100,350,450,500,x,y))
	{//NUT LAM BAI THI/XEM BAI THI
        cleardevice();
        if(check == 1)	trang6(dsmon,dslop,dscht,check,1,0,-1,0);
        if(check == 2)	trang6_5(dsmon,dslop,dscht,check,1,1);
    }
    if(VT(100,350,550,600,x,y))
	{//NUT HUONG DAN SU DUNG
        cleardevice();
        huong_dan_su_dung(dsmon,dslop,dscht,check);
    }
}

//DIEU KHIEN CHUOT TRANG DANH SACH LOP				  
void click_3(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk, int dksearch)  
{
	List_LOP ds_lop;
	LOP *lopMoi = new LOP;
	if(dksearch==1) OpenFile_DSLOP_TheoNienKhoa(ds_lop,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt",nienkhoa);
	else if(dksearch==0) OpenFile_DSLOP(ds_lop,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
	int y_tmp; 
	char tmp;
	int dk_break=0;
	int page_max = (ds_lop.n) / 7;
	if ((ds_lop.n) % 7 != 0) {
    	page_max++;
	}
	while(dk_break==0)
	{
		y_tmp=170;
		if(kbhit()){
			while(kbhit()){
				tmp=getch();
			}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) 
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
	   		clearmouseclick(WM_LBUTTONDOWN);
	        if((VT(1250,1400,670,720,x,y)&&dk==0)||(VT(380,450,650,710,x,y)&&dk!=1&&dk!=4&&dk!=5)||(VT(900,1050,670,720,x,y)&&dksearch==0&&dk!=1&&dk!=4&&dk!=5&&page+1<=page_max)||(VT(900,1050,670,720,x,y)&&dksearch==1&&dk!=1&&dk!=4&&dk!=5&&page+1<=((ds_lop.n+1)/7+1))
			||(VT(700,850,670,720,x,y)&&page!=1&&dk!=1&&dk!=4&&dk!=5)||(VT(90,200,225,280,x,y)&&dk==0&&check==1)||(VT(90,200,375,430,x,y)&&dk==0&&check==1)||(VT(90,200,525,580,x,y)&&dk==0&&check==1)||(VT(50,200,670,720,x,y)&&dk!=0&&dk!=5)
			||(VT(1050,1200,670,720,x,y)&&dk==5&&check==1)||(VT(1240,1390,670,720,x,y)&&dk==5&&check==1))
	        break;
	        if(VT(60,280,115,170,x,y)&&dk!=1&&dk!=4&&dk!=5)
			{//IN THEO NIEN KHOA
				setcolor(BLACK);
				setbkcolor(LIGHTGREEN);			
				NhapNienKhoa(100,130,nienkhoa);
				if(Search_nienkhoa(dslop,nienkhoa)==1){
					break;
				}
				else{
					setcolor(RED);
			   		setbkcolor(WHITE);
			   		if(strcmp(nienkhoa,"\0")==0) outtextxy(40,650,"NIEN KHOA RONG!");
					else outtextxy(40,650,"NIEN KHOA KHONG TON TAI!");
					outtextxy(40,670,"VUI LONG NHAP LAI!");
					delay(2000);	
					outtextxy(40,650,"                        ");	
					outtextxy(40,670,"                  ");
					setcolor(BLACK);
				}
			}
	       
			//THEM LOP		 	
			if(dk==1 && check==1)
			{
				if(VT(305,550,260,315,x,y)){
					NhapMa(15,320,275,lopMoi->MALOP);
				}
				if(VT(550,1020,260,315,x,y)){
					NhapInHoa(30,580,275,lopMoi->TENLOP);
				}
				if(VT(1020,1215,260,315,x,y)){
					NhapNienKhoa(1070,275,lopMoi->Nienkhoa);
				}
				if(VT(1240,1390,670,720,x,y)){
					if(Search(dslop,lopMoi->MALOP)!=-1){
						setcolor(RED);
						setbkcolor(WHITE);
						outtextxy(350,400,"--Ma lop bi trung! Vui long nhap lai!--");
						delay(2000);
						outtextxy(350,400,"                                       ");
						setbkcolor(LIGHTCYAN);	
						setcolor(BLACK);
					}
					else {
						if(strcmp(lopMoi->MALOP,"\0")!=0 && strcmp(lopMoi->Nienkhoa,"\0")!=0 && strcmp(lopMoi->Nienkhoa,"\0")){
							InsertClass(dslop,lopMoi);
							SaveFile_DSLOP(dslop,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
							break;	
						}
						else{
							setcolor(RED);
							setbkcolor(WHITE);
							outtextxy(350,400,"--Nhap thieu thong tin! Vui long bo sung!--");
							delay(2000);
							outtextxy(350,400,"                                           ");
							setbkcolor(LIGHTCYAN);	
							setcolor(BLACK);
						}	
					} 
				}
			} 
			
			//HIEU CHINH LOP
			if(VT(40,370,210,280,x,y) && dk==3 && check==1)
			{
				setcolor(BLACK);
				setbkcolor(LIGHTGREEN);
				NhapMa(15,45,230,malop_sua_xoa);
				vi_tri_lop_sua=Search(dslop,malop_sua_xoa);
				if(vi_tri_lop_sua==-1){
					setcolor(RED);
					setbkcolor(WHITE);
					if(strcmp(malop_sua_xoa,"\0")==0)
					outtextxy(30,290,"MA LOP RONG VUI LONG NHAP LAI!");
					else{
						outtextxy(40,290,"KHONG TIM THAY MA LOP!");
						outtextxy(40,310,"VUI LONG NHAP LAI!");	
					}
					delay(2000);
					outtextxy(30,290,"                              ");	
					outtextxy(40,310,"                  ");
				}
				else{
					if(CheckClass(malop_sua_xoa)==0)
					{
						break;
					}
			   		else  {
			   			setcolor(RED);
			   			setbkcolor(WHITE);
						outtextxy(40,290,"LOP DA CO SINH VIEN!");
						outtextxy(40,310,"KHONG THE SUA!");
						delay(2000);	
						outtextxy(40,290,"                    ");	
						outtextxy(40,310,"              ");
					}	
				}
			}
			
			for (int i=(page-1)*7; i<page*7 && i<ds_lop.n;i++)
			{
				if(VT(1300,1445,y_tmp,y_tmp+60,x,y)&&(dk==0||dk==2||dk==3))
				{
					cleardevice();
					strcpy(ma_lop, ds_lop.node[i]->MALOP);
					dk_break=1;
					break;
				}
				if(VT(1430,1500,y_tmp,y_tmp+60,x,y)&&dk==3&&check==1)
				{
					if(CheckClass(ds_lop.node[i]->MALOP)==0) {
						if(dksearch==1){
							int j=Search(dslop,ds_lop.node[i]->MALOP);
							vi_tri_lop_sua=j;	
						}
						else if(dksearch==0){
							vi_tri_lop_sua=i;
						}
						dk_break=1;
						break;
					}
   					else  {
   						setcolor(RED);
						setbkcolor(WHITE);
						outtextxy(40,290,"LOP DA CO SINH VIEN!");
						outtextxy(40,310,"KHONG THE SUA!");
						setcolor(BLACK);
						delay(2000);
						outtextxy(40,290,"                    ");
						outtextxy(40,310,"              ");
					}		
				}
				if(VT(1430,1500,y_tmp,y_tmp+60,x,y)&&dk==2&&check==1)
				{
					if(CheckClass(ds_lop.node[i]->MALOP)==0) {
						if(dksearch==1){
							int j=Search(dslop,ds_lop.node[i]->MALOP);
							vi_tri_lop_sua=j;		
						}
						else if(dksearch==0){
							vi_tri_lop_sua=i;
						}
						dk_break=1;		
        	    		break;
					}
   					else  {
   						setcolor(RED);
						setbkcolor(WHITE);
						outtextxy(40,290,"LOP DA CO SINH VIEN!");
						outtextxy(40,310,"KHONG THE XOA!");
						setcolor(BLACK);
						delay(2000);
						outtextxy(40,290,"                    ");
						outtextxy(40,310,"              ");
					}
				}
				y_tmp+=60;
			}
			
			if(dk==4&&check==1)
			{
				if(VT(305,550,260,315,x,y)){
					NhapMa(15,320,275,dslop.node[vi_tri_lop_sua]->MALOP);
				}
				if(VT(550,1020,260,315,x,y)){
					NhapInHoa(30,580,275,dslop.node[vi_tri_lop_sua]->TENLOP);
				}
				if(VT(1020,1215,260,315,x,y)){
					NhapNienKhoa(1070,275,dslop.node[vi_tri_lop_sua]->Nienkhoa);
				}
				if(VT(1240,1390,670,720,x,y)){
					if(strcmp(dslop.node[vi_tri_lop_sua]->MALOP,"\0")!=0 && strcmp(dslop.node[vi_tri_lop_sua]->TENLOP,"\0")!=0 && strcmp(dslop.node[vi_tri_lop_sua]->Nienkhoa,"\0")){
						strcpy(lopMoi->MALOP,dslop.node[vi_tri_lop_sua]->MALOP);
						strcpy(lopMoi->TENLOP,dslop.node[vi_tri_lop_sua]->TENLOP);
						strcpy(lopMoi->Nienkhoa,dslop.node[vi_tri_lop_sua]->Nienkhoa);
						DeleteItem(dslop,vi_tri_lop_sua);
						InsertClass(dslop,lopMoi);
						SaveFile_DSLOP(dslop,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
						break;	
					}
					else{
						setcolor(RED);
						setbkcolor(WHITE);
						outtextxy(350,400,"--Nhap thieu thong tin! Vui long bo sung!--");
						delay(2000);
						outtextxy(350,400,"                                           ");
						setbkcolor(LIGHTCYAN);	
						setcolor(BLACK);
					} 
				}
			}
			
			if(VT(40,370,210,280,x,y)&&dk==2&&check==1){
				//NUT XOA 
				setbkcolor(LIGHTGREEN);
				setcolor(BLACK);
				NhapMa(15,45,230,malop_sua_xoa);
			   	vi_tri_lop_sua = Search(dslop,malop_sua_xoa);
			   	if (vi_tri_lop_sua==-1) {
			   		setcolor(RED);
					setbkcolor(WHITE);
					if(strcmp(malop_sua_xoa,"\0")==0)
					outtextxy(30,290,"MA LOP RONG VUI LONG NHAP LAI!");
					else{
						outtextxy(40,290,"KHONG TIM THAY MA LOP!");
						outtextxy(40,310,"VUI LONG NHAP LAI!");	
					}
					delay(2000);
					outtextxy(30,290,"                              ");	
					outtextxy(40,310,"                  ");
				}
				else{
					if(CheckClass(malop_sua_xoa)==0)
					{
						break;
					}
			   		else  {
			   			setcolor(RED);
			   			setbkcolor(WHITE);
						outtextxy(40,290,"LOP DA CO SINH VIEN!");
						outtextxy(40,310,"KHONG THE XOA!");
						delay(2000);	
						outtextxy(40,290,"                    ");	
						outtextxy(40,310,"              ");
					}	
				}
			}		
      }
      delay(100);
   }
   	if(VT(1250,1400,670,720,x,y)&&dk==0)
	{//NUT VE TRANG CHU
		if(back4_3==4)
	 	{
	 		Print_SV(dsmon,dslop,dscht,1);
			OpenFile_SV(dslop,ma_lop);
			trang4(dsmon,dslop,dscht,check,1,0);	
		}
		else
		{
			cleardevice();
		    OpenFile_DSLOP(dslop,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
		    trang2(dsmon,dslop,dscht,check);
		}
	    
	}
	if(VT(380,450,650,710,x,y)&&dk!=1&&dk!=4&&dk!=5)
	{//NUT RESET DS
	    cleardevice();
	    strcpy(nienkhoa,"\0");
	    trang3(dsmon,dslop,dscht,check,1,dk,0);
	}
    if(VT(900,1050,670,720,x,y)&&dksearch==0&&dk!=1&&dk!=4&&dk!=5&&page+1<=((dslop.n+1)/7+1))
	{//NUT QUA TRANG SAU
        cleardevice();
        trang3(dsmon,dslop,dscht,check,page+1,dk,dksearch);	
    }
	if(VT(900,1050,670,720,x,y)&&dksearch==1&&dk!=1&&dk!=4&&dk!=5&&page+1<=((ds_lop.n+1)/7+1))
    {//NUT QUA TRANG SAU
        cleardevice();
        trang3(dsmon,dslop,dscht,check,page+1,dk,dksearch);	
    }
    if(VT(700,850,670,720,x,y)&&page!=1&&dk!=1&&dk!=4&&dk!=5)
	{//NUT QUAY LAI TRANG TRUOC
        cleardevice();
        trang3(dsmon,dslop,dscht,check,page-1,dk,dksearch);
    }
    if(VT(60,280,115,170,x,y)&&dk!=1&&dk!=4&&dk!=5)
	{//IN THEO NIEN KHOA
		cleardevice();
		trang3(dsmon,dslop,dscht,check,1,dk,1);	
	}
    if(VT(90,200,225,280,x,y)&&dk==0&&check==1)
	{//NUT THEM
    	cleardevice();
        trang3(dsmon,dslop,dscht,check,page,1,dksearch);
    }
    if(VT(90,200,375,430,x,y)&&dk==0&&check==1)
	{//NUT XOA
        cleardevice();
        trang3(dsmon,dslop,dscht,check,page,2,dksearch);
    }
    if(VT(90,200,525,580,x,y)&&dk==0&&check==1)
	{//NUT SUA
        cleardevice();
        trang3(dsmon,dslop,dscht,check,page,3,dksearch);
    }
    if(VT(50,200,670,720,x,y)&&dk!=0)
	{//NUT QUAY LAI
		if(dksearch==0) strcpy(nienkhoa,"\0");
		if(dk==4){
		cleardevice();
        trang3(dsmon,dslop,dscht,check,page,3,dksearch);
		}
		else{
		if(dk==2||dk==3) strcpy(malop_sua_xoa,"\0");
			cleardevice();
            trang3(dsmon,dslop,dscht,check,page,0,dksearch);	
		}
    }
	if(VT(1300,1445,170,590,x,y)&&(dk==0||dk==2||dk==3))
	{//XEM DS SV 
		OpenFile_SV(dslop,ma_lop);
		Print_SV(dsmon,dslop,dscht,1);
		trang4(dsmon,dslop,dscht,check,1,0);
	}
	if(dk==1 && check==1){
		cleardevice();
		trang3(dsmon,dslop,dscht,check,page,dk,dksearch);	
	}
	//HIEU CHINH LOP
	if(VT(40,370,210,280,x,y) && dk==3 && check==1){
		cleardevice();
		trang3(dsmon,dslop,dscht,check,page,4,dksearch);
	}
	if(VT(1430,1500,170,590,x,y)&&dk==3&&check==1){
		cleardevice();
		trang3(dsmon,dslop,dscht,check,page,4,dksearch);
	}
	if(VT(1240,1390,670,720,x,y)&&dk==4&&check==1){
		cleardevice();
		trang3(dsmon,dslop,dscht,check,page,3,dksearch);	
	}
	if(VT(40,370,210,280,x,y)&&dk==2&&check==1){
		cleardevice();
		trang3(dsmon,dslop,dscht,check,page,5,dksearch);
	}
	if(VT(1430,1500,170,590,x,y)&&dk==2&&check==1)
	{	
		cleardevice();
        trang3(dsmon,dslop,dscht,check,page,5,dksearch);
	}
	if(VT(1050,1200,670,720,x,y)&&dk==5&&check==1){//NUT NO
		cleardevice();
		trang3(dsmon,dslop,dscht,check,page,2,dksearch);
	}
	if(VT(1240,1390,670,720,x,y)&&dk==5&&check==1){//NUT YES
		DeleteItem(dslop,vi_tri_lop_sua);
		SaveFile_DSLOP(dslop,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
		cleardevice();
		trang3(dsmon,dslop,dscht,check,page,2,dksearch);
	}
	delete lopMoi;
}

//DIEU KHIEN CHUOT TRANG DANH SACH SINH VIEN
void click_4(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk)
{
	SV sv,sv_sua;
	char tmp;
	char lop[10]="\0", mssv[11], ho[51],ten[11], pass[20], phai[2];
  	int dem = 0,sum = 170, i_sv =0;
  	PTRSV psv4;
  	OpenFile_DSLOP(dslop,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
	int gioihan,sonut;
	bool dk_duyet = 1;
	int*arr_saveid=new int[10000];
	int SoCH=0;
	int a[SoCH];
	char Diemthi[5];
	treeCAUHOITHI dscauhoi=NULL;
	if(strcmp(ma_lop, "Nhap ma lop") != 0)
	{
		OpenFile_SV(dslop,ma_lop);
		sonut = countNodes(dslop.node[Search(dslop,ma_lop)]->dssv);
		int sopage =  sonut/7+1;
		if(page < sopage) gioihan = 170 + 6*60;
		else gioihan = 170 + (sonut - (page-1)*7-1)*60;
	} 	
	int k;
	PTRSV nodesinhvien;
	PTRDIEM q;
	if(dk==5){
		k = Search(dslop,ma_lop);
		nodesinhvien=search_info(dslop.node[k]->dssv,ma_sv_xem);
		OpenScore(nodesinhvien);
		dem=countNodes_DIEM(nodesinhvien->sv.ds_diem);
	}
	while(dk_duyet)
	{
		if(kbhit())
		{
			while(kbhit())
			{
				tmp = getch();									
			}			
		}
		if (ismouseclick(WM_LBUTTONDOWN)) 
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
	   		clearmouseclick(WM_LBUTTONDOWN);
	   		
	   		if((VT(900,1050,670,720,x,y) && (strcmp(ma_lop, "Nhap ma lop") != 0)&&dk!=1&&dk!=6&&(page*7 < sonut))||(VT(700,850,670,720,x,y)&&page!=1)) break;
			if(dk==0)
         	{
         		if((VT(20,200,110,160,x,y))||(VT(1250,1400,670,720,x,y))||((VT(320,370,110,160,x,y)&&(strcmp(ma_lop, "Nhap ma lop") != 0))) ||(VT(200,300,110,160,x,y))||(VT(90,200,225,280,x,y) && (strcmp(ma_lop, "Nhap ma lop") != 0) && check==1 &&(dk == 0))||(VT(90,200,375,430,x,y) && (strcmp(ma_lop, "Nhap ma lop") != 0) && check==1 && dk == 0)||(VT(90,200,525,580,x,y) && (strcmp(ma_lop, "Nhap ma lop") != 0) && check==1 && dk==0)||(VT(50,300,670,720,x,y)&&check==1)&&strcmp(ma_lop, "Nhap ma lop") != 0) break;
				if(strcmp(ma_lop, "Nhap ma lop") != 0 &&check ==2)
		        {//XEM DIEM SV
		        	int vitri = vitrinode(dslop.node[Search(dslop,ma_lop)]->dssv,psv_login);
					if(vitri==-1) continue;
					else vitri = vitri-(page-1)*7;
					sum+= (vitri-1)*60;
					if(VT(1280,1405,sum,sum+60,x,y) && sum >=170 && sum < 590)
					{
						strcpy(ma_sv_xem,psv_login->sv.MASV);
						break;
					}
					else
					{
						sum = 170;
						continue;
					}
				}
				if(strcmp(ma_lop, "Nhap ma lop") != 0 &&check ==1)
		        {//XEM DIEM
					for(int i = 0; i < 7; i++)
					{
						if(VT(1280,1405,sum,sum+60,x,y) && sum >=170 && sum <= gioihan )
						{	
							sum = 170;
							dk_duyet = 0;
							break;		
						}
						sum += 60;
						if(sum > gioihan&&i==6)
						{
							sum = 170;
							continue;
						}
					}
				}
			}
			if(dk==1) 
         	{//THEM
         		if((VT(1250,1400,670,720,x,y)&&strlen(sv.MASV) != 0 && strlen(sv.HO) != 0  && strlen(sv.TEN)!= 0 && strlen(BtC(sv.PHAI)) != 0 && strlen(sv.password)!=0)||(VT(50,200,670,720,x,y))) break;
				if(VT(355,520,382,460,x,y) )
         		{ //MSSV
         			strcpy(mssv,"\0");
					NhapMa(11,355+(165-textwidth("N21DCCNxxx"))/2,408,mssv);
					if(trung_ma(dslop,ma_lop,mssv)==1) 
					{
						outtextxy(355+(165-textwidth("N21DCCNxxx"))/2,408,mssv);
						outtextxy(355+(840-textwidth("Ma so da ton tai. Vui long nhap lai"))/2,600,"Ma so da ton tai. Vui long nhap lai");
					}
					else 
					{
						setbkcolor(WHITE);
						outtextxy(355+(840-textwidth("Ma so da ton tai. Vui long nhap lai"))/2,600,"                                   ");
						strcpy(sv.MASV,mssv);
						setbkcolor(LIGHTCYAN);
					}
				}
				if(VT(520,850,382,460,x,y))
         		{//HO
         			strcpy(ho,"\0");
					NhapThuong(51,520 + 25,408,ho);
					strcpy(sv.HO,ho);
				}
				if(VT(850,990,382,460,x,y))
         		{//TEN
         			strcpy(ten,"\0");
					NhapThuong(11,850 + 25,408,ten);
					strcpy(sv.TEN,ten);
				}
				if(VT(990,1100,382,460,x,y))
         		{//PHAI
         			strcpy(phai,"\0");
					NhapPhai(2,990 +(110-textwidth("0"))/2 ,408,phai);
					if(strlen(phai)!=0) sv.PHAI = stoi(phai);
				}
				if(VT(1100,1245,382,460,x,y))
         		{//pass
         			strcpy(pass,"\0");
					NhapSo(20,1100 + (145-textwidth("      "))/2,408,pass);
					strcpy(sv.password,pass);
				}
			}
			
			if(dk==2)
	        {//XOA
	        	//QUAY LAI
	        	if(VT(50,200,670,720,x,y)) break;
	        	if(VT(40,370,210,280,x,y))
				{//Nhap mssv can xoa
					setbkcolor(LIGHTGREEN);			
					outtextxy(65,233,"                         ");
					char mssv_tmp[11];
					strcpy(mssv_tmp,"\0");
					setcolor(BLACK);
					NhapMa(11,40+(330-textwidth("N21DCCNxxx"))/2,233,mssv_tmp);
					psv4 = search_info(dslop.node[Search(dslop,ma_lop)]->dssv,mssv_tmp);	
					if(psv4 == NULL)
					{	
						outtextxy(65,233,"-    Khong tim thay    -");
						continue;
					}	
					if(!CheckEmpty(psv4->sv.MASV)) 
					{
   						setcolor(RED);
			   			setbkcolor(WHITE);
						outtextxy(40,290,"SINH VIEN DA CO DIEM!");
						outtextxy(40,310,"KHONG THE XOA!");
						delay(2000);	
						outtextxy(40,290,"                     ");	
						outtextxy(40,310,"               ");	
						continue;
					}
					break;	
				}
				for(int i = 0; i < 7; i++)
				{
					if(VT(1280,1405,sum,sum+60,x,y) && sum >=170 && sum <= gioihan)
					{
						sum = 170;
						dk_duyet = 0;
						break;
					}
					sum += 60;
					if(sum > gioihan&&i==6)
					{
						sum = 170;
						continue;
					}
				}
			}
	   		
	   		if(dk==3)
	        {//SUA
				if(VT(50,200,670,720,x,y)) break; // THOAT
				if(VT(40,370,210,280,x,y))
				{//Nhap mssv can sua
					setbkcolor(LIGHTGREEN);			
					outtextxy(65,233,"                         ");
					SV sv_sua;
					char mssv_tmp[11];
					strcpy(mssv_tmp,"\0");
					setcolor(BLACK);
					NhapMa(11,40+(330-textwidth("N21DCCNxxx"))/2,233,mssv_tmp);
					strcpy(sv_sua.MASV,mssv_tmp);
					strcpy(ma_sv_sua,sv_sua.MASV);
					psv = search_info(dslop.node[Search(dslop,ma_lop)]->dssv,mssv_tmp);
					if(psv == NULL ) 
					{
						outtextxy(65,233,"-    Khong tim thay    -");
						continue;                                            
					}
					if(!CheckEmpty(psv->sv.MASV)) 
					{
   						setcolor(RED);
			   			setbkcolor(WHITE);
						outtextxy(40,290,"SINH VIEN DA CO DIEM!");
						outtextxy(40,310,"KHONG THE SUA!");
						delay(2000);	
						outtextxy(40,290,"                     ");	
						outtextxy(40,310,"               ");	
						continue;	
					}
					break;
				}
				for(int i = 0; i < 7; i++)
				{//Click chon sinh vien
					if(VT(1280,1405,sum,sum+60,x,y) && sum >=170 && sum <= gioihan)
					{
						sum = 170;
						dk_duyet = 0;
						break;
					}
					sum += 60;
					if(sum > gioihan&&i==6)
					{
						sum = 170;
						continue;
					}
				}
			}
			
			if(dk==4)
         	{//NHAP SUA
         		if(VT(50,200,670,720,x,y)||VT(1250,1400,670,720,x,y))
         		break;
				psv_tmp = psv;
         		if(VT(355,520,382,460,x,y) )
         		{ //MSSV
         			strcpy(mssv,psv->sv.MASV);
					NhapMa(11,355+(165-textwidth("N21DCCNxxx"))/2,408,psv_tmp->sv.MASV);
					if(trung_ma(dslop,ma_lop,psv_tmp->sv.MASV)==1&&strcmp(psv->sv.MASV,psv_tmp->sv.MASV)!=0)
					{
						outtextxy(355+(165-textwidth("N21DCCNxxx"))/2,408,mssv);
						outtextxy(355+(840-textwidth("Ma so da ton tai. Vui long nhap lai"))/2,600,"Ma so da ton tai. Vui long nhap lai");
						continue;
					} 
					else if(strlen(psv_tmp->sv.MASV)==0) 
					{
						outtextxy(355+(840-textwidth("Khong duoc de trong"))/2,600,"Khong duoc de trong");
						continue;
					}
					else 
					{
						setbkcolor(WHITE);
						outtextxy(355+(840-textwidth("Ma so da ton tai. Vui long nhap lai"))/2,600,"                                   ");
						setbkcolor(LIGHTCYAN);
					}	
				}
				
				if(VT(520,850,382,460,x,y))
         		{//HO
         			strcpy(ho,psv->sv.HO);
					NhapThuong(27,520 + 25,408,psv_tmp->sv.HO);
					if(strlen(psv_tmp->sv.HO)==0)
					{
						outtextxy(355+(840-textwidth("Khong duoc de trong"))/2,600,"Khong duoc de trong");
						continue;
					}
				}
				if(VT(850,990,382,460,x,y))
         		{//TEN
					NhapThuong(10,850 + 25,408,psv_tmp->sv.TEN);
					if(strlen(psv_tmp->sv.TEN)==0)
					{
						outtextxy(355+(840-textwidth("Khong duoc de trong"))/2,600,"Khong duoc de trong");
						continue;
					}	
				}
				if(VT(990,1100,382,460,x,y))
         		{//PHAI
					strcpy(phai,BtC(psv->sv.PHAI));
					NhapPhai(2,990 +(110-textwidth("0"))/2 ,408,phai);
					if(strlen(phai)==0)
					{
						outtextxy(355+(840-textwidth("Khong duoc de trong"))/2,600,"Khong duoc de trong");
						continue;
					}
					psv_tmp->sv.PHAI = stoi(phai);
				}
				if(VT(1100,1245,382,460,x,y))
         		{//pass
					NhapSo(8,1100 + (145-textwidth("      "))/2,408,psv_tmp->sv.password);
					if(strlen(psv_tmp->sv.password)==0)
					{
						outtextxy(355+(840-textwidth("Khong duoc de trong"))/2,600,"Khong duoc de trong");
						continue;
					}
				}
			}
			if(dk==5)
			{//XEM DIEM
				if(VT(1250,1400,670,720,x,y)) 
				{
					sum = 170;
					break;
				}
				int flag=220;
				for(int j = (page-1)*7; j < page*7 && j<dem ; j++)
				{ 
					if(VT(1300,1400,flag,flag+60,x,y))
					{
						if((flag >= 640 || flag >=(220+(dem-(page-1)*7)*60))) continue;
						else
						{
							q=nodepointer_DIEM(nodesinhvien->sv.ds_diem, j+1);
							if(q!=NULL)
							{
								char name[100];
								strcpy(name,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\Baithi\\");
								strcat(name,ma_sv_xem);
								strcat(name,".txt");
								OpenFile_DSCHT(dscauhoi,name);
								Inorder(dscauhoi,arr_saveid, SoCH, q->dt.MAMH);
								for(int i=0; i<SoCH; i++){
									a[i]=arr_saveid[i];
									cout<<a[i]<<endl;
								}
								delete[] arr_saveid;
								cleardevice();
								snprintf(Diemthi, sizeof(Diemthi), "%.2f", q->dt.Diem);
								trang9_khung(dsmon,dslop,dscht,dscauhoi,check,1,q->dt.MAMH, SoCH,a, "\0", Diemthi);
							}
						}
					//BAT DK GIAO VIEN SINH VIEN
					}
						flag += 60;		
				}
			}
			if(dk==6)
			{//TIM KIEM SINH VIEN
				if(VT(1250,1400,670,720,x,y)) break;
				if(VT(50,200,110,160,x,y))
				{//Nhap ten/mssv
					Clearlist(p_tim);
					setbkcolor(LIGHTCYAN);
		     		outtextxy(50,125,"              ");
		     		Search_realtime_dssv(11,66,125,mssv,page);
					continue;	
		     	}
		     	if(check ==2)
		        {//XEM DIEM SV
		        	int vitri = vitrinode(p_tim,psv_login);
					if(vitri==-1) continue;
					else vitri = vitri-(page-1)*7;
					sum+= (vitri-1)*60;
					if(VT(1280,1405,sum,sum+60,x,y) && sum >=170 && sum < 590)
					{
						strcpy(ma_sv_xem,psv_login->sv.MASV);
						break;
					}
					else
					{
						sum =170; 
						continue;
					}
				}
				if(check==1)
				{
					int cnt;
					for(int i = 0; i < 7; i++)
					{//Xem diem
						if(VT(1280,1405,sum,sum+60,x,y) && sum >=170 && sum <= 170+(countNodes(p_tim)-1)*60)
						{	
							sum = 170;
							dk_duyet = 0;
							break;
						}
						sum += 60;
						if(sum > gioihan&&i==6)
						{
							sum = 170;
							continue;
						}
					}
				}
	        	
			}
			
			if(dk==7)
			{//CHON MON THI
				if(VT(50,350,400,460,x,y)||VT(1250,1400,670,720,x,y)) break;
				if(VT(70,330,270,330,x,y))
				{
					strcpy(MonHoc,"\0");
					vehcn(70,270,330,330,BLACK,LIGHTGREEN,BLACK,"                     ",1);											
					NhapMa(15,150,290,MonHoc);
					if(TimMaMon(dsmon,MonHoc)==-1) 
					{
						vehcn(70,270,330,330,BLACK,LIGHTGREEN,BLACK,"Khong tim thay",1);
						continue;
					} 
					break;
				}
			}
		}
		delay(100);	
	}
		   // MOT NUT CHO NHIEU CHUC NANG	
		    if(VT(1250,1400,670,720,x,y)&&dk!=1&&dk!=2&&dk!=3)
			{//NUT VE TRANG CHU + THEM
         		cleardevice();
         		if(dk==0) 
         		{
         			back4_3 = -1;
					trang2(dsmon,dslop,dscht,check);	
				}
				else if(dk == 4 )
				{
					if(trung_ma(dslop,ma_lop,mssv)==1&&strcmp(psv->sv.MASV,mssv)!=0) 
					{
						trung = 1;
						trang4(dsmon,dslop,dscht,check,page,4);
					}
					else
					{
						trung = -1;
						sua(dslop,ma_lop,ma_sv_sua,psv_tmp->sv);
						trang4(dsmon,dslop,dscht,check,page,3);
					}	
				}
				else if(dk==5)
				{
					if(back==6) trang4(dsmon,dslop,dscht,check,page,back);
					else trang4(dsmon,dslop,dscht,check,page,0);
				} 
				else if(dk==6) 
				{
					back=-1;
					trang4(dsmon,dslop,dscht,check,page,0);
				}
				else if(dk==7) trang4(dsmon,dslop,dscht,check,page,0);
         	}
         	
    		if(VT(900,1050,670,720,x,y) && (strcmp(ma_lop, "Nhap ma lop") != 0)&&dk!=1&&dk!=6&&(page*7 < sonut))
			{//NUT QUA TRANG SAU
         	//	cleardevice();
         		trang4_tach(dsmon,dslop,dscht,check,page+1,dk);
         	}
        	if(VT(700,850,670,720,x,y)&&page!=1)
			{//NUT QUAY LAI TRANG TRUOC
         	//	cleardevice();
         		Print_SV(dsmon,dslop,dscht,1);
         		trang4_tach(dsmon,dslop,dscht,check,page-1,dk);
         	}
  	
         	
        //MOT NUT TRONG MOT CHUC NANG 	
         	if(dk==0)
         	{
         		if(VT(20,200,110,160,x,y) )
				{//NHAP MA LOP
					setbkcolor(WHITE);
					outtextxy(50+(150-textwidth("Khong tim thay"))/2,175,"                  ");
					setbkcolor(LIGHTCYAN);
		     		outtextxy(50,125,"            ");
					NhapMa(11,66,125,lop);
					strcpy(ma_lop,lop);
					Print_SV(dsmon,dslop,dscht,1);
					trang4_tach(dsmon,dslop,dscht,check,1,0);
		     	}
		    
		     	if(VT(320,370,110,160,x,y)&&(strcmp(ma_lop, "Nhap ma lop") != 0))
		     	{//TIM SINH VIEN
		     		cleardevice();
		     		back = 6;
		     		trang4(dsmon,dslop,dscht,check,page,6);	
				}
				
				if(VT(200,300,110,160,x,y))
				{//NUT XEM DS LOP TU DS SINH VIEN 200,110,300,160
         			cleardevice();
         			strcpy(nienkhoa,"\0");
         			back4_3=4;
         			trang3(dsmon,dslop,dscht,check,page,0,0);	
				} 
				
         		if(strcmp(ma_lop, "Nhap ma lop") != 0 &&check ==1)
		        {//XEM DIEM
					for(int i = 0; i < 7; i++)
					{
						if(VT(1280,1405,sum,sum+60,x,y) && sum >=170 && sum <= gioihan )
						{	
							i_sv = i+(page-1)*7;
							psv = nodepointer(dslop.node[Search(dslop,ma_lop)]->dssv, i_sv+1);	
							if(psv == NULL ) 
							{
								trang4(dsmon,dslop,dscht,check,page,0);
								continue;                                            
							}
							strcpy(ma_sv_xem,psv->sv.MASV);
							trang4(dsmon,dslop,dscht,check,1,5);		
						}
						sum += 60;
						if(sum > gioihan&&i==6)
						{
							sum = 170;
							continue;
						}
					}
				}
				else if(strcmp(ma_lop, "Nhap ma lop") != 0 &&check ==2) trang4(dsmon,dslop,dscht,check,1,5);
				if(VT(50,300,670,720,x,y)&&check==1&&strcmp(ma_lop, "Nhap ma lop") != 0)
				{//XEM DIEM THEO MOM 50,670,300,720
					cleardevice();
					trang4(dsmon,dslop,dscht,check,page,7);
				}	
				
				if(VT(90,200,225,280,x,y) && (strcmp(ma_lop, "Nhap ma lop") != 0) && check==1 &&(dk == 0))
				{//NUT THEM
					cleardevice();
	         		if(dk == 4) trang4(dsmon,dslop,dscht,check,page,3);
	         		else trang4(dsmon,dslop,dscht,check,page,1);
	         	}	
	         	if(VT(90,200,375,430,x,y) && (strcmp(ma_lop, "Nhap ma lop") != 0) && check==1 && dk == 0)
				{//NUT XOA
	         		cleardevice();
	            	trang4(dsmon,dslop,dscht,check,page,2);
	         	}
	         	if(VT(90,200,525,580,x,y) && (strcmp(ma_lop, "Nhap ma lop") != 0) && check==1 && dk==0)
				{//NUT SUA
	         		cleardevice();
	            	trang4(dsmon,dslop,dscht,check,page,3);
	         	}
			}
         	
         	if(dk==1) 
         	{//THEM
         				
				if(VT(1250,1400,670,720,x,y)&&strlen(sv.MASV) != 0 && strlen(sv.HO) != 0  && strlen(sv.TEN)!= 0 && strlen(BtC(sv.PHAI)) != 0 && strlen(sv.password)!=0)
     			{
     				if(trung_ma(dslop,ma_lop,sv.MASV))	
     				{
     					trung=1; 
//						continue;
					}
					else
					{
						trung = 0;
						input_lop(dslop,ma_lop,sv);	
						trang4(dsmon,dslop,dscht,check,page,1);		
					}	
				}
				if(VT(50,200,670,720,x,y))
				{//QUAY LAI TRANG 4
					cleardevice();
					Print_SV(dsmon,dslop,dscht,page);
					trang4(dsmon,dslop,dscht,check,page,0);	 	
				}
//				continue;
			}
	        if(dk==2)
	        {//XOA
	        	if(VT(40,370,210,280,x,y))
	        	{
	        		int j = Search(dslop,ma_lop);
	        		if(checkxoa(psv4) == 1) 
	        		{
	        			Delete_Info(dslop.node[j]->dssv,psv4->sv.MASV);
						XuatFile_SV(dslop,j,ma_lop);
//						cleardevice();
//						Print_SV(dsmon,dslop,dscht,page);
//						trang4(dsmon,dslop,dscht,check,page,2);
					}
					//else 
					{
						cleardevice();
						Print_SV(dsmon,dslop,dscht,page);
						trang4(dsmon,dslop,dscht,check,page,2);	
					}		
					
				}
	        	for(int i = 0; i < 7; i++)
				{
					if(VT(1280,1405,sum,sum+60,x,y) && sum >=170 && sum <= gioihan)
					{					
						int j = Search(dslop,ma_lop);
						i_sv = i+(page-1)*7;
						psv4 = nodepointer(dslop.node[j]->dssv, i_sv+1);	
						if(psv4 == NULL)
						{	
							trang4(dsmon,dslop,dscht,check,page,2);
							continue;
						}	
						if(!CheckEmpty(psv4->sv.MASV)) 
						{
	   						setcolor(RED);
				   			setbkcolor(WHITE);
							outtextxy(40,290,"SINH VIEN DA CO DIEM!");
							outtextxy(40,310,"KHONG THE XOA!");
							delay(2000);	
							outtextxy(40,290,"                     ");	
							outtextxy(40,310,"               ");	
						}
						else
						{
							if(checkxoa(psv4) == 1)
							{
								Delete_Info(dslop.node[j]->dssv,psv4->sv.MASV);
								XuatFile_SV(dslop,j,ma_lop);
							}
						}			
						cleardevice();
						Print_SV(dsmon,dslop,dscht,page);
						trang4(dsmon,dslop,dscht,check,page,2);
						return;
					}
					sum += 60;
					if(sum > gioihan)
					{
						sum = 170;
						continue;
					} 
				}
				if(VT(50,200,670,720,x,y))
				{//QUAY LAI
					cleardevice();
					trang4(dsmon,dslop,dscht,check,page,0);
				}
				
			}
			
			if(dk==3)
	        {//SUA
	        	for(int i = 0; i < 7; i++)
				{//click de sua
					if(VT(1280,1405,sum,sum+60,x,y) && sum >=170 && sum <=gioihan)
					{						
						int j = Search(dslop,ma_lop);
						i_sv = i+(page-1)*7;
						psv = nodepointer(dslop.node[j]->dssv, i_sv+1);	
						if(psv == NULL ) 
						{
							trang4(dsmon,dslop,dscht,check,page,3);
							continue;                                            
						}
						if(!CheckEmpty(psv->sv.MASV)) 
						{
	   						setcolor(RED);
				   			setbkcolor(WHITE);
							outtextxy(40,290,"SINH VIEN DA CO DIEM!");
							outtextxy(40,310,"KHONG THE SUA!");
							delay(2000);	
							outtextxy(40,290,"                     ");	
							outtextxy(40,310,"               ");	
							trang4(dsmon,dslop,dscht,check,page,3);	
						}
						strcpy(ma_sv_sua,psv->sv.MASV);
						trang4(dsmon,dslop,dscht,check,page,4);
						return;
					}
					sum += 60;
					if(sum > gioihan)
					{
						sum = 170;
						continue;
					}
				}
				
				if(VT(40,370,210,280,x,y))
				{//Nhap mssv can sua
					trang4(dsmon,dslop,dscht,check,page,4);
				}
				if(VT(50,200,670,720,x,y))
				{
					cleardevice();
					trang4(dsmon,dslop,dscht,check,page,0);
				}
			}
			if(dk==4)
			{//NHAP SUA
				if(VT(50,200,670,720,x,y))
				{//QUAY LAI
					cleardevice();
					trang4(dsmon,dslop,dscht,check,page,3);	
				}		
			}
			if(dk==5)
			{//DIEM THI, o day la bat dieu kien xem bai thi
				int flag=220;
				for(int j = (page-1)*7; j < page*7 && j<dem ; j++)
				{ 
					if(VT(1300,1400,flag,flag+60,x,y))
					{
						if((flag >= 640 || flag >=(220+(dem-(page-1)*7)*60))) continue;
						else
						{
							trang9_khung(dsmon,dslop,dscht,dscauhoi,check,1,q->dt.MAMH, SoCH,a, "\0", Diemthi);
						}
					}
					//BAT DK GIAO VIEN SINH VIEN
				}
					flag += 60;		
			}
			if(dk==6)
			{//TIM KIEM SINH VIEN
				if(check==1)
				{
					int cnt;
					for(int i = 0; i < 7; i++)
					{//Xem diem
						if(VT(1280,1405,sum,sum+60,x,y) && sum >=170 && sum <= 170+(countNodes(p_tim)-1)*60)
						{	
							psv = nodepointer(p_tim, i+1);	
							cout<<cnt;
							if(psv == NULL ) 
							{
								trang4(dsmon,dslop,dscht,check,page,0);
								continue;                                            
							}
							strcpy(ma_sv_xem,psv->sv.MASV);
							trang4(dsmon,dslop,dscht,check,1,5);
						}
						sum += 60;
						if(sum > 170+(countNodes(p_tim)-1)*60 ) 
						{
							sum = 170;
							continue;
						}
					}
				}
	        	else if(check ==2) trang4(dsmon,dslop,dscht,check,1,5);			
        	}
	        if(dk==7)
			{
				if(VT(50,350,400,460,x,y))
				{
					cleardevice();
					trang5(dsmon,dslop,dscht,check,page,12,1);
				}
				if(VT(70,330,270,330,x,y))
				{
					cleardevice();
				    trang4(dsmon,dslop,dscht,check,page,7);
				}
			}

}
//DIEU KHIEN CHUOT TRANG DANH SACH MON HOC
void click_5(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk, int dksearch)
{
	int x,y,vitri;
	List_MH ds_mon;
	MH mh;
	char s[50];
	char MaMon_xoa[15];
	string tmp,monhoc;
	int y_tmp;
	treeCAUHOITHI p=NULL;
    OpenFile_DSCHT(p,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");
    if(dksearch==0) OpenFile_DSMH(ds_mon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_SEARCH.txt");
	else OpenFile_DSMH(ds_mon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");				
	int dk_break=0;
	while(dk_break==0)
	{
		y_tmp=190;
		if(kbhit())
		{
			while(kbhit())
			{
				tmp= getch();									
			}			
		}
		
		if (ismouseclick(WM_LBUTTONDOWN)) 
		{
			clearmouseclick(WM_MOUSEMOVE);
			getmouseclick(WM_LBUTTONDOWN, x, y);
		//XOA THEO MA MON
			if(VT(40,480,270,340,x,y) && dk==2)
			{
				setcolor(BLACK);
				setbkcolor(LIGHTGREEN);
				strcpy(s,"\0");
				NhapMa(15,200,290,s);
        	    break;
			}
		//XOA THEO TEN MON
			if(VT(40,480,400,470,x,y) && dk==2)
			{
				setcolor(BLACK);
				setbkcolor(LIGHTGREEN);
				strcpy(s,"\0");
				NhapInHoa(50,60,420,s);
        	    break;
			}
			for (int i=(page-1)*7; i<=page*7&&i<ds_mon.n; i++)
			{
				if(VT(1350,1450,y_tmp,y_tmp+60,x,y))
				{
					if((check==1 && dk==2)||(dk==0)||(dk==8 && dksearch==0)||(dk==9 && dksearch==0)
					||dk==11||dk==13||(check==1 && dk==3)||dk==12)
					{
						vitri=i;
						dk_break=1;
						break;
	        	    }
				}
				y_tmp+=60;
			}
		//THEM MA MON HOC
		    if((VT(400,650,260,320,x,y) && dk==1))
            {
            	outtextxy(480,270,"              ");
            	strcpy(s,"\0");
				NhapMa(15,480,270,s);
	            strcpy(mh.MAMH, s);
			}
		//THEM TEN MON HOC
			if(VT(650,1200,260,320,x,y) && dk==1)
			{
				outtextxy(690,270,"                                 ");
				strcpy(s,"\0");
				NhapInHoa(50,690,270,s);
				strcpy(mh.TENMH, s);
			}
		//CAC CHUC NANG...
		    if((VT(1250,1400,670,720,x,y)&&(dk==0||dk==1||dk==10))||(VT(50,200,110,180,x,y) && dk==4)||(VT(900,1050,670,720,x,y) && dk!=4 && ds_mon.n>=(page*7+1))
			||(VT(700,850,670,720,x,y) && page!=1 && dk!=4)||(VT(90,200,225,280,x,y) && dk==0 && check==1)||(VT(90,200,375,430,x,y ) && dk==0 && check==1)
			||(VT(90,200,525,580,x,y) && dk==0 && check==1)||(VT(40,350,270,340,x,y) && dk==3)||(VT(40,350,400,470,x,y) && dk==3)
			||(VT(50,200,670,720,x,y)&&dk!=0)) break; 	
			
			if(VT(40,490,270,340,x,y) && dk==4)
         	{
				setcolor(BLACK);
				setbkcolor(LIGHTGREEN);
				strcpy(s,"\0");
				NhapMa(15,150,290,s);
				Search_monhoc(ds_mon,s);
				if(SearchMAMON(p,s) > 0)
				{
					MessageBoxA(NULL, "Mon hoc da co cau hoi thi, khong duoc hieu chinh!", "Thong bao", MB_OK | MB_ICONINFORMATION);
					break;
				}
				else
				{
					if(check_trung(dsmon,s) == 1)
					{
						int result = MessageBoxA(NULL, "Ban co chac muon hieu chinh ma mon hoc nay?", "XAC NHAN", MB_YESNO | MB_ICONQUESTION);
						if (result == IDYES)
						{
							ofstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_temp1.txt", ios::app);
							file<<s<<",";
							file.close();
						    break;
						}
						else outtextxy(150,290,"           ");
					}
					else 
					{
						MessageBoxA(NULL, "Ma mon hoc khong ton tai", "Thong bao", MB_OK | MB_ICONINFORMATION);
						outtextxy(150,290,"           ");
					}
				}
			}
			if(VT(40,480,270,340,x,y) && dk==5)
			{
				setcolor(BLACK);
				setbkcolor(LIGHTGREEN);
				strcpy(s,"\0");
				NhapMa(15,150,290,s);
				if(check_trung(dsmon,s) == 0)
				{
					ofstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_temp1.txt", ios::app);
					file<<s<<",";
					file.close();
					Docfile_temp(1);
					MessageBoxA(NULL, "Hieu chinh thanh cong!", "Thong bao", MB_OK | MB_ICONINFORMATION);
			    	break;
				}
				else 
				{
				    MessageBoxA(NULL, "Ma mon hoc nay da bi trung voi mon hoc khac!", "Thong bao", MB_OK | MB_ICONINFORMATION);
				    outtextxy(150, 290, "            ");
				}
			}
			if(VT(40,480,270,340,x,y) && dk==6)
			{
				setcolor(BLACK);
				setbkcolor(LIGHTGREEN);
				strcpy(s,"\0");
				NhapInHoa(50,70,290,s);
				Search_monhoc(ds_mon,s);
				if(SearchMAMON(p,TimMaMonTheoTenMon(dsmon,s)) > 0)
				{
					MessageBoxA(NULL, "Mon hoc da co cau hoi thi, khong duoc hieu chinh!", "Thong bao", MB_OK | MB_ICONINFORMATION);
					break;
				}
				else
				{
					if(check_trung(dsmon,TimMaMonTheoTenMon(dsmon,s))==1)
					{
						int result = MessageBoxA(NULL, "Ban co chac muon hieu chinh ten mon hoc nay?", "XAC NHAN", MB_YESNO | MB_ICONQUESTION);
						if (result == IDYES)
						{
							ofstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_temp1.txt", ios::app);
							file<<s<<",";
							file.close();
						    break;
						}
						else outtextxy(70,290,"                       ");
					}
					else 
					{
						MessageBoxA(NULL, "Ten mon hoc khong ton tai", "Thong bao", MB_OK | MB_ICONINFORMATION);
						outtextxy(70,290,"                       ");
					}
				}
			}
			if(VT(40,480,270,340,x,y) && dk==7)
			{
				setcolor(BLACK);
				setbkcolor(LIGHTGREEN);
				strcpy(s,"\0");
				NhapInHoa(50,70,290,s);
				if(check_trung(dsmon,TimMaMonTheoTenMon(dsmon,s)) == 0)
				{
					ofstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_temp1.txt", ios::app);
					file<<s<<",";
					file.close();
					Docfile_temp(2);
					MessageBoxA(NULL, "Hieu chinh thanh cong!", "Thong bao", MB_OK | MB_ICONINFORMATION);
			    	break;
				}
				else 
				{
				    MessageBoxA(NULL, "Ten mon hoc nay da bi trung voi mon hoc khac!", "Thong bao", MB_OK | MB_ICONINFORMATION);
				    outtextxy(70, 290, "                                ");
				}
			}
        //SEARCH MON HOC
         	if(VT(70,480,130,185,x,y) && (dk==0||dk==2||dk==3||dk==8||dk==9||dk==11||dk==12))
         	{
         		if(dk==2||dk==3||dk==8||dk==11||dk==12||dk==13) 	setbkcolor(LIGHTCYAN);
         		Search_realtime_dsMON(30,90,145,s,page);
    			remove("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_SEARCH.txt");
         		Search_chuoicon(ds_mon,s);
         		if(dk==0||dk==8||dk==3||dk==9||dk==2||dk==11||dk==12||dk==13)	break;
			}
		//SUA MA MON HOC
			if(VT(400,650,260,320,x,y) && dk==10)
			{
				outtextxy(480,270,"              ");
				setcolor(BLACK);
				setbkcolor(LIGHTCYAN);
				strcpy(s,"\0");
				NhapMa(15,480,270,s);
				if(kiemTraChuoiKhacKhoangTrang(s))
				{
					if(check_trung(dsmon,s) == 1)
					{
						cout<<check_trung(dsmon,s)<<endl;
						MessageBoxA(NULL, "Ma mon hoc da bi trung!", "Thong bao", MB_OK | MB_ICONINFORMATION);
						break;
					}
					else	Alter_mamon(MaMon,s);
				}
				else 
				{
					MessageBoxA(NULL, "Hieu chinh that bai, vui long nhap day du thong tin", "Thong bao", MB_OK | MB_ICONINFORMATION);
					break;
				}
			}
		//SUA TEN MON HOC
			if(VT(650,1200,260,320,x,y) && dk==10)
			{
				outtextxy(690,270,"                                 ");
				setcolor(BLACK);
				setbkcolor(LIGHTCYAN);
				strcpy(s,"\0");
				NhapInHoa(51,690,270,s);
				if(kiemTraChuoiKhacKhoangTrang(s))
				{
					if(check_trung(dsmon,TimMaMonTheoTenMon(dsmon,s).c_str()) == 1)
					{
						MessageBoxA(NULL, "Ten mon hoc da bi trung!", "Thong bao", MB_OK | MB_ICONINFORMATION);
						break;
					}
					else	Alter_tenmon(TenMon,s);
				}
				else 
				{
					MessageBoxA(NULL, "Hieu chinh that bai, vui long nhap day du thong tin", "Thong bao", MB_OK | MB_ICONINFORMATION);
					break;
				}
			}
        }
    	delay(100);
	}
	//XOA THEO MA MON
			if(VT(40,480,270,340,x,y) && dk==2)
			{
				if(kiemTraChuoiKhacKhoangTrang(s))
				{
					if(check_trung(dsmon,s) == 1)
					{
		        	    if(SearchMAMON(p,s) > 0)
		        	    {
		        	    	MessageBoxA(NULL, "Mon hoc da co cau hoi thi, khong duoc xoa!", "Thong bao", MB_OK | MB_ICONINFORMATION);
						}
						else
						{
							int result = MessageBoxA(NULL, "Ban co chac muon xoa mon hoc nay?", "XAC NHAN", MB_YESNO | MB_ICONQUESTION);
							if (result == IDYES)
							{
								Delete_mamon(ds_mon,s);
		        	    		MessageBoxA(NULL, "Xoa mon hoc thanh cong!", "Thong bao", MB_OK | MB_ICONINFORMATION);
							}
						}
					}
					else MessageBoxA(NULL, "Ma mon hoc khong ton tai", "Thong bao", MB_OK | MB_ICONINFORMATION);
				}
				else MessageBoxA(NULL, "Vui long nhap day du thong tin!", "Thong bao", MB_OK | MB_ICONINFORMATION);
        	    cleardevice();
        	    trang5(dsmon,dslop,dscht,check,page,2,1);
			}
		//XOA THEO TEN MON
			if(VT(40,480,400,470,x,y) && dk==2)
			{
				if(kiemTraChuoiKhacKhoangTrang(s))
				{
					if(check_trung(dsmon,TimMaMonTheoTenMon(dsmon,s)) == 1)
					{
		        	    if(SearchMAMON(p,TimMaMonTheoTenMon(dsmon,s)) > 0)
		        	    {
		        	    	MessageBoxA(NULL, "Mon hoc da co cau hoi thi, khong duoc xoa!", "Thong bao", MB_OK | MB_ICONINFORMATION);
						}
						else
						{
							int result = MessageBoxA(NULL, "Ban co chac muon xoa mon hoc nay?", "XAC NHAN", MB_YESNO | MB_ICONQUESTION);
							if (result == IDYES)
							{
								Delete_tenmon(ds_mon,s);
		        	    		MessageBoxA(NULL, "Xoa mon hoc thanh cong!", "Thong bao", MB_OK | MB_ICONINFORMATION);
							}
						}
					}
					else MessageBoxA(NULL, "Ten mon hoc khong ton tai", "Thong bao", MB_OK | MB_ICONINFORMATION);
				}
				else MessageBoxA(NULL, "Vui long nhap day du thong tin!", "Thong bao", MB_OK | MB_ICONINFORMATION);
        	    cleardevice();
        	    trang5(dsmon,dslop,dscht,check,page,2,1);
			}
			if(VT(1350,1450,190,610,x,y))
			{
						if(check==1 && dk==2)
						{
							if(SearchMAMON(p,ds_mon.node[vitri].MAMH) > 0)
							{
								MessageBoxA(NULL, "Mon hoc da co cau hoi thi, khong duoc xoa!", "Thong bao", MB_OK | MB_ICONINFORMATION);
								trang5(dsmon,dslop,dscht,check,page,2,1);
		        	    	}
		        	    	else 
		        	    	{
		        	    		int result = MessageBoxA(NULL, "Ban co chac muon xoa mon hoc nay?", "XAC NHAN", MB_YESNO | MB_ICONQUESTION);
								if (result == IDYES)
								{
									Delete_mamon(ds_mon,ds_mon.node[vitri].MAMH);
									MessageBoxA(NULL, "Xoa mon hoc thanh cong!", "Thong bao", MB_OK | MB_ICONINFORMATION);
									cleardevice();
				        	    	trang5(dsmon,dslop,dscht,check,page,2,1);
			        	    	}
			        	    	else 
								{
									trang5(dsmon,dslop,dscht,check,page,2,1);
								}
							}
	        	    	}
	        	    //NUT CHON MON THI
	        	    	if(dk == 0)
	        	    	{
	        	    		cout<<vitri<<"---"<<ds_mon.node[vitri].MAMH<<"...."<<endl;
							if(SearchMAMON(p,ds_mon.node[vitri].MAMH) > 0)
							{
								strcpy(MonHoc,ds_mon.node[vitri].MAMH);
				        	    cleardevice();
				        	    trang6_5(dsmon,dslop,dscht,check,page,0);
							}
							else
							{
								MessageBoxA(NULL, "Chua co cau hoi thi cho mon hoc nay!", "Thong bao", MB_OK | MB_ICONINFORMATION);
								trang5(dsmon,dslop,dscht,check,page,0,1);
		        	    	}
		        		}
		        	//CHON MON THI VA XOA/SUA MON HOC THEO DSMON_SEARCH
	        	    	if((dk==8||dk==9||dk==11||dk==13))
	        	    	{
	        	    		if(dk == 8 && dksearch == 0)
	        	    		{
			        	    	if(SearchMAMON(p,ds_mon.node[vitri].MAMH) > 0)
			        	    	{
					        	    strcpy(MonHoc,ds_mon.node[vitri].MAMH);
					        	    cleardevice();
					        	    trang6_5(dsmon,dslop,dscht,check,page,0);
								}	
								else
								{
									MessageBoxA(NULL, "Chua co cau hoi thi cho mon hoc nay!", "Thong bao", MB_OK | MB_ICONINFORMATION);
									trang5(dsmon,dslop,dscht,check,page,8,0);
				        	    }
			        	    }
			        	    if(dk==9 && dksearch==0)
			        	    {
			        	    	strcpy(MaMon,ds_mon.node[vitri].MAMH);
								strcpy(TenMon,ds_mon.node[vitri].TENMH);
								if(SearchMAMON(p,MaMon) > 0)
								{
									MessageBoxA(NULL, "Mon hoc da co cau hoi thi, khong duoc hieu chinh!", "Thong bao", MB_OK | MB_ICONINFORMATION);
									trang5(dsmon,dslop,dscht,check,page,9,0);
								}
								else 
								{
									cleardevice();
									trang5(dsmon,dslop,dscht,check,page,10,0);
								}
							}
							if(dk==11)
							{
								strcpy(MaMon_xoa,ds_mon.node[vitri].MAMH);
								if(SearchMAMON(p,MaMon_xoa) > 0  && (dksearch==0))
								{
									MessageBoxA(NULL, "Mon hoc da co cau hoi thi, khong duoc xoa!", "Thong bao", MB_OK | MB_ICONINFORMATION);
									trang5(dsmon,dslop,dscht,check,page,11,1);
				        	    }
				        	   	else 
				        	    {
				        	    	int result = MessageBoxA(NULL, "Ban co chac muon xoa mon hoc nay?", "XAC NHAN", MB_YESNO | MB_ICONQUESTION);
									if (result == IDYES)
									{	
										Delete_mamon(ds_mon,MaMon_xoa);
										MessageBoxA(NULL, "Xoa mon hoc thanh cong!", "Thong bao", MB_OK | MB_ICONINFORMATION);
										cleardevice();
						        	    trang5(dsmon,dslop,dscht,check,page,2,1);
					        	    }
					        	   	else 
									{
									   		trang5(dsmon,dslop,dscht,check,page,11,1);
									}
								}
							}
							if(dk==13)
							{
								strcpy(MonHoc,ds_mon.node[vitri].MAMH);
					        	cleardevice();
					        	trang4(dsmon,dslop,dscht,check,page,7);
							}
						}
					//HIEU CHINH MON HOC
						if(check==1 && dk==3)
						{
							strcpy(MaMon,ds_mon.node[vitri].MAMH);
							strcpy(TenMon,ds_mon.node[vitri].TENMH);
							if(SearchMAMON(p,MaMon) > 0)
							{
								MessageBoxA(NULL, "Mon hoc da co cau hoi thi, khong duoc hieu chinh!", "Thong bao", MB_OK | MB_ICONINFORMATION);
								trang5(dsmon,dslop,dscht,check,page,3,1);
							}
							else 
							{
								cleardevice();
								trang5(dsmon,dslop,dscht,check,page,10,1);
							}
						}
					//CHON MON HOC DE IN DIEM MON HOC NAY
						if(dk==12)
						{
							strcpy(MonHoc,ds_mon.node[vitri].MAMH);
				        	cleardevice();
				        	trang4(dsmon,dslop,dscht,check,page,7);
						}
			}
		//CAC CHUC NANG...
			if(dk==0||dk==1||dk==10)
			{
		    	if(VT(1250,1400,670,720,x,y))
				{
	         		cleardevice();
	         	//NUT VE TRANG CHU
	         		if(dk==0) trang2(dsmon,dslop,dscht,check);
	         	//NUT SUA MON HOC
	         		if(dk==10)
					{
						MessageBoxA(NULL, "Hieu chinh mon hoc thanh cong!", "Thong bao", MB_OK | MB_ICONINFORMATION);
					 	trang5(dsmon,dslop,dscht,check,page,3,1);
					}
				//NUT THEM MON HOC
         			else
					{
						OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
						string mamon = mh.MAMH;
						string tenmon = mh.TENMH;
						if(check_trung(dsmon, mamon) == 0)
						{
							if (kiemTraChuoiKhacKhoangTrang(mamon)&&kiemTraChuoiKhacKhoangTrang(tenmon))
							{
								if(dsmon.n<=MAX_MH)
								{
								ofstream file;
								file.open("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt",ios::app);	
								file<<endl;
								file<<mamon<<"|"<<tenmon;
								dsmon.n++;
	            				dsmon.node[dsmon.n - 1] = mh;		
								file.close();
								MessageBoxA(NULL, "Them mon hoc thanh cong!", "Thong bao", MB_OK | MB_ICONINFORMATION);
								trang5(dsmon,dslop,dscht,check,page,0,1);
								}
								else 
								{
									MessageBoxA(NULL, "Danh sach mon hoc da day! Danh sach mon hoc khong vuot qua 300", "Thong bao", MB_OK | MB_ICONINFORMATION);
									trang5(dsmon,dslop,dscht,check,page,0,1);
								}
							}
							else 
							{
								MessageBoxA(NULL, "Vui long nhap day du thong tin", "Thong bao", MB_OK | MB_ICONINFORMATION);
								trang5(dsmon,dslop,dscht,check,page,1,1);
							}
						}
						else
						{
							MessageBoxA(NULL, "Mon hoc nay da ton tai!", "Thong bao", MB_OK | MB_ICONINFORMATION);
							trang5(dsmon,dslop,dscht,check,page,1,1);
						}
         			}
         		}
         	}
			if(VT(50,200,110,180,x,y) && dk==4)
			{
			    cleardevice();
        	    trang5(dsmon,dslop,dscht,check,page,0,1);
			}
		//NUT QUA TRANG SAU
			if(VT(900,1050,670,720,x,y) && dk!=4 && ds_mon.n>=(page*7+1))
			{
         		cleardevice();
         		trang5(dsmon,dslop,dscht,check, page+1,dk,1);
         	}
         //NUT QUAY VE TRANG TRUOC	
        	if(VT(700,850,670,720,x,y) && page!=1 && dk!=4)
			{
         		cleardevice();
         		trang5(dsmon,dslop,dscht,check, page-1,dk,1);
         	}
         //NUT THEM	
         	if(VT(90,200,225,280,x,y) && dk==0 && check==1)
			{
         		cleardevice();
         		trung = -1;
            	trang5(dsmon,dslop,dscht,check,page,1,1);
			}
		//NUT XOA
         	if(VT(90,200,375,430,x,y ) && dk==0 && check==1)
			{
         		cleardevice();
            	trang5(dsmon,dslop,dscht,check,page,2,1);
         	}
         //NUT SUA	
         	if(VT(90,200,525,580,x,y) && dk==0 && check==1)
			{
         		cleardevice();
            	trang5(dsmon,dslop,dscht,check,page,3,1);
         	}
        //HIEU CHINH THEO MA MON
         	if(VT(40,350,270,340,x,y) && dk==3)
         	{
         		cleardevice();
            	trang5(dsmon,dslop,dscht,check,page,4,1);
			}
			if(VT(40,490,270,340,x,y) && dk==4)
         	{
				if(SearchMAMON(p,s) > 0)
				{
					trang5(dsmon,dslop,dscht,check,1,4,1);
				}
				else
				{
					trang5(dsmon,dslop,dscht,check,1,5,1);
				}
			}
			if(VT(40,480,270,340,x,y) && dk==5)
			{
					cleardevice();
			    	trang5(dsmon,dslop,dscht,check,1,3,1);
			}
		//HIEU CHINH THEO TEN MON
         	if(VT(40,350,400,470,x,y) && dk==3)
         	{
         		cleardevice();
            	trang5(dsmon,dslop,dscht,check,page,6,1);
			}
			if(VT(40,480,270,340,x,y) && dk==6)
			{
				if(SearchMAMON(p,TimMaMonTheoTenMon(dsmon,s)) > 0)
				{
					trang5(dsmon,dslop,dscht,check,1,6,1);
				}
				else
				{
			        cleardevice();
					trang5(dsmon,dslop,dscht,check,1,7,1);
				}
			}
			if(VT(40,480,270,340,x,y) && dk==7)
			{
				cleardevice();
			    trang5(dsmon,dslop,dscht,check,1,3,1);
			}
		//NUT QUAY LAI
         	if(VT(50,200,670,720,x,y)&&dk!=0)
			{
	         	cleardevice();
	         	if(dk==5||dk==7||dk==9||dk==10) trang5(dsmon,dslop,dscht,check,page,3,1);
	         	if(dk==11) trang5(dsmon,dslop,dscht,check,page,2,1);
	            else trang5(dsmon,dslop,dscht,check,page,0,1);
         	}
        //SEARCH MON HOC
         	if(VT(70,480,130,185,x,y) && (dk==0||dk==2||dk==3||dk==8||dk==9||dk==11||dk==12))
         	{
         		if(dk==0)	trang5(dsmon,dslop,dscht,check,1,8,0);
         		if(dk==8)	trang5(dsmon,dslop,dscht,check,page,8,0);
         		if(dk==3)	trang5(dsmon,dslop,dscht,check,1,9,0);
         		if(dk==9)	trang5(dsmon,dslop,dscht,check,page,9,0);
         		if(dk==2)	trang5(dsmon,dslop,dscht,check,1,11,0);
         		if(dk==11)	trang5(dsmon,dslop,dscht,check,page,11,0);
         		if(dk==12)	trang5(dsmon,dslop,dscht,check,1,13,0);
         		if(dk==13)	trang5(dsmon,dslop,dscht,check,page,13,0);
			}
		//SUA MA MON HOC
			if(VT(400,650,260,320,x,y) && dk==10)
			{
				if(kiemTraChuoiKhacKhoangTrang(s))
				{
					cleardevice();
					trang5(dsmon,dslop,dscht,check,page,10,1);
				}
				else 
				{
					trang5(dsmon,dslop,dscht,check,page,10,1);
				}
			}
		//SUA TEN MON HOC
			if(VT(650,1200,260,320,x,y) && dk==10)
			{
				if(kiemTraChuoiKhacKhoangTrang(s))
				{
						cleardevice();
						trang5(dsmon,dslop,dscht,check,page,10,1);
				}
				else 
				{
					trang5(dsmon,dslop,dscht,check,page,10,1);
				}
			}
}

int id;
//DIEU KHIEN CHUOT TRANG THONG TIN BAI THI CUA SINH VIEN or SUA BAI THI CUA GIAO VIEN
void click_6(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk, int vitriclick, int dk_search)
{
	treeCAUHOITHI dscht_dathi_all;
	OpenFile_DSCHT(dscht_dathi_all,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSCHTdathi.txt");
	treeCAUHOITHI a=Search(dscht_dathi_all,id);
	CAUHOITHI ques;
	strcpy(ques.MAMH,"\0");
	strcpy(ques.NoiDung,"\0");
	strcpy(ques.A,"\0");
	strcpy(ques.B,"\0");
	strcpy(ques.C,"\0");
	strcpy(ques.D,"\0");
	ques.DapAn='\0';
	int x,y;
	int sum;
	int dem;
	if(dk_search==0) dem=CountLineInFile("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");
	else if(dk_search==1) dem=CountLineInFile_TheoMa("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt",MonHoc);
	char tmp;
	int dk_break=0;
	int page_max = dem / 8;
	if (dem % 8 != 0) {
    	page_max++;
	}
	while(dk_break==0){
		sum=190;
		if(kbhit()){
			while(kbhit()){
				tmp=getch();
			}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) 
		{
		clearmouseclick(WM_MOUSEMOVE);
		getmouseclick(WM_LBUTTONDOWN, x, y); 
		    if((VT(1250,1400,670,720,x,y)&&dk==0&&check==1)||(VT(900,1050,670,720,x,y)&&(dk==0||dk==2||dk==3)&&check==1&&(page+1)<=page_max)||(VT(700,850,670,720,x,y)&&page!=1&&(dk==0||dk==2||dk==3)&&check==1)
			||(VT(600,800,700,720,x,y)&&check==2&&dk==0)||(VT(80,230,670,720,x,y)&&check==1&&dk==0)||(VT(90,200,225,280,x,y)&&(dk==0||dk==5)&&check==1)||(VT(50,200,670,720,x,y)&&dk!=0&&check==1)
			||(VT(380,450,670,720,x,y)&&check==1&&dk!=1&&dk!=4&&dk!=5&&dk!=6&&dk_search==1))
			break;
			if(VT(60,280,115,170,x,y)&&dk!=1&&dk!=4&&dk!=5&&dk!=6){
				setcolor(BLACK);
				setbkcolor(LIGHTGREEN);
				NhapMa(15,80,135,MonHoc);
				int ktraMaMH=Duyet_ktraMaMH(dscht,MonHoc);
				if(ktraMaMH==1) break;
				else{
					setcolor(RED);
					setbkcolor(WHITE);
					outtextxy(40,175,"--Khong ton tai ma mon nay!--");
					delay(2000);
					outtextxy(40,175,"                             ");
					setbkcolor(LIGHTCYAN);	
					setcolor(BLACK);
					strcpy(MonHoc,"\0");
					setbkcolor(LIGHTGREEN);
					outtextxy(80,135,"                 ");
					setbkcolor(WHITE);
				}
			}
         	if(VT(90,200,375,430,x,y)&&(dk==0||dk==5)&&check==1)
			{//NUT XOA
				if(dk==0){
					break;	
				}
				if (dk==5){
					if(a==NULL){
						break;		
					}
					else{
						setcolor(RED);
						setbkcolor(WHITE);
						outtextxy(350,700,"--Cau hoi da duoc thi! Khong the xoa!--");
						delay(2000);
						outtextxy(350,700,"                                       ");
						setbkcolor(LIGHTCYAN);	
						setcolor(BLACK);
					}
				}
         	}
         	if(VT(90,200,525,580,x,y)&&(dk==0||dk==5)&&check==1)
			{//NUT SUA
         		if(dk==0){
         			break;	
				}
				if(dk==5){
					if(a==NULL){
						break;
					}
					else{
						setcolor(RED);
						setbkcolor(WHITE);
						outtextxy(350,700,"--Cau hoi da duoc thi! Khong the sua!--");
						delay(2000);
						outtextxy(350,700,"                                       ");
						setbkcolor(LIGHTCYAN);	
						setcolor(BLACK);
					}
				}
         	}
			if(dk==6&&check==1)
			{//NUT HOI BAN CO CHAC CHAN MUON XOA
				if(VT(1050,1200,670,720,x,y)){//NUT NO
					break;	
				}
				if(VT(1240,1390,670,720,x,y)){//NUT YES
					remove_id(id,dscht);
					SaveFile_DSCHT(dscht,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");
					break;
				}
			}
			if(dk==1 && check==1){//CUA SO THEM CHT
				setbkcolor(LIGHTCYAN);
				bool idExists;
				if(VT(100,500,60,120,x,y)){
					NhapMa(15,120,80,ques.MAMH);
				}
				if(VT(100,1430,180,240,x,y)){
					NhapNoiDung(220,200,ques.NoiDung);
				}
				if(VT(100,1430,300,340,x,y)){
					NhapCauTraLoi(100,160,300,ques.A);
				}
				if(VT(100,1430,340,380,x,y)){
					NhapCauTraLoi(100,160,340,ques.B);
				}
				if(VT(100,1430,380,420,x,y)){
					NhapCauTraLoi(100,160,380,ques.C);
				}
				if(VT(100,1430,420,460,x,y)){
					NhapCauTraLoi(100,160,420,ques.D);
				}
				if(VT(600,800,60,120,x,y)){
					NhapDapAn(640,80,ques.DapAn);
				}
				if(VT(1240,1390,670,720,x,y)){
					if(strcmp(ques.MAMH,"\0")!=0&&strcmp(ques.NoiDung,"\0")!=0&&strcmp(ques.A,"\0")!=0&&strcmp(ques.B,"\0")!=0&&strcmp(ques.C,"\0")!=0&&strcmp(ques.D,"\0")!=0&&ques.DapAn!='\0'){
						if(TimMaMon(dsmon,ques.MAMH)!=-1){
							idExists = true;
		    				srand(time(NULL));
		    				int dk_day=1;
		    				while (idExists&&dk_day<=1000) {
						        ques.Id = rand() % 1000 + 1; 
						        idExists = checkId(dscht, ques.Id);
						        dk_day++;
						    }
						    if(dk_day<=1000){
						    	InsertNode(dscht,ques);
						    	SaveFile_DSCHT(dscht,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");
								break;	
							}
							else{
								setcolor(RED);
								setbkcolor(WHITE);
								outtextxy(350,700,"--DS cau hoi thi da day!Khong the them!--");
								delay(2000);
								outtextxy(350,700,"                                         ");
								setbkcolor(LIGHTCYAN);	
								setcolor(BLACK);
							}	
						}
						else{
							setcolor(RED);
							setbkcolor(WHITE);
							outtextxy(350,700,"--Ma mon khong ton tai! Vui long nhap lai!--");
							delay(2000);
							outtextxy(350,700,"                                            ");
							setbkcolor(LIGHTCYAN);	
							setcolor(BLACK);
						}
					}
					else{
						setcolor(RED);
						setbkcolor(WHITE);
						outtextxy(350,700,"--Nhap thieu thong tin! Vui long bo sung!--");
						delay(2000);
						outtextxy(350,700,"                                           ");
						setbkcolor(LIGHTCYAN);	
						setcolor(BLACK);
					}
				}
			}
			if(VT(40,300,240,300,x,y)&&dk==2)//CUA SO XOA CHT
			{
				OpenFile_DSCHT(dscht,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");
				NhapId(45,265, id);
				treeCAUHOITHI p;
				p=Search(dscht,id);
				if(p!=NULL){
					if(a==NULL){
						remove_id(id,dscht);
						SaveFile_DSCHT(dscht,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");
						break;		
					}
					else{
						setcolor(RED);
						setbkcolor(WHITE);
						outtextxy(40,340,"Cau hoi da thi!");
						outtextxy(40,360,"Khong the xoa!");
						delay(2000);
						outtextxy(40,340,"               ");
						outtextxy(40,360,"               ");
						setbkcolor(LIGHTCYAN);	
						setcolor(BLACK);
						outtextxy(45,265,"        ");
						id=NULL;
						continue;
					}	
				}
				else{
			   		setcolor(RED);
					setbkcolor(WHITE);
					outtextxy(40,340,"ID khong ton tai!");
					outtextxy(40,360,"Vui long nhap lai!");
					delay(2000);
					outtextxy(40,340,"                 ");
					outtextxy(40,360,"                  ");
					setbkcolor(LIGHTCYAN);	
					setcolor(BLACK);
					outtextxy(45,265,"        ");
					id=NULL;
					continue;
				}
			}
			if(VT(40,300,240,300,x,y)&&dk==3){//CUA SO SUA CHT
				OpenFile_DSCHT(dscht,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");
				NhapId(45,265,id);
				treeCAUHOITHI p=Search(dscht, id);
				if(p!=NULL){
					if(a==NULL){
						break;		
					}
					else{
						setcolor(RED);
						setbkcolor(WHITE);
						outtextxy(40,340,"Cau hoi da thi!");
						outtextxy(40,360,"Khong the sua!");
						delay(2000);
						outtextxy(40,340,"               ");
						outtextxy(40,360,"               ");
						setbkcolor(LIGHTCYAN);	
						setcolor(BLACK);
						outtextxy(45,265,"        ");
						id=NULL;
						continue;
					}		
				}
				else{
			   		setcolor(RED);
					setbkcolor(WHITE);
					outtextxy(40,340,"ID khong ton tai!");
					outtextxy(40,360,"Vui long nhap lai!");
					delay(2000);
					outtextxy(40,340,"                 ");
					outtextxy(40,360,"                  ");
					setbkcolor(LIGHTCYAN);	
					setcolor(BLACK);
					outtextxy(45,265,"        ");
					id=NULL;
					continue;
				}
			}
			if(dk==4 && check==1){//CUA SO SUA CHT
				setbkcolor(LIGHTCYAN);
				setcolor(BLACK);
				treeCAUHOITHI p=Search(dscht, id);
				if(VT(540,940,60,120,x,y)){
					NhapMa(15,550,80,p->QUES.MAMH);
				}
				if(VT(100,1430,180,240,x,y)){
					NhapNoiDung(220,200,p->QUES.NoiDung);
				}
				if(VT(100,1430,300,340,x,y)){
					NhapCauTraLoi(100,160,300,p->QUES.A);
				}
				if(VT(100,1430,340,380,x,y)){
					NhapCauTraLoi(100,160,340,p->QUES.B);
				}
				if(VT(100,1430,380,420,x,y)){
					NhapCauTraLoi(100,160,380,p->QUES.C);
				}
				if(VT(100,1430,420,460,x,y)){
					NhapCauTraLoi(100,160,420,p->QUES.D);
				}
				if(VT(980,1180,60,120,x,y)){
					NhapDapAn(1070,80,p->QUES.DapAn);
				}
				if(VT(1240,1390,670,720,x,y)){
					if(strcmp(p->QUES.MAMH,"\0")!=0&&strcmp(p->QUES.NoiDung,"\0")!=0&&strcmp(p->QUES.A,"\0")!=0&&strcmp(p->QUES.B,"\0")!=0&&strcmp(p->QUES.C,"\0")!=0&&strcmp(p->QUES.D,"\0")!=0&&p->QUES.DapAn!='\0'){
						if(TimMaMon(dsmon,p->QUES.MAMH)!=-1){
						    SaveFile_DSCHT(dscht,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");
							break;		
						}
						else{
							setcolor(RED);
							setbkcolor(WHITE);
							outtextxy(350,700,"--Ma mon khong ton tai! Vui long nhap lai!--");
							delay(2000);
							outtextxy(350,700,"                                            ");
							setbkcolor(LIGHTCYAN);	
							setcolor(BLACK);
						}
					}
					else{
						setcolor(RED);
						setbkcolor(WHITE);
						outtextxy(350,700,"--Nhap thieu thong tin! Vui long bo sung!--");
						delay(2000);
						outtextxy(350,700,"                                           ");
						setbkcolor(LIGHTCYAN);	
						setcolor(BLACK);
					}
				}
			}
			for(int i=(page-1)*8; i<page*8 && i<dem ; i++)
			{
				if(VT(1300,1445,sum,sum+60,x,y)&&dk==0&&check==1){
						vitriclick=i;
						dk_break=1;
						break;
				}
				if(VT(1300,1445,sum,sum+60,x,y)&&dk==2&&check==1){
						vitriclick=i;
						InDSCHT(dscht,page,vitriclick,dk,id);
						a=Search(dscht_dathi_all,id);
						if(a==NULL){
							dk_break=1;
							break;		
						}
						else{
							setcolor(RED);
							setbkcolor(WHITE);
							outtextxy(40,340,"Cau hoi da thi!");
							outtextxy(40,360,"Khong the xoa!");
							delay(2000);
							outtextxy(40,340,"               ");
							outtextxy(40,360,"               ");
							setbkcolor(LIGHTCYAN);	
							setcolor(BLACK);
							break;
						}		
				}
				if(VT(1300,1445,sum,sum+60,x,y)&&dk==3&&check==1){
						vitriclick=i;
						InDSCHT(dscht,page,vitriclick,dk,id);
						a=Search(dscht_dathi_all,id);
						if(a==NULL){
							dk_break=1;
							break;		
						}
						else{
							setcolor(RED);
							setbkcolor(WHITE);
							outtextxy(40,340,"Cau hoi da thi!");
							outtextxy(40,360,"Khong the sua!");
							delay(2000);
							outtextxy(40,340,"               ");
							outtextxy(40,360,"               ");
							setbkcolor(LIGHTCYAN);	
							setcolor(BLACK);
							break;
						}	
				}
				sum += 60;
			}
        }
        delay(100);
    }
    if(VT(380,450,670,720,x,y)&&check==1&&dk!=1&&dk!=4&&dk!=5&&dk!=6&&dk_search==1){
    	cleardevice();
    	strcpy(MonHoc,"\0");
    	trang6(dsmon,dslop,dscht,check,1,dk,-1,0);
	}
    if(VT(60,280,115,170,x,y)&&dk!=1&&dk!=4&&dk!=6&&dk!=5){
		cleardevice();
		trang6(dsmon,dslop,dscht,check,1,dk,-1,1);
	}
    if(VT(1250,1400,670,720,x,y)&&dk==0&&check==1)
	{//NUT VE TRANG CHU
        cleardevice();
        trang2(dsmon,dslop,dscht,check);
    }
    if(VT(900,1050,670,720,x,y)&&(dk==0||dk==2||dk==3)&&check==1&&(page+1)<=(dem/8+1))
	{//NUT QUA TRANG SAU
        cleardevice();
        trang6(dsmon,dslop,dscht,check,page+1,dk,-1,dk_search);
    }
	if(VT(700,850,670,720,x,y)&&page!=1&&(dk==0||dk==2||dk==3)&&check==1)
	{//NUT QUAY LAI TRANG TRUOC
        cleardevice();
        trang6(dsmon,dslop,dscht,check,page-1,dk,-1,dk_search);
    }
    if(VT(600,800,700,720,x,y)&&check==2&&dk==0)
	{//NUT NHAN DE LAM BAI THI CUA SINH VIEN
        cleardevice();
        trang6_5(dsmon,dslop,dscht,check,page,1);
    }
    if(VT(80,230,670,720,x,y)&&check==1&&dk==0)
	{//NUT THI THU CUA GIAO VIEN
        cleardevice();
        strcpy(MonHoc,"\0");
        trang6_5(dsmon,dslop,dscht,check,page,1);
	}
	if(VT(90,200,225,280,x,y)&&(dk==0||dk==5)&&check==1)
	{//NUT THEM
        cleardevice();
        trang6(dsmon,dslop,dscht,check,page,1,-1,dk_search);
	}
    if(VT(90,200,375,430,x,y)&&(dk==0||dk==5)&&check==1)
	{//NUT XOA
		if(dk==0){
			cleardevice();
            trang6(dsmon,dslop,dscht,check,page,2,-1,dk_search);	
		}
		if (dk==5){
			cleardevice();
			trang6(dsmon,dslop,dscht,check,page,6,vitriclick,dk_search);		
		}
	}
    if(VT(90,200,525,580,x,y)&&(dk==0||dk==5)&&check==1)
	{//NUT SUA
        if(dk==0){
        	cleardevice();
            trang6(dsmon,dslop,dscht,check,page,3,-1,dk_search);	
		}
		if(dk==5){
			cleardevice();
			trang6(dsmon,dslop,dscht,check,page,4,-1,dk_search);		
		}
    }
    if(VT(50,200,670,720,x,y)&&dk!=0&&check==1)
	{//NUT QUAY LAI
        if(dk==4){
         	cleardevice();
         	OpenFile_DSCHT(dscht,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");	
         	trang6(dsmon,dslop,dscht,check,page,3,-1,dk_search);
		}
        else{
         	cleardevice();	
         	trang6(dsmon,dslop,dscht,check,page,0,-1,dk_search);
		} 
	}
	if(dk==6&&check==1)
	{
		if(VT(1050,1200,670,720,x,y)){//NUT NO
			cleardevice();
			trang6(dsmon,dslop,dscht,check,page,2,-1,dk_search);	
		}
		if(VT(1240,1390,670,720,x,y)){//NUT YES
			cleardevice();
			trang6(dsmon,dslop,dscht,check,page,2,-1,dk_search);
		}
	}
	if(VT(1240,1390,670,720,x,y)&&dk==1 && check==1){//CUA SO THEM CHT
		cleardevice();
		trang6(dsmon,dslop,dscht,check,page,1,vitriclick,dk_search);		
	}
	if(VT(40,300,240,300,x,y)&&dk==2)//CUA SO XOA CHT
	{
		cleardevice();
		trang6(dsmon,dslop,dscht,check,page,2,-1,dk_search);		
	}			
	if(VT(40,300,240,300,x,y)&&dk==3)
	{//CUA SO SUA CHT
		cleardevice();
		trang6(dsmon,dslop,dscht,check,page,4,-1,dk_search);		
	}
	if(VT(1240,1390,670,720,x,y)&&dk==4 && check==1){//CUA SO SUA CHT
		cleardevice();
		trang6(dsmon,dslop,dscht,check,page,3,-1,dk_search);		
	}
	if(VT(1300,1445,190,670,x,y)&&check==1){
		if(dk==0){
			cleardevice();
			trang6(dsmon,dslop,dscht,check,page,5,vitriclick,dk_search);
		}
		else if(dk==2){
			cleardevice();
			trang6(dsmon,dslop,dscht,check,page,6,vitriclick,dk_search);		
		}
		else if(dk==3){
			cleardevice();
			trang6(dsmon,dslop,dscht,check,page,4,vitriclick,dk_search);		
		}		
	}
}

//DIEU KHIEN CHUOT TRANG LAM BAI THI
void click_7(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, treeCAUHOITHI p,int &check, int page,char MonHoc[],int SoCHT,int phut,int a[],char dapan[])
{
	int x,y;
	while(1)
	{
		outtextxy(1360,220,CharToString(dapan[page-1]));
		setbkcolor(WHITE);	
		if(tra_ve == 1)
		{
			tra_ve = 0;
			cleardevice();
			trang8(dsmon,dslop,dscht,p,check,page,MonHoc,SoCHT,a,dapan);
		} 
		if (ismouseclick(WM_LBUTTONDOWN)) 
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);	
			clearmouseclick(WM_MOUSEMOVE);
			if((VT(600,700,670,720,x,y)&&page<SoCHT)||VT(1200,1350,670,720,x,y)||(VT(300,400,670,720,x,y)&&page!=1))
           	break;
	        if(VT(120,300,350,370,x,y))
		    {
		       	dapan[page-1]='A';
			}
			if(VT(120,300,380,400,x,y))
			{
				dapan[page-1]='B';
			}
			if(VT(120,300,410,430,x,y))
			{
				dapan[page-1]='C';
			}
			if(VT(120,300,440,460,x,y))
			{
				dapan[page-1]='D';
			}
        }
    	delay(100);
	}
	if(VT(600,700,670,720,x,y)&&page<SoCHT)
	{//NUT QUA CAU SAU
        vehcn(105,205,1445,745,BLACK,WHITE,BLACK,"\0",1);
        trang7(dsmon,dslop,dscht,p,check,page+1,MonHoc,SoCHT,phut,a,dapan);
	}
	if(VT(300,400,670,720,x,y)&&page!=1)
	{//NUT VE CAU TRUOC
    	vehcn(105,205,1445,745,BLACK,WHITE,BLACK,"\0",1);
        trang7(dsmon,dslop,dscht,p,check,page-1,MonHoc,SoCHT,phut,a,dapan);
	}
	if(VT(1200,1350,670,720,x,y))
	{//NUT NOP BAI // thoat khoi trang xem bai thi
		cleardevice();
	    out = 1;
	    trang8(dsmon,dslop,dscht,p,check,page,MonHoc,SoCHT,a,dapan);
	}
}

//DIEU KHIEN CHUOT TRANG KET THUC BAI THI 
void click_8(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check)
{
	int x,y;
	while(1){
		if (ismouseclick(WM_LBUTTONDOWN)) 
		{
			clearmouseclick(WM_MOUSEMOVE);
			getmouseclick(WM_LBUTTONDOWN, x, y);
        	if(VT(1300,1450,670,720,x,y))
			{//NUT QUAY LAI TRANG CHU
       			break;
    		}
    	}
      delay(100);
   	}
   	if(VT(1300,1450,670,720,x,y))
	{//NUT QUAY LAI TRANG CHU
        cleardevice();
        trang2(dsmon,dslop,dscht,check);
    }
}

void click_9(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, treeCAUHOITHI p,int &check, int page,char MonHoc[],int SoCH,int a[],char dapan[])
{
	int x,y;
	while(1)
	{
		//outtextxy(1360,220,CharToString(dapan[page-1]));	
		if (ismouseclick(WM_LBUTTONDOWN)) 
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);	
			clearmouseclick(WM_MOUSEMOVE);
			if((VT(600,700,670,720,x,y)&&page<SoCH)||(VT(300,400,670,720,x,y)&&page!=1)||VT(1200,1350,670,720,x,y))
			break;
        }
    	delay(100);
	}
	if(VT(600,700,670,720,x,y)&&page<SoCH)
	{//NUT QUA CAU SAU
        vehcn(105,205,1445,745,BLACK,WHITE,BLACK,"\0",1);
        trang9_in(dsmon,dslop,dscht,p,check,page+1,MonHoc,SoCH,a,dapan);
	}
	else if(VT(300,400,670,720,x,y)&&page!=1)
	{//NUT VE CAU TRUOC
    //	cleardevice();
        vehcn(105,205,1445,745,BLACK,WHITE,BLACK,"\0",1);
        trang9_in(dsmon,dslop,dscht,p,check,page-1,MonHoc,SoCH,a,dapan);
	}
	else if(VT(1200,1350,670,720,x,y))
	{// thoat khoi trang xem bai thi
		cleardevice();
	    trang4(dsmon,dslop,dscht,check,1,5);	
	}
}

void KhungNgoai()
{
	setcolor(BLACK);
   	setbkcolor(WHITE);
   	settextstyle(0,HORIZ_DIR,2);
   	char name[50]="Chao: ";
   	if(check == 1)
	{
		strcat(name,tendangnhap);
		vehcn(20,0,200,80,BLACK,WHITE,WHITE,name,1);
	}	

   	if(check == 2)
   	{
	   	strcat(name,psv_login->sv.HO);
	   	strcat(name," ");
	   	strcat(name,psv_login->sv.TEN);
	   	strcat(name," - ");
		strcat(name,psv_login->sv.MASV);
		vehcn(40,0,400,80,BLACK,WHITE,WHITE,name,1);	
   } 
   floodfill(100,100,WHITE);
   setlinestyle(SOLID_LINE, 1, 3);
   rectangle(15, 20, 1500, 775);
   rectangle(10, 15, 1505, 780);
}

void Khung_them_xoa_sua(int &check)
{
	if(check==1){
	vehcn(90,225,200,280,BLACK,LIGHTGREEN,BLACK,"THEM",1);
	vehcn(90,375,200,430,BLACK,LIGHTGREEN,BLACK,"XOA",1);
	vehcn(90,525,200,580,BLACK,LIGHTGREEN,BLACK,"SUA",1);
	}
	setbkcolor(WHITE);
}

void Khung_ho_tro(int page,int ht)
{
	//VT(1250,1400,670,720,x,y)
	if(page==1){
		//khung trang chu
		if(ht==1)
		{
			vehcn(1250,670,1400,720,BLACK,LIGHTRED,BLACK,"Trang chu",1);
		}
		//Khung trang sau
		vehcn(900,670,1050,720,BLACK,LIGHTCYAN,BLACK,"Trang sau",1);
		setcolor(RED);
		setbkcolor(WHITE);
		outtextxy(950,730,"--->");	
		outtextxy(870,730,inttochar(page));
	} else{
		//khung trang chu
		if(ht==1)
		{
		vehcn(1250,670,1400,720,BLACK,LIGHTRED,BLACK,"Trang chu",1);
		}
		//Khung trang sau
		vehcn(700,670,850,720,BLACK,LIGHTCYAN,BLACK,"Trang truoc",1);
		vehcn(900,670,1050,720,BLACK,LIGHTCYAN,BLACK,"Trang sau",1);
		setcolor(RED);
		setbkcolor(WHITE);
		outtextxy(950,730,"--->");
		outtextxy(750,730,"<---");
		outtextxy(870,730,inttochar(page));
	}
}

void Khung_ho_tro_back(int page,int ht)
{
	//VT(1250,1400,670,720,x,y)
	if(page==1){
		//khung quay lai
		if(ht==1)
		{
			vehcn(1250,670,1400,720,BLACK,LIGHTRED,BLACK,"Quay lai",1);
		}
		//Khung trang sau
		vehcn(900,670,1050,720,BLACK,LIGHTCYAN,BLACK,"Trang sau",1);
		setcolor(RED);
		setbkcolor(WHITE);
		outtextxy(950,730,"--->");	
		outtextxy(870,730,inttochar(page));
	} else{
		//khung trang chu
		if(ht==1)
		{
		vehcn(1250,670,1400,720,BLACK,LIGHTRED,BLACK,"Quay lai",1);
		}
		//Khung trang sau
		vehcn(700,670,850,720,BLACK,LIGHTCYAN,BLACK,"Trang truoc",1);
		vehcn(900,670,1050,720,BLACK,LIGHTCYAN,BLACK,"Trang sau",1);
		setcolor(RED);
		setbkcolor(WHITE);
		outtextxy(950,730,"--->");
		outtextxy(750,730,"<---");
		outtextxy(870,730,inttochar(page));
	}
}

void Khung_ho_tro_cau_hoi_thi(int page){
	if(page==1){
		vehcn(600,670,720,710,BLACK,LIGHTCYAN,BLACK,"Cau sau",1);
		setcolor(RED);
		setbkcolor(WHITE);
		outtextxy(625,720,"--->");
		outtextxy(490,720,inttochar(page));
	} else{
		vehcn(300,670,420,710,BLACK,LIGHTCYAN,BLACK,"Cau truoc",1);
		vehcn(600,670,720,710,BLACK,LIGHTCYAN,BLACK,"Cau sau",1);
		setcolor(RED);
		setbkcolor(WHITE);
		outtextxy(325,720,"<---");
		outtextxy(625,720,"--->");
		outtextxy(490,720,inttochar(page));
	}
	setbkcolor(WHITE);
}

void huong_dan_su_dung(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check)
{
	vehcn(0,0,1530,800,BLACK,WHITE,WHITE,"\0",1);
	vehcn(0,0,1530,200,BLACK,WHITE,WHITE,"HUONG DAN SU DUNG",5);
	vehcn(1250,670,1400,720,BLACK,LIGHTRED,BLACK,"TRANG CHU",1);
	KhungNgoai();
	Docfile_huongdansudung();
	click_8(dsmon,dslop,dscht,check);
	getch();
	closegraph;
}

//TRANG IN BAI THI
void trang9_khung(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, treeCAUHOITHI p,int &check, int page,char MonHoc[],int SoCH,int a[], char dapan[], char diemthi[]){
	vehcn(0,0,1530,800,BLACK,WHITE,BLACK,"\0",1);
	KhungNgoai();
	setbkcolor(WHITE);
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(550,40,"BAI THI");	
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	outtextxy(100,100,"MON THI:");
	outtextxy(100,150,"DIEM: ");
	outtextxy(180,150,diemthi);
	int vitrimonhoc=TimMaMon(dsmon,MonHoc);
	outtextxy(200,100, dsmon.node[vitrimonhoc].TENMH);
	trang9_in(dsmon,dslop,dscht,p,check,page,MonHoc,SoCH,a,dapan);
}

void trang9_in(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, treeCAUHOITHI p,int &check, int page,char MonHoc[],int SoCH,int a[], char dapan[]){
	setcolor(BLACK);
	rectangle(100,200,1450,750);
	rectangle(105,205,1445,745);
	line(100,650,1450,650);
	line(100,645,1450,645);
	line(1200,200,1200,650);
	line(1195,200,1195,650);	
	outtextxy(1220,220,"Da chon:");
	outtextxy(1220,280,"Dap an dung:");
	treeCAUHOITHI q=Search(dscht,a[page-1]);
	outtextxy(1350,280,CharToString(q->QUES.DapAn));
	vehcn(1200,670,1350,720,BLACK,LIGHTGREEN,BLACK,"Tro ve",1);
	setbkcolor(WHITE);
    Khung_ho_tro_cau_hoi_thi(page);
    InCauHoi(p,page,SoCH,a, 1);
    click_9(dsmon,dslop,dscht,p,check, page, MonHoc,SoCH,a,dapan);
	closegraph();
}

//TRANG KET THUC BAI THI
void trang8(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, treeCAUHOITHI p,int &check, int page,char MonHoc[],int SoCHT,int a[],char dapan[])
{
	treeCAUHOITHI dscht_dathi=NULL;
	treeCAUHOITHI dscht_dathi_all=NULL;
	char s[100];
	if(check==2){
		strcpy(s,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\Baithi\\");
		strcat(s,tendangnhap);
		strcat(s,".txt");
		OpenFile_DSCHT(dscht_dathi,s);
		OpenFile_DSCHT(dscht_dathi_all,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSCHTdathi.txt");
	}
	float diem=0;
	for(int i=0; i<SoCHT; i++){
		treeCAUHOITHI q=Search(p,a[i]);
		if(q->QUES.DapAn==dapan[i]) diem+=1;
		if(check==2){
			InsertNode(dscht_dathi_all,q->QUES);
			q->QUES.DapAn=dapan[i];
			InsertNode(dscht_dathi,q->QUES);	
		}
	}
	diem=(diem/(float)SoCHT)*10;
	diem=roundFloat(diem,2);
	//luu bai thi vao file
	if(check==2){
		SaveFile_DSCHT(dscht_dathi_all,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSCHTdathi.txt");
		SaveFile_DSCHT(dscht_dathi,s);
	} 
	KhungNgoai();
	//khung trang chu
	setbkcolor(WHITE);
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	rectangle(400,200,1100,650);
	rectangle(405,205,1095,645);
	outtextxy(550,100,"KET THUC BAI THI");
	outtextxy(420,230,"Diem cua ban:");
	char tongdiem[5];
	snprintf(tongdiem, sizeof(tongdiem), "%.2f", diem);
	outtextxy(420,300,tongdiem);
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	vehcn(1300,670,1450,720,BLACK,LIGHTRED,BLACK,"Trang chu",1);
	setbkcolor(WHITE);
	if(check == 2) InputDiem(psv_login->sv.MASV,dslop.node[IndexClass]->MALOP,MonHoc,diem);
    click_8(dsmon,dslop,dscht,check);
	closegraph;
}

void trang7_tach(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, treeCAUHOITHI p,int &check, int page,char MonHoc[],int SoCHT,int phut,int a[], char dapan[])
{
	List_MH mon;
	OpenFile_DSMH(mon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
	out = 0;
	vehcn(0,0,1530,800,BLACK,WHITE,BLACK,"\0",1);
	setbkcolor(WHITE);
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(550,40,"THI TRAC NGHIEM");
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	outtextxy(100,100,"MON THI:");
	outtextxy(100,150,"THOI GIAN LAM BAI: ");
	int vitrimonhoc=TimMaMon(mon,MonHoc);
	outtextxy(200,100,mon.node[vitrimonhoc].TENMH);
	thread cl(countdownClock,phut,0);
	trang7(dsmon,dslop,dscht,p,check,page,MonHoc,SoCHT,phut,a,dapan);	
}

//TRANG LAM BAI THI
void trang7(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, treeCAUHOITHI p,int &check, int page,char MonHoc[],int SoCHT,int phut, int a[], char dapan[])
{
//	vehcn(100,650,1450,750,BLACK,LIGHTGRAY,BLACK,"\0",1);
	setbkcolor(WHITE);
	setcolor(BLACK);
	InCauHoi(p,page,SoCHT,a, 0);
	rectangle(100,200,1450,750);
	rectangle(105,205,1445,745);
	line(100,650,1450,650);
	line(100,645,1450,645);
	line(1200,200,1200,650);
	line(1195,200,1195,650);
	outtextxy(1220,220,"Ban da chon:");
//	vehcn(105,650,1445,745,BLACK,LIGHTGRAY,BLACK,"\0",1);
//	vehcn(1200,205,1445,645,BLACK,LIGHTGRAY,BLACK,"\0",1);
	vehcn(1200,670,1350,720,BLACK,LIGHTGREEN,BLACK,"Nop bai",1);
//	setbkcolor(LIGHTGRAY);
	setcolor(BLACK);
//	outtextxy(1220,220,"Ban da chon:");
	setbkcolor(WHITE);
    Khung_ho_tro_cau_hoi_thi(page);
    click_7(dsmon,dslop,dscht,p,check, page, MonHoc,SoCHT,phut,a,dapan);
	closegraph();
}

void trang6_5(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page,int dk)
{
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(100,100,BLACK);
	setbkcolor(WHITE);
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	vehcn(0,0,1530,100,BLACK,WHITE,WHITE,"THI TRAC NGHIEM",5);
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	vehcn(950,115,1195,175,BLACK,LIGHTGREEN,BLACK,"DANH SACH MON HOC",1);
	if(check==2)	vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
	if(check==1)	vehcn(50,670,300,720,BLACK,LIGHTGREEN,BLACK,"DANH SACH CAU HOI THI",1);
	if(dk==0)
	{
		setbkcolor(WHITE);
		outtextxy(320+textwidth("Nhap mon ban muon thi: "),135,MonHoc);
	}
	setbkcolor(WHITE);
	rectangle(300,110,1200,310);
	rectangle(305,115,1195,305);
	outtextxy(320,135,"Nhap mon ban muon thi: ");
	line(300,180,1200,180);
	line(300,175,1200,175);
	outtextxy(320,200,"Nhap so cau hoi ban muon thi: ");
	line(300,250,1200,250);
	line(300,245,1200,245);
	outtextxy(320,265,"Nhap so phut ban muon thi: ");
	rectangle(400,330,1100,650);
	line(400,400,1100,400);
    settextstyle(BOLD_FONT,HORIZ_DIR,1);
	outtextxy(600,350,"THONG TIN SINH VIEN");
	if(check==2)
	{
		char HoTen[62];
		strcpy(HoTen,psv_login->sv.HO);
		strcat(HoTen," ");
		strcat(HoTen,psv_login->sv.TEN);
		setbkcolor(WHITE);
		outtextxy(450,442,"Ho va ten:");
	    outtextxy(450,506,"MSSV:");
	    outtextxy(450,570,"Lop:");
	    outtextxy(450+textwidth("Ho va ten: "),442,HoTen);
	    outtextxy(450+textwidth("MSSV: "),506,psv_login->sv.MASV);
	    outtextxy(450+textwidth("Lop: "),570,dslop.node[IndexClass]->TENLOP);
	}
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	setcolor(BLUE);
	outtextxy(600,700,"Nhan chuot de bat dau thi...");
	int phut=0,SoCHT=0;
	string tmp;
	while(1)
	{
		if(kbhit())
		{
			while(kbhit())
			{
				tmp = getch();									
			}			
		}
		if (ismouseclick(WM_LBUTTONDOWN)) 
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);	
			clearmouseclick(WM_MOUSEMOVE);
			setcolor(BLACK);
			if(VT(950,1195,115,175,x,y)||(VT(50,200,670,720,x,y)&&check==2)||(VT(50,300,670,720,x,y)&&check==1))
			break;
			//Chon mon thi
			if(VT(305,945,115,175,x,y))
			{
				treeCAUHOITHI p=NULL;
        	    OpenFile_DSCHT(p,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");
				setcolor(BLACK);
				NhapMa(50,320+textwidth("Nhap mon ban muon thi: "),135,MonHoc);
				if(kiemTraChuoiKhacKhoangTrang(MonHoc)==0)
					MessageBoxA(NULL, "Vui long nhap day du thong tin!", "Thong bao", MB_OK | MB_ICONINFORMATION);
					
				if(check_trung(dsmon,MonHoc) == 0 && kiemTraChuoiKhacKhoangTrang(MonHoc))
					MessageBoxA(NULL, "Mon hoc khong ton tai!", "Thong bao", MB_OK | MB_ICONINFORMATION);
						
				if(SearchMAMON(p,MonHoc) == 0 && kiemTraChuoiKhacKhoangTrang(MonHoc) && check_trung(dsmon,MonHoc)) 
					MessageBoxA(NULL, "Chua co cau hoi thi cho mon hoc nay!", "Thong bao", MB_OK | MB_ICONINFORMATION);	 
					
				if(check==2 && CheckDaThi(psv_login,MonHoc) == 1)
				{
					MessageBoxA(NULL, "Mon hoc da thi!", "Thong bao", MB_OK | MB_ICONINFORMATION);
					continue;
				}
			}
			if(VT(305,1195,175,245,x,y))
			{
				SoCHT = 0;
				treeCAUHOITHI p=NULL;
        	    OpenFile_DSCHT(p,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");
				NhapCHT_phut(2,320 + textwidth("Nhap so cau hoi ban muon thi: "),200,SoCHT,50);
				if(SearchMAMON(p,MonHoc) < SoCHT)
				{
					MessageBoxA(NULL, "So cau hoi thi vuot qua so cau co the co!", "Thong bao", MB_OK | MB_ICONINFORMATION);
					outtextxy(320 + textwidth("Nhap so cau hoi ban muon thi: "),200,"       ");
				}
			}
			if(VT(305,1195,245,305,x,y))
			{
				phut = 0;
				NhapCHT_phut(2,320+textwidth("Nhap so phut ban muon thi: "),265,phut,60);
				if(phut < 1)
				{
					MessageBoxA(NULL, "So phut khong hop le!", "Thong bao", MB_OK | MB_ICONINFORMATION);
//					outtextxy(320+textwidth("Nhap so phut ban muon thi: "),265,"   ");
				}
			}	
			if(VT(600,600+textwidth("Nhan de bat dau thi..."),700,720,x,y)&&strlen(MonHoc)!=0&&phut!=0 &&SoCHT!=0)
			{ 
				if(check==2 && CheckDaThi(psv_login,MonHoc) == 1)
				{
					MessageBoxA(NULL, "Mon hoc da thi!", "Thong bao", MB_OK | MB_ICONINFORMATION);
					continue;
				}
				break; 
			}
		}
		delay(100);
	}
	if(VT(950,1195,115,175,x,y))
	{
		cleardevice();
		trang5(dsmon,dslop,dscht,check,page,0,1);
	}
	if(VT(50,300,670,720,x,y)&&check==1)
	{
		cleardevice();
		trang6(dsmon,dslop,dscht,check,1,0,-1,0);
	}
	if(VT(50,200,670,720,x,y)&&check==2)
	{
		cleardevice();
		trang2(dsmon,dslop,dscht,check);
	}
	if(VT(600,600+textwidth("Nhan de bat dau thi..."),700,720,x,y)&&strlen(MonHoc)!=0&&phut!=0 &&SoCHT!=0)
	{ 
		treeCAUHOITHI p=NULL;
		OpenFile_DSCHT(p,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");
		int CHTmax=0;
		int*values=new int[10000];
		Inorder(p,values,CHTmax,MonHoc);
		if(CHTmax>=SoCHT){
			int a[SoCHT];
			char dapan[SoCHT];
			for(int i=0; i<SoCHT; i++){
				dapan[i]='X';
			}
					generateArr(values,a,SoCHT,CHTmax);
					cleardevice();
					cout<<endl<<MonHoc;
					trang7_tach(dsmon,dslop,dscht,p,check,1,MonHoc,SoCHT,phut,a,dapan);
		} 
	}
	closegraph();
}

//TRANG THONG TIN BAI THI CUA SINH VIEN or SUA BAI THI CUA GIAO VIEN
void trang6(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk, int vitriclick, int dk_search)
{
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(100,100,BLACK);
	KhungNgoai();
	setbkcolor(WHITE);
    settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(750,40,"THI TRAC NGHIEM");
	if(dk!=1&&dk!=4&&dk!=5&&dk!=6) {
		settextstyle(BOLD_FONT,HORIZ_DIR,1);
		outtextxy(70,80,"--Nhap ma mon--");
		vehcn(60,115,280,170,BLACK,LIGHTGREEN,BLACK,"\0",1);
		vehcn(380,670,450,720,BLACK,LIGHTCYAN,BLACK,"RESET",1);
		setbkcolor(WHITE);
	}
	if(dk==0){
		id=NULL;
		settextstyle(BOLD_FONT,HORIZ_DIR,1);
		vehcn(80,670,230,720,BLACK,LIGHTCYAN,BLACK,"THI THU",1);
		setbkcolor(WHITE);
		setcolor(BLACK);
		settextstyle(BOLD_FONT,HORIZ_DIR,1);
		Khung_them_xoa_sua(check);
		Khung_ho_tro(page,1);
	}
	vehcn(400,110,1450,650,BLACK,WHITE,BLACK,"\0",1);
	vehcn(405,115,1445,170,BLACK,CYAN,BLACK,"\0",1);
	outtextxy(430,130,"ID");
	outtextxy(530,130,"MA MON");
	outtextxy(880,130,"CAU HOI");
	outtextxy(1310,130,"XEM CAU HOI");
	vehcn(405,170,1445,645,BLACK,LIGHTCYAN,BLACK,"\0",1);
	for (int i = 1; i <= 8; i++) 
	{
    	int y = 110 + i * 60;
    	line(400, y, 1450, y);
    }
    line(500,110,500,650);
   	line(700,110,700,650);
    line(1300,110,1300,650);
    if(dk_search==0) InDSCHT(dscht,page, vitriclick, dk, id);
    else if(dk_search==1){
    	setcolor(BLACK);
		setbkcolor(LIGHTGREEN);
		outtextxy(80,135,MonHoc);
    	InDSCHT_mamon(dscht,page, vitriclick, dk, id, MonHoc);
    	setbkcolor(WHITE);
	} 
	if(dk==1){
		cleardevice();
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(100,100,BLACK);
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(1240,670,1390,720,BLACK,LIGHTGREEN,BLACK,"THEM",1);
		vehcn(100,60,500,120,BLACK,LIGHTCYAN,BLACK,"\0",1);
		vehcn(100,180,1430,580,BLACK,LIGHTCYAN,BLACK,"\0",1);
		vehcn(600,60,800,120,BLACK,LIGHTCYAN,BLACK,"\0",1);
		outtextxy(120,200,"Cau hoi:");
		outtextxy(120,300,"A. ");
		outtextxy(120,340,"B. ");
		outtextxy(120,380,"C. ");
		outtextxy(120,420,"D. ");
		setbkcolor(WHITE);
		outtextxy(100,20,"----Nhap ma mon hoc----");
		outtextxy(100,140,"----Nhap cau hoi thi----");
		outtextxy(600,20,"----Nhap dap an----");
	}
	if(dk==2 || dk==3){
		id=NULL;
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(40,240,300,300,BLACK,LIGHTCYAN,BLACK,"\0",1);
		setbkcolor(WHITE);
		if (dk==2) outtextxy(50,200,"--Nhap id can xoa--");
		if (dk==3) outtextxy(50,200,"--Nhap id can sua--");
		Khung_ho_tro(page,0);
	}
	if(dk==4){
		cleardevice();
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(100,100,BLACK);
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(1240,670,1390,720,BLACK,LIGHTGREEN,BLACK,"SUA",1);
		vehcn(100,60,500,120,BLACK,LIGHTCYAN,BLACK,"\0",1);
		vehcn(540,60,940,120,BLACK,LIGHTCYAN,BLACK,"\0",1);
		vehcn(100,180,1430,580,BLACK,LIGHTCYAN,BLACK,"\0",1);
		vehcn(980,60,1180,120,BLACK,LIGHTCYAN,BLACK,"\0",1);
		outtextxy(120,200,"Cau hoi:");
		outtextxy(120,300,"A. ");
		outtextxy(120,340,"B. ");
		outtextxy(120,380,"C. ");
		outtextxy(120,420,"D. ");
		treeCAUHOITHI p=Search(dscht,id);
		outtextxy(120,80,IntToChar(p->QUES.Id));
		outtextxy(550,80,p->QUES.MAMH);
		XuLyNoiDung(100,220,200,p);
		outtextxy(160,300,p->QUES.A);
		outtextxy(160,340,p->QUES.B);
		outtextxy(160,380,p->QUES.C);
		outtextxy(160,420,p->QUES.D);
		outtextxy(1070,80,CharToString(p->QUES.DapAn));
		setbkcolor(WHITE);
		outtextxy(100,20,"----Nhap id cau hoi----");
		outtextxy(540,20,"----Nhap ma mon hoc----");
		outtextxy(100,140,"----Nhap cau hoi thi----");
		outtextxy(980,20,"----Nhap dap an----");
	}
	if(dk==5){
		cleardevice();
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(100,100,BLACK);
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(400,110,1450,650,BLACK,LIGHTCYAN,BLACK,"\0",1);
		line(400,170,1450,170);
		line(400,230,1450,230);
		line(400,375,1450,375);
		line(400,575,1450,575);
		outtextxy(420,135,"MA MON:");
		outtextxy(420,195,"ID:");
		outtextxy(420,255,"CAU HOI:");
		outtextxy(420,400,"A.");
		outtextxy(420,440,"B.");
		outtextxy(420,480,"C.");
		outtextxy(420,520,"D.");
		outtextxy(420,600,"DAP AN:");
		Khung_them_xoa_sua(check);
		if(dk_search==0) InDSCHT(dscht,page, vitriclick,dk,id);
		else if(dk_search==1){
			InDSCHT_mamon(dscht,page,vitriclick,dk,id,MonHoc);	
		} 
	}
	if(dk==6){
		cleardevice();
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(100,100,BLACK);
		vehcn(1050,670,1200,720,BLACK,RED,BLACK,"NO",1);
		vehcn(1240,670,1390,720,BLACK,LIGHTGREEN,BLACK,"YES",1);
		vehcn(400,110,1450,650,BLACK,LIGHTCYAN,BLACK,"\0",1);
		line(400,170,1450,170);
		line(400,230,1450,230);
		line(400,375,1450,375);
		line(400,575,1450,575);
		outtextxy(420,135,"MA MON:");
		outtextxy(420,195,"ID:");
		outtextxy(420,255,"CAU HOI:");
		outtextxy(420,400,"A.");
		outtextxy(420,440,"B.");
		outtextxy(420,480,"C.");
		outtextxy(420,520,"D.");
		outtextxy(420,600,"DAP AN:");
		setcolor(RED);
		setbkcolor(WHITE);
		settextstyle(BOLD_FONT,HORIZ_DIR,3);
		outtextxy(200,20,"BAN CO CHAC MUON XOA CAU HOI NAY?");
		settextstyle(BOLD_FONT,HORIZ_DIR,1);
		setcolor(BLACK);
		if(dk_search==0) InDSCHT(dscht,page,vitriclick,dk,id);
		else if(dk_search==1){
			InDSCHT_mamon(dscht,page,vitriclick,dk,id,MonHoc);
		}
	}
	click_6(dsmon,dslop,dscht,check,page,dk, vitriclick, dk_search);
	closegraph();	
}

//Doc_file DANH SACH MON HOC
void Input_monhoc(int page, int k)
{
	int i=(page-1)*7;
    List_MH dsmon;
	dsmon.n = 0;
	char *s;
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	int y = 190;
    if(k==1) OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
    if(k==2)
    {
    	OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_SEARCH.txt");
    	ifstream file;
    	file.open("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_SEARCH.txt",ios::out);
    	file.close();
	}
	if(k==3)
    {
    	OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_temp.txt");
    	ifstream file;
    	file.open("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_temp.txt",ios::out);
    	file.close();
	}
	for (i; i < dsmon.n && i<page*7; i++)
	{
	    s=inttochar(i+1);
	    outtextxy(600, y, s);
	    outtextxy(730, y, dsmon.node[i].MAMH);
	    outtextxy(950, y, dsmon.node[i].TENMH);
	    y += 60;
	}
	remove("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_temp.txt");	
}

void clear_khung()
{
	vehcn(550,110,1450,600,BLACK,WHITE,BLACK,"\0",1);
	vehcn(555,115,1445,170,BLACK,CYAN,BLACK,"\0",1);
	outtextxy(720,130,"MA MON HOC");
    outtextxy(1100,130,"TEN MON HOC");
    outtextxy(580,130,"STT");
    vehcn(555,170,1445,595,BLACK,LIGHTCYAN,BLACK,"\0",1);
	for (int i = 1; i <= 7; i++) 
	{
    	int y = 110 + i * 60;
    	line(550, y, 1450, y);
    }
    line(650,110,650,600);
    line(900,110,900,600);
}

void Search_realtime_dsMON(int n, int x, int y, char str[],int page){
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setcolor(BLACK);
	char c;
	char s[n];
	strcpy(s,str);
	int k=0,i=0;
	List_MH dsmon;
	outtextxy(x,y,"|");
	OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
	MH mh;
	int y_sv;
	int dem = 1;
	while(i>=0){
		if(kbhit()){
		clear_khung();
		int cnt = (page-1)*7;
		c=getch();
		y_sv = 190;
		if((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122) || c==32){ //0=48 9=57
			if(i<n){
				if(i==0 && c==32){
					continue;
				}
				if(c>=97 && c<=122){
					c-=32;
				}
				if(str[i-1]==32 && c==32){
					continue;	
				}			
				str[i]=c;
				str[i+1]='\0';
                outtextxy(x, y, str);
                outtextxy(x+textwidth(str),y,"|");
				i++;
					
				for(int k = 0; k < dsmon.n; k++)
				{
					if ((strstr(dsmon.node[k].MAMH, str) != NULL)|| (strstr(dsmon.node[k].TENMH, str) != NULL))
					{
						cnt++;
						if(cnt<=page*7&&cnt<dsmon.n)
						{
						    outtextxy(600, y_sv, inttochar(cnt));
						    outtextxy(730, y_sv, dsmon.node[k].MAMH);
						    outtextxy(950, y_sv, dsmon.node[k].TENMH);
						    y_sv += 60;
						}	    
			    	}
				}		
			}
		} 
		else if(c==13 || c==27){ //enter=13 esc=27
			if(i==0){
				outtextxy(x,y," ");
				strcpy(str,s);
			}
			if(str[strlen(str)-1]==32){
				xoa_kitu(str,strlen(str)-1);
            	moveto(x+textwidth(str),y);
            	outtextxy(x+textwidth(str),y,"  ");		
			} 
			else{
				outtextxy(x+textwidth(str),y," ");	
				//Search_chuoicon(dsmon,s);
			}
			break; 
		} 
		else if(c==8 && str!='\0'){ //backspace=8
			xoa_kitu(str, i-1);
			if(i>0) {
				i--;
            	moveto(x+textwidth(str),y);
            	outtextxy(x+textwidth(str),y,"  ");
            	outtextxy(x+textwidth(str),y,"|");
				for(int k = 0; k < dsmon.n; k++)
				{
					if ((strstr(dsmon.node[k].MAMH, str) != NULL)|| (strstr(dsmon.node[k].TENMH, str) != NULL))
					{
						cnt++;
						if(cnt<=page*7&&cnt<dsmon.n)
						{
						    outtextxy(600, y_sv, inttochar(cnt));
						    outtextxy(730, y_sv, dsmon.node[k].MAMH);
						    outtextxy(950, y_sv, dsmon.node[k].TENMH);
						    y_sv += 60;
						}
			    	}
				}	
			}
		}
		else if(c==-32 || c==0){
			c=getch();	
		} 
		}	
	}
}

//IN CAC CHU 
void In_Chu(int color, int bkcolor, char *s)
{ 
	for (int i = 1 ; i <= 7; i++) 
	{
		int y = 130 + i*60;
		setcolor(color);
		setbkcolor(bkcolor);
	    outtextxy(1380,y,s);
	}
	setcolor(BLACK);
	setbkcolor(WHITE);
}
//TRANG DANH SACH MON HOC
void trang5(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht,int &check, int page, int dk, int dksearch)
{
	vehcn(0,0,1530,800,BLACK,WHITE,WHITE,"\0",1);
	KhungNgoai();
	vehcn(550,110,1450,600,BLACK,WHITE,BLACK,"\0",1);
	vehcn(555,115,1445,170,BLACK,CYAN,BLACK,"\0",1);
	outtextxy(720,130,"MA MON HOC");
    outtextxy(1100,130,"TEN MON HOC");
    outtextxy(580,130,"STT");
    vehcn(555,170,1445,595,BLACK,LIGHTCYAN,BLACK,"\0",1);
	for (int i = 1; i <= 7; i++) 
	{
    	int y = 110 + i * 60;
    	line(550, y, 1450, y);
    }
    line(650,110,650,600);
    line(900,110,900,600);
    if(dk==0||dk==2||dk==3||dk==4||dk==6||dk==12) Input_monhoc(page,1);
    if(dk==5||dk==7)	Input_monhoc(1,3);
    if(dk==13||dk==11||dk==9||dk==8) Input_monhoc(1,2);
    if(dk==0||dk==8)
	{
		vehcn(550,30,1450,100,BLACK,WHITE,WHITE,"DANH SACH MON HOC",5);
		vehcn(70,130,480,185,BLACK,LIGHTCYAN,BLACK,"\0",1);
		In_Chu(BLUE,LIGHTCYAN,"Thi");
		line(1350,110,1350,600);
		outtextxy(90,90,"---Nhap ma mon hoc/ten mon hoc---");
		if(dk==0)
		{
			Khung_ho_tro(page,1);
			Khung_them_xoa_sua(check);
			setbkcolor(LIGHTCYAN);
		}
		if(dk==8)
		{
			vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		}
	}
	if(dk==1||dk==10)
	{
		cleardevice();
		vehcn(0,0,1530,800,BLACK,WHITE,WHITE,"\0",1);
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		if(dk==1)
		{
			vehcn(1240,670,1390,720,BLACK,LIGHTGREEN,BLACK,"THEM",1);
			vehcn(400,50,1200,120,BLACK,WHITE,WHITE,"THEM MON HOC",5);//400,200,1200,320
		}
		if(dk==10)
		{
			vehcn(1240,670,1390,720,BLACK,LIGHTGREEN,BLACK,"SUA",1);
			vehcn(400,50,1200,120,BLACK,WHITE,WHITE,"HIEU CHINH MON HOC",5);
		}
		KhungNgoai();
		vehcn(400,200,1200,320,BLACK,WHITE,BLACK,"\0",1);
		vehcn(405,205,1195,260,BLACK,CYAN,BLACK,"\0",1);
		outtextxy(470,220,"MA MON HOC");
        outtextxy(850,220,"TEN MON HOC");
        vehcn(405,260,1195,315,BLACK,LIGHTCYAN,BLACK,"\0",1);
		line(400,260,1200,260);
		line(650,200,650,320);
		if(dk==10)
		{
			outtextxy(480,270,MaMon);
			outtextxy(690,270,TenMon);
		}
	}
	if(dk==2||dk==11)
	{
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(550,30,1450,100,BLACK,WHITE,WHITE,"XOA MON HOC",5);
		settextstyle(BOLD_FONT,HORIZ_DIR,1);
		if(dk==2)
		{
			Khung_ho_tro(page,0);
			vehcn(40,230,480,250,BLACK,WHITE,WHITE,"- Nhap ma mon hoc muon xoa:",1);
			vehcn(40,270,480,340,BLACK,LIGHTGREEN,BLACK,"\0",1);
			vehcn(40,360,480,380,BLACK,WHITE,WHITE,"- Nhap ten mon hoc muon xoa:",1);
			vehcn(40,400,480,470,BLACK,LIGHTGREEN,BLACK,"\0",1);
		}
		if(dk==11)
		{
			vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		}
		line(1350,110,1350,600);
		In_Chu(RED,LIGHTCYAN,"Xoa");
		outtextxy(90,90,"---Nhap ma mon hoc/ten mon hoc---");
    	vehcn(60,130,470,185,BLACK,LIGHTCYAN,BLACK,"\0",1);;
		line(1350,110,1350,600);
    	setcolor(BLACK);
//    	Khung_ho_tro(page,0);
	}
	if(dk==3||dk==9)
	{
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(550,30,1450,100,BLACK,WHITE,WHITE,"HIEU CHINH MON HOC",5);
		settextstyle(BOLD_FONT,HORIZ_DIR,1);
		vehcn(60,130,470,185,BLACK,LIGHTCYAN,BLACK,"\0",1);
		setbkcolor(WHITE);
		outtextxy(80,90,"---Nhap ma mon hoc/ten mon hoc---");
		if(dk==3)
		{
			Khung_ho_tro(page,0);
			vehcn(40,270,480,340,BLACK,LIGHTGREEN,BLACK,"Hieu chinh ma mon hoc",1);
			vehcn(40,400,480,470,BLACK,LIGHTGREEN,BLACK,"Hieu chinh ten mon hoc",1);
		}
		if(dk==9)
		{
			vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		}
		In_Chu(BLUE,LIGHTCYAN,"Sua");
	    line(1350,110,1350,600);
    	Khung_ho_tro(page,0);
	}
	if(dk==4||dk==5)
	{
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(550,30,1450,100,BLACK,WHITE,WHITE,"HIEU CHINH MON HOC",5);
		settextstyle(BOLD_FONT,HORIZ_DIR,1);
		if(dk==5)
		{
			outtextxy(40,230,"- Nhap ma mon hoc moi:");
			vehcn(40,270,480,340,BLACK,LIGHTGREEN,BLACK,"\0",1);
		}
		if(dk==4)
		{
			outtextxy(40,230,"- Nhap ma mon hoc muon hieu chinh:");
			vehcn(40,270,480,340,BLACK,LIGHTGREEN,BLACK,"\0",1);
		}
	}
	if(dk==6||dk==7)
	{
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(550,30,1450,100,BLACK,WHITE,WHITE,"HIEU CHINH MON HOC",5);
		settextstyle(BOLD_FONT,HORIZ_DIR,1);
	    setcolor(BLACK);
	    setbkcolor(WHITE);
		if(dk==7)
		{
			outtextxy(40,230,"- Nhap ten mon hoc moi:");
			vehcn(40,270,480,340,BLACK,LIGHTGREEN,BLACK,"\0",1);
		}
		if(dk==6)
		{
			outtextxy(40,230,"- Nhap ten mon hoc muon hieu chinh:");
			vehcn(40,270,480,340,BLACK,LIGHTGREEN,BLACK,"\0",1);
		}
	}
	if(dk==12||dk==13)
	{
		setbkcolor(WHITE);
		outtextxy(90,90,"---Nhap ma mon hoc/ten mon hoc---");
		vehcn(70,130,480,185,BLACK,LIGHTCYAN,BLACK,"\0",1);
		vehcn(550,30,1450,100,BLACK,WHITE,WHITE,"DANH SACH MON HOC",5);
		settextstyle(BOLD_FONT,HORIZ_DIR,1);
		In_Chu(BLUE,LIGHTCYAN,"Chon");
		line(1350,110,1350,600);
	    if(dk==13)
		{
			vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		}
	    Khung_ho_tro(page,0);
	}
    click_5(dsmon,dslop,dscht,check,page,dk,dksearch);
    closegraph();
}

//Doc_file DANH SACH SINH VIEN
void Print_SV(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int page)
{
	int first = 1;
	int c1,c2, cnt = 0;
	c1 = (page - 1) *7;
	c2 = page *7;

	List_LOP ds_lop;
    OpenFile_DSLOP(ds_lop,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
    PTRSV p;
	LOP lop;

	int j;
    bool found = false;
    setcolor(BLACK);
    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    int dem = 1;
    int i = Search(ds_lop,ma_lop);
    if(i!= -1) 
    {
    	OpenFile_SV(ds_lop,ma_lop);
    	lop = *(ds_lop.node[i]);
    	found = true;
    	p = lop.dssv;
    	
	    while (p != NULL) 
		{
			if(cnt >= c1 && cnt < c2)
			{
				outtextxy(380+(195-textwidth(p->sv.MASV))/2,160+30*dem,p->sv.MASV);
				outtextxy(550+25,160+30*dem,p->sv.HO);
				outtextxy(880+25,160+30*dem,p->sv.TEN);
				outtextxy(1020+(100-textwidth(" "))/2,160+30*dem, BtC(p->sv.PHAI));
				if(check==1)outtextxy(1080+(250-textwidth(p->sv.password))/2,160+30*dem,p->sv.password);
				dem+=2;
			}	
			cnt++;			
            p = p->next;
        }
    }
    else OpenFile_SV(ds_lop,"CNTT");
    
    if(found == false )
	{
		setbkcolor(WHITE);
		outtextxy(70+(150-textwidth("Khong tim thay"))/2,175,"Khong tim thay");
		strcpy(ma_lop,"Nhap ma lop");
		click_4(dsmon,ds_lop,dscht,check,1,0);
		return;
	}
	return; 
}

clear_khung_dssv()
{
	vehcn(385,170,1405,595,BLACK,LIGHTCYAN,BLACK,"\0",1);
	for (int i = 1; i <= 7; i++) 
	{
    	int y = 110 + i * 60;
    	line(380, y, 1410, y);
    }
    line(550,110,550,600);
    line(880,110,880,600);
    line(1020,110,1020,600);
    line(1130,110,1130,600);
    line(1280,110,1280,600);
    int y_tmp = 190;
	for(int i=1; i<=7;i++)
	{	
		outtextxy(1330,y_tmp,"Xem");
		y_tmp+=60;
	}
}

void Search_realtime_dssv(int n, int x, int y, char str[],int page){
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setcolor(BLACK);
	char c;
	char s[n];
	strcpy(s,str);
	int k=0,i=0;
	outtextxy(x,y,"|");
	
	List_LOP dslop;
	OpenFile_DSLOP(dslop,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
	OpenFile_SV(dslop,ma_lop);
	int sonut;
	if(strcmp(ma_lop,"Nhap ma lop")!=0) sonut = countNodes(dslop.node[Search(dslop,ma_lop)]->dssv);
	PTRSV p;
	
	while(i>=0){
		if(kbhit()){
		int dem = 1;
		p = dslop.node[Search(dslop,ma_lop)]->dssv;
		clear_khung_dssv();
		int cnt = (page-1)*7;
		c=getch();
		if((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122) || c==32){ //0=48 9=57
			if(i<n){
				if(i==0 && c==32){
					continue;
				}
				if(c>=97 && c<=122){
					c-=32;
				}
				if(str[i-1]==32 && c==32){
					continue;	
				}			
				str[i]=c;
				str[i+1]='\0';
                outtextxy(x, y, str);
                outtextxy(x+textwidth(str),y,"|");
				i++;
					
				while(p!=NULL)
				{
					char tmp[11];
					strcpy(tmp,p->sv.TEN);
					for(int i=0; i<strlen(tmp);i++)
					{
						if (islower(tmp[i])) 
						{ 
            				tmp[i] = toupper(tmp[i]); 
        				}
					}
					if(strstr(p->sv.MASV,str)!=NULL||strstr(tmp,str)!=NULL)
					{
						cnt++;
						if(cnt<=page*7&&cnt<sonut)
						{
							outtextxy(380+(195-textwidth(p->sv.MASV))/2,160+30*dem,p->sv.MASV);
							outtextxy(550+25,160+30*dem,p->sv.HO);
							outtextxy(880+25,160+30*dem,p->sv.TEN);
							outtextxy(1020+(100-textwidth(" "))/2,160+30*dem, BtC(p->sv.PHAI));
							if(check==1)outtextxy(1080+(250-textwidth(p->sv.password))/2,160+30*dem,p->sv.password);
							dem+=2;
						}	
					}	
					p=p->next;
				}		
			}
		} 
		else if(c==13 || c==27){ //enter=13 esc=27
			if(i==0){
				outtextxy(x,y," ");
				strcpy(str,s);
			}
			if(str[strlen(str)-1]==32){
				xoa_kitu(str,strlen(str)-1);
            	moveto(x+textwidth(str),y);
            	outtextxy(x+textwidth(str),y,"  ");		
			} 
			else{
				outtextxy(x+textwidth(str),y," ");	
				while(p!=NULL)
				{
					char tmp[11];
					strcpy(tmp,p->sv.TEN);
					for(int i=0; i<strlen(tmp);i++)
					{
						if (islower(tmp[i])) 
						{ 
            				tmp[i] = toupper(tmp[i]); 
        				}
					}
					if(strstr(p->sv.MASV,str)!=NULL||strstr(tmp,str)!=NULL)
					{
						cnt++;
						if(cnt<=page*7&&cnt<sonut)
						{
							outtextxy(380+(195-textwidth(p->sv.MASV))/2,160+30*dem,p->sv.MASV);
							outtextxy(550+25,160+30*dem,p->sv.HO);
							outtextxy(880+25,160+30*dem,p->sv.TEN);
							outtextxy(1020+(100-textwidth(" "))/2,160+30*dem, BtC(p->sv.PHAI));
							if(check==1)outtextxy(1080+(250-textwidth(p->sv.password))/2,160+30*dem,p->sv.password);
							dem+=2;
							add_sv_tim(p_tim,p->sv);
						}	
					}	
					p=p->next;
				}
			}
			break; 
		} 
		else if(c==8 && str!='\0'){ //backspace=8
			xoa_kitu(str, i-1);
			if(i>0) {
				i--;
            	moveto(x+textwidth(str),y);
            	outtextxy(x+textwidth(str),y,"  ");
            	outtextxy(x+textwidth(str),y,"|");
				while(p!=NULL)
				{
					char tmp[11];
					strcpy(tmp,p->sv.TEN);
					for(int i=0; i<strlen(tmp);i++)
					{
						if (islower(tmp[i])) 
						{ 
            				tmp[i] = toupper(tmp[i]); 
        				}
					}
					if(strstr(p->sv.MASV,str)!=NULL||strstr(tmp,str)!=NULL)
					{
						cnt++;
						if(cnt<=page*7&&cnt<sonut)
						{
							outtextxy(380+(195-textwidth(p->sv.MASV))/2,160+30*dem,p->sv.MASV);
							outtextxy(550+25,160+30*dem,p->sv.HO);
							outtextxy(880+25,160+30*dem,p->sv.TEN);
							outtextxy(1020+(100-textwidth(" "))/2,160+30*dem, BtC(p->sv.PHAI));
							if(check==1)outtextxy(1080+(250-textwidth(p->sv.password))/2,160+30*dem,p->sv.password);
							dem+=2;
						}	
					}	
					p=p->next;
				}			
			}
		}
		else if(c==-32 || c==0){
			c=getch();	
		} 
		}	
	}
}

//TRANG DANH SACH SINH VIEN
void trang4(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk)
{
	vehcn(0,0,1530,800,BLACK,WHITE,WHITE,"\0",1);
	KhungNgoai();
	vehcn(380,110,1410,600,BLACK,WHITE,BLACK,"\0",1);
	vehcn(385,115,1405,170,BLACK,CYAN,BLACK,"\0",1);
	outtextxy(430,130,"MSSV");
    outtextxy(690,130,"HO");
    outtextxy(930,130,"TEN");
    outtextxy(1050,130,"PHAI");
    outtextxy(1160,130,"PASSWORD");
    if(dk==0||dk==6) outtextxy(1300,130,     "DIEM THI");
    else if(dk==2) outtextxy(1300,130,"  XOA  ");
    else if(dk==3) outtextxy(1300,130,"  SUA  ");
    vehcn(385,170,1405,595,BLACK,LIGHTCYAN,BLACK,"\0",1);
	for (int i = 1; i <= 7; i++) 
	{
    	int y = 110 + i * 60;
    	line(380, y, 1410, y);
    }
    line(550,110,550,600);
    line(880,110,880,600);
    line(1020,110,1020,600);
    line(1130,110,1130,600);
    line(1280,110,1280,600);
	if(dk==0)
	{
		vehcn(380,30,1410,100,BLACK,WHITE,WHITE,"DANH SACH SINH VIEN",5);
    	vehcn(320,110,370,160,BLACK,LIGHTCYAN,BLACK,"Tim",1);
	}
	trang4_tach(dsmon, dslop, dscht, check,page, dk);
}

//TRANG DANH SACH SINH VIEN
void trang4_tach(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk)
{
	vehcn(385,170,1405,595,BLACK,LIGHTCYAN,BLACK,"\0",1);
	for (int i = 1; i <= 7; i++) 
	{
    	int y = 110 + i * 60;
    	line(380, y, 1410, y);
    }
    line(550,110,550,600);
    line(880,110,880,600);
    line(1020,110,1020,600);
    line(1130,110,1130,600);
    line(1280,110,1280,600);
	if(strcmp(ma_lop, "Nhap ma lop") == 0) dk = 0;
    if(dk==0)
	{
		Khung_ho_tro(page,1);
		Khung_them_xoa_sua(check);
		setbkcolor(LIGHTCYAN);
		vehcn(380,30,1410,100,BLACK,WHITE,WHITE,"DANH SACH SINH VIEN",5);
    	KhungNgoai();
		if(check==1)vehcn(50,670,300,720,BLACK,LIGHTGREEN,BLACK,"XEM DIEM THEO MON",1);
//    	vehcn(350,670,600,720,BLACK,LIGHTGREEN,BLACK,"XEM DIEM THEO MON",1);
    	vehcn(20,110,200,160,BLACK,LIGHTCYAN,BLACK,ma_lop,1);
    	vehcn(200,110,300,160,BLACK,LIGHTGREEN,BLACK,"TIM LOP",1);
    	setbkcolor(LIGHTCYAN);
		int y_tmp = 190;
		for(int i=1; i<=7;i++)
		{	
			setcolor(BLUE);
			outtextxy(1330,y_tmp,"Xem");
			y_tmp+=60;
		}	
		setcolor(BLACK);
		Print_SV(dsmon,dslop,dscht,page);
	}
	if(dk==1)
	{
		cleardevice();
		vehcn(0,0,1530,800,BLACK,WHITE,WHITE,"\0",1);
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(1250,670,1400,720,BLACK,LIGHTGREEN,BLACK,"THEM",1);
		vehcn(0,0,1530,300,BLACK,WHITE,WHITE,"----THEM SINH VIEN----",5);
		KhungNgoai();
		vehcn(350,300,1250,460,BLACK,WHITE,BLACK,"\0",1);
		vehcn(355,305,1245,380,BLACK,CYAN,BLACK,"\0",1);
		outtextxy(400,330,"MSSV");
    	outtextxy(660,330,"HO");
    	outtextxy(900,330,"TEN");
    	outtextxy(1020,330,"PHAI");
    	outtextxy(1130,330,"PASSWORD");
		vehcn(355,380,1245,455,BLACK,LIGHTCYAN,BLACK,"\0",1);
		line(355,380,1250,380);
		line(520,305,520,460);
		line(850,305,850,460);
		line(990,305,990,460);
		line(1100,305,1100,460);
		if(trung ==1) 
		{
			outtextxy(355+(840-textwidth("Ma so da ton tai. Vui long nhap lai"))/2,600,"Ma so da ton tai. Vui long nhap lai");
			trung = -1;
		}
		else if(trung ==0 )
		{
			outtextxy(355+(840-textwidth("Them thanh cong"))/2,600,"Them thanh cong");
			trung = -1;
		}
	}
	if(dk==2)
	{
		vehcn(380,30,1410,100,BLACK,WHITE,WHITE,"----XOA SINH VIEN----",5);
		vehcn(40,210,370,280,BLACK,LIGHTGREEN,BLACK,"- Nhap ma so sinh vien -",1);
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(0,0,0,0,BLACK,LIGHTCYAN,BLACK,"XOA",1);
		int y_tmp = 190;
		for(int i=1; i<=7;i++)
		{	
			setcolor(RED);
			outtextxy(1330,y_tmp,"Xoa");
			y_tmp+=60;
		}
    	setcolor(BLACK);
		Khung_ho_tro(page,0);
		setbkcolor(LIGHTCYAN);
		Print_SV(dsmon,dslop,dscht,page);
	}
	if(dk==3)
	{
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(380,30,1410,100,BLACK,WHITE,WHITE,"----HIEU CHINH SINH VIEN----",5);
		vehcn(40,210,370,280,BLACK,LIGHTGREEN,BLACK,"- Nhap ma so sinh vien -",1);
		vehcn(0,0,0,0,BLACK,LIGHTCYAN,BLACK,"SUA",1);
		int y_tmp = 190;
		for(int i=1; i<=7;i++){	
			setcolor(RED);
			outtextxy(1330,y_tmp,"Sua");
			y_tmp+=60;
		}
    	setcolor(BLACK);
		Khung_ho_tro(page,0);
		setbkcolor(LIGHTCYAN);
		Print_SV(dsmon,dslop,dscht,page);
	}
	if(dk==4)
	{
		cleardevice();
		vehcn(0,0,1530,800,BLACK,WHITE,WHITE,"\0",1);
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(1240,670,1390,720,BLACK,LIGHTGREEN,BLACK,"SUA",1);
		vehcn(0,0,1530,300,BLACK,WHITE,WHITE,"----HIEU CHINH SINH VIEN----",5);
		KhungNgoai();
		vehcn(350,300,1250,460,BLACK,WHITE,BLACK,"\0",1);
		vehcn(355,305,1245,380,BLACK,CYAN,BLACK,"\0",1);
		outtextxy(400,330,"MSSV");
    	outtextxy(660,330,"HO");
    	outtextxy(900,330,"TEN");
    	outtextxy(1020,330,"PHAI");
    	outtextxy(1130,330,"PASSWORD");
		vehcn(355,380,1245,455,BLACK,LIGHTCYAN,BLACK,"\0",1);
		line(355,380,1250,380);
		line(520,305,520,460);
		line(850,305,850,460);
		line(990,305,990,460);
		line(1100,305,1100,460);
		
		outtextxy(355+(165-textwidth("N21DCCNxxx"))/2,408,psv->sv.MASV);
		outtextxy(520 + 25,408,psv->sv.HO);
		outtextxy(850 + 25,408,psv->sv.TEN);
		outtextxy(990 +(110-textwidth("0"))/2 ,408,BtC(psv->sv.PHAI));
		outtextxy(1100 + (145-textwidth("      "))/2,408,psv->sv.password);
		if(trung ==1) 
		{
			outtextxy(355+(840-textwidth("Ma so da ton tai. Vui long nhap lai"))/2,600,"Ma so da ton tai. Vui long nhap lai");
			trung = -1;
		}
		else if(trung ==0 )
		{
			outtextxy(355+(840-textwidth("Sua thanh cong"))/2,600,"Sua thanh cong");
			trung = -1;
		}
		
	}
	if(dk==5)
	{//DIEM CUA 1 SINH VIEN
		cleardevice();
		vehcn(0,0,1530,800,BLACK,WHITE,WHITE,"\0",1);
		vehcn(1250,670,1400,720,BLACK,RED,BLACK,"QUAY LAI",1);
		Khung_ho_tro(page,0);
		vehcn(500,160,1400,650,BLACK,WHITE,BLACK,"\0",1);
		vehcn(505,165,1395,220,BLACK,CYAN,BLACK,"\0",1);
		outtextxy(812-textwidth("MON HOC")/2,180,"MON HOC");
	    outtextxy(1160,180,"DIEM THI");
	    outtextxy(1310,180,"BAI THI");
		vehcn(505,220,1395,645,BLACK,LIGHTCYAN,BLACK,"\0",1);
		for (int i = 1; i <= 7; i++) 
		{
	    	int y = 160 + i * 60;
	    	line(505, y, 1400, y);
	    }
	    line(1120,160,1120,650);
	    line(1300,160,1300,650);
	    setbkcolor(WHITE);
	    outtextxy(50,220,"---THONG TIN SINH VIEN---");
	    outtextxy(50,270,"Ho va ten:");
	    outtextxy(50,320,"MSSV:");
	    outtextxy(50,370,"Lop:");
	    vehcn(350,30,1420,100,BLACK,WHITE,WHITE,"----DIEM THI CUA SINH VIEN----",5);
		vehcn(0,0,0,0,BLACK,LIGHTCYAN,WHITE,"",1);
		Show(ma_lop,ma_sv_xem,page);
	}
	if(dk==6)
	{//TIM KIEM SINH VIEN
		char ma_sv_tim[15];
		strcpy(ma_sv_tim,"Nhap thong tin");
		vehcn(385,170,1405,595,BLACK,LIGHTCYAN,BLACK,"\0",1);
		for (int i = 1; i <= 7; i++) 
		{
	    	int y = 110 + i * 60;
	    	line(380, y, 1410, y);
	    }
	    line(550,110,550,600);
	    line(880,110,880,600);
	    line(1020,110,1020,600);
	    line(1130,110,1130,600);
	    line(1280,110,1280,600);
	    
		vehcn(1250,670,1400,720,BLACK,LIGHTRED,BLACK,"QUAY LAI",1);
		setbkcolor(LIGHTCYAN);
												
		vehcn(380,30,1410,100,BLACK,WHITE,WHITE,"   TIM SINH VIEN   ",5);
    	vehcn(30,110,230,160,BLACK,LIGHTCYAN,BLACK,ma_sv_tim,1);
		int y_tmp = 190;
		for(int i=1; i<=7;i++)
		{	
			outtextxy(1330,y_tmp,"Xem");
			y_tmp+=60;
		}
		int dem = 1;
		int cnt=0;
		PTRSV p_tim_tmp= p_tim;
		while(p_tim_tmp!=NULL)
		{
			if(cnt<=7)
			{
				outtextxy(380+(195-textwidth(p_tim_tmp->sv.MASV))/2,160+30*dem,p_tim_tmp->sv.MASV);
				outtextxy(550+25,160+30*dem,p_tim_tmp->sv.HO);
				outtextxy(880+25,160+30*dem,p_tim_tmp->sv.TEN);
				outtextxy(1020+(100-textwidth(" "))/2,160+30*dem, BtC(p_tim_tmp->sv.PHAI));
				if(check==1)outtextxy(1080+(250-textwidth(p_tim_tmp->sv.password))/2,160+30*dem,p_tim_tmp->sv.password);
				dem+=2;
			}
			cnt++;
			p_tim_tmp=p_tim_tmp->next;		
		}
		Clearlist(p_tim_tmp);			
	}
	if(dk==7)
	{//DIEM CUA LOP THEO MA MON
		cleardevice();
		vehcn(0,0,1530,800,BLACK,WHITE,WHITE,"\0",1);
		vehcn(505,0,1420,50,BLACK,WHITE,WHITE,"DIEM THI THEO MON",5);
		OpenFile_DSLOP(dslop,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
		OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
		string s ="Lop: "+string(dslop.node[Search(dslop,ma_lop)]->TENLOP ) +"    Mon: "+string(dsmon.node[TimMaMon(dsmon,MonHoc)].TENMH);
		char cstr[s.length() + 1];
		strcpy(cstr, s.c_str());
		vehcn(505,50,1410,100,BLACK,WHITE,WHITE,cstr,3);
		vehcn(1250,670,1400,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(505,110,1410,600,BLACK,WHITE,BLACK,"\0",1);
		vehcn(510,115,1405,170,BLACK,CYAN,BLACK,"\0",1);
		outtextxy(555,130,"MSSV");
	    outtextxy(815,130,"HO");
	    outtextxy(1055,130,"TEN");
	    outtextxy(1175,130,"PHAI");
	    outtextxy(1285,130,"DIEM THI");
		vehcn(510,170,1405,595,BLACK,LIGHTCYAN,BLACK,"\0",1);
		//vehcn(100,220,300,250,BLACK,WHITE,WHITE,"---Nhap ma mon hoc---",1);
		vehcn(70,270,330,330,BLACK,LIGHTGREEN,BLACK,"---Nhap ma mon hoc---",1);
		if(strlen(MonHoc)!=0)vehcn(70,270,330,330,BLACK,LIGHTGREEN,BLACK,"                     ",1);
		outtextxy(150,290,MonHoc);
		Khung_ho_tro(page,0);
		vehcn(50,400,350,460,BLACK,LIGHTGREEN,BLACK,"XEM DANH SACH MON HOC",1);
		for (int i = 1; i <= 7; i++) 
		{
	    	int y = 110 + i * 60;
	    	line(505, y, 1410, y);
	    }
	    line(675,110,675,600);
	    line(1005,110,1005,600);
	    line(1145,110,1145,600);
	    line(1255,110,1255,600);
	    setbkcolor(LIGHTCYAN);
	    PrintDiem_MonHoc(ma_lop,MonHoc,page);
	}
    click_4(dsmon,dslop,dscht,check,page,dk);
    closegraph();
}

bool checkxoa(PTRSV psv)
{
	cleardevice();
	vehcn(0,0,1530,800,BLACK,WHITE,WHITE,"\0",1);
	vehcn(50,670,200,720,BLACK,LIGHTGREEN,BLACK,"QUAY LAI",1);
	vehcn(1250,670,1400,720,BLACK,RED,BLACK,"XOA",1);							
	vehcn(0,0,1530,300,RED,WHITE,WHITE,"BAN CO THAT SU MUON XOA?",5);
	KhungNgoai();
	vehcn(350,300,1250,460,BLACK,WHITE,BLACK,"\0",1);
	vehcn(355,305,1245,380,BLACK,CYAN,BLACK,"\0",1);
	outtextxy(400,330,"MSSV");
	outtextxy(660,330,"HO");
	outtextxy(900,330,"TEN");
	outtextxy(1020,330,"PHAI");
	outtextxy(1130,330,"PASSWORD");
	vehcn(355,380,1245,455,BLACK,LIGHTCYAN,BLACK,"\0",1);
	line(355,380,1250,380);
	line(520,305,520,460);
	line(850,305,850,460);
	line(990,305,990,460);
	line(1100,305,1100,460);
	outtextxy(355+(165-textwidth("N21DCCNxxx"))/2,408,psv->sv.MASV);
	outtextxy(520 + 25,408,psv->sv.HO);
	outtextxy(850 + 25,408,psv->sv.TEN);
	outtextxy(990 +(110-textwidth("0"))/2 ,408,BtC(psv->sv.PHAI));
	outtextxy(1100 + (145-textwidth("      "))/2,408,psv->sv.password);
	string tmp;
	while(1)
	{
		if(kbhit())
		{
			while(kbhit())
			{
				tmp = getch();									
			}			
		}
		
		if (ismouseclick(WM_LBUTTONDOWN)) 
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
	   		clearmouseclick(WM_LBUTTONDOWN);
	   		if(VT(50,200,670,720,x,y)) return 0;
	   		if(VT(1250,1400,670,720,x,y)) return 1;
	   	}
	   	delay(50);
	}
}

//TRANG DANH SACH LOP
void trang3(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check, int page, int dk, int dksearch)
{
	vehcn(0,0,1530,800,BLACK,WHITE,WHITE,"\0",1);
	KhungNgoai();
	vehcn(380,650,450,710,BLACK,LIGHTCYAN,BLACK,"RESET",1);
	vehcn(380,110,1430,600,BLACK,WHITE,BLACK,"\0",1);
	vehcn(385,115,1425,170,BLACK,CYAN,BLACK,"\0",1);
	outtextxy(410,130,"STT");
	outtextxy(510,130,"MA LOP");
	outtextxy(820,130,"TEN LOP");
	outtextxy(1170,130,"NIEN KHOA");
	outtextxy(1330,130,"XEM DSSV");
	vehcn(385,170,1425,595,BLACK,LIGHTCYAN,BLACK,"\0",1);
	for (int i = 1; i <= 7; i++) 
	{
    	int y = 110 + i * 60;
    	line(380, y, 1430, y);
    }
    line(470,110,470,600);
    line(650,110,650,600);
    line(1120,110,1120,600);
    line(1320,110,1320,600);
	setbkcolor(WHITE);
	if(dk==0)
	{
		if(back4_3==4)Khung_ho_tro_back(page,1);
		else Khung_ho_tro(page,1);
		Khung_them_xoa_sua(check);
		settextstyle(BOLD_FONT,HORIZ_DIR,1); 
		setcolor(BLACK);
		setbkcolor(WHITE);
		outtextxy(70,80,"--Nhap nien khoa--");
		vehcn(380,30,1430,100,BLACK,WHITE,WHITE,"DANH SACH LOP",5);
		vehcn(60,115,280,170,BLACK,LIGHTGREEN,BLACK,"\0",1);
		if(dksearch==0) InDanhSachLop(page,dk);
		else if(dksearch==1) {
			outtextxy(100,130,nienkhoa);
			InLopTheoNienKhoa(page,nienkhoa,dk);
		}
		KhungNgoai();
	}
	if(dk==1)
	{
		cleardevice();
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(1240,670,1390,720,BLACK,LIGHTGREEN,BLACK,"THEM",1);
		vehcn(0,0,1530,200,BLACK,WHITE,WHITE,"-----THEM LOP-----",5);
		KhungNgoai();
		vehcn(300,200,1220,320,BLACK,WHITE,BLACK,"\0",1);
		vehcn(305,205,1215,260,BLACK,CYAN,BLACK,"\0",1);
		outtextxy(370,220,"MA LOP");
	    outtextxy(720,220,"TEN LOP");
	    outtextxy(1070,220,"NIEN KHOA");
		vehcn(305,260,1215,315,BLACK,LIGHTCYAN,BLACK,"\0",1);
		line(300,260,1220,260);
		line(550,200,550,320);
		line(1020,200,1020,320);
	}
	if(dk==2)
	{
		vehcn(50,50,1480,100,BLACK,WHITE,WHITE,"XOA LOP",5);
		vehcn(40,170,370,200,BLACK,WHITE,WHITE,"- Nhap ma lop muon xoa:",1);
		vehcn(40,210,370,280,BLACK,LIGHTGREEN,BLACK,"\0",1);
		outtextxy(45,230,malop_sua_xoa);
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(1430,115,1500,170,BLACK,CYAN,BLACK,"XOA",1);
		vehcn(1430,170,1500,595,BLACK,LIGHTCYAN,BLACK,"\0",1);
		line(1430,110,1500,110);
		line(1425,115,1500,115);
    	for (int i = 1; i <= 7; i++) 
		{
    		int y = 110 + i * 60;
    		line(1430, y, 1500, y);
    	}
    	line(1430,600,1500,600);
		line(1425,595,1500,595);
		setbkcolor(WHITE);
		outtextxy(70,80,"--Nhap nien khoa--");
		vehcn(60,115,280,170,BLACK,LIGHTGREEN,BLACK,"\0",1);
		if(dksearch==0) InDanhSachLop(page,dk);
		else if(dksearch==1) {
			outtextxy(100,130,nienkhoa);
			InLopTheoNienKhoa(page,nienkhoa,dk);
		}
		Khung_ho_tro(page,0);
	}
	if(dk==3)
	{
		vehcn(50,50,1480,100,BLACK,WHITE,WHITE,"HIEU CHINH LOP",5);
		vehcn(40,170,370,200,BLACK,WHITE,WHITE,"- Nhap ma lop muon hieu chinh:",1);
		vehcn(40,210,370,280,BLACK,LIGHTGREEN,BLACK,"\0",1);
		outtextxy(45,230,malop_sua_xoa);
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(1430,115,1500,170,BLACK,CYAN,BLACK,"SUA",1);
		vehcn(1430,170,1500,595,BLACK,LIGHTCYAN,BLACK,"\0",1);
		line(1430,110,1500,110);
		line(1425,115,1500,115);
    	for (int i = 1; i <= 7; i++) 
		{
    		int y = 110 + i * 60;
    		line(1430, y, 1500, y);
    	}
    	line(1430,600,1500,600);
		line(1425,595,1500,595);
		setbkcolor(WHITE);
		outtextxy(70,80,"--Nhap nien khoa--");
		vehcn(60,115,280,170,BLACK,LIGHTGREEN,BLACK,"\0",1);
		if(dksearch==0) InDanhSachLop(page,dk);
		else if(dksearch==1) {
			outtextxy(100,130,nienkhoa);
			InLopTheoNienKhoa(page,nienkhoa,dk);
		}
		Khung_ho_tro(page,0);
	}
	if(dk==4)
	{
		cleardevice();
		vehcn(50,670,200,720,BLACK,RED,BLACK,"QUAY LAI",1);
		vehcn(1240,670,1390,720,BLACK,LIGHTGREEN,BLACK,"SUA",1);
		vehcn(0,0,1530,200,BLACK,WHITE,WHITE,"-----HIEU CHINH LOP-----",5);
		KhungNgoai();
		vehcn(300,200,1220,320,BLACK,WHITE,BLACK,"\0",1);
		vehcn(305,205,1215,260,BLACK,CYAN,BLACK,"\0",1);
		outtextxy(370,220,"MA LOP");
	    outtextxy(720,220,"TEN LOP");
	    outtextxy(1070,220,"NIEN KHOA");
		vehcn(305,260,1215,315,BLACK,LIGHTCYAN,BLACK,"\0",1);
		line(300,260,1220,260);
		line(550,200,550,320);
		line(1020,200,1020,320);
		outtextxy(320,275,dslop.node[vi_tri_lop_sua]->MALOP);
		outtextxy(580,275,dslop.node[vi_tri_lop_sua]->TENLOP);
		outtextxy(1070,275,dslop.node[vi_tri_lop_sua]->Nienkhoa);
	}
	if(dk==5){
		cleardevice();
		vehcn(1050,670,1200,720,BLACK,LIGHTRED,BLACK,"NO",1);
		vehcn(1240,670,1390,720,BLACK,LIGHTGREEN,BLACK,"YES",1);
		vehcn(0,0,1530,200,BLACK,WHITE,WHITE,"BAN CO CHAC CHAN MUON XOA?",4);
		KhungNgoai();
		vehcn(300,200,1220,320,BLACK,WHITE,BLACK,"\0",1);
		vehcn(305,205,1215,260,BLACK,CYAN,BLACK,"\0",1);
		outtextxy(370,220,"MA LOP");
	    outtextxy(720,220,"TEN LOP");
	    outtextxy(1070,220,"NIEN KHOA");
		vehcn(305,260,1215,315,BLACK,LIGHTCYAN,BLACK,"\0",1);
		line(300,260,1220,260);
		line(550,200,550,320);
		line(1020,200,1020,320);
		outtextxy(320,275,dslop.node[vi_tri_lop_sua]->MALOP);
		outtextxy(580,275,dslop.node[vi_tri_lop_sua]->TENLOP);
		outtextxy(1070,275,dslop.node[vi_tri_lop_sua]->Nienkhoa);
	}
	click_3(dsmon,dslop,dscht,check,page,dk,dksearch);
	closegraph();
}

//TRANG CHU
void trang2(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht, int &check)
{
	vehcn(0,0,1530,800,BLACK,WHITE,WHITE,"\0",2);
   	KhungNgoai();
   	setbkcolor(WHITE);
   	rectangle(500, 150, 1400, 600);
   	rectangle(505,155,1395,595);
   	line(500,220,1400,220);
   	line(500,225,1400,225);
   	settextstyle(BOLD_FONT,HORIZ_DIR,5);
   	outtextxy(800,50,"TRANG CHU");
   	outtextxy(780,190,"THONG TIN MOI");
   	vehcn(100,150,350,200,BLACK,GREEN,BLACK,"DANH SACH LOP",1);
   	vehcn(100,250,350,300,BLACK,GREEN,BLACK,"DANH SACH SINH VIEN",1);
   	vehcn(100,350,350,400,BLACK,GREEN,BLACK,"DANH SACH MON HOC",1);
   	vehcn(100,550,350,600,BLACK,GREEN,BLACK,"HUONG DAN SU DUNG",1);
   	vehcn(1250,670,1400,720,BLACK,RED,BLACK,"DANG XUAT",1);
   	if(check==1) vehcn(100,450,350,500,BLACK,GREEN,BLACK,"CAU HOI THI",1);
   	else if(check==2) vehcn(100,450,350,500,BLACK,GREEN,BLACK,"LAM BAI THI",1);
   	click_2(dsmon,dslop,dscht,check);
	closegraph;
}

//TRANG MAN HINH DANG NHAP
void trang1(List_MH &dsmon, List_LOP &dslop, treeCAUHOITHI &dscht)
{
	vehcn(0,0,1530,800,BLACK,WHITE,WHITE,"\0",2);
	//Chu "HOC VIEN CONG NGHE BUU CHINH VIEN THONG
	vehcn(0,50,1530,100,RED,WHITE,WHITE,"HOC VIEN CONG NGHE BUU CHINH VIEN THONG",4);
	vehcn(0,100,1530,150,RED,WHITE,WHITE,"CO SO TAI THANH PHO HO CHI MINH",4);
	//CHU "THI TRAC NGHIEM";
	vehcn(0,200,1530,280,RED,WHITE,WHITE,"THI TRAC NGHIEM",5);
	//CHU "Vui long dang nhap..."
	vehcn(0,300,1530,340,BLACK,WHITE,WHITE,"Vui long dang nhap...",2);
	//Khung dang nhap
	vehcn(560,350,970,460,BLACK,WHITE,BLACK,"\0",1);
	vehcn(565, 355, 965, 455,WHITE,BLACK,BLACK,"\0",1);
	outtextxy(575, 375 , "TEN DANG NHAP: ");
	outtextxy(575, 405, "MAT KHAU: ");
	//Khung nut THOAT
	vehcn(1350,700,1450,750,BLACK,RED,BLACK,"THOAT",1);
	//KhungNgoai();
	floodfill(100,100,WHITE);
   	setlinestyle(SOLID_LINE, 1, 3);
   	rectangle(15, 20, 1500, 775);
   	rectangle(10, 15, 1505, 780);
	//Khung log in
	vehcn(695,470,845,520,BLACK,GREEN,BLACK,"DANG NHAP",1);
	click_1(dsmon,dslop,dscht);
	closegraph();
}
