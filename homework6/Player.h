/*
    PIC 10A Homework 6, Player.h
    header file
    Author: Megan Ma
    Date: 11/17/2021
 
 */

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<string>
using namespace std;

class Player
{
    public:
        /**
         Constructs a Player with name "MyPlayer" and health 0, n_battle 0, and n_win 0.
         */
        Player();
        /**
         Constructs a Player with name "myname" and health mystamina, n_battle mybattles, and n_win 0.
         */
        Player(string myname, int mystamina, int mybattles);
        /**
          Mimics the process of having 1 battle.
          @param enemy the object the player is playing against
          @return true if the player wins
          */
        bool battle(Player& enemy);
        /**
         Mimics the process of having one game (multiple battles)
         @param enemy the object the player is playing against
         @return true if the player wins the game (player wins more battles than enemy)
         */
        bool game(Player& enemy);
    //private variables
    private:
        string name;
        int health;
        int n_battle;
        int n_win;
};

#endif
