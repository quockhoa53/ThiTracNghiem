#pragma once
#include"khai_bao.h"
#include"ham_lop.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

void XuatFile_SV(List_LOP ds_lop,int j,char ma_lop[]);
void OpenFile_SV(List_LOP& dslop, char ma_lop[]);

char* StC(const string& s)
{
    char* cstr = new char[s.length() + 1];
    strcpy(cstr, s.c_str());
    return cstr;
}

PTRSV new_node(SV sv) 
{
    PTRSV p = new nodeSV;
    p->sv = sv;
    p->next = NULL;
    return p;
}

void add_sv(PTRSV &First, SV sv) 
{
   	PTRSV p, t, s;  // t la nut truoc, s la nut sau
   	p = new_node(sv);
   	for(s = First; s != NULL && strcmp(s->sv.MASV,sv.MASV) <0 ; t=s, s = s->next)   ;
 	if (s == First)  // them nut vao dau danh sach lien ket
   	{
      	p->next = First;
      	First = p;
   	}
   	else           // them nut p vao truoc nut s
   	{
      	p->next= s;
      	t->next= p;
   	}
}


void input_lop(List_LOP &dslop, char ma_lop[] , SV sv) 
{
    int i = Search(dslop,ma_lop);
    add_sv(dslop.node[i]->dssv, sv);	
   	XuatFile_SV(dslop,i,ma_lop);
}

char* BtC(bool c)
{
	if(c == 1)
		return "1";
	else return "0";
}

bool StB(string s)
{
	if(s=="1")
		return 1;
	else if(s=="0") return 0; 
}

bool trung_ma(List_LOP &dslop,char ma_lop[], char ma_sv[])
{
	PTRSV p = dslop.node[Search(dslop,ma_lop)]->dssv;
	while(p!=NULL)
	{
		if(strcmp(p->sv.MASV,ma_sv )==0)	return 1;
		else p=p->next;
	}
	return 0;
}

int count(PTRSV p)
{
   int cnt=0;
   while(p != NULL)
   {
      cnt++;
      p = p->next;
   }
   return cnt;
}

bool is_file_empty(string filename) 
{
    ifstream file(filename);
    return file.peek() == ifstream::traits_type::eof();
}

void OpenFile_SV(List_LOP& dslop, char ma_lop[])
{
    string s = "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\Lop\\"+string(ma_lop) +".txt";
	ifstream file(s);
	int i = Search(dslop,ma_lop);
    if (is_file_empty(s))	return;

    else if(is_file_empty(StC(s)))
    {
    	dslop.node[i]->dssv = NULL;
    	return;
	}
    else
	{	
		string line;
    	while (getline(file, line)) 
		{
			if (line.empty()) continue;
			SV sv;
        	stringstream ss(line);
        	getline(ss, line, '|');
        	strcpy(sv.MASV, line.c_str());
        	getline(ss, line, '|');
        	strcpy(sv.HO, line.c_str());
        	getline(ss, line, '|');
        	strcpy(sv.TEN, line.c_str());
        	getline(ss, line, '|');	
        	sv.PHAI = StB(line);       	
        	getline(ss, line, '\n');
        	strcpy(sv.password, line.c_str());
			if (dslop.node[i]->dssv == NULL) dslop.node[i]->dssv = new_node(sv);
			else add_sv(dslop.node[i]->dssv, sv);	
		}
        file.close();
	}
}

int Empty(PTRSV First)
{
   return(First == NULL ? 1 : 0);
}


int Delete_First (PTRSV  &First)
{ 	
	PTRSV p;
   	if (Empty(First)) return 0;
    p = First;    // nut can xoa la nut dau
    First = p->next;
    delete p; 
    return 1;
}

int  Delete_After(PTRSV p)
{   
	PTRSV q;
   	if((p == NULL) || (p->next == NULL))	return 0;
    q = p->next;  // q chi nut can xoa
    p->next = q->next;
    delete q;
    return 1;
}


int Delete_Info(PTRSV &First, char ma_sv[])
{
	PTRSV p=First;
  	if (First==NULL ) return 0;
  	if (strcmp(First->sv.MASV,ma_sv )==0)
  	{
  		Delete_First(First); return 1;
	}
	for ( p=First; p->next!=NULL && strcmp(p->next->sv.MASV, ma_sv) != 0; p=p->next) ;  
	if (p->next!= NULL ) 
	{
		Delete_After(p);  
		return 1;
	}
    return 0;
}

int vitrinode(PTRSV first, PTRSV p_truyen)
{
	PTRSV p = first;
	int vitri =1;
	while(p!=NULL&& strcmp(p->sv.MASV,p_truyen->sv.MASV)!=0)
	{
		vitri++;
		p=p->next;
	}
	if(p == NULL) return -1;
	return vitri;
}

PTRSV nodepointer(PTRSV First, int i)
{
	PTRSV p;
	int vitri=1;
	p = First;
	while(p != NULL && vitri < i)
	{
		p = p->next;
		vitri++;
	}
	return(p);
}


PTRSV search_info(PTRSV First, char ma_sv[])
{
	PTRSV p;
	p = First;
	while(p != NULL && (strcmp(p->sv.MASV, ma_sv) != 0 ) )
		p = p->next;
	return(p);
}

int countNodes(PTRSV head) {
    PTRSV current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int sua(List_LOP &dslop, char ma_lop[], char ma_sv[], SV sv)
{
	int i = Search(dslop,ma_lop);
	PTRSV First = dslop.node[i]->dssv; 
	PTRSV p= First;
	
  	if (First==NULL ) return 0;
	for ( p=First; p!=NULL && strcmp(p->sv.MASV, ma_sv) != 0; p=p->next) ;  
	if (p!= NULL ) 
	{
		p->sv = sv;
		XuatFile_SV(dslop,i,ma_lop);
		return 1;
	}
    return 0;
}


void XuatFile_SV(List_LOP ds_lop,int j, char ma_lop[]) 
{
	LOP lop;
	lop = *(ds_lop.node[j]);
	string s = "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\Lop\\"+string(ma_lop) +".txt";
	ofstream f(s);
    if (f.is_open()) 
	{
		PTRSV p = lop.dssv;
		while (p!= NULL)
		{	
			f << p->sv.MASV<< "|"<< p->sv.HO <<"|"<<p->sv.TEN<<"|" <<p->sv.PHAI<<"|"<<p->sv.password<<endl;
	    	p = p->next;
		}
	    f.close();     
	} 
	else;
}

void add_sv_tim(PTRSV &head, SV sv) 
{
    PTRSV p = new_node(sv);
    if (head == NULL) 
	{
        head = p;
    } 
	else 
	{
        PTRSV temp = head;
        while (temp->next != NULL) 
		{
            temp = temp->next;
        }
        temp->next = p;
    }
}

void Clearlist(PTRSV &First)  
{  
   	PTRSV p;  
  	while(First != NULL) Delete_First(First);
}

