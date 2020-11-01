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
    
    I experienced a problem that my program only works in debug mode but not in terminal output.
    I fixed the problem by moving srand() in every function to start_soccer_game() function.

    After this, I tested my program 30 times. It works well in all conditions. 

    Limitations: 

    The program doesn't count yellow cards for every player 
    so 2 yellow cards becomes 1 red card is not doable for the program.

    There is a chance that the program keeps giving red cards to one team 
    and their number of players may become negative.

    <Windows.h> is imported into this program so it only works in a windows system.
*/
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <unistd.h>
using namespace std;

int shots_on_goal = 0, shots_off_goal = 0, blocked_shots = 0,
    fouls = 0, yellow_cards = 0, red_cards = 0;

void foul_rng(char team, int event);
// PURPOSE: Determine the penalty of the foul.
// INPUT: the team A or B and the random event number
// OUTPUT: penalty: warning, yellow card or red card

bool goal_rng(char team, int event);
// PURPOSE: Determine if the team scores a goal.
// INPUT: the team A or B and the random event number
// OUTPUT: return 1 if a team scored, 0 if no team scored.

bool penalty_goal_rng(char team, int event);
// PURPOSE: Determine if the team scores a goal from penalty kick.
// INPUT: the team A or B and the random event number
// OUTPUT: return 1 if a team scored, 0 if no team scored.

bool dice(int event, int goal_event, int foul_event, int penalty_goal_event);
// PURPOSE: Determine the type of the event.
// INPUT: random event number for each type of event
// OUTPUT: return 1 if a team scored, 0 if no team scored.

void start_soccer_game();
// PURPOSE: Simulate the whole soccer game.
// INPUT: N/A
// OUTPUT: result of first half and second half of the game

void foul_rng(char team, int event){
    // variable declaration and definition
    const int NO_PENALTY = 0, YELLOW_CARD = 1, RED_CARD = 2;

    // Find the event based on the given random number
    // and output the results and log stats of the game.
    if(event == NO_PENALTY){
        cout << "Warning for team " << team << endl;
        fouls++;
    }else if(event == YELLOW_CARD){
        cout << "YELLOW CARD FOR TEAM " << team << endl;
        fouls++;
        yellow_cards++;
    }else if(event == RED_CARD){
        cout << "RED CARD FOR TEAM " << team << endl;
        fouls++;
        red_cards++;
    }
}

bool goal_rng(char team, int event){
    // variable declaration and definition
    const int SCORE = 0, SAVED_BY_KEEPER = 1,
              OFF_TARGET = 2, SAVED_BY_DEFENDER = 3;

    // Find the event based on the given random number
    // and output the results and log stats of the game.
    if(event == SCORE){
        if(team == 'A'){
            cout << "GOALLLLLLL for team A!!!" << endl;
            shots_on_goal++;
            return true;
        }else{
            cout << "GOALLLLLLL for team B!!!" << endl;
            shots_on_goal++;
            return true;
        }
    }else if(event == SAVED_BY_KEEPER){
        cout << "SAVED BY THE KEEPER!" << endl;
        shots_on_goal++;
        blocked_shots++;
    }else if(event == OFF_TARGET){
        cout << "VERY CLOSE TO A GOAL" << endl;
        shots_off_goal++;
    }else if(event == SAVED_BY_DEFENDER){
        cout << "SAVED BY A DEFENDER!" << endl;
        shots_on_goal++;
        blocked_shots++;
    }
    return false;
}

bool penalty_goal_rng(char team, int event){
    // variable declaration and definition
    const int SCORE = 0, SAVED_BY_KEEPER = 1,
              OFF_TARGET = 2;

    // Find the event based on the given random number
    // and output the results and log stats of the game.
    if(event == SCORE){
        if(team == 'A'){
            cout << "GOALLLLLLL for team A!!!" << endl;
            shots_on_goal++;
            return true;
        }else{
            cout << "GOALLLLLLL for team B!!!" << endl;
            shots_on_goal++;
            return true;
        }
    }else if(event == SAVED_BY_KEEPER){
        cout << "SAVED BY THE KEEPER!" << endl;
        shots_on_goal++;
        blocked_shots++;
    }else if(event == OFF_TARGET){
        cout << "VERY CLOSE TO A GOAL" << endl;
        shots_off_goal++;
    }
    return false;
}

