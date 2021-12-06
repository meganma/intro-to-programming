/*
    PIC 10A Homework 6, Player.cpp
    Implementation file
    Author: Megan Ma
    Date: 11/17/2021
 
 */
#include “Player.h”

#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<string>
using namespace std;


/************************************************
  methods implementation
 ***********************************************/

Player::Player()
{
    name = "MyPlayer";
    health = 0;
    n_battle = 0;
    n_win = 0;
}

Player::Player(string myname, int mystamina, int mybattles)
{
    name = myname;
    health = mystamina;
    n_battle = mybattles;
    n_win = 0;
}

bool Player::battle(Player& enemy){
    //declare variables to hold the number of points the player/enemy uses this battle
    int userhealthpoints, enemyhealthpoints;
    cout << "There are " << n_battle << " more battles left." << endl;
    cout << "You have " << health << " health points left." << endl;
    cout << "How many health points do you want to use? ";
    //store user input to the var userhealthpoints
    cin >> userhealthpoints;
    //don't allow the user to use more points than their current health
    if(userhealthpoints > health){
        userhealthpoints = health;
    }
    cout << name << " choose to use " << userhealthpoints << " health points." << endl;
    
    if(n_battle == 1){
        //use all of the enemy's points on the last battle
        enemyhealthpoints = enemy.health;
    }else{
        //if it isn't the last battle, the enemy uses a random int of health points in the range from 1 to their total health points
        enemyhealthpoints = rand() % enemy.health + 1;
    }
    cout << enemy.name << " choose to use " << enemyhealthpoints << " health points." << endl;
    
    //update new total health points
    health = health - userhealthpoints;
    enemy.health = enemy.health - enemyhealthpoints;
    
    if(enemyhealthpoints >= userhealthpoints){
        //return false if enemy wins the battle
        enemy.n_win = enemy.n_win + 1; //increase enemy win count
        cout << enemy.name << " wins this battle!\n" ;
        cout << "****************************************************\n" ;
        return false;
    }else{
        //return true if user wins the battle
        n_win = n_win + 1; //increase user win count
        cout << name << " wins this battle!\n";
        cout << "****************************************************\n" ;
        return true;
    }
}

bool Player::game(Player& enemy)
{
    bool count = true;
    //repeat battles until the number of battles is 0
    while(count == true){
        battle(enemy); //user battle the enemy
        n_battle = n_battle - 1; //update number of battles
        if(n_battle == 0){
            count = false;
        }
    }
    
    if(n_win > enemy.n_win){
        // return true if player wins the game
        cout << "The final winner is " << name << "."<< endl;
        return true;
    }else{
        //return false if enemy wins the game
        cout << "The final winner is " << enemy.name << "." << endl;
        return false;
    }
}

