#include<iostream>
#include"khaibao.h"
#include"hamlop.h"
using namespace std;

int main()
{
	List_LOP ds_lop; 

	OpenFile(ds_lop);
	input_lop(ds_lop);
	in_ds_sv_mot_lop(ds_lop);

	return 0;
}
