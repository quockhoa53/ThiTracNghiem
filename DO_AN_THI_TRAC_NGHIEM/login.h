#pragma once
#include <iostream>
#include <graphic.h>

using namespace std;

void VeLogin(int x,int y)
{
	//Khung dang nhap
   setcolor(WHITE);
   setlinestyle(SOLID_LINE, 1, 3);
   rectangle(x, y, x + 400, y + 100);
   setfillstyle(SOLID_FILL, 15); 
   floodfill(100, 100, WHITE);
   setcolor(WHITE);
   settextstyle(8,HORIZ_DIR,1);
   outtextxy(x+10 , y+20 , "TEN DANG NHAP: ");
   outtextxy(x+10 , y+50, "MAT KHAU: ");
   //Chu "HOC VIEN CONG NGHE BUU CHINH VIEN THONG"
   setcolor(RED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setbkcolor(15);
   outtextxy((1530)/2-textwidth("HOC VIEN CONG NGHE BUU CHINH VIEN THONG")/2 , y-250, "HOC VIEN CONG NGHE BUU CHINH VIEN THONG");
   outtextxy((1530)/2-textwidth("CO SO TAI THANH PHO HO CHI MINH")/2 , y - 200, "CO SO TAI THANH PHO HO CHI MINH");
   //CHU "Vui long dang nhap..."
   setcolor(BLACK);
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
   setbkcolor(15);
   outtextxy((1530)/2-textwidth("Vui long dang nhap...")/2, y-50,"Vui long dang nhap...");
   //Khung log in
   setcolor(BLACK);
   setlinestyle(SOLID_LINE, 1, 3);
   rectangle(x+130,y+120,x+280,y+170);
   setcolor(BLACK);
   settextstyle(BOLD_FONT,HORIZ_DIR,1); 
   outtextxy(x+150 , y+135 , "DANG NHAP");
   //Khung nut THOAT
   setcolor(BLACK);
   setlinestyle(SOLID_LINE, 1, 3);
   rectangle(1350,700,1450,750);
   setcolor(BLACK);
   settextstyle(BOLD_FONT,HORIZ_DIR,1); 
   outtextxy(1370, 715 , "THOAT");
   //Khung ngoai
   setcolor(BLUE);
   setlinestyle(SOLID_LINE, 1, 3);
   rectangle(15, 20, 1500, 775);
   rectangle(10, 15, 1505, 780);
}
