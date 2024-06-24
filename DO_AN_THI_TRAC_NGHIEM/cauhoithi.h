#pragma once
#include"khai_bao.h"
#include"ham_nhap.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstring>
#include <fstream>
#include<sstream>
#include<iomanip>
#include<stdlib.h>

char* floatToChar(float num) {
    char* buffer=new char[20];
    sprintf(buffer, "%f", num);
    return buffer;
}

float roundFloat(float num, int decimalPlaces) {
    float multiplier = pow(10, decimalPlaces);
    return round(num * multiplier) / multiplier;
}

void swap(int &a, int &b){
	int c=a;
	a=b;
	b=c;
}

void Inorder(treeCAUHOITHI p, int*a, int &i, char *mamon){
	if(p!=NULL){
		Inorder(p->left,a,i,mamon);
		if(strcmp(p->QUES.MAMH,mamon)==0){
			a[i]=p->QUES.Id;
			i++;
		}
		Inorder(p->right,a,i,mamon);
	}
}

void generateArr(int*values, int* a, int m, int n) {
	int randomValue;
	for (int i = 0; i < m; i++) {
		randomValue = rand() % (n -1 - i + 1) + i;
		a[i] = values[randomValue];
		swap(values[randomValue], values[i]);
	}
	delete [] values;	
}

int TimKhoangTrangGanNhat(treeCAUHOITHI p, int vitri) {
    char str[200];  
    strcpy(str,p->QUES.NoiDung);
    int leftSpace = -1;
    for (int i = vitri-1; i >= 0; i--) {
        if (str[i] == ' ') {
            leftSpace = i;
            break;
        }
    }
    return leftSpace;
}

//void XuLyNoiDung_1(int x, int y, treeCAUHOITHI p){
//	if(strlen(p->QUES.NoiDung)<=100){
//		outtextxy(x,y,p->QUES.NoiDung);
//	}
//	else if(strlen(p->QUES.NoiDung)>100){
//		int i=TimKhoangTrangGanNhat(p,100);
//		if(i==-1) i=101;
//		char s1[i];
//		char s2[120];
//		strncpy(s1,p->QUES.NoiDung,i);
//		s1[i]='\0';
//		strcpy(s2,p->QUES.NoiDung+i+1);
//		s2[strlen(s2)]='\0';
//		outtextxy(x,y,s1);
//		outtextxy(x,y+25,s2);	
//	}
//}

void XuLyNoiDung(int n, int x, int y, treeCAUHOITHI p) {
	if(strlen(p->QUES.NoiDung)<=n){
		outtextxy(x,y,p->QUES.NoiDung);
	}
	else if(strlen(p->QUES.NoiDung)>n&&strlen(p->QUES.NoiDung)<=n*2){
		int i=TimKhoangTrangGanNhat(p,n);
		if(i==-1)
			i=n;
			char s1[i+1];	
			strncpy(s1,p->QUES.NoiDung,i+1);
			s1[i+1]='\0';
			outtextxy(x,y,s1);
//		}else if(i!=-1)
//		{
//			char s1[i];	
//			strncpy(s1,p->QUES.NoiDung,i);
//			s1[i]='\0'; 
//			outtextxy(x,y,s1);
//		}
		char s2[120];
		strcpy(s2,p->QUES.NoiDung+i+1);
		s2[strlen(s2)]='\0';
		outtextxy(x,y+25,s2);	
	}
	else if(strlen(p->QUES.NoiDung)>n*2){
		int i=TimKhoangTrangGanNhat(p,n);	
		int j=TimKhoangTrangGanNhat(p,n*2-20);
		if(i==-1) i=n;
		if(j==-1) j=n*2-20;
		int k=j-i;
		char s1[i];
		char s2[x];
		char s3[80];
		strncpy(s1,p->QUES.NoiDung,i);
		s1[i]='\0';
		strncpy(s2,p->QUES.NoiDung+i+1,k);
		s2[k]='\0';
		strcpy(s3,p->QUES.NoiDung+j+1);
		s3[strlen(s3)]='\0';
		outtextxy(x,y,s1);
		outtextxy(x,y+25,s2);
		outtextxy(x,y+50,s3);		
	}
}

void Insert_queue(Queue &q, treeCAUHOITHI x){
	Node_queue p;
	p=new node;
	p->diachi=x; p->next=NULL;
	if(q.Front==NULL)
		q.Front=p;
	else q.Rear->next=p;
		q.Rear=p;
}

treeCAUHOITHI Delete_queue(Queue &q){
	Node_queue p;
	treeCAUHOITHI x;
	if(q.Front==NULL){
//		cout<<"queue rong";
	}
	else{
		p=q.Front;
		x=p->diachi;
		q.Front=p->next;
		delete p;
		return x;
	}
}

