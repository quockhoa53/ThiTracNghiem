#ifndef HAMLOP_H
#define HAMLOP_H
#include"khaibao.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

void themLop(List_LOP &list_lop) {
    LOP *lop = new LOP();
    cout << "Nhap ma lop: ";
    cin>>lop->MALOP;
    cout << "Nhap ten lop: ";
    cin>> lop->TENLOP;
    cout << "Nhap nien khoa: ";
    cin>> lop->Nienkhoa;
    
    list_lop.node[list_lop.n] = lop;
    list_lop.n++;
}

void LietKe (List_LOP &ds) {
// 	system("cls") ;
 	printf ("                     DANH SACH LOP \n");
 	printf ("   Ma Lop      Ten Lop                   Nien Khoa\n");
 	for (int i =0 ; i < ds.n ; i++)
  	printf ("%-15s %-30s%-10s\n", ds.node[i]->MALOP, ds.node[i]->TENLOP, ds.node[i]->Nienkhoa);
// 	getch();
}
void xuatlop(List_LOP list_lop){
	for(int i=0; i<list_lop.n; i++){
            cout<< list_lop.node[i]->MALOP << "\n";
            cout << list_lop.node[i]->TENLOP << "\n";
            cout << list_lop.node[i]->Nienkhoa << "\n";
        }
}

void xuat_danh_sach_lop_ra_file(List_LOP &list_lop) {
    ofstream f("lop.txt");
    if (f.is_open()) {
    	for(int i=0; i<list_lop.n; i++){
            f << list_lop.node[i]->MALOP << ",";
            f << list_lop.node[i]->TENLOP << ",";
            f << list_lop.node[i]->Nienkhoa << "\n";
        }
        f.close(); 
        cout << "Da xuat danh sach lop vao file lop.txt" << endl;
    } else {
        cout << "Khong the mo file lop.txt de ghi." << endl;
    }
}

void DeleteItem (List_LOP &ds, int i){
	delete  ds.node[i];
    for (int j=i+1; j <ds.n; j++)
       ds.node[j-1]=ds.node[j];
    ds.n--;
}

void xoaLop(List_LOP &dsl, char malop[]) {
    //duyet dsl co lop can xoa hay khong
    int c=0;
    for(int i=0; i<dsl.n; i++){
    	if(strcmp(dsl.node[i]->MALOP, malop) == 0){
    		DeleteItem(dsl, i);
    		c=1;
    		break;
		}
	}
	if(c==1) cout<<"\nXoa thanh cong!\n";
	else cout<<"Khong tim thay lop can xoa!\n";
}


PTRSV new_node(SV sv) 
{
    PTRSV p = new nodeSV;
    p->dssv = sv;
    p->next = NULL;
    return p;
}


void input_sv(SV &sv) 
{
    cout << "Nhap ma sinh vien: ";
    cin.getline(sv.MASV, 15);

    cout << "Nhap ho sinh vien: ";
    cin.getline(sv.HO, 51);

    cout << "Nhap ten sinh vien: ";
    cin.getline(sv.TEN, 11);

    cout << "Nhap gioi tinh (1: Nam, 0: Nu): ";
    cin >> sv.PHAI;
    cin.ignore();

    cout << "Nhap password: ";
    cin.getline(sv.password, 20);
}


void add_sv(PTRSV &head, SV sv) 
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


void input_dssv(LOP &lop) 
{
    int n;
    cout << "Nhap so sinh vien cua lop: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) 
	{
        SV sv;
        input_sv(sv);
        add_sv(lop.dssv, sv);
    }
}


int find_lop(List_LOP &ds_lop, char malop[]) 
{
    for (int i = 0; i < ds_lop.n; i++) 
	{
        if (strcmp(ds_lop.node[i]->MALOP, malop) == 0) 
		{
            return i;
        }
    }
    return -1;
}

