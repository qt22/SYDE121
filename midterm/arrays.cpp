//*****************************************************************************
// Student Name: Jerry Tian
// Student Number: 20894361
//
// SYDE 121 Midterm Question 2
// Filename: arrays.cpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Purpose: Output number in the array until it is not increasing. 
// Due Date: Thursday, October 22, 2020
//**************************************************************
//
// Program steps:
// Step 1: initialize an array with 20 elements available 
//         and add the first element into the output array.
// Step 2: In a for loop, check if the previous element is smaller than the current element
// Step 3: If it is smaller, add the current number into the output array
//         If it is larger, add 21 to the index to exit the for loop.
// Step 4: In another for loop, output the output loop. 

#include <iostream>
using namespace std;

void increasing_arr(int arr[], int arr_size);
// Purpose: Output number in the array until it is not increasing. 
// Input: an array and its size
// Output: number in increasing order separated by space.

void increasing_arr(int arr[], int arr_size){
    // declare and initialize the variable
    int MAX_SIZE = 20; 

    // Even if the whole array is decreasing, it still outputs the first number.
    cout << arr[0] << " ";

    for (int index = 1; index < arr_size; index++){
        // if the current value is smaller
        if(arr[index-1] < arr[index]){
            cout << arr[index] << " "; 
        }else{
            index += MAX_SIZE; 
            // by adding the index by max_size, 
            // the index variable becomes greater than arr_size
            // so that it can escape the loop.
        }
    }
    
}
int main(){
    // int SIZE = 20;
    // int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    //                  10, 4, 4, 2, 4, 2, 4, 2, 2, 4};
    // It tests the scenario when the array size is at maximum.

    // int SIZE = 1;
    // int arr[SIZE] = {10};
    // It tests the scenario when the array size is at minimum.

    // int SIZE = 10;
    // int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 9, 9, 10};
    // It tests the scenario when two equal values are next to each other.

    int SIZE = 10;
    int arr[SIZE] = {4, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // It tests the scenario when the first two elements are in decreasing order.

    increasing_arr(arr, SIZE);
}