treeCAUHOITHI Search(treeCAUHOITHI root, int id){
	treeCAUHOITHI p;
	p=root;
	while(p!=NULL && p->QUES.Id!=id){
		if(id<p->QUES.Id)
			p=p->left;
		else if(id>p->QUES.Id)
			p=p->right;
	}
	return(p);
}

int Duyet_ktraMaMH(treeCAUHOITHI root, char* mamon) {
    if (root == NULL) return 0;
    if (strcmp(root->QUES.MAMH, mamon) == 0) {
        return 1;
    }
    int leftResult = Duyet_ktraMaMH(root->left, mamon);
    if (leftResult == 1) {
        return 1;
    }
    int rightResult = Duyet_ktraMaMH(root->right, mamon);
    if (rightResult == 1) {
        return 1;
    }
    return 0;
}

treeCAUHOITHI rp;
void remove_case_3(treeCAUHOITHI& r) {
    if (r->left != NULL) {
        remove_case_3(r->left);
    }
    else {
        rp->QUES = r->QUES;
        rp = r;
        r = rp->right;
    }
}

void remove_id(int id, treeCAUHOITHI& p) {
    if (p == NULL) {
//        cout<<"cay rong"
        return;
    }

    if (id < p->QUES.Id) {
        remove_id(id, p->left);
    }
    else if (id > p->QUES.Id) {
        remove_id(id, p->right);
    }
    else {
        rp = p;
        if (rp->right == NULL) {
            p = rp->left;
        }
        else if (rp->left == NULL) {
            p = rp->right;
        }
        else {
            remove_case_3(rp->right);
        }
        delete rp;
    }
}

void InsertNode(treeCAUHOITHI &t, CAUHOITHI q) {
    if (t == NULL) {
        t=new nodeCAUHOITHI;
        t->QUES=q;
        t->left=NULL;
        t->right=NULL;
        return;
    }
    if (q.Id < t->QUES.Id) {
        InsertNode(t->left, q);
    }
    else if (q.Id > t->QUES.Id) {
        InsertNode(t->right, q);
    }
    else if (q.Id == t->QUES.Id) {
    	return;
	}
}

bool checkId(treeCAUHOITHI &t, int id) {
    if (t == NULL) {
        return false;
    }
    else {
        if (t->QUES.Id == id) {
            return true;
        }
        else if (id < t->QUES.Id) {
            return checkId(t->left, id);
        }
        else {
            return checkId(t->right, id);
        }
    }
}

void save_tree_level(treeCAUHOITHI tree, ofstream& file) {
	treeCAUHOITHI p;
	Queue q;
	q.Front=NULL;
	q.Rear=NULL;
    if (tree != NULL) Insert_queue(q,tree); 
	while(q.Front!=NULL){
		p=Delete_queue(q);
        //save_tree_LNR(tree->left, file);
        file << p->QUES.Id << "|" << p->QUES.MAMH << "|" << p->QUES.NoiDung << "|" 
             << p->QUES.A << "|" << p->QUES.B << "|" << p->QUES.C << "|" 
             << p->QUES.D << "|" << p->QUES.DapAn << endl;
        //save_tree_LNR(tree->right, file);
        if(p->left!=NULL)
        	Insert_queue(q,p->left);
        if(p->right!=NULL)
        	Insert_queue(q,p->right);
    }
}

void SaveFile_DSCHT(treeCAUHOITHI tree, char *filename) {
	ofstream f(filename);
	if(f.is_open()){
		save_tree_level(tree,f);
	}
	else{
		cout<<"khong the mo file "<<filename<<" de luu!\n";
		return;
	}
}

void OpenFile_DSCHT(treeCAUHOITHI &tree, char *filename) {
	if(tree!=NULL) tree=NULL;
    ifstream file(filename);
    if (!file.is_open()) {
    	cout<<"khong the mo file"<<filename<<endl;
        return;
    }
    else{
    		string line;
        	while (getline(file, line)) {
        		if(line=="\0") break;
            	CAUHOITHI QUES;
            	stringstream ss(line);
            	getline(ss, line, '|');
            	QUES.Id=atoi(line.c_str());
            	getline(ss, line, '|');
            	strcpy(QUES.MAMH, line.c_str());
            	getline(ss, line, '|');
            	strcpy(QUES.NoiDung, line.c_str());
            	getline(ss, line, '|');
            	strcpy(QUES.A, line.c_str());
            	getline(ss, line, '|');
            	strcpy(QUES.B, line.c_str());
            	getline(ss, line, '|');
            	strcpy(QUES.C, line.c_str());
            	getline(ss, line, '|');
            	strcpy(QUES.D, line.c_str());
            	getline(ss, line, '\n');
            	QUES.DapAn=line[0];
            	InsertNode(tree,QUES);
			}
        file.close();
//        cout<<"load file "<<filename<<" Thanh cong!\n";
	}
}

