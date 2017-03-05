
#include "header.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


void string_sort(){
    string str;
    cout << "please type a string" << endl;
    getline(cin,str,'\r');
    sort(str.begin(),str.end());
    cout << str;
    
    
}
