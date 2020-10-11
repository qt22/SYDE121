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
    const int ARRAY_SIZE = 31, ARRAY_SIZE_2 = 2, DEFAULT_VALUE = 0;
    int distances[ARRAY_SIZE][ARRAY_SIZE_2] = {{DEFAULT_VALUE, DEFAULT_VALUE}};

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    cout << "Time (in sec):   " << "Distance during interval (in m):   " 
         << "Total distance (in m):   " << endl; 

}

int main() {
    cout << distance(1.2, 3.5);
}