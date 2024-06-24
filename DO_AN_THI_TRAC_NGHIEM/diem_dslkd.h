#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
#include <sstream>
#include "dslop_dslkdon.h"
#include "khai_bao.h"
#include"ham_lop.h"
using namespace std;
float StF(string s);
void XuatFile_diem(PTRSV sv) ;
void PrintDiem(PTRSV psv) ;
void AddDiem(PTRDIEM &First, Diemthi dt);

PTRDIEM NewNodeDiem(Diemthi dt) 
{
    PTRDIEM p = new nodeDIEM;
    p->dt = dt;
    p->next = NULL;
    return p;
}

PTRDIEM nodepointer_DIEM(PTRDIEM First, int i)
{
	PTRDIEM p;
	int vitri=1;
	p = First;
	while(p != NULL && vitri < i)
	{
		p = p->next;
		vitri++;
	}
	return(p);
}

int countNodes_DIEM(PTRDIEM head) {
    PTRDIEM current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void OpenScore(PTRSV psv)
{
    string s ="D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DiemThi\\" +string(psv->sv.MASV) +".txt";
	char cstr[s.length() + 1];
	strcpy(cstr, s.c_str());
	ifstream file(cstr);
	
    if (!file.is_open())	return;

    else if(is_file_empty(cstr))
    {
    	psv->sv.ds_diem = NULL;
    	return;
	}
    else
	{	
		string line;
    	while (getline(file, line)) 
		{
			if (line.empty()) continue;
			Diemthi dt;
        	stringstream ss(line);
        	getline(ss, line, '|');
        	strcpy(dt.MAMH, line.c_str());       	
        	getline(ss, line, '\n');
        	dt.Diem = StF(line.c_str());
			if (psv->sv.ds_diem == NULL) 
			{
                psv->sv.ds_diem = NewNodeDiem(dt);
        	} 
			else AddDiem(psv->sv.ds_diem,dt);
		}
        file.close();
	}
}

int SearchMaLop(List_LOP &ds, char *s) {
  for (int i =0; i < ds.n ; i++)
     if (strcmp(ds.node[i]->MALOP,s) == 0 ) return i;
  return -1;
}

void AddDiem(PTRDIEM &head, Diemthi dt) 
{
    PTRDIEM p = NewNodeDiem(dt);
    if (head == NULL) 
	{
        head = p;
    } 
	else 
	{
        PTRDIEM temp = head;
        while (temp->next != NULL) 
		{
            temp = temp->next;
        }
        temp->next = p;
    }
}

void Nhap(Diemthi &dt)
{
	cout<<"Nhap ma mon: "; cin>>dt.MAMH;
	cout<<"Nhap diem: "; cin>>dt.Diem;
}

void InputDiem(char ma_sv[],char ma_lop[],char ma_mon[],float diem) 
{
	List_LOP dsLOP;
	OpenFile_DSLOP(dsLOP, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
	OpenFile_SV(dsLOP,ma_lop);
	PTRSV psv_add = search_info(dsLOP.node[Search(dsLOP,ma_lop)]->dssv,ma_sv);

	Diemthi dt;
	strcpy(dt.MAMH,ma_mon);
	dt.Diem = diem;
	OpenScore(psv_add);
    AddDiem(psv_add->sv.ds_diem, dt);	
	//PrintDiem(psv_add);
	XuatFile_diem(psv_add);
}


float StF(string s)
{
	return stof(s);
}

int  DelAfter(PTRDIEM p)
{   
	PTRDIEM q;
   	if((p == NULL) || (p->next == NULL))	return 0;
    q = p->next;  // q chi nut can xoa
    p->next = q->next;
    delete q;
    return 1;
}

int empty(PTRDIEM First)
{
   return(First == NULL ? 1 : 0);
}

int DelFirst (PTRDIEM  &First)
{ 	
	PTRDIEM p;
   	if (empty(First)) return 0;
    p = First;    // nut can xoa la nut dau
    First = p->next;
    delete p; 
    return 1;
}

void PrintDiem(PTRSV psv,int page) 
{
	List_MH dsmon;
	OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
	//ifstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
	int i =1, j;
	PTRDIEM p = psv->sv.ds_diem;
	PTRDIEM check;
	int c1,c2, cnt = 0;
	c1 = (page - 1) *7;
	c2 = page *7;
    while (p != NULL) 
	{	
		if(cnt >= c1 && cnt < c2)
		{
			for(int k = 0; k < dsmon.n; k++)
			{
				if (strcmp(p->dt.MAMH, dsmon.node[k].MAMH) == 0 )
				{
					outtextxy(570,180+i*60,dsmon.node[k].TENMH);
		    	}
			}
	  		char DiemTmp[5];
			snprintf(DiemTmp, sizeof(DiemTmp), "%.2f", p->dt.Diem);
	        outtextxy(1160+textwidth("    ")/2,180+i*60,DiemTmp);
	        outtextxy(1330,180+i*60,"Xem");
	        i++;
		}
		p=p->next;
    }
}



void XuatFile_diem(PTRSV psv) 
{
	string s = "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DiemThi\\" + string(psv->sv.MASV) +".txt";
	char cstr[s.length() + 1];
	strcpy(cstr, s.c_str());
	ofstream f(cstr);
	
    if (f.is_open()) 
	{
		PTRDIEM p = psv->sv.ds_diem;
		while (p!= NULL)
		{	
	    	f << p->dt.MAMH<<"|"<<p->dt.Diem<<endl;
	    	p = p->next;
		}
	    f.close();     
	} 
	else ;
    //cout << "Khong the mo file" <<cstr<<" de ghi." << endl;
	//cout << "Da xuat danh sach sinh vien vao file " <<cstr << endl;
}


void Show(char ma_lop[],char ma_sv[],int page)
{
    List_LOP dsLOP;
    OpenFile_DSLOP(dsLOP, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
	OpenFile_SV(dsLOP,ma_lop);
	SV sv;
	PTRSV psv_add;
	strcpy(sv.MASV,ma_sv);
	psv_add = search_info(dsLOP.node[Search(dsLOP,ma_lop)]->dssv,sv.MASV);
	char HoTen[62];
	OpenScore(psv_add);
	PrintDiem(psv_add,page); 
	
	strcpy(HoTen,psv_add->sv.HO);
	strcat(HoTen," ");
	strcat(HoTen,psv_add->sv.TEN);
	setbkcolor(WHITE);
    outtextxy(50+textwidth("Ho va ten: "),270,HoTen);
    outtextxy(50+textwidth("MSSV: "),320,psv_add->sv.MASV);
    outtextxy(50+textwidth("Lop: "),370,dsLOP.node[Search(dsLOP,ma_lop)]->TENLOP);
}

bool CheckEmpty(char ma_sv[])
{
	string s = "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DiemThi\\" + string(ma_sv) +".txt";
	char cstr[s.length() + 1];
	strcpy(cstr, s.c_str());
	return is_file_empty(cstr);
}

bool CheckDaThi(PTRSV psv, char mamon[])
{
	string s ="D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DiemThi\\" +string(psv->sv.MASV) +".txt";
	char cstr[s.length() + 1];
	strcpy(cstr, s.c_str());
	ifstream file(cstr);
	
    if (!file.is_open()) return 0;

    else if(is_file_empty(cstr))
    {
    	psv->sv.ds_diem = NULL;
    	return 0;
	}
    else
	{	
		string line;
    	while (getline(file, line)) 
		{
			if (line.empty()) continue;
			Diemthi dt;
        	stringstream ss(line);
        	getline(ss, line, '|');
        	strcpy(dt.MAMH, line.c_str());    
			if(strcmp(dt.MAMH,mamon)==0) return 1;   	
        	getline(ss, line, '\n');
		}
        file.close();
	}
	return 0;
}

void PrintDiem_MonHoc(char MaLop[], char MaMon[],int page)
{	
	List_LOP dslop;
	OpenFile_DSLOP(dslop,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
	OpenFile_SV(dslop,MaLop);
	PTRSV psv = dslop.node[Search(dslop,MaLop)]->dssv;
	PTRDIEM p;
	int c1,c2, cnt = 0;
	c1 = (page - 1) *7;
	c2 = page *7;
	int dem = 1;
	bool flag;
	char DiemTmp[5];
	while(psv!=NULL)
	{
		flag =0;
		OpenScore(psv);
		p = psv->sv.ds_diem;
		while(p!=NULL)
		{
			if(strcmp(p->dt.MAMH,MaMon)==0)
			{
				snprintf(DiemTmp, sizeof(DiemTmp), "%.2f", p->dt.Diem);
				flag =1;
				break;
			} 
			p = p->next;
		}
		if(cnt >= c1 && cnt < c2)
		{
			outtextxy(505+(195-textwidth(psv->sv.MASV))/2,160+30*dem,psv->sv.MASV);
			outtextxy(700,160+30*dem,psv->sv.HO);
			outtextxy(1030,160+30*dem,psv->sv.TEN);
			outtextxy(1145+(100-textwidth(BtC(psv->sv.PHAI)))/2,160+30*dem, BtC(psv->sv.PHAI));
			if(flag == 1) outtextxy(1205+(250-textwidth("00.00"))/2,160+30*dem,DiemTmp);
			else 
			{
				setcolor(RED);
				outtextxy(1205+(250-textwidth("Chua thi"))/2,160+30*dem,"Chua thi");
				setcolor(BLACK);
			}
			dem+=2;
		}
		cnt++;
		psv = psv->next;
	}
}


