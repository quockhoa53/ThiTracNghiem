#pragma once
#include "khai_bao.h"
#include <bits/stdc++.h>
#include "xu_ly_login.h"
#include <graphics.h> 
using namespace std;

void xoa_kitu(char str[], int vitri){
	for(int i=vitri+1; i<strlen(str); i++){
		str[i-1]=str[i];
	}
	str[strlen(str)-1]='\0';
}

//NHAP MA
void NhapMa(int n, int x, int y, char str[]){
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	char c;
//	char s[n];
//	strcpy(s,str);
	int i=strlen(str);
	outtextxy(x+textwidth(str),y,"|");
	while(i>=0){
		if(kbhit()){
		c=getch();
		
		if((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122)){ //0=48 9=57
			if(i<n){
				if(c>=97 && c<=122){
					c-=32;
				}	
				str[i]=c;
				str[i+1]='\0';
                outtextxy(x, y, str);
                outtextxy(x+textwidth(str),y,"|");
				i++;			
			}
		} 
		else if(c==13 || c==27){ //enter=13 esc=27
//			if(i==0){
//				outtextxy(x,y," ");
//				strcpy(str,s);
//			}
			outtextxy(x+textwidth(str),y," ");
			break; 
		} 
		else if(c==8 && str!='\0'){ //backspace=8
			xoa_kitu(str, i-1);
			if(i>0){
				i--;
            	moveto(x+textwidth(str),y);
            	outtextxy(x+textwidth(str),y,"  ");
            	outtextxy(x+textwidth(str),y,"|");	
			} 
		}
		else if(c==-32 || c==0){
			c=getch();	
		} 
		}	
	}
} 


//NHAP TAT CA CHU IN
void NhapInHoa(int n, int x, int y, char str[]){
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setcolor(BLACK);
	char c;
//	char s[n];
//	strcpy(s,str);
	int i=strlen(str);
	outtextxy(x+textwidth(str),y,"|");
	while(i>=0){
		if(kbhit()){
		c=getch();
		if((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122) || c==32){ //0=48 9=57
			if(i<n){
				if(i==0 && c==32){
					continue;
				}
				if(c>=97 && c<=122){
					c-=32;
				}
				if(str[i-1]==32 && c==32){
					continue;	
				}			
				str[i]=c;
				str[i+1]='\0';
                outtextxy(x, y, str);
                outtextxy(x+textwidth(str),y,"|");
				i++;			
			}
		} 
		else if(c==13 || c==27){ //enter=13 esc=27
//			if(i==0){
//				outtextxy(x,y," ");
//				strcpy(str,s);
//			}
			if(str[strlen(str)-1]==32){
				xoa_kitu(str,strlen(str)-1);
            	moveto(x+textwidth(str),y);
            	outtextxy(x+textwidth(str),y,"  ");		
			} 
			else{
				outtextxy(x+textwidth(str),y," ");	
			}
			break; 
		} 
		else if(c==8 && str!='\0'){ //backspace=8
			xoa_kitu(str, i-1);
			if(i>0) {
				i--;
            	moveto(x+textwidth(str),y);
            	outtextxy(x+textwidth(str),y,"  ");
            	outtextxy(x+textwidth(str),y,"|");	
			}
		}
		else if(c==-32 || c==0){
			c=getch();	
		} 
		}	
	}
}

