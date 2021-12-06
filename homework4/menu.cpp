/*
    PIC 10A Homework 4, menu.cpp
    Author: Megan Ma
    Date: 10/30/2021
 
 */

#include <iostream>
#include <string>
using namespace std;

/* Prints the menu of options and the number of times Menu has been called.
@param times: number of times the menu has been called;
*/
void displayMenu(int& times){
    //print number of times menu has been called
    cout << "================== MENU " << times << " ==================" << endl;
    //print menu options
    cout << "1. Output the median" << endl;
    cout << "2. Get the next permutation" << endl;
    cout << "3. Sort in descending order" << endl;
    cout << "4. Simplify the numbers" << endl;
}

/* Computes the median of 3 integers.
@param a, b, c: user inputed positive integers
@return the median of a,b,c
*/
int median(int a, int b, int c){
    //comparison logic for finding the median number
    if((a > b && b > c)||(a < b && b < c)){
        // b is the median
        return b;
    }else if((b > a && a > c)||(b < a && a < c)){
        //a is the median
        return a;
    }else if((a > c && c > b)||(a < c && c < b)){
        // c is the median
        return c;
    }else{
        if(a == b){
            //when a == b
            if(a > c){
                //a is is the median
                return a;
            }else{
                //c is is the median
                return c;
            }
        }else if(b == c){
            //when b == c
            if(a > b){
                //b is is the median
                return b;
            }else{
                //a is is the median
                return a;
            }
        }else{
            //when a == c
            if(a > b){
                //a is is the median
                return a;
            }else{
                //b is is the median
                return b;
            }
        }
    }
}

/* Sorts 3 integers into descending order
@param a, b, c: user inputed positive integers
*/
void mySort(int& a, int& b, int& c){
    //store the old values of a,b,c to make reassigning values later easier
    int olda = a;
    int oldb = b;
    int oldc = c;
    //comparison logic for returning 3 strings in descending order
    if(a > b){
        if(b > c){
            // reassign values of a,b,c so that a>b>c
            a = olda;
            b = oldb;
            c = oldc;
        }else{
            if(a > c){
                // reassign values of a,b,c so that a>b>c

                b = oldc;
                c = oldb;
            }else{
                // reassign values of a,b,c so that a>b>c
                a = oldc;
                b = olda;
                c = oldb;
            }
        }
    }else{
        if(a > c){
            // reassign values of a,b,c so that a>b>c
            a = oldb;
            b = olda;
        }else{
            if(b > c){
                // reassign values of a,b,c so that a>b>c
                a = oldb;
                b = oldc;
                c = olda;
            }else{
                // reassign values of a,b,c so that a>b>c
                a = oldc;
                c = olda;
            }
        }
    }
}

/* Applies a permutation to three numbers: moving the last to the front
@param a, b, c: user inputed positive integers
*/
void myPermutation(int& a, int& b, int& c){
    // store the values of the old ints before changing them to make reassingment easier
    int oldc = c;
    int oldb = b;
    int olda = a;
    // reassign variables so that abc is the new permutation (with oldc moved to the front)
    a = oldc;
    b = olda;
    c = oldb;
}

/* Simplifies the three integers by dividing them by their maximum common factor
@param a, b, c: user inputed positive integers
*/

void mySimplify(int& a, int& b, int& c){
    //initialize variable to store max value
    int max;
    // comparison logic for finding the max value out of 3 numbers
        if(a > b && a > c){
            //max value out of a,b,c is a
            max = a;
        }else if(b > a && b > c){
            //max value out of a,b,c is b
            max = b;
        }else if(c > a && c > b){
            //max value out of a,b,c is c
            max = c;
        }else if(a == b){
            // max value when a == b
            if(a > c){
               max = a;
            }else{
                max = c;
            }
        }else if(b == c){
            // max value when b == c
            if(b > a){
               max = b;
            }else{
                max = a;
            }
        }else{
            // max value when a == c
            if(a > b){
                max = a;
            }else{
                max = b;
            }
        }
        //initialize max common denominator as 1 (every number has 1 as a factor)
        int mcd = 1;
        for(int i = 1; i <= max ; i++){
            if((a%i == 0)&&(b%i == 0)&&(c%i == 0)){
                mcd = i;
            }
        }
        
        // return each user int divided by the max common denominator
        a = a/mcd;
        b = b/mcd;
        c = c/mcd;
}

int main(){
    //initialize int variable to hold user input
    int x;
    int y;
    int z;
    //bool badoutput = true;
    while(true){
        cout << "Enter your three positive integers: ";
        cin >> x;
        cin >> y;
        cin >> z;
        if((x <= 0)||(y <= 0)||(z <= 0)){
            cout << "Error: non-positive inputs received." << endl;
            cout<< "\n";
        }else{
            break;
        }
    }
    
    //initialize an int var to count the number of times the menu is displayed
    int times = 1;
    //declare a string used to store user's menu choice
    string userChoice;
    
    //run program while userChoice is from 1-4
    while(true){
        displayMenu(times);
        cout << "Enter your choice (1 - 4), Q to quit: ";
        cin >> userChoice;
        if(userChoice == "1"){
            //user chooses median
            cout << "The median among the three is: " << median(x, y, z) << endl;
            cout << "\n";
        }else if(userChoice == "2"){
            //user chooses permutation
            myPermutation(x, y, z);
            cout << "After one permutation: " << x << " "  << y << " " << z << endl;
            cout << "\n";
        }else if(userChoice == "3"){
            //user chooses sort
            mySort(x, y, z);
            cout << "After sorting: " << x << " "  << y << " " << z << endl;
            cout << "\n";
        }else if(userChoice == "4"){
            //user chooses simplify
            mySimplify(x, y, z);
            cout << "After simplify: "<< x << " "  << y << " " << z << endl;
            cout << "\n";
        }else{
            //any imput besides 1-4: user exits the program
            cout << "Exit the Menu" << endl;
            break;
        }
        //increase the number of times menu is called
        times = times + 1;
    }
    
    return 0;
}








