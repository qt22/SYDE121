//*****************************************************************************
// Student Name: Jerry Tian
// Student Number: 20894361
//
// SYDE 121 Assignment: Assignment #2
// Filename: a2_p2.cpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Distance of the baseball
// Purpose: #1: Find the distance of the baseball has fallen in each 1-second 
//          interval for the first 30 seconds along with the total distance 
//          traveled at the end of each interval.
//          #2: Find the amount of time that takes the baseball to reach the
//          ground when it is released at 15000 meters.
// Due Date: Friday, October 9, 2020
//**************************************************************

// Program steps:
// Step 1: Create a function that computes the distance using the formula
//         with given start time and end time.
// Step 2: Create another function that calculate the total distance 
//         with end time.
// Step 3: Create another function that has two arrays. One for the distance
//         during interval, the other for the total distance. Get both using 
//         the functions above. Then output them in a for loop with proper 
//         formatting.
// Step 4: Create another function that finds the time before the total 
//         distance reaches 15000 meters. Then find the exact time when the 
//         the baseball touches 15000 meters and round it up to 1 decimal place.
//
// Test cases: 
#include <iostream>
#include <iomanip>
using namespace std;

double distance(int start_time, int end_time);
// PURPOSE: Find the distance that the baseball traveled due to gravity
//          within the given time.
// INPUT: start_time, the time when the baseball is dropped;
//        end_time, the ending time of the time interval.
// OUTPUT: The distance traveled during the time interval. 

double distance(double start_time, double end_time);
// PURPOSE: Find the distance that the baseball traveled due to gravity
//          within the given time.
// INPUT: start_time, the time when the baseball is dropped;
//        end_time, the ending time of the time interval.
// OUTPUT: The distance traveled during the time interval.

void distance_in_30_seconds();
// PURPOSE: Display a chart that breaks down the distance a baseball
//          traveled in 30 seconds. 
// INPUT: N/A
// OUTPUT: An organized chart of the distance that a baseball traveled
//         in 30 seconds via console.

void time_for_15000m();
// PURPOSE: Find the time that the baseball needs to travel 15000m.
// INPUT: N/A
// OUTPUT: The amount of time in seconds with the resolution of 0.1s.

double distance(int start_time, int end_time){
    const double G = 9.80665;
    double distance = 0.5 * G * end_time * end_time - 
                      0.5 * G * start_time* start_time;
    return distance;
}

double distance(double start_time, double end_time){
    const double G = 9.80665;
    double distance = 0.5 * G * end_time * end_time - 
                      0.5 * G * start_time* start_time;
    return distance;
}

void distance_in_30_seconds(){
    const int ARRAY_SIZE = 31, ARRAY_SIZE_2 = 2, 
              DEFAULT_VALUE = 0, START_TIME = 0,
              START_DISTANCE = 0,
              TIME_WIDTH = 16, DISTANCE_WIDTH = 36;
    double distances[ARRAY_SIZE][ARRAY_SIZE_2] = {{DEFAULT_VALUE, DEFAULT_VALUE}};

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    cout << left << setw(TIME_WIDTH) << "Time (in sec):  " 
         << setw(DISTANCE_WIDTH) << "Distance during interval (in m):  " 
         << "Total distance (in m):  " << endl; 

    distances[0][0] = START_DISTANCE; 
    distances[0][1] = START_DISTANCE;
    cout << left << setw(TIME_WIDTH) << START_TIME
         << setw(DISTANCE_WIDTH) << distances[0][0] 
         << distances[0][1] << endl;

    for(int time = 1; time < ARRAY_SIZE; time++){
        distances[time][0] = distance(time - 1, time);
        distances[time][1] = distance(START_TIME, time);
        cout << left << setw(TIME_WIDTH) << time 
             << setw(DISTANCE_WIDTH) << distances[time][0] 
             << distances[time][1] << endl;
    }
}

void time_for_15000m(){
    const int HEIGHT = 15000, START_TIME = 0;
    const double PRECISE_HEIGHT = 15000.0, START_TIME_2 = 0.0,
                 INCREMENT = 0.1;
    int end_time = 1, falling_distance = 0;
    double end_time_2 = 0, falling_distance_2 = 0;
    
    while(falling_distance < HEIGHT){
        end_time++;
        falling_distance = distance(START_TIME, end_time);
    }   
    
    end_time_2 = --end_time;
    falling_distance_2 = distance(START_TIME_2, end_time_2);
    while(falling_distance_2 < PRECISE_HEIGHT){
        end_time_2 += INCREMENT;
        falling_distance_2 = distance(START_TIME_2, end_time_2);
    }
    
    cout << "It will take " << end_time_2 << " seconds for the ball to reach the ground.";
}

int main() {
    // distance_in_30_seconds();
    time_for_15000m();
}