//HAM VIET HOA CHU CAI DAU
void NhapThuong(int n, int x, int y, char str[]) {
settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    char c;
//    char s[n];
//    strcpy(s,str);
    int i=strlen(str);
    outtextxy(x+textwidth(str),y,"|");
    while(i>=0){
        if(kbhit()){
            c=getch();
            if((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122) || c==32){ //0=48 9=57
                if(i<n){
                	if(i==0 && c==32){
						continue;
					}
                    if(i == 0 || str[i-1] == 32) { // n?u dây là ký t? d?u tiên ho?c tru?c dó là d?u cách, chuy?n ký t? thành ch? hoa
                        if(c>=97 && c<=122){
                            c = toupper(c);
                        }
                    } else {
                        if(c>=65 && c<=90){
                            c+=32;
                        }
                    }
                    if(str[i-1]==32 && c==32){
                        continue;    
                    }           
                    str[i]=c;
                    str[i+1]='\0';
                    outtextxy(x, y, str);
                    outtextxy(x+textwidth(str),y,"|");
                    i++;            
                }
            } 
            else if(c==13 || c==27){ //enter=13 esc=27
//                if(i==0){
//                    outtextxy(x,y," ");
//                    strcpy(str,s);
//                }
                if(str[strlen(str)-1]==32){
					xoa_kitu(str,strlen(str)-1);
            		moveto(x+textwidth(str),y);
            		outtextxy(x+textwidth(str),y,"  ");		
				} 
				else{
					outtextxy(x+textwidth(str),y," ");	
				}
                break; 
            } 
            else if(c==8 && str!='\0'){ //backspace=8
                xoa_kitu(str, i-1);
                if(i>0) {
                    i--;
                    moveto(x+textwidth(str),y);
                    outtextxy(x+textwidth(str),y,"  ");
                    outtextxy(x+textwidth(str),y,"|");   
                }
            }
            else if(c==-32 || c==0){
				c=getch();	
			} 
        }   
    }
}

//NHAP SO
void NhapSo(int n, int x, int y, char str[]) {
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    char c;
	int i=strlen(str);
	outtextxy(x+textwidth(str),y,"|");
    while (i >= 0) {
        if (kbhit()) {
            c = getch();
            if (c >= 48 && c <= 57) { // 0 = 48, 9 = 57
                if (i < n) {
                    str[i] = c;
                    str[i + 1] = '\0';
                    outtextxy(x, y, str);
                    outtextxy(x + textwidth(str), y, "|");
                    i++;
                }
            }
            else if (c == 13 || c == 27) { // enter = 13, esc = 27
                outtextxy(x + textwidth(str), y, " ");
                break;
            }
            else if (c == 8 && str[0] != '\0') { // backspace = 8
                xoa_kitu(str, i - 1);
                if (i > 0) {
                    i--;
                    moveto(x + textwidth(str), y);
                    outtextxy(x + textwidth(str), y, "  ");
                    outtextxy(x + textwidth(str), y, "|");
                }
            }
        }
    }
}

//NHAP MAT KHAU
void NhapSoThanhSao(int n, int x, int y, char str[]) {
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    char c;
    int i = strlen(str);
    char tmp[n];
    strcpy(tmp, str);

    outtextxy(x, y, tmp);
    outtextxy(x + textwidth(tmp), y, "|");

    while (1) {
        if (kbhit()) {
            c = getch();
            if (c >= 48 && c <= 57) { // 0 = 48, 9 = 57
                if (i < n) {
                    str[i] = c;
                    str[i + 1] = '\0';
                    strcat(tmp, "*");
                    outtextxy(x, y, tmp);
                    outtextxy(x + textwidth(tmp), y, "|");
                    i++;
                }
            }
            else if (c == 13 || c == 27) { // enter = 13, esc = 27
                outtextxy(x + textwidth(tmp), y, " ");
                break;
            }
            else if (c == 8) { // backspace = 8
                if (i > 0) {
                    str[i] = '\0';
                    i--;
                    tmp[i] = '\0';
                    moveto(x + textwidth(tmp), y);
                    outtextxy(x + textwidth(tmp), y, "  ");
                    outtextxy(x + textwidth(tmp), y, "|");
                }
            }
        }
    }
}



