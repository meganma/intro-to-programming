/*
    PIC 10A Homework 3, randomWalk.cpp
    Author: Megan Ma
    Date: 10/25/2021
 
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    //initialize variables
    int x = 0;
    int y = 0;
    bool done = false;
    int direction;
    //set up pseudorandom number generator seed (based on current time)
    srand(static_cast<int>(time(nullptr)));
    
    while(!done){
        //direction is a random integer from 1 to 4
        
        direction = rand() % 4 + 1;
        if(direction == 1){
            // move up if direction = 1
            y = y + 1;
            cout << setw(10) << left << "Up" << "(" << x << "," << y << ")" << endl;
        }else if(direction == 2){
            // move down if direction = 2
            y = y - 1;
            cout << setw(10) << left << "Down" << "(" << x << "," << y << ")" << endl;
        }else if(direction == 3){
            // move right if direction = 3
            x = x + 1;
            cout << setw(10) << left << "Right" << "(" << x << "," << y << ")" << endl;
        }else{
            // move left if direction = 4
            x = x - 1;
            cout << setw(10) << left << "Left" << "(" << x << "," << y << ")" << endl;
        }
        
        if(x==0 && y==0){
            cout << "Back to the origin!" << endl;
            done = true; //stop the while loop
        }else if((x == 5) || (x == -5) || (y == 5) | (y == -5)){
            cout << "Hit the boundary!" << endl;
            done = true; //stop the while loop
        }
    
    }
    return 0;
}

 
