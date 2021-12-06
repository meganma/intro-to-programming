/*
    PIC 10A Homework 1, evaluation.cpp
    Author: Megan Ma
    Date: 10/9/2021
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    //variable declaration
    int variable1, variable2;
    double expression;
    cout << "Input two integers:\n";
    cin >> variable1 >> variable2;
    cout << "The first number is equal to " << variable1 << " .\n";
    cout << "The second number is equal to " << variable2 << " .\n";
    
    //evaluate the expression and store the result
    expression = (cos(variable1) + pow(variable1, -5))/(abs(variable2)+1);
    //return the result with 4 decimal points
    cout << fixed << setprecision(4) << "The expression is equal to " << expression << " .\n";
    
    return 0;
}

