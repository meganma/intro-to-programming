/* PIC10A Battle with enemy
 * Coded by Weiqi Chu
 */

#include<iostream>
#include<ctime>
#include<stdlib.h>
#include"Player.h"

using namespace std;

int main()
{
    srand(static_cast<int>(time(nullptr)));
    
    // set total health points and number of battles
    const int TOTAL_HEALTH = 100;
    const int N_BATTLES = 3;
    
    // initialize two Players: Skywalker and Vader
    // User will play as Skywalker and computer will play as Vader
    Player Skywalker("Anakin Skywalker", TOTAL_HEALTH, N_BATTLES);
    Player Vader("Darth Vader", TOTAL_HEALTH, N_BATTLES);
    
    // conduct one game consisting of N_BATTLES battles
    // first argument is played by the Player and the second argument is played by computer (random number generators)
    Skywalker.game(Vader);

    return 0;
}