void OpenFile_DSCHT_TheoMaMon(treeCAUHOITHI &tree, char *filename, char*mamon, int startLine) {
	if(tree!=NULL) tree=NULL;
    ifstream file(filename);
    if (!file.is_open()) {
    	cout<<"khong the mo file"<<filename<<endl;
        return;
    }
    else{
    	string line;
        int lineCount = 1;
        int dem=0;
        while (getline(file, line)) {
            if (line == "\0" || dem==8) break;
            CAUHOITHI QUES;
            stringstream ss(line);
            getline(ss, line, '|');
            QUES.Id = atoi(line.c_str());
            getline(ss, line, '|');
            strcpy(QUES.MAMH, line.c_str());
            if (strcmp(QUES.MAMH,mamon)!=0||lineCount < startLine){
            	lineCount++;
            	continue;
			}
            getline(ss, line, '|');
            strcpy(QUES.NoiDung, line.c_str());
            getline(ss, line, '|');
            strcpy(QUES.A, line.c_str());
            getline(ss, line, '|');
            strcpy(QUES.B, line.c_str());
            getline(ss, line, '|');
            strcpy(QUES.C, line.c_str());
            getline(ss, line, '|');
            strcpy(QUES.D, line.c_str());
            getline(ss, line, '\n');
            QUES.DapAn = line[0];
            InsertNode(tree, QUES);
            dem++;
            lineCount++;
			}
        file.close();
//        cout<<"load file "<<filename<<" Thanh cong!\n";
	}
}

void DocFileTheoDong(treeCAUHOITHI &tree, char *filename, int startLine) {
    ifstream file(filename);
    if (!file.is_open()) {
//    	cout<<"khong the load file "<<filename<<" tu dong "<<startLine<<endl;
        return;
    } else {
        string line;
        int lineCount = 0;
        while (getline(file, line)) {
            lineCount++;
            if (lineCount < startLine)
                continue;
            
            if (line == "\0" || lineCount==startLine+8)
                break;

            CAUHOITHI QUES;
            stringstream ss(line);
            getline(ss, line, '|');
            QUES.Id = atoi(line.c_str());
            getline(ss, line, '|');
            strcpy(QUES.MAMH, line.c_str());
            getline(ss, line, '|');
            strcpy(QUES.NoiDung, line.c_str());
            getline(ss, line, '|');
            strcpy(QUES.A, line.c_str());
            getline(ss, line, '|');
            strcpy(QUES.B, line.c_str());
            getline(ss, line, '|');
            strcpy(QUES.C, line.c_str());
            getline(ss, line, '|');
            strcpy(QUES.D, line.c_str());
            getline(ss, line, '\n');
            QUES.DapAn = line[0];
            InsertNode(tree, QUES);
        }
        file.close();
//        cout<<"load file "<<filename<<" tu dong "<<startLine<<" thanh cong\n";
    }
}

int CountLineInFile_TheoMa(char *filename, char *mamon){
	ifstream file(filename);
    if (!file.is_open()) {
    } else {
        string line;
        int lineCount = 0;
        while (getline(file, line)) {
            CAUHOITHI QUES;
            stringstream ss(line);
            getline(ss, line, '|');
            QUES.Id = atoi(line.c_str());
            getline(ss, line, '|');
            strcpy(QUES.MAMH, line.c_str());
            getline(ss, line, '|');
            if(strcmp(QUES.MAMH,mamon)==0) lineCount++;
            if (line.empty())
			break;
        }
        return lineCount;
        file.close();
    }
    return -1;
}

int CountLineInFile(char *filename){
	ifstream file(filename);
    if (!file.is_open()) {
    } else {
        string line;
        int lineCount = 0;
        while (getline(file, line)) {
            lineCount++;
            if (line.empty())
			break;
        }
        return lineCount;
        file.close();
    }
    return -1;
}

