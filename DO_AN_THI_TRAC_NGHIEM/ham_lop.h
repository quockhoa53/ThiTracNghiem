#pragma once
#include"khai_bao.h"
#include "ham_nhap.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstring>
#include <fstream>
#include<sstream>
#include<iomanip>
using namespace std;

int CheckClass(char *malop){
	string s = "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\Lop\\"+string(malop) +".txt";
    ifstream file(s.c_str());
	if(file.is_open()) {
		string line;
		getline(file,line);
		if(line=="\0") return 0;
		file.close();
		return 1;	
	}
	else{
		return 0;	
	}
}

void SaveFile_DSLOP(List_LOP &dslop, char *filename) {
	ofstream file(filename);
	if(file.is_open()){
		for(int i=0; i<dslop.n; i++){
			file << dslop.node[i]->MALOP << "|";
			file << dslop.node[i]->TENLOP << "|";
			file << dslop.node[i]->Nienkhoa << "\n";
		}
//		cout<<"luu file "<<filename<<" thanh cong!";
		file.close();
	} else {
//		cout<<"khong the mo file "<<filename<<" de luu";
		return;
	}
}

void OpenFile_DSLOP(List_LOP& dslop, char*filename) {
	dslop.n=0;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if(line=="\0") {
                break;
            }
            LOP* lop = new LOP;
            stringstream ss(line);
            getline(ss, line, '|');
            strcpy(lop->MALOP, line.c_str());
            getline(ss, line, '|');
            strcpy(lop->TENLOP, line.c_str());
            getline(ss, line, '\n');
            strcpy(lop->Nienkhoa, line.c_str());
            dslop.node[dslop.n++] = lop;
        }
//      cout<<"doc file "<<filename<<" thanh cong!\n";
        file.close();
    } else{
//    	cout<<"khong the mo file "<<filename<<endl;
    	return;	
	} 
}


int Search(List_LOP &ds, char *s) {
  for (int i =0; i < ds.n ; i++)
     if (strcmp(ds.node[i]->MALOP,s) == 0 ) return i;
  return -1;
}

int Search_nienkhoa(List_LOP &ds, char *s) {
	if(strcmp(ds.node[0]->Nienkhoa,s)>0) return 0;
	else if(strcmp(ds.node[ds.n-1]->Nienkhoa,s)<0) return 0;
	else{
		for (int i =0; i < ds.n ; i++)
    		if (strcmp(ds.node[i]->Nienkhoa,s) == 0 ) return 1;
  		return 0;	
	}
}

void DeleteItem(List_LOP &ds, int i){
	delete  ds.node[i];
    for (int j=i+1; j <ds.n; j++)
       ds.node[j-1]=ds.node[j];
    ds.n--; 
}

//void AddClass(List_LOP &listLop, LOP *lopMoi) {
//  	if (listLop.n == MAX_LOP) {
//    	return;
//  	}
//  	listLop.node[listLop.n] = lopMoi;
//  	listLop.n++;
//}

void InsertClass(List_LOP &listLop, LOP *lopMoi) {
	if (listLop.n == MAX_LOP) {
		setcolor(RED);
		setbkcolor(WHITE);
		outtextxy(350,400,"--Lop da day! Khong the them!--");
		delay(2000);
		outtextxy(350,400,"                               ");
		setbkcolor(LIGHTCYAN);	
		setcolor(BLACK);
  		return;
  	}
  	else if(listLop.n<MAX_LOP){
  		listLop.node[listLop.n] = lopMoi;
  		listLop.n++;
  		int i=listLop.n-1;
		for(i; i>0; ){
			if(strcmp(listLop.node[i]->Nienkhoa,listLop.node[i-1]->Nienkhoa)<0){
				LOP *lop=listLop.node[i];
				listLop.node[i]=listLop.node[i-1];
				listLop.node[i-1]=lop;
				i--;
			}
			else break;
		}
		for(int j=i; j>0; j--){
			if(strcmp(listLop.node[j]->Nienkhoa,listLop.node[j-1]->Nienkhoa)==0 
			&& strcmp(listLop.node[j]->MALOP,listLop.node[j-1]->MALOP)<0){
				LOP *lop=listLop.node[j];
				listLop.node[j]=listLop.node[j-1];
				listLop.node[j-1]=lop;
			}
			else break;
		}	
	}
}

char* inttochar(int x)
{
    char* result = new char[20];
    sprintf(result, "%d", x);
    return result;
}

void OpenFile_DSLOP_TheoNienKhoa(List_LOP& dslop, char* filename, char* nienkhoa) {
	dslop.n=0;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line == "\0") {
                break;
            }
            LOP* lop = new LOP;
            stringstream ss(line);
            getline(ss, line, '|');
            strcpy(lop->MALOP, line.c_str());
            getline(ss, line, '|');
            strcpy(lop->TENLOP, line.c_str());
            getline(ss, line, '\n');
            strcpy(lop->Nienkhoa, line.c_str());
            if (strcmp(lop->Nienkhoa, nienkhoa) == 0) { 
                dslop.node[dslop.n++] = lop; 
            } else {
                delete lop; 
            }
        }
//        cout<<"mo file "<<filename<<" thanh cong\n";
        file.close();
    } else {
//    	cout<<"khong the mo file "<<filename<<endl;
        return;
    }
}

void InLopTheoNienKhoa(int page, char nienkhoa[], int &dk){
	setcolor(BLACK);
	setbkcolor(LIGHTCYAN);
	List_LOP dslop;
	OpenFile_DSLOP_TheoNienKhoa(dslop,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt",nienkhoa);
	int i=(page-1)*7;
	char*s;
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	int y = 190;
	for (i; i < dslop.n && i<page*7; i++)
	{
	    s=inttochar(i+1);
		outtextxy(420,y,s);
		outtextxy(520, y, dslop.node[i]->MALOP);
		outtextxy(690, y, dslop.node[i]->TENLOP);
		outtextxy(1170, y, dslop.node[i]->Nienkhoa);
		setcolor(BLUE);
		outtextxy(1340,y,"Xem...");
		if(dk==2){
			setcolor(RED);
		    outtextxy(1445,y,"Xoa");	
		}
		if(dk==3){
			setcolor(RED);
		   	outtextxy(1445,y,"Sua");	
		}
		setcolor(BLACK);
		y += 60;	
	}
}

//Doc_file DANH SACH LOP
void InDanhSachLop(int page, int &dk)
{
	setcolor(BLACK);
	setbkcolor(LIGHTCYAN);
	int i=(page-1)*7;
    List_LOP dslop;
	dslop.n = 0;
	char*s;

    OpenFile_DSLOP(dslop, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
	
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	
    int y = 190;
    for (i; i < dslop.n && i<page*7; i++)
    {
    	s=inttochar(i+1);
    	outtextxy(420,y,s);
        outtextxy(520, y, dslop.node[i]->MALOP);
        outtextxy(690, y, dslop.node[i]->TENLOP);
        outtextxy(1170, y, dslop.node[i]->Nienkhoa);
        setcolor(BLUE);
		outtextxy(1340,y,"Xem...");
		if(dk==2){
			setcolor(RED);
    		outtextxy(1445,y,"Xoa");	
		}
		if(dk==3){
			setcolor(RED);
	    	outtextxy(1445,y,"Sua");	
		}
		setcolor(BLACK);
        y += 60;	
    }
}

