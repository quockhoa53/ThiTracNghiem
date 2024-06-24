#pragma once
#include "khai_bao.h"
#include <bits/stdc++.h>
#include "xu_ly_login.h"
#include "cauhoithi.h";
#include <graphics.h> 
using namespace std;


int Full(List_MH &ds)
{ 
	return ds.n==MAX_MH ;
}

int Delete_item (List_MH &ds, int i)
{
	if(i < 0 || i >= ds.n || ds.n == 0) 
		return 0;
	for(int j = i+1;  j< ds.n ; j++)
		ds.node[j-1] = ds.node[j];
	ds.n--;
	return 1; 
}
		
void OpenFile_DSMH(List_MH& dsmon, char*filename)
{
    ifstream file(filename);
    if (!file.is_open())
	{
        cout<<"Khong the load file!"<<endl; 
		return;
    }
    else
	{
    		string line;
        	while (getline(file, line)) {
        		if(line=="\0") continue;
            	MH mh;
            	stringstream ss(line);
            	getline(ss, line, '|');
            	strcpy(mh.MAMH, line.c_str());
            	getline(ss, line, '\n');
            	strcpy(mh.TENMH, line.c_str());
            	dsmon.node[dsmon.n++] = mh;
			}
        file.close();
        //Sap xep theo ma mon hoc bang thuat toan insertion sort
   		for (int i = 1; i < dsmon.n; i++) 
		{
        	MH key = dsmon.node[i];
        	int j = i - 1;
        	while (j >= 0 && strcmp(dsmon.node[j].MAMH, key.MAMH) > 0)
			{
            	dsmon.node[j + 1] = dsmon.node[j];
            	j--;
       		}
        dsmon.node[j + 1] = key;
    	}
	}
	file.close();
}	

//void Remove(List_MH& dsmon) {
//    int Index = 0; // Chi so cua mon hien tai
//
//    for (int i = 1; i < dsmon.n; i++) {
//        if (strcmp(dsmon.node[Index].MAMH, dsmon.node[i].MAMH) != 0) {
//            Index++; // Tim thay 1 mon, tang chi so mon len
//
//            if (Index != i) {
//                dsmon.node[Index] = dsmon.node[i]; // gan mon vao vi tri duy nhat
//            }
//        }
//    }
//    dsmon.n = Index + 1;
//}

void Delete_mamon(List_MH &dsmon, char *s)
{
	dsmon.n = 0;
	OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
//	Remove(dsmon);
	fstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt", ios::out);
	MH mh;
	strcpy(mh.MAMH, s);
	bool isDeleted = false;
	for(int i = 0; i < dsmon.n; i++)
	{
		if(strcmp(mh.MAMH, dsmon.node[i].MAMH) == 0) 
		{ 
			Delete_item(dsmon,i);
			isDeleted = true;
			i--;
		}
		else
		{	
			if(i != (dsmon.n-1)) 
				file << dsmon.node[i].MAMH << "|" << dsmon.node[i].TENMH << endl;
			else 	
				file << dsmon.node[i].MAMH << "|" << dsmon.node[i].TENMH;
		}	
	}
	if (dsmon.n == 0 && isDeleted) file << endl;
	file.close();
}

void Delete_tenmon(List_MH &dsmon, char *s)
{
	dsmon.n = 0;
	OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
//	Remove(dsmon);
	fstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt", ios::out);
	MH mh;
	strcpy(mh.TENMH, s);
	bool isDeleted = false;
	for(int i = 0; i < dsmon.n; i++)
	{
		if(strcmp(mh.TENMH, dsmon.node[i].TENMH) == 0)	
		{
			Delete_item(dsmon,i);
			isDeleted = true;
			i--;
		}
		else
		{
			if(i != (dsmon.n-1)) 
				file << dsmon.node[i].MAMH << "|" << dsmon.node[i].TENMH << endl;
			else 	
				file << dsmon.node[i].MAMH << "|" << dsmon.node[i].TENMH;
		}	
	}
	if (dsmon.n == 0 && isDeleted) file << endl;
	file.close();
}

void Search_monhoc(List_MH &dsmon, char *s)  
{
	OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
	ifstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
	MH mh;
	strcpy(mh.TENMH, s);
	for(int i = 0; i < dsmon.n; i++)
	{
		if ((strcmp(mh.TENMH, dsmon.node[i].MAMH) == 0) || (strcmp(mh.TENMH, dsmon.node[i].TENMH) == 0))
		{
	    	ofstream tempfile("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_temp.txt", ios::app);
            tempfile << dsmon.node[i].MAMH << "|" << dsmon.node[i].TENMH << endl;
            tempfile.close();
            break;
    	}
	}
	file.close();
}