void InDSCHT(treeCAUHOITHI &dscht, int &page, int &vitriclick, int &dk, int &id){
	int i=(page-1)*8;
	treeCAUHOITHI root=NULL;
	DocFileTheoDong(root,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt",i+1);
	int x=430;
	int y=190;
	treeCAUHOITHI p;
	Queue q;
	q.Front=NULL;
	q.Rear=NULL;
	if(root!=NULL) Insert_queue(q,root);
	while(q.Front!=NULL){
		p=Delete_queue(q);
		if(i<page*8) {
			if(vitriclick==-1){
				outtextxy(x,y,IntToChar(p->QUES.Id));
	        	outtextxy(x+100,y,p->QUES.MAMH);
	        	char c[31];
	        	strncpy(c,p->QUES.NoiDung,26);
	        	if(strlen(c)==26)
	        	strcat(c,"...");
	        	c[30]='\0';
	        	outtextxy(x+300,y,c);
	        	if(dk==0){
	        		setcolor(BLUE);	
	        		outtextxy(x+920,y,"Xem");
				}
	        	else if(dk==2){
	        		setcolor(RED);
	        		outtextxy(x+920,y,"Xoa");
	        	}
	        	else if(dk==3){
	        		setcolor(RED);
	        		outtextxy(x+920,y,"Sua");
				}
	        	setcolor(BLACK);	
			}
	        else if(i==vitriclick && vitriclick!=-1){
	        	id=p->QUES.Id;
	        	if(dk==5 || dk==6){
	        	setbkcolor(LIGHTCYAN);
	        	outtextxy(510,135,p->QUES.MAMH);
				outtextxy(470,195,IntToChar(p->QUES.Id));
				XuLyNoiDung(80,520,255,p);
				outtextxy(460,400,p->QUES.A);
				outtextxy(460,440,p->QUES.B);
				outtextxy(460,480,p->QUES.C);
				outtextxy(460,520,p->QUES.D);
				outtextxy(510,600,CharToString(p->QUES.DapAn));
				setbkcolor(WHITE);
				return;	
				}
			}
	    	y+=60;	
			i++;	
		}
		if(p->left!=NULL)
			Insert_queue(q,p->left);
		if(p->right!=NULL)
			Insert_queue(q,p->right);
	}
}

void InDSCHT_mamon(treeCAUHOITHI &dscht, int &page, int &vitriclick, int &dk, int &id, char*mamon){
	setbkcolor(LIGHTCYAN);
	int i=(page-1)*8;
	treeCAUHOITHI root=NULL;
	OpenFile_DSCHT_TheoMaMon(root,"D:\\Thi-trac-nghiem\\DO_AN_THI_TRAC_NGHIEM\\dsCHT.txt",mamon,i+1);
	int x=430;
	int y=190;
	treeCAUHOITHI p;
	Queue q;
	q.Front=NULL;
	q.Rear=NULL;
	if(root!=NULL) Insert_queue(q,root);
	while(q.Front!=NULL){
		p=Delete_queue(q);
		if(i<page*8) {
			if(vitriclick==-1){
				outtextxy(x,y,IntToChar(p->QUES.Id));
	        	outtextxy(x+100,y,p->QUES.MAMH);
	        	char c[31];
	        	strncpy(c,p->QUES.NoiDung,26);
	        	if(strlen(c)==26)
	        	strcat(c,"...");
	        	c[30]='\0';
	        	outtextxy(x+300,y,c);
	        	if(dk==0){
	        		setcolor(BLUE);	
	        		outtextxy(x+920,y,"Xem");
				}
	        	else if(dk==2){
	        		setcolor(RED);
	        		outtextxy(x+920,y,"Xoa");
	        	}
	        	else if(dk==3){
	        		setcolor(RED);
	        		outtextxy(x+920,y,"Sua");
				}
	        	setcolor(BLACK);	
			}
	        else if(i==vitriclick && vitriclick!=-1){
	        	id=p->QUES.Id;
	        	if(dk==5 || dk==6){
	        	setbkcolor(LIGHTCYAN);
	        	outtextxy(510,135,p->QUES.MAMH);
				outtextxy(470,195,IntToChar(p->QUES.Id));
				XuLyNoiDung(80,520,255,p);
				outtextxy(460,400,p->QUES.A);
				outtextxy(460,440,p->QUES.B);
				outtextxy(460,480,p->QUES.C);
				outtextxy(460,520,p->QUES.D);
				outtextxy(510,600,CharToString(p->QUES.DapAn));
				setbkcolor(WHITE);	
				return;
				}
			}
	    	y+=60;	
			i++;	
		}
		if(p->left!=NULL)
			Insert_queue(q,p->left);
		if(p->right!=NULL)
			Insert_queue(q,p->right);
	}
}

void InCauHoi(treeCAUHOITHI &p, int &page, int &SoCHT, int a[], int dk_inbaithi){
	if(page<=SoCHT){
		treeCAUHOITHI q=Search(p,a[page-1]);
		setcolor(BLACK);
		outtextxy(120,220,"ID:");
		outtextxy(160,220,IntToChar(q->QUES.Id));
		outtextxy(120,250,"CAU HOI:");
		XuLyNoiDung(80,210,250,q);
		outtextxy(120,350,"A.");
		outtextxy(160,350,q->QUES.A);
		outtextxy(120,380,"B.");
		outtextxy(160,380,q->QUES.B);
		outtextxy(120,410,"C.");	
		outtextxy(160,410,q->QUES.C);
		outtextxy(120,440,"D.");
		outtextxy(160,440,q->QUES.D);
		if(dk_inbaithi==1){
			outtextxy(1310,220,CharToString(q->QUES.DapAn));
		}
	}	
}
