#include <iostream>
using namespace std;

// Program steps:
// Step 1: Output the board in the start_game() function
// Step 2: Ask user for input position (x,y coordinate)
// Step 3: Call update(int x, int y) function to display the updated board
// Step 4: Call check() function to check if a player wins the game
// Step 5: Ask the user if they want to play again, if one of the users says no, exit the program

bool check(char player);
// PURPOSE: check the board if any row, column or diagonal has 4 Xs or 4 Os in a row
// INPUT: the player that moved before this function is called
// OUTPUT: 1 if a player wins, 0 if no player win
// use vector to compare

void update(char player, int x, int y);
// PURPOSE: update the board with given coordinates and current player
// INPUT: current player, x and y coordinates
// OUTPUT: N/A

void start_game();
// PURPOSE: start the Tic_Tac_Toe game
// INPUT: each user will input the coordinate 
// OUTPUT: N/A


int main(){

}