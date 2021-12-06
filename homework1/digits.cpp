/*
    PIC 10A Homework 1, digits.cpp
    Author: Megan Ma
    Date: 10/9/2021
 
 */

#include <iostream>
using namespace std;

int main() {
    // variable declaration
    int digit, ones, tens, hundreds, product;
    cout << "Input a three-digit number (100-999)";
    cin >> digit;
    
    ones =  digit%10; //remainder of dividing digit by 10
    tens = (digit/10)%10; //get rid of the rightmost digit, then do remainder of dividing by 10
    hundreds = (digit/100)%10; //get rid of the two rightmost digits, then do remainder of dividing by 10
    product = ones * tens * hundreds;
    
    // print each digit and product of all the digits
    cout << "The one's digit is " << ones << ".\n";
    cout << "The tens's digit is " << tens << ".\n";
    cout << "The hundred's digit is " << hundreds << ".\n";
    cout << "The product of three digits is " << product << ".\n";
    
    return 0;
}

