/*
    PIC 10A Homework 3, mySqrt.cpp
    Author: Megan Ma
    Date: 10/25/2021
 
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    //variable initialization
    double left = 0;
    double right, middle;
    int userInt;
    
    //get user integer
    cout << "Please enter a positive integer: ";
    cin >> userInt;
    //right of first interval is user integer
    right = userInt;
    double tolerance = right - left;
    cout << "Square root of " << userInt << " is located in the interval [" << left << ", " << right << "]." << endl;
    
    while(tolerance > 1e-5){
        middle = (left+right)/2;
        if(middle*middle-userInt > 0){
            //sqrt located in interval [left,middle]
            right = middle;
            cout << "Square root of " << setprecision (10) << userInt << " is located in the interval [" << left << ", " << right << "]." << endl;
            //update tolerance
            tolerance = right - left;
        }else{
            //sqrt located in interval [middle,right]
            left = middle;
            cout << "Square root of " << setprecision (10) << userInt << " is located in the interval [" << left << ", " << right << "]." << endl;
            //update tolerance
            tolerance = right - left;
        }
    }
    cout << "The interval length is " << (right-left) << "." << endl;
    
    return 0;
}
