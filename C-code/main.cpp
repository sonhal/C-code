
#include "header.h"
#include <iostream>
#include <string>
using namespace std;




int main() {
    
    int n;
    cin >> n;
    
    int * p = createArray(n);
    
    
    cout << *p;
    
    deleteArray(p);
    
}