bool isFileEmpty(char fileName[]) {
    ifstream file(fileName);
    file.seekg(0, ios::end);
    int length = file.tellg();

    if (length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

    file.close();
}


void in_ds_sv_mot_lop(List_LOP ds_lop); 
void xuat_danh_sach_sinh_vien_ra_file(List_LOP ds_lop);
void tachChuoi(string chuoi, char* malop, char* tenlop, char* nienkhoa) 
{
    char* token = strtok((char*)chuoi.c_str(), ",");
    strcpy(malop, token);
    token = strtok(NULL, ",");
    strcpy(nienkhoa, token);
    token = strtok(NULL, ",");
    char* ptr = token;
    while (*ptr == ' ') ptr++;
    strcpy(tenlop, ptr);
}

 
void OpenFile(List_LOP& ds) {
    ifstream fin("lop.txt");
    if (!fin ) {
        cout << "Loi mo file de doc";
        return;
    }
    else if(isFileEmpty("lop.txt"))
    {
    	cout<<"File rong";
    	return;
	}
    	
    LOP lop;
    string s;
    int dem =0;
    string line;

	while (getline(fin, line)) 
	{

		cout <<line<<endl;

		tachChuoi(line,lop.MALOP,lop.TENLOP,lop.Nienkhoa);

        ds.node[ds.n] = new LOP;
        *ds.node[ds.n] = lop;
        ds.n++;

    }

    fin.close();
    cout << "Da load xong danh sach vao bo nho\n";
    xuatlop(ds);
}
void input_lop(List_LOP &ds_lop) 
{
	char ma_lop[15];
	cout << "Nhap ma lop can in danh sach sinh vien: ";
    cin.getline(ma_lop, 15);
    int i = find_lop(ds_lop,ma_lop);
	input_dssv(*(ds_lop.node[i]));

}

void xuat_danh_sach_sinh_vien_ra_file(List_LOP ds_lop,int j,char ma_lop[]) ;
void in_ds_sv_mot_lop(List_LOP ds_lop) 
{
	PTRSV p;
	LOP lop;
    char ma_lop[15];
    cout << "Nhap ma lop can in danh sach sinh vien: ";
    cin.getline(ma_lop, 15);
	int j;
    bool found = false;
    for (int i = 0; i < ds_lop.n; i++) 
	{
        lop = *(ds_lop.node[i]);
        if (strcmp(lop.MALOP, ma_lop) == 0) 
		{
            found = true;
            j = i;
            cout << "Ma lop: " << lop.MALOP << endl;
            cout << "Ten lop: " << lop.TENLOP << endl;
            cout << "Nien khoa: " << lop.Nienkhoa << endl;
            cout << "Danh sach sinh vien: " << endl;
            p = lop.dssv;
            while (p != NULL) 
			{
                cout << p->dssv.MASV << " - " << p->dssv.HO << " " << p->dssv.TEN << endl;
                p = p->next;
            }

            break;
        }
    }
	
    if (!found) 
	{
        cout << "Khong tim thay lop co ma " << ma_lop << endl;
    }
	xuat_danh_sach_sinh_vien_ra_file(ds_lop,j,ma_lop);
}


void xuat_danh_sach_sinh_vien_ra_file(List_LOP ds_lop,int j, char ma_lop[]) 
{
	LOP lop;

		lop = *(ds_lop.node[j]);
		string s = string(ma_lop) +".txt";
		char cstr[s.length() + 1];
		strcpy(cstr, s.c_str());
    	ofstream f(cstr);
    	if (f.is_open()) 
		{
			PTRSV p = lop.dssv;
	    	while(p != NULL )
	    	{
	    		f << p->dssv.MASV<< ","<< p->dssv.HO <<" "<<p->dssv.TEN<<"," <<p->dssv.PHAI<<","<<p->dssv.password<<endl;
	    		p = p->next;
			}
	        f.close(); 
	        
	    } 
		else 
		{
        	cout << "Khong the mo file" <<cstr<<" de ghi." << endl;
    	}

	cout << "Da xuat danh sach sinh vien vao file " <<cstr << endl;
}






        
#endif