//NHAP PHAI
void NhapPhai(int n, int x, int y, char str[]) {
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    char c;
//	char s[n];
//	strcpy(s,str);
	int i=strlen(str);
	outtextxy(x+textwidth(str),y,"|");
    while (i >= 0) {
        if (kbhit()) {
            c = getch();
            if (c == '0' || c == '1') { // 0 = 48, 9 = 57
                if (i < n) {
                    str[i] = c;
                    str[i + 1] = '\0';
                    outtextxy(x, y, str);
                    outtextxy(x + textwidth(str), y, "|");
                    i++;
                }
            }
            else if (c == 13 || c == 27) { // enter = 13, esc = 27
//                if (i == 0) {
//                    outtextxy(x, y, " ");
//                    strcpy(str, s);
//                }
                outtextxy(x + textwidth(str), y, " ");
                break;
            }
            else if (c == 8 && str[0] != '\0') { // backspace = 8
                xoa_kitu(str, i - 1);
                if (i > 0) {
                    i--;
                    moveto(x + textwidth(str), y);
                    outtextxy(x + textwidth(str), y, "  ");
                    outtextxy(x + textwidth(str), y, "|");
                }
            }
        }
    }
}

//NHAP NIEN KHOA
void NhapNienKhoa(int x, int y, char str[]){
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	char c;
	int i=strlen(str);
	outtextxy(x+textwidth(str),y,"|");
	while(i>=0){
		if(kbhit()){
		c=getch();
		if((c>=48 && c<=57)){ //0=48 9=57
			if(i<4){
				if((i==0 && c==50)||(i==1 && c==48)||(i==2 && c<=50)){
					str[i]=c;
					str[i+1]='\0';
	                outtextxy(x, y, str);
	                outtextxy(x+textwidth(str),y,"|");
					i++;			
				}
				else if(i==3&&str[3]=='\0'){		
					str[i]=c;
					str[4]='-';
					str[5]=str[0];
					str[6]=str[1];
					if(str[3]!='9'){
						str[7]=str[2];
						str[8]=c+1;	
					}
					else{
						str[7]=str[2]+1;
						str[8]='0';	
					}
					str[9]='\0';
	                outtextxy(x, y, str);
	                outtextxy(x+textwidth(str),y,"|");			
				}
			}
		}
		else if(c==13 || c==27){ //enter=13 esc=27
//			if(i==0){
//				outtextxy(x,y," ");
//				strcpy(str,s);
//			}
			outtextxy(x+textwidth(str),y,"  ");
			break; 
		} 
		else if(c==8 && str!='\0'){ //backspace=8
			strcpy(str,"\0");
			outtextxy(x,y,"           ");
			outtextxy(x,y,"|");
			i=0;
		}
		}	
	}
} 

int x_xoa_so, y_xoa_so;

int NhapGioPhut(int SoKiTu, int SoLonNhat)
{
	int num = 0,dem = 0;
    char c[30],a[20];
    x_xoa_so = getx(); y_xoa_so = gety();
    do
    {
    	if(kbhit())
    	{
    		*c = getch();
 
    		if(*c==8 && dem > 0)
			{ 
				num /= 10;
				if(dem >= 0 ) dem--;
				outtextxy(getx() - textwidth(" "), gety()," ");
				moveto(getx() - textwidth(" "),gety());
				continue;	
			}
			if(dem == SoKiTu )	continue;
    		if (!isdigit(*c)) 
       		{
        		continue;
			}
			if(num*10 + (*c-'0') > SoLonNhat) continue;
			num = num*10 + (*c-'0');
			dem++;
			outtext(c);
			outtext("|");
		}
		
    }
    while (*c!=13);
    cout<<num;
    return num;
}

void NhapCHT_phut(int n, int x, int y, int& num,int sln) {
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    char str[n] = "\0";
	char c;
	int i=strlen(str);
	outtextxy(x+textwidth(str),y,"|");
    while (i >= 0) {
        if (kbhit()) {
            c = getch();
            if (c >= 48 && c <= 57&&(num*10 + (c-'0') < sln)) { // 0 = 48, 9 = 57
                if (i < n) {
                    str[i] = c;
                    str[i + 1] = '\0';
                    outtextxy(x, y, str);
                    outtextxy(x + textwidth(str), y, "|");
                    i++;
					num = num*10 + (c-'0');
                }
            }
            else if (c == 13 || c == 27) { // enter = 13, esc = 27
//                if (i == 0) {
//                    outtextxy(x, y, " ");
//                    strcpy(str, s);
//                }
                outtextxy(x + textwidth(str), y, " ");
                break;
            }
            else if (c == 8 && str[0] != '\0') { // backspace = 8
                xoa_kitu(str, i - 1);
                if (i > 0) {
                    i--;
                    moveto(x + textwidth(str), y);
                    outtextxy(x + textwidth(str), y, "  ");
                    outtextxy(x + textwidth(str), y, "|");
                    num /= 10;
                }
            }
        }
    }
}

