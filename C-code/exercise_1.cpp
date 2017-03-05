#include "header.h"
#include <iostream>


using namespace std;


int array(int a){
    
    if(a = 1){
        
        
    }
    
    
}

 void return_number(){
     int numbers[2];
     int order = 0;
 cout << "Enter 3 numbers" << endl;
 for(int i = 0; i < 3; i++){
     cout << "number " << i << endl;
      cin >> numbers[i];
              
 }
 cout << "list in rising(enter 1) or decreasing(enter 0) order?" << endl;
 cin >> order;
 
 if(order == 0){
     if(numbers[0] < numbers[1]) swap (numbers[0], numbers[1]);
     if(numbers[1] < numbers[2]) swap (numbers[1], numbers[2]);
     if(numbers[0] < numbers[1]) swap (numbers[0], numbers[1]); 
      cout << "numbers: " << numbers[0] << " , " << numbers[1] << " , " << numbers[2];
     }
 
 else if(order != 0){
     if(numbers[0] > numbers[1]) swap (numbers[0], numbers[1]);
     if(numbers[1] > numbers[2]) swap (numbers[1], numbers[2]);
     if(numbers[0] > numbers[1]) swap (numbers[0], numbers[1]);
      cout << "numbers: " << numbers[0] << " , " << numbers[1] << " , " << numbers[2];
 }
else{
    cout << "please enter 0 or 1";
 }

 }




