#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <cstring>
#include <windows.h>
#include <mylib.h>
#include <fstream>
#include<sstream>
#include<iomanip>

using namespace std;
const int MAX_LOP =500;

const int so_item = 7;
const int dong =10;
const int cot = 30 ;
const int Up = 72; 
const int Down = 80;

char thucdon [so_item][50] = {"1. THEM LOP                  ",
			                  "2. XOA THEO MA LOP           ",
			                  "3. HIEU CHINH LOP            ",
			                  "4. XUAT LOP                  ",
			                  "5. GHI LOP VAO FILE          ",
							  "6. IN LOP THEO NIEN KHOA     ",
							  "7. KET THUC CHUONG TRINH     "};

struct LOP
{
	char MALOP[15];
	char TENLOP[30];
	char Nienkhoa[10];
	//PTRSV dssv=NULL;
}; 
struct List_LOP
{
	int n=0;
	LOP *node[MAX_LOP];
};

void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(9);
}
int MenuDong(char td [so_item][50]){
  Normal();
  system("cls");   int chon =0;
  int i; 
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  }  // end switch
  } while (1);
}

void BaoLoi (char *s){
  int x=wherex() , y=wherey();
  gotoxy (10,24);
  cout <<s;
  Sleep(2000);
  gotoxy(10,24);
  clreol();
  gotoxy(x,y);
}

int Search(List_LOP &ds, char *s) {
  for (int i =0; i < ds.n ; i++)
     if (strcmp(ds.node[i]->MALOP,s) == 0 ) return i;
  return -1;
}

void ThemLop(List_LOP &listLop, LOP *lopMoi) {
  if (listLop.n == MAX_LOP) {
    cout << "Danh sach lop da day!" << endl;
    return;
  }
  listLop.node[listLop.n] = lopMoi;
  listLop.n++;
  cout << "Them lop thanh cong!" << endl;
}


void ThemDanhSachLop(List_LOP &listLop) {
	LOP *lopMoi;
  	while (true) {
  	lopMoi = new LOP;
    cout << "Nhap ma lop (nhap '0' de dung lai): ";
    fflush(stdin);
    gets(lopMoi->MALOP);
	//cin.getline(lopMoi->MALOP,10);
	if(Search(listLop,lopMoi->MALOP)>=0) {
		BaoLoi("Ma lop da ton tai!");
		delete lopMoi;
		continue;	
	}
    if (strcmp(lopMoi->MALOP, "\0") == 0) {
      	delete lopMoi;
      	break;
    }
    cout << "Nhap ten lop: ";
    fflush(stdin);
    gets(lopMoi->TENLOP);
	//cin.getline(lopMoi->TENLOP,50);
    cout << "Nhap nien khoa: ";
    fflush(stdin);
    gets(lopMoi->Nienkhoa);
	//cin.getline(lopMoi->NIENKHOA,10);
    ThemLop(listLop, lopMoi);
	}
}

void LietKe (List_LOP &ds) {
 	system("cls") ;
 	cout <<left <<setw(34)<<"                   DANH SACH LOP\n";
 	cout<<left<<setw(17)<<"\nMa Lop"<<left<<setw(30)<<"Ten Lop"<<left<<setw(10)<<"Nien Khoa\n";
 	for (int i =0 ; i < ds.n ; i++)
 	cout<<left<<setw(16)<<ds.node[i]->MALOP<<left<<setw(30)<<ds.node[i]->TENLOP<<left<<setw(10)<<ds.node[i]->Nienkhoa<<endl;
 	getch();
}

void SaveFile(List_LOP &list_lop, char *filename) {
    ofstream f(filename);
    //ofstream f("DSLOP.txt");
 	if(f.is_open()){
    	for(int i=0; i<list_lop.n; i++){
            f << list_lop.node[i]->MALOP << "|";
            f << list_lop.node[i]->TENLOP << "|";
            f << list_lop.node[i]->Nienkhoa;
            if(i!=list_lop.n-1) f<<endl;
        }
        f.close(); 
    	BaoLoi("Da ghi xong danh sach vao file");
    } else {
        BaoLoi("Khong the mo file de ghi"); return;
    }
}

