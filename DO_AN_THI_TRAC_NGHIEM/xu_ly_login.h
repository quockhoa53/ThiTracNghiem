#pragma once
#include <bits/stdc++.h>
#include "dslop_dslkdon.h"
#include <conio.h>
#include <fstream>
#include <graphics.h>
#include <string>
#include <sstream>

using namespace std;

string ten_dang_nhap;
int mat_khau, x_xoa_chu, y_xoa_chu;


bool ChuIn(char chr)
{
	if((chr>= 'a') && (chr<='z'))
	{
    	return 0;
  	}
  	else if((chr>= 'A') && (chr<='Z')){
    	return 1;
  	}
}

bool kytudb(char c)
{
	if((c >= 33 && c<= 47)||(c >= 58 && c<= 64)||(c >= 94 && c<= 96)||(c >= 123 && c<= 126)||c==32)
		return 1;
	else return 0;
}


void ghep_file(string s1, string s2, string out)
{
	ifstream file1(s1.c_str());
    ifstream file2(s2.c_str());
    ofstream file_out(out.c_str());
    file_out << file1.rdbuf() <<endl<< file2.rdbuf();
    file1.close();
    file2.close();
    file_out.close();
}

string dang_nhap()
{
	string tdn,chuoi,chuyen;
	int mk;
	
	tdn = ten_dang_nhap;
	mk = mat_khau;
	
	stringstream ss;
    ss << mk;
    string str = ss.str();
    
	cout <<endl;
	chuoi = tdn + '_' + str;
	
	return chuoi;
}

bool kiemTraChuoiKhacKhoangTrang(const string& chuoi) {
    for (size_t i = 0; i < chuoi.size(); ++i) 
	{
        if (!isspace(chuoi[i])) 
		{
            return true; 
        }
    }
    return false; 
}


int KiemTraDangNhap(List_LOP &dslop, char tendangnhap[], char matkhau[],int &IndexClass,PTRSV &psv_login){
	ifstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\giao_vien.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if(line=="\0") {
                break;
            }
            char tk[15];
            char mk[20];
            stringstream ss(line);
            getline(ss, line, '|');
            strcpy(tk, line.c_str());
            getline(ss, line, '\n');
            strcpy(mk, line.c_str());
        	if(strcmp(tk,tendangnhap)==0 && strcmp(mk,matkhau)==0) {
        		file.close();
				return 1;	
			}
        }
        file.close();
    } 
	for(IndexClass=0; IndexClass<dslop.n; IndexClass++){
		OpenFile_SV(dslop,dslop.node[IndexClass]->MALOP);
	//	PTRSV p;
		psv_login=dslop.node[IndexClass]->dssv;
		while(psv_login!=NULL){
			if(strcmp(psv_login->sv.MASV,tendangnhap)==0 && strcmp(psv_login->sv.password,matkhau)==0) return 2;
			else psv_login=psv_login->next;
		}
	}
	return 0;
}

void FreeDiemthi(PTRDIEM &ds_diem) {
    while (ds_diem != NULL) {
        PTRDIEM temp = ds_diem;
        ds_diem = ds_diem->next;
        delete temp;
    }
}

void FreeSV(PTRSV& sv) {
    while (sv != NULL) {
        FreeDiemthi(sv->sv.ds_diem);
        PTRSV temp = sv;
        sv = sv->next;
        delete temp;
    }
}

void FreeLOP(List_LOP& list_lop) {
    for (int i = 0; i < list_lop.n; i++) {
        FreeSV(list_lop.node[i]->dssv);
        delete list_lop.node[i];
    }
    list_lop.n = 0;
}

void FreeTreeCAUHOITHI(treeCAUHOITHI& root) {
    if (root != NULL) {
        FreeTreeCAUHOITHI(root->left);
        FreeTreeCAUHOITHI(root->right);
        delete root;
    }
    root = NULL;
}

void FreeMemory(List_MH& list_mon, List_LOP& list_lop, treeCAUHOITHI& root) {
	list_mon.n=0;
    FreeLOP(list_lop);
    FreeTreeCAUHOITHI(root);
}

void DoiKiTuThanhSao(char* s) {
    if (s == NULL)
        return;

    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = '*';
    }
}
