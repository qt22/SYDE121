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
//         Part 1: 30s, 12s, 0s, 1s, 300s, 2147483647s, 2147483s, 65536s, 86400s.
//         Part 2: (15000m, 55.4s), (10000m, 45.2s), (384000000, 8849.6s),
//                 (42m, 3.0s), (2m, 1.0s), (5m, 1.1s).
// Valid Range: Part 1: 0s to 86400s and more. The reason I chose 86400s is because it means 24 hours.
//              Part 2: 5m to 384000000m and more. The program will give 1s if the given distance is smaller than 5m.
//                      The reason I chose 384000000m is because it is the distance between moon and earth.
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
    // Declare and initialize variables.
    const double G = 9.80665;
    double distance = 0.5 * G * end_time * end_time - 
                      0.5 * G * start_time* start_time; // Plug in the formula
    return distance;
}

double distance(double start_time, double end_time){
    // Declare and initialize variables.
    const double G = 9.80665;
    double distance = 0.5 * G * end_time * end_time - 
                      0.5 * G * start_time* start_time; // Plug in the formula
    return distance;
}

void distance_in_30_seconds(){
    // Declare and initialize variables.
    const int ARRAY_SIZE = 31, ARRAY_SIZE_2 = 2, 
              DEFAULT_VALUE = 0, 
              START_TIME = 0, START_DISTANCE = 0,
              PRECISION = 3,
              TIME_WIDTH = 16, DISTANCE_WIDTH = 36;
    // The array below is a 2 dimensional array. 
    // It stores the distance during interval and the total distance of each second.
    double distances[ARRAY_SIZE][ARRAY_SIZE_2] = {{DEFAULT_VALUE, DEFAULT_VALUE}};
    
    // Set the precision to three decimal points.
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(PRECISION);

    // Set alignment to left and set the width between each element.
    cout << left << setw(TIME_WIDTH) << "Time (in sec):  " 
         << setw(DISTANCE_WIDTH) << "Distance during interval (in m):  " 
         << "Total distance (in m):  " << endl; 

    // Set the start distance to 0.
    distances[0][0] = START_DISTANCE; 
    distances[0][1] = START_DISTANCE;
    cout << left << setw(TIME_WIDTH) << START_TIME
         << setw(DISTANCE_WIDTH) << distances[0][0] 
         << distances[0][1] << endl;
    
    // Compute the distance during interval and the total distance for each second.
    // Output them with the format for the headers.
    for(int time = 1; time < ARRAY_SIZE; time++){
        distances[time][0] = distance(time - 1, time);
        distances[time][1] = distance(START_TIME, time);
        cout << left << setw(TIME_WIDTH) << time 
             << setw(DISTANCE_WIDTH) << distances[time][0] 
             << distances[time][1] << endl;
    }
}

void time_for_15000m(){
    // Declare and initialize variables
    // Double variables are introduced here to match the parameters of the function.
    const int HEIGHT = 15000, START_TIME = 0;
    const double PRECISE_HEIGHT = 15000.0, START_TIME_2 = 0.0,
                 INCREMENT = 0.1, PRECISION = 1;
    int end_time = 1, falling_distance = 0;
    double end_time_2 = 0, falling_distance_2 = 0; 
    
    // The loop finds the time in seconds when the total distance reaches 15000 meters.
    while(falling_distance < HEIGHT){
        end_time++;
        falling_distance = distance(START_TIME, end_time);
    }   
    
    // The variable end_time is the time that takes the ball to pass 15000 meters.
    // end_time_2 brings the time back by 1 second which the ball is still flying.
    end_time_2 = --end_time;
    falling_distance_2 = distance(START_TIME_2, end_time_2); // Get the distance when 
                                                             // it is close to the ground
                                                             // but it hasn't touched the 
                                                             // ground yet.
    // The loop finds the time in seconds when the total distance reaches 15000 meters.
    while(falling_distance_2 < PRECISE_HEIGHT){
        end_time_2 += INCREMENT;
        falling_distance_2 = distance(START_TIME_2, end_time_2);
    }
    // Output the time 
    cout.precision(PRECISION);
    cout << "It will take " << end_time_2 << " seconds for the ball to reach the ground.";
}

int main() {
    distance_in_30_seconds();
    time_for_15000m();
}