bool dice(int event, int goal_event, int foul_event, int penalty_goal_event){
    // variable declaration and definition
    const int A_ON_TARGET = 1, B_ON_TARGET = 2,
              A_FREE_KICK = 3, B_FREE_KICK = 4, 
              A_PENALTY_KICK = 5, B_PENALTY_KICK = 6;

    // Find the event based on the given random number 
    // also pass on the result from children functions to the parent function.
    if(event < A_FREE_KICK){ // event: shot on target
        if(event == A_ON_TARGET){
            cout << "Team A has a shot on target!!" << endl;
            return goal_rng('A', goal_event); 
        }else{
            cout << "Team B has a shot on target!!" << endl;
            return goal_rng('B', goal_event);
        }
    }else if(event >= A_FREE_KICK && event < A_PENALTY_KICK){ // event: free kick
        if(event == A_FREE_KICK){
            cout << "Free Kick for TEAM A!" << endl;
            foul_rng('B', foul_event);
            return goal_rng('A', goal_event);
        }else{
            cout << "Free Kick for TEAM B!" << endl;
            foul_rng('A', foul_event);
            return goal_rng('B', goal_event);
        }
    }else{// event: penalty kick
        if(event == A_PENALTY_KICK){
            cout << "PENALTY KICK chance for TEAM A!!!" << endl;
            foul_rng('B', foul_event);
            return penalty_goal_rng('A', penalty_goal_event);
        }else{
            cout << "PENALTY KICK chance for TEAM B!!!" << endl;
            foul_rng('A', foul_event);
            return penalty_goal_rng('B', penalty_goal_event);
        }
    }
}

void start_soccer_game(){
    // variable declaration and definition
    const int MAX_EVENT = 20, DICE = 6, GOAL = 4, FOUL = 3, PENALTY_GOAL = 3,
              EVENT_TIME_DELAY = 2000, HALF_TIME = 8000;
    srand(time(0)); // set the seed to time
    int num_events = rand() % MAX_EVENT + 1; // generate an integer between 1 and 20
    int A_score = 0, B_score = 0;

    
    for (int i = 0; i < num_events; i++){
        int dice_event = rand() % DICE + 1; // generate an integer between 1 and 6
        int goal_event = rand() % GOAL; // generate an integer between 0 and 3
        int foul_event = rand() % FOUL; // generate an integer between 0 and 2
        int penalty_goal_event = rand() % PENALTY_GOAL; // generate an integer between 0 and 2

        if(dice_event % 2){ // if the event number is odd, then A has a chance to score
            A_score += dice(dice_event, goal_event, foul_event, penalty_goal_event);
        }else{ // if the event number is even, then B has a chance to score
            B_score += dice(dice_event, goal_event, foul_event, penalty_goal_event);
        }
        cout << '\n';
        
        Sleep(EVENT_TIME_DELAY); // time delay between each event

        if(i == (num_events-1) / 2){ // Half time stats
            cout << "FIRST HALF OF THE GAME HAS FINISHED!" << endl;
            cout << "Team A: " << A_score << "  Team B: " << B_score << endl;
            cout << "Number of shots on goal: " << shots_on_goal 
                 << "   Number of shots off goal: " << shots_off_goal << endl;
            cout << "Number of blocked shots: " << blocked_shots << endl;
            cout << "Number of fouls: " << fouls << endl;
            cout << "Number of yellow cards: " << yellow_cards 
                 << "   Number of red cards: " << red_cards << '\n' << endl;

            Sleep(HALF_TIME); // time delay between two halves
        }
    }

    // full time stats
    cout << "GAME FINISHED!" << endl;
    cout << "Team A: " << A_score << "  Team B: " << B_score << endl;
    cout << "Number of shots on goal: " << shots_on_goal 
         << "   Number of shots off goal: " << shots_off_goal << endl;
    cout << "Number of blocked shots: " << blocked_shots << endl;
    cout << "Number of fouls: " << fouls << endl;
    cout << "Number of yellow cards: " << yellow_cards 
         << "   Number of red cards: " << red_cards << endl;
    
}

int main(){
    start_soccer_game();
}