void Search_chuoicon(List_MH &dsmon, char *s)  
{
	ifstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
	MH mh;
	strcpy(mh.TENMH, s);
	for(int i = 0; i < dsmon.n; i++)
	{
		if ((strstr(dsmon.node[i].MAMH, s) != NULL) || (strstr(dsmon.node[i].TENMH, s) != NULL))
		{
	    	ofstream tempfile("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_SEARCH.txt", ios::app);
            tempfile << dsmon.node[i].MAMH << "|" << dsmon.node[i].TENMH << endl;
            tempfile.close();
    	}
	}
	file.close();
}

void Alter_mamon(string oldCode, string newCode)
{
    ifstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
    if (!file.is_open())
	{
        cout << "Khong tim thay file DSMONHOC.txt" << endl;
    }
    string content;
    string line;
    while (getline(file, line)) 
	{
        content += line + '\n';
    }
    size_t pos = content.find(oldCode + "|");
    if (pos != string::npos) 
	{
        content.replace(pos, oldCode.length(), newCode);
    }
    file.close();
    ofstream outfile("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
    outfile << content;
    outfile.close();
    cout << "Da thay doi xong" << endl;
}

void Alter_tenmon(string oldName, string newName)
{
	ifstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
    if (!file.is_open())
	{
        cout << "Khong tim thay file DSMONHOC.txt" << endl;
    }
    string content;
    string line;
    while (getline(file, line)) 
	{
        content += line + '\n';
    }
    size_t pos = content.find("|" + oldName);
    if (pos != string::npos) 
	{
        content.replace(pos + 1, oldName.length(), newName);
    }
    file.close();
    ofstream outfile("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
    outfile << content;
    outfile.close();
    cout << "Da thay doi xong" << endl;
}

void Docfile_huongdansudung()
{
    ifstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\huongdansudung.txt");
    if (!file.is_open())
    {
        cout << "Khong tim thay file huongdansudung.txt" << endl;
        return;
    }
    
    vector<string> v;
    string line;
    
    while (getline(file, line)) 
    {
        v.push_back(line);
    }
    
    file.close();
    
    int y = 160;
    setcolor(BLACK);
    setbkcolor(WHITE);
    
    for (const string& str : v) {
    	const char* constString = str.c_str();
    	char* tmp = const_cast<char*>(constString);
        outtextxy(100, y, tmp);
        y += 50;
    }
}


void Docfile_temp(int check)
{
//	remove("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_temp1.txt");
	ifstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_temp1.txt");
	vector <string> v;
    string line;
    while (getline(file, line)) 
	{
        stringstream ss(line);
        string token;
        while (getline(ss, token, ',')) 
		{
            v.push_back(token);
        }
    }
    int i = 0;
    while(i < v.size())
    {
    	if(kiemTraChuoiKhacKhoangTrang(v[i]) && kiemTraChuoiKhacKhoangTrang(v[i+1]))
    	{
	    	if(check==1)	
				Alter_mamon(v[i],v[i+1]);
	    	if(check==2)	
				Alter_tenmon(v[i],v[i+1]);
		}
    	i+=10;
	}
    file.close();
    remove("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC_temp1.txt");
}

int check_trung(List_MH& dsmon, string s)
{
	dsmon.n = 0;
	OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
    bool trung = false;
    ifstream file("D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
    if (!file.is_open())
    {
        cout << "Khong tim thay file DSMONHOC.txt" << endl;
        return trung;
    }
    MH mh;
    strcpy(mh.MAMH, s.c_str());
    for (int i = 0; i < dsmon.n; i++)
    {
        if (strcmp(mh.MAMH, dsmon.node[i].MAMH) == 0)
        {
            trung = true;
        }
    }
    return trung;
}

int SearchMAMON(treeCAUHOITHI root,const string& mamon) 
{
    if (root == NULL) 
	{
        return 0;
    }
    int dem = 0;
    if (mamon == root->QUES.MAMH) 
	{
		dem = 1;
    }
	dem+=SearchMAMON(root->left,mamon);
	dem+=SearchMAMON(root->right, mamon);
	return dem;
}

string TimMaMonTheoTenMon(List_MH &dsmon, char *tenmon)
{
	OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
	for (int i =0; i < dsmon.n ; i++)
    if (strcmp(dsmon.node[i].TENMH,tenmon) == 0 ) return dsmon.node[i].MAMH;
  return "";
}

string TimTenMonTheoMaMon(List_MH &dsmon, char *mamon)
{
	OpenFile_DSMH(dsmon, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
	for (int i =0; i < dsmon.n ; i++)
    if (strcmp(dsmon.node[i].MAMH,mamon) == 0 ) return dsmon.node[i].TENMH;
  return "";
}

int TimMaMon(List_MH dsmon, char *mamon){
	for (int i =0; i < dsmon.n ; i++)
     if (strcmp(dsmon.node[i].MAMH,mamon) == 0 ) return i;
  return -1;
}
