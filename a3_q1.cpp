//*****************************************************************************
// Student Name: Jerry Tian
// Student Number: 20894361
//
// SYDE 121 Assignment: Assignment #3
// Filename: a3_q1.cpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Soccer Game Simulator
// Purpose: Simulate a soccer game between two teams with 1 to 20 events. 
// Due Date: Friday, October 30, 2020
//**************************************************************

// Program steps:
// Step 1: Generate the number of events and store it in a variable.
// Step 2: Call the dice function to generate a random number between 1 and 6.
//         Repeat this for all events.
// Step 3: Based on the number generated, call another random number generator function 
//         to determine if a goal is scored.
// Step 4: Output the event. Divide the game into two parts by a timer.
//         Output game stats at the end of each half.
//
/* 
    Test cases: 
    Limitations: 
    The program doesn't count yellow cards for every player 
    so 2 yellow cards becomes 1 red card is not doable for the program.
    There is a chance that the program keeps giving red cards to one team 
    and their number of players may become negative.
*/
#include <iostream>
#include <ctime>
using namespace std;

bool foul_rng(char team);
// PURPOSE: Determine the penalty of the foul.
// INPUT: the team A or B
// OUTPUT: 0 for no card, 1 for yellow card, 2 for red card.

bool goal_rng(char team);
// PURPOSE: Determine if the team scores a goal.
// INPUT: the team A or B
// OUTPUT: 0 for scoring a goal, 1 for made on goal but saved by goalkeeper or last defender,
//         2 for off target, 3 for blocking by other defenders.

void dice(int event);
// PURPOSE: Determine the type of the event.
// INPUT: N/A
// OUTPUT: 1, Team A has shot at target;
//         2, Team B has shot at target;
//         3, Team B has committed a foul and Team A was awarded a free kick;
//         4, Team A has committed a foul and Team B was awarded a free kick;
//         5, Team B has committed a foul close to the goal and Team A was awarded a penalty kick. 
//         6, Team A has committed a foul close to the goal and Team B was awarded a penalty kick. 

void start_soccer_game();
// PURPOSE: Simulate the whole soccer game, first half and second half.
// INPUT: N/A
// OUTPUT: Game stats for each half. 
//         Event statement for each event.

bool foul_rng(char team){
    srand(time(0));
    const int NO_PENALTY = 0, YELLOW_CARD = 1, RED_CARD = 2;
    int event = rand() % (RED_CARD + 1);

    if(event == NO_PENALTY){
        cout << "Warning for team " << team << " !" << endl;
    }else if(event == YELLOW_CARD){
        cout << "YELLOW CARD FOR TEAM " << team 
        << " ! They need to be more careful now!" << endl;
    }else if(event == RED_CARD){
        cout << "!!!!!!!\n" << "RED CARD FOR TEAM " << team 
        << " ! They lose one player from the team!!!" << endl;
    }
}

bool goal_rng(char team){
    srand(time(0));
    const int SCORE = 0, SAVED_BY_KEEPER = 1,
              OFF_TARGET = 2, SAVED_BY_DEFENDER = 3;
    int event = rand() % (SAVED_BY_DEFENDER + 1);

    if(event == SCORE){
        if(team == 'A'){
            cout << "GOALLLLLLL for team A!!!" << endl;
            return true;
        }else{
            cout << "GOALLLLLLL for team B!!!" << endl;
            return true;
        }
    }else if(event == SAVED_BY_KEEPER){
        cout << "SAVED BY THE KEEPER!" << endl;
    }else if(event == OFF_TARGET){
        cout << "SO CLOSE! HE MISSED THE SHOT!" << endl;
    }else if(event == SAVED_BY_DEFENDER){
        cout << "THE BALL COULDN'T PASS THE WALL!" << endl;
    }
    return false;
}

void dice(int event){
    const int A_ON_TARGET = 1, B_ON_TARGET = 2,
              A_FREE_KICK = 3, B_FREE_KICK = 4, 
              A_PENALTY_KICK = 5, B_PENALTY_KICK = 6;
    if(event < A_FREE_KICK){ // event: shot on target
        if(event == A_ON_TARGET){
            cout << "Team A has a shot on target!!" << endl;
            goal_rng('A'); 
        }else{
            cout << "Team B has a shot on target!!" << endl;
            goal_rng('B');
        }
    }else if(event >= A_FREE_KICK && event < A_PENALTY_KICK){ // event: free kick
        if(event == A_FREE_KICK){
            cout << "Free Kick chance for TEAM A!" << endl;
            foul_rng('B');
            goal_rng('A');
        }else{
            cout << "Free Kick chance for TEAM B!" << endl;
            foul_rng('A');
            goal_rng('B');
        }
    }else{// event: penalty kick
        if(event == A_PENALTY_KICK){
            cout << "PENALTY KICK chance for TEAM A!!! Can they score?!!" << endl;
            foul_rng('B');
            goal_rng('A');
        }else{
            cout << "PENALTY KICK chance for TEAM B!!! Can they score?!!" << endl;
            foul_rng('A');
            goal_rng('B');
        }
    }
}

void start_soccer_game(){
    const int MAX_EVENT = 20, DICE = 6, GOAL = 5, FOUL = 4;
    srand(time(0)); // set the seed to time
    int num_events = 3; // generate an integer between 1 and 20

    
    for (int i = 0; i < num_events; i++){
        int dice_event = rand() % DICE + 1; 
        dice(dice_event);
        cout << '\n';
    }
    
}

int main(){
    start_soccer_game();
}