void OpenFile(List_LOP& dslop, char *filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        BaoLoi("Khong the loa file"); return;
    }
    else{
    		string line;
        	while (getline(file, line)) {
        		if(line=="\0") break;
            	LOP* lop = new LOP;
            	stringstream ss(line);
            	getline(ss, line, '|');
            	strcpy(lop->MALOP, line.c_str());
            	getline(ss, line, '|');
            	strcpy(lop->TENLOP, line.c_str());
            	getline(ss, line, '\n');
            	strcpy(lop->Nienkhoa, line.c_str());
            	// Them lop vao danh sach
            	dslop.node[dslop.n++] = lop;
			}
        file.close();
        BaoLoi("Da load file thanh cong");
	}
}


void DeleteItem (List_LOP &ds, int i){
	delete  ds.node[i];
    for (int j=i+1; j <ds.n; j++)
       ds.node[j-1]=ds.node[j];
    ds.n--; 
}
void XoaLop(List_LOP &ds, char *malop){
   int i = Search(ds,malop) ;
   if (i==-1) BaoLoi("Ma lop khong co trong danh sach");
   else  DeleteItem (ds,  i);
}

void HieuChinhLop(List_LOP &ds,char *malop){
	char c;
	int i;
	i=Search(ds,malop);
	if(i==-1) BaoLoi("Ma lop khong co trong danh sach");
	cout<<"Ban co muon doi ma lop? (Y/N) ";
	cin>>c;
	if(c=='y' || c=='Y'){
		cout<<"Nhap lai ma lop: ";
		fflush(stdin);
		gets(ds.node[i]->MALOP);
	}
	cout<<"Nhap ten lop: ";
	fflush(stdin);
	gets(ds.node[i]->TENLOP);
	cout<<"Nhap nien khoa: ";
	fflush(stdin);
	gets(ds.node[i]->Nienkhoa);
}

void InLopTheoNienKhoa(List_LOP &ds, char *nienkhoa){
	system("cls") ;
 	cout <<left <<setw(34)<<"                   DANH SACH LOP";
 	cout <<"\n  Nien Khoa: "<<nienkhoa;
 	cout<<left<<setw(17)<<"\nMa Lop"<<"Ten Lop\n";
 	for (int i =0 ; i < ds.n ; i++)
 		if(strcmp(ds.node[i]->Nienkhoa,nienkhoa)==0){
			cout<<left<<setw(16)<<ds.node[i]->MALOP<<left<<setw(30)<<ds.node[i]->TENLOP<<endl;
		}
 	getch();
}

int main (){ 
system ("cls");
  char filename[80]="D:\\Thi-trac-nghiem\\DSLOP\\DSLOP.txt";
  char ten[20]; 
  int chon;  List_LOP ds; ds.n=0; char malop[15]; char nienkhoa[10];
  OpenFile(ds,filename);
  do
  {
    chon = MenuDong (thucdon);
    system ("cls");
    switch (chon ){
    case 1: ThemDanhSachLop(ds) ; break;
    case 2: {
    	cout<<"Nhap ma lop can xoa: ";
    	cin>>malop;
    	XoaLop(ds,malop);	
		break;
	}
	case 3: {
		cout<<"Nhap ma lop ban muon hieu chinh: ";
		cin>>malop;
		HieuChinhLop(ds,malop);
		break;
	}
    case 4: LietKe(ds); break;
	case 5: SaveFile(ds, filename); break;
	case 6: {
		cout<<"Nhap nien khoa ban muon in: ";
		cin>>nienkhoa;
		InLopTheoNienKhoa(ds,nienkhoa);
		break;
	}
	case so_item : { SaveFile(ds,filename); return 0;}
   }
  } while (1);
  return 0;
  }
