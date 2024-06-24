#ifndef KHAIBAO_H
#define KHAIBAO_H
#include <bits/stdc++.h>
const int MAX_MH=300;
struct MH
{
	char MAMH[15], TENMH[50]; 
}; 
struct List_MH
{
	int n=0;
	MH node[MAX_MH];
};
struct Diemthi
{
	char MAMH[15];
	float Diem ;
}; 
struct nodeDIEM
{
	Diemthi dt;
	nodeDIEM *next;
}; 
typedef nodeDIEM *PTRDIEM;
struct SV
{
	char MASV[15], HO[51], TEN[11];
	bool PHAI;
	char password[20];
	PTRDIEM ds_diem=NULL; 
}; 
struct nodeSV
{
	SV dssv;
	nodeSV *next;
}; 
typedef nodeSV *PTRSV;
const int MAX_LOP=500; 
struct LOP
{
	char MALOP[15], TENLOP[30], Nienkhoa[10];
	PTRSV dssv=NULL;
}; 
struct List_LOP
{
	int n=0;
	LOP *node[MAX_LOP];
};
struct CAUHOITHI 
{
    int Id; 
    char MAMH[15]; 
    char NoiDung[200]; 
    char A[100], B[100], C[100], D[100];
	char DapAn; 
};
struct nodeCAUHOITHI 
{
	CAUHOITHI QUES;
	nodeCAUHOITHI *left, *right;
};
typedef nodeCAUHOITHI *treeCAUHOITHI;

#endif
