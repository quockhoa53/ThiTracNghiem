#include <iostream>
#include <cstring>

using namespace std;

void tachChuoi(string chuoi, char* malop, char* tenlop, char* nienkhoa) 
{
    char* token = strtok((char*)chuoi.c_str(), ",");
    strcpy(malop, token);


    token = strtok(NULL, ",");
    char* ptr = token;
    while (*ptr == ' ') ptr++;
    strcpy(tenlop, ptr);
    
    
    token = strtok(NULL, ",");
    strcpy(nienkhoa, token);
      
}

int main() 
{
	char ma_lop[5] ="tuan";
    string ten_file =  "dslop" + string(ma_lop) +".txt";
    cout <<ten_file;
    return 0;
}
