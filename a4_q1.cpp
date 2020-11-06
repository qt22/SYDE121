//*****************************************************************************
// Student Name: Jerry Tian, Neha Javed
// Student Number: 20894361, 
//
// SYDE 121 Assignment: Assignment #4
// Filename: a4_q1.cpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Tic-Tac-Toe Game
// Purpose: Build a Tic-Tac-Toe game that allows two users to play 
// Due Date: Friday, November 6, 2020
//**************************************************************

// Program steps:
// Step 1: Output the board in the start_game() function
// Step 2: Ask user for input position (x,y coordinate)
// Step 3: Call update(int x, int y) function to display the updated board
// Step 4: Call check() function to check if a player wins the game
// Step 5: Ask the user if they want to play again, if one of the users says no, exit the program

/* 
    Test cases: 

    4 x 4 diagonal winning condition & replayed 3 times:
    X on position 1, 6, 11, 16 

    4 x 4 vertical winning condition & replayed 2 times:
    O on position 3, 7, 11, 15

    4 x 4 horizontal winning condition & replayed 2 times:
    X on position 5, 6, 7, 8

    Limitations: 
    The input has to be an integer, otherwise it will be round down to an integer.
    Don't enter other data types like string, it may result in breaking the program.
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


const unsigned int N = 4, WIDTH = 10;

void check(bool& game, string player, vector<string> positions);
// PURPOSE: check the board if any diagonal has 4 Xs or 4 Os in a row
// INPUT: current game status, current player, coordinates data
// OUTPUT: N/A

void update(string player, int pos, vector<string>& positions);
// PURPOSE: update the board with given coordinates and current player
// INPUT: current player and his/her coordinate
// OUTPUT: N/A

void X_input(int& X_pos, int& O_pos, vector<string>& positions, bool& game);

void O_input(int& X_pos, int& O_pos, vector<string>& positions, bool& game);

void start_game(int game_count);
// PURPOSE: start the Tic_Tac_Toe game
// INPUT: each user will input the coordinate 
// OUTPUT: N/A

void check(bool& game, string player, vector<string> positions){
    const unsigned int WIN_CONDITION = 4;
    bool check_same_char = true;
    // diagonal check
    for(int row = 0, column = 0; row < N, column < N; row++, column++){
        if(positions[row*N + column] != player){
            check_same_char = false;
            break;
        }
    }
    game = check_same_char;

    // horizontal check
    if(!check_same_char){
        for (int row = 0; row < N; row++){
            unsigned int horizontal_check = 0;
            for (int column = 0; column < N; column++){
                int position = row*N + column;
                if(positions[position] == player){
                    horizontal_check++;
                }
                if(horizontal_check == WIN_CONDITION){
                    game = true;
                    return;
                }
            }
        }
    }

    // vertical check
    if(!check_same_char){
        for (int column = 0; column < N; column++){
            unsigned int vertical_check = 0;
            for (int row = 0; row < N; row++){
                int position = row*N + column;
                if(positions[position] == player){
                    vertical_check++;
                }
                if(vertical_check == WIN_CONDITION){
                    game = true;
                    return;
                }
            }
        }
    }
    
}

void update(string player, int pos, vector<string>& positions){

    for (int row = 0; row < N; row++){

        for (int column = 0; column < N; column++){

            int position = row*N + column + 1;

            if(positions[position-1] == to_string(pos)){ // if the current position is the player input position
                // assign the letter to this position
                positions[position-1] = player;
                cout << left << setw(WIDTH) << positions[pos-1];
            }else{
                cout << left << setw(WIDTH) << positions[position-1];
            }
            
            
        }
        cout.put('\n');
    }
}


void O_input(int& X_pos, int& O_pos, vector<string>& positions, bool& game){
    bool input_again = false;

    do{
        input_again = false;
        cout << "Player O, please enter the coordinate." << endl;
        cin >> O_pos; // player O input coordinate

        // check if the other player already occupied the position 
        if(O_pos > N*N || O_pos < 1){
            input_again = true;
        }else if(positions[O_pos-1] != "X" && positions[O_pos-1] != "O"){
            update("O", O_pos, positions); // update the game board
            check(game, "O", positions); 
            if(game){
                cout << "Player O wins! \n\n\n";
                return;
            }
        }else{
            input_again = true;
        }
    }while(input_again);

    X_input(X_pos, O_pos, positions, game);
}

void X_input(int& X_pos, int& O_pos, vector<string>& positions, bool& game){
    bool input_again = false;

    do{
        input_again = false;
        cout << "Player X, please enter the coordinate." << endl;
        cin >> X_pos; // player X input coordinate

        // check if the other player already occupied the position  
        if(X_pos > N*N || X_pos < 1){
            input_again = true;
        }else if(positions[X_pos-1] != "X" && positions[X_pos-1] != "O"){
            update("X", X_pos, positions); // update the game board
            check(game, "X", positions);
            if(game){
                cout << "Player X wins! \n\n\n";
                return;
            }
        }else{
            input_again = true;
        }
    }while(input_again);

    O_input(X_pos, O_pos, positions, game);
}

void start_game(int game_count){
    vector<string> positions;
    positions.reserve(N*N);

    int X_pos = 0, O_pos = 0; // position in numbers from 1 to N squared
    bool game = false, next_game = false;
    string answer;

    // display the game board on the screen
    for (int row = 0; row < N; row++){
        for (int column = 0; column < N; column++){
            int position = row*N + column + 1;
            positions.push_back(to_string(position));
            cout << left << setw(WIDTH) << position;
        }
        cout.put('\n');
    }
    cout.put('\n');

    // ask for player X input and update
    cout << "Please only enter integer values! " <<
        "The program will break if you enter a value in other data types!" << endl;

    // each player alternates the starting move every game
    if(game_count % 2 == 0){
        O_input(X_pos, O_pos, positions, game);
    }else{
        X_input(X_pos, O_pos, positions, game);
    }
    
    
    // ask the players if they want to play again
    cout << "Players, do you want to play the game again? Answer yes or no (case sensitive)" << endl;
    cin >> answer;

    if(answer == "yes"){
        start_game(++game_count);
    }
}

int main(){
    start_game(1); // start the first game
}