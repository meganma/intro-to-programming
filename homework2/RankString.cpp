/*
    PIC 10A Homework 2, RankString.cpp
    Author: Megan Ma
    Date: 10/17/2021
 
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    //variable initialization
    string string1, string2, string3;
    
    //get 3 strings from user and store into string1, string2, string3
    cout << "Please enter three strings:\n";
    getline(cin, string1);
    getline(cin, string2);
    getline(cin, string3);
    
    cout << "Descending dictionary order:\n";
    
    //comparison logic for returning 3 strings in descending order
    if(string1 > string2){
        if(string2 > string3){
            cout << string1 << "\n" << string2 << "\n" << string3 <<endl;
        }else{
            if(string1 > string3){
                cout << string1 << "\n" << string3 << "\n" << string2 <<endl;
            }else{
                cout << string3 << "\n" << string1 << "\n" << string2 <<endl;
            }
        }
    }else{
        if(string1 > string3){
            cout << string2 << "\n" << string1 << "\n" << string3 <<endl;
        }else{
            if(string2>string3){
                cout << string2 << "\n" << string3 << "\n" << string1 <<endl;
            }else{
                cout << string3 << "\n" << string1 << "\n" << string1 <<endl;

            }
        }
    }
    
    return 0;
}