int SearchSpaceNear(char x[], int vitri) {
    char* str = x;  
    int leftSpace = -1;
    for (int i = vitri-1; i >= 0; i--) {
        if (str[i] == ' ') {
            leftSpace = i;
            break;
        }
    }
    return leftSpace;
}

void NhapNoiDung(int x, int y, char str[]) {
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    setbkcolor(LIGHTCYAN);
    char c;
    int i = strlen(str);
    int vitri = 100;
    if (strlen(str) > 100) {
        vitri = SearchSpaceNear(str, 100);
        if (vitri == -1) {
            vitri = 100;
        }
        outtextxy(x + textwidth(str + vitri + 1), y + 25, "|");
    } else {
        outtextxy(x + textwidth(str), y, "|");
    }
    while (i >= 0) {
        if (kbhit()) {
            c = getch();
            if (((c >= 32 && c <= 126) || c == 179)&&i<200) { // 0=48, 9=57
                if (i == 0 && c == 32) {
                    continue;
                }
                if (c >= 97 && c <= 122) {
                    c -= 32;
                }
                if (str[i - 1] == 32 && c == 32) {
                    continue;
                }
                if (i > 95 && c==32 && i<vitri) {
                    vitri=i;
                }
				if (i < vitri ) {
					str[i] = c;
                    str[i + 1] = '\0';
                    outtextxy(x, y, str);
                    outtextxy(x + textwidth(str),y, "|");
				}
                if (i == vitri) {
                    str[i] = c;
                    str[i + 1] = '\0';
                    outtextxy(x, y, str);
                    outtextxy(x,y+25, "|");
                }
                if (i > vitri && i < 200) {
                    str[i] = c;
                    str[i + 1] = '\0';
                    outtextxy(x, y + 25, str + vitri+1);
                    outtextxy(x + textwidth(str + vitri + 1), y + 25, "|");
                }
                i++;
			} 
			else if (c == 13 || c == 27) { // enter=13, esc=27
                if (str[strlen(str) - 1] == 32) {
                    xoa_kitu(str, strlen(str) - 1);
                    if (i > 0 && i <= vitri) {
                        outtextxy(x + textwidth(str), y, "   ");
                    } else if (i > vitri) {
                        outtextxy(x + textwidth(str + vitri + 1), y + 25, "   ");
                    }
                } else {
                    if (i >= 0 && i < vitri) {
                        outtextxy(x + textwidth(str), y, "   ");
                    } else {
                        outtextxy(x + textwidth(str + vitri + 1), y + 25, "   ");
                    }
                }
                break;
            } 
			else if (c == 8 && str[0] != '\0') { // backspace=8
                xoa_kitu(str, i - 1);
                if (i == vitri + 1) {
                    outtextxy(x, y + 25, "  ");
                    outtextxy(x + textwidth(str), y, "|");
                }
                if (i > 0 && i <= vitri) {
                    i--;
                    moveto(x + textwidth(str), y);
                    outtextxy(x + textwidth(str), y, "  ");
                    outtextxy(x + textwidth(str), y, "|");
                } else if (i > vitri) {
                    i--;
                    moveto(x + textwidth(str + vitri + 1), y + 25);
                    outtextxy(x + textwidth(str + vitri + 1), y + 25, "  ");
                    if (i != vitri) {
                        outtextxy(x + textwidth(str + vitri + 1), y + 25, "|");
                    }
                }
            } 
			else if (c == -32 || c == 0) {
                c = getch();
            }
    	}
    }
}



