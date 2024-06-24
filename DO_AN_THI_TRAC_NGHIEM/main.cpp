#include<iostream>
#include<conio.h>
#include"khai_bao.h"
#include"graphic_window.h"
#include"xu_ly_login.h"

using namespace std;

int main(){
	List_MH dsMON;
	List_LOP dsLOP;
	treeCAUHOITHI dsCHT=NULL;
	OpenFile_DSMH(dsMON, "D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSMONHOC.txt");
	OpenFile_DSLOP(dsLOP,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\DSLOP.txt");
	OpenFile_DSCHT(dsCHT,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt");
	initwindow(1530,800);
	trang1(dsMON,dsLOP,dsCHT);
	FreeMemory(dsMON,dsLOP,dsCHT);
	return 0;
}
