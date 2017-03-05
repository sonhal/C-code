
#include <iostream>
#include "header.h"
#include <string>
using namespace std;

int perfect (int a){
    
    // starts for loop from 1 to the parameter value
    for(int i = 1; i <= a; i++){
        
        
        //assigns counter for divisors for the potential perfect number
        int counter = 1;
        //sum to hold value of positive divisors
        int sum = 0;
        //as long as counter is less then the number checked for being a perfect number the loop continues
        while(counter < i){
            //if the number is perfectly dividable by the counter value the couter value gets added to the sum
            if(i % counter == 0){
                sum = sum + counter;
                
               
            }
            counter++;
        }
        //after all the positive dividers for the number has been collected the sum is checked against the potenial
        //perfect number. If the values match the number is perfect
        if(sum == i){
            cout << sum << "\n";
            
        }
    }

}

//defines fuction and takes the three sides of the triangle as parameters
int tri(int a,int b, int c){
    //if every side is equal
    if(a == b && b == c){
        cout << "equilateral";
    }
    //if only 2 sides are equal
    else if(a == b || b == c || a == c) {
        cout << "isosceles";
    }
    //if all sides are different
    else
    {
        cout << "scalene";
    }
    
    return 0;
}


int pattern(){
    int str = 1;;
    
    for(int i = 2; i <= 5; i++){
        
        str *= 10;
        str += i;
        cout << str << endl;
                
        
        
    }
}


//takes the amount of F numbers to calculate
int fib(int a){
    
    int total = a;
    //for loop to calculate a F number for the amount specified
    for(int i = 1; i < a; i++){
        
       //call the F calculating method 
       int  fa = fibo(i - 1);
       int fb = fibo(i - 2);
       //Adds the results and dispays to screen
       int fin = fa + fb;
        cout << fin << endl;
    }
    
    
}
//F method takes the number to calculate as a variable
int fibo(int a){
    
    
    int f = a;
    //if the number is under 1, 1 is returned
    if(f < 1){
        return 1;
    }
    //if the number is over 1 the method calls it self on Fn -1 and Fn -2 and returns the result of that
    else {
       int b = fibo(f - 1) + fibo(f -2);
       return  b;
    }
    
   
}

int swap1(int a, int b){
    int c = a;
    a = b;
    b = c;
    cout << " Dette er er a: " << a << "\n Dette er b: " << b << endl;
}

int swap2(int& a, int& b){
    int c = a;
    a = b;
    b = c;
    cout << " Dette er er a: " << a << "\n Dette er b: " << b << endl;
}