void NhapCauTraLoi(int n, int x, int y, char str[]){
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setbkcolor(LIGHTCYAN);
	char c;
	char s[n];
	strcpy(s,str);
	int i=strlen(str);
	outtextxy(x+textwidth(str),y,"|");
	while(i>=0){
		if(kbhit()){
		c=getch();
		if((c>=32 && c<=126) || c==179){ //0=48 9=57
			if(i<n){
				if(i==0 && c==32) continue;
				if(c>=97 && c<=122){
					c-=32;
				}
				if(str[i-1]==32 && c==32){
					continue;	
				}			
				str[i]=c;
				str[i+1]='\0';
                outtextxy(x, y, str);
                outtextxy(x+textwidth(str),y,"|");
				i++;			
			}
		} 
		else if(c==13 || c==27){ //enter=13 esc=27
			if(i==0){
				outtextxy(x,y," ");
				strcpy(str,s);
			}
			if(str[strlen(str)-1]==32){
					xoa_kitu(str,strlen(str)-1);
            		moveto(x+textwidth(str),y);
            		outtextxy(x+textwidth(str),y,"  ");		
			} 
			else{
				outtextxy(x+textwidth(str),y," ");	
			}
			break; 
		} 
		else if(c==8 && str!='\0'){ //backspace=8
			xoa_kitu(str, i-1);
			if(i>0) {
				i--;
            	moveto(x+textwidth(str),y);
            	outtextxy(x+textwidth(str),y,"  ");
            	outtextxy(x+textwidth(str),y,"|");	
			}
		}
		else if(c==-32 || c==0){
			c=getch();	
		} 
		}	
	}
}

char* CharToString(char c) {
    char* result = new char[2];
    result[0] = c;
    result[1] = '\0';
    return result;
}

void NhapDapAn(int x, int y, char &a){
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    setbkcolor(LIGHTCYAN);
	char c;
	char str[2];
	strcpy(str,CharToString(a));
	int i=strlen(str);
	outtextxy(x+textwidth(str),y,"|");
	while(i>=0){
		if(kbhit()){
		c=getch();
		if((c>=65 && c<=68) || (c>=97 && c<=100)){ //0=48 9=57
			if(i<1){
				if(c>=97 && c<=100){
					c-=32;
				}		
				str[i]=c;
				str[i+1]='\0';
                outtextxy(x, y, str);
                outtextxy(x+textwidth(str),y,"|");
				i++;			
			}
		} 
		else if(c==13 || c==27){ //enter=13 esc=27
			if(i==0){
				outtextxy(x,y," ");
				strcpy(str,CharToString(a));
			}
			outtextxy(x+textwidth(str),y," ");
			break; 
		} 
		else if(c==8 && str!='\0'){ //backspace=8
			xoa_kitu(str, i-1);
			if(i>0){
				i--;
            	moveto(x+textwidth(str),y);
            	outtextxy(x+textwidth(str),y,"  ");
            	outtextxy(x+textwidth(str),y,"|");	
			} 
		}	
		}	
	}
	a=str[0];
}

char* IntToChar(int x)
{
    char* result = new char[20];
    sprintf(result, "%d", x);
    return result;
}

void NhapId(int x, int y, int &id){
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setcolor(BLACK);
	setbkcolor(LIGHTCYAN);
	char c;
	char str[20];
	strcpy(str,IntToChar(id));
	int i=0;
	outtextxy(x,y,"|");
	while(i>=0){
		if(kbhit()){
		c=getch();
		if((c>=48 && c<=57)){ //0=48 9=57
			if(i<20){		
				str[i]=c;
				str[i+1]='\0';
                outtextxy(x, y, str);
                outtextxy(x+textwidth(str),y,"|");
				i++;			
			}
		} 
		else if(c==13 || c==27){ //enter=13 esc=27
			if(i==0){
				outtextxy(x,y," ");
				strcpy(str,IntToChar(id));
			}
			outtextxy(x+textwidth(str),y," ");
			break; 
		} 
		else if(c==8 && str!='\0'){ //backspace=8
			xoa_kitu(str, i-1);
			if(i>0){
				i--;
            	moveto(x+textwidth(str),y);
            	outtextxy(x+textwidth(str),y,"  ");
            	outtextxy(x+textwidth(str),y,"|");	
			} 
		}	
		}	
	}
	id=atoi(str);
}
