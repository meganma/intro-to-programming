/*
    PIC 10A Homework 2, CountSpace.cpp
    Author: Megan Ma
    Date: 10/17/2021
 
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //variable initialization
    string userString;
    int counter = 0;
    //get string from user and store in userString
    cout << "Please enter a sentence: ";
    getline(cin,userString);
    //check whether or not each char in userString is a space
    for(int i = 0; i < userString.length(); i++)
    {
        if( userString[i] == ' ')
        {
            counter++; //increase counter by 1 if current char is a space
        }
    }
    // print counter
    cout << "\"" << userString << "\" has " << counter << " spaces." << endl;

    return 0;
}
