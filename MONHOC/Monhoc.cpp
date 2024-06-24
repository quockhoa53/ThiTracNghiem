#include <bits/stdc++.h>
#include "Khaibao.h"
#include "mylib2.h"

const int so_item = 4;
const int dong =10;
const int cot = 30 ;
const int Up = 72; // Extended code 
const int Down = 80;
using namespace std;


char thucdon [so_item][50] = {"1. THEM THONG TIN MON HOC",
			                  "2. XOA THONG TIN MON HOC",
			                  "3. HIEU CHINH THONG TIN MON HOC",
							  "4. IN THONG TIN MON HOC"};

void Normal () 
{
	SetColor(15);
	SetBGColor(0);
}
void HighLight () 
{
	SetColor(15);
	SetBGColor(1);
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
							  
int Full(List_MH &ds)
{ 
	return ds.n==MAX_MH ;
}

int Insert_item( List_MH &ds, int i, MH info)
{  
	if (i < 0 || i > ds.n || Full(ds))
		return 0;
	for(int j = ds.n - 1; j >= i; j--)
		ds.node[j+1] = ds.node[j];
	ds.node[i] = info;
	ds.n ++;
	return 1;
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

void ThemMH(List_MH &monhoc)
{
	int n;
	cout<<"Nhap so mon can them: ";
	cin>>n;
	cout<<"Nhap cac mon hoc ban muon them vao danh sach: "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"Mon thu "<<i+1<<": "<<endl;
    	fflush(stdin);
    	cout<<" -Ten mon: ";
    	gets(monhoc.node[i].TENMH);
    	cout<<" -Ma mon: ";
    	gets(monhoc.node[i].MAMH);
		Insert_item(monhoc, i, monhoc.node[i]);	
	}
}

void XoaMH(List_MH &monhoc)
{
	MH mh;
	cout<<"Ban muon xoa theo mon hoc hay ma mon? "<<endl;
	cout<<"   - Mon hoc, nhap 0"<<endl;
	cout<<"   - Ma mon hoc, nhap 1"<<endl;
	cout<<"   Lua chon cua ban la: ";
	int tmp;
	cin>>tmp;
	if(tmp == 0)
	{
		cout<<"Nhap mon muon xoa: ";
		fflush(stdin);
    	gets(mh.TENMH);
		for(int i = 0; i < monhoc.n; i++)
		{
			if(strcmp(mh.TENMH, monhoc.node[i].TENMH) == 0)
				Delete_item(monhoc, i);
		}
	}
	else
	{
		cout<<"Nhap ma mon muon xoa: ";
		fflush(stdin);
    	gets(mh.MAMH);
		for(int i = 0; i < monhoc.n; i++)
		{
			if(strcmp(mh.MAMH, monhoc.node[i].MAMH) == 0)
				Delete_item(monhoc, i);
		}
	}
}

void HieuChinhMH(List_MH &monhoc)
{
	cout << "Ban muon hieu chinh mon hoc, ma mon hoc hay ca hai?" << endl;
	cout << "   - Mon hoc, nhap 0" << endl;
	cout << "   - Ma mon hoc, nhap 1" << endl;
	cout << "   - Ca hai, nhap 2" << endl;
	cout << "   Lua chon cua ban la:  ";
	bool isEditName;
	int tmp;
	char info[50];
	cin >> tmp;
	isEditName = (tmp == 0);
	bool isEditCode = (tmp == 1);
	bool isEditBoth = (tmp == 2);
	
	if (isEditBoth) {
    isEditName = true;
    isEditCode = true;
	}
	
	while (true) {
    cout << "Nhap " << (isEditBoth ? "mon hoc va ma mon hoc" : (isEditName ? "mon hoc" : "ma mon hoc")) << " muon hieu chinh: ";
    fflush(stdin);
    gets(info);

    bool found = false;
    for (int i = 0; i < monhoc.n; i++) {
        if ((isEditName && strcmp(info, monhoc.node[i].TENMH) == 0) || (isEditCode && strcmp(info, monhoc.node[i].MAMH) == 0) || (isEditBoth && (strcmp(info, monhoc.node[i].TENMH) == 0 || strcmp(info, monhoc.node[i].MAMH) == 0))) {
            if (isEditBoth) {
                cout << "Nhap mon hoc moi: ";
                fflush(stdin);
                gets(monhoc.node[i].TENMH);
                cout << "Nhap ma mon hoc moi: ";
                fflush(stdin);
                gets(monhoc.node[i].MAMH);
            } else {
                cout << "Nhap " << (isEditName ? "mon hoc" : "ma mon hoc") << " moi: ";
                fflush(stdin);
                gets(isEditName ? monhoc.node[i].TENMH : monhoc.node[i].MAMH);
            }
            found = true;
            break;
        }
    }
    if (found) {
        break;
    } else {
        cout << "Khong tim thay " << (isEditBoth ? "mon hoc hoac ma mon hoc" : (isEditName ? "mon hoc" : "ma mon hoc")) << " muon hieu chinh. Vui long nhap lai." << endl;
    }
}

}
void Traverse(List_MH &ds)
{
	system("cls") ;
	cout<<"DANH SACH CAC MON HOC: "<<endl;
	if(ds.n == 0)
	{
		cout<<"Danh sach khong co phan tu"<<endl;
		return;
	}
	for(int i = 0; i < ds.n; i++)
	{
		cout<<ds.node[i].TENMH<<"     "<<ds.node[i].MAMH<<endl;
	}
	getch();
}
   
int main()
{
	system ("cls");
	List_MH monhoc;
	int chon;
    do
	{
		chon = MenuDong (thucdon);
    	system ("cls");
    	switch (chon)
		{
			case 1:{
				ThemMH(monhoc);
				cout<<"Da them thong tin mon hoc thanh cong!"<<endl;
				system("pause");
				break;
			}
			case 2: {
				if(monhoc.n != 0)
				{
					XoaMH(monhoc);
			        cout<<"Da xoa thong tin mon hoc thanh cong!"<<endl;
			        system("pause");
				}
				break;
			}
			case 3: {
				if(monhoc.n != 0)
				{
					HieuChinhMH(monhoc);
					cout<<"Da hieu chinh thong tin mon hoc thanh cong!"<<endl;
					system("pause");
				}
				break;
			}
			case 4:{
				Traverse(monhoc);
				break;
			}
		}
	} while (1);
	return 0;
}
