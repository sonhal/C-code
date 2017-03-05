
#include "header.h"
#include <iostream>

using namespace std;

// a.

int * createArray(int n){
    
    int * arr = new (nothrow) int[n];
    if(arr == 0){
        cout << "could not make array";
    }
    
    return arr;
}



float * createMatrix(float n, float m){
    
    float * arr = new (nothrow) float[n][m];
    if(arr == 0){
        cout << "could not make array";
    }
                       
    
}

 void deletematrix(float * p){
     cout << "array has been deleted";
     delete [] p;
}





// b

void deleteArray(int * p){

    delete [] p;
    cout << "array has been deleted";
}
