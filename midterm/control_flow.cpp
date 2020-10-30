//*****************************************************************************
// Student Name: Jerry Tian
// Student Number: 20894361
//
// SYDE 121 Midterm Question 3
// Filename: control_flow.cpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Due Date: Thursday, October 22, 2020
//**************************************************************
//
// Program steps:
// Step 1: Get input from the user.
// Step 2: Find the number of digits of the number and store the digits in an array.
// Step 3: Access the array backwards and check if the conditions are met.
// Step 4: Output the digits.

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void break_down_num(int arr[], int size, int n);
// Purpose: Assign each digit as an element in an array.
// Input: An array with its size and the interger n provided by the user.
// Output: N/A

void check_num();
// Purpose: find the digits before seven or between 2 sevens.
// Input: Integer n provided by the user.
// Output: N/A

void break_down_num(int arr[], int size, int n){
    // Declare and initialize variables
    const int TEN = 10;
    const double HALF = 0.5; 
    int index = 0;

    while(n){
        // tens means the 10 to the power of number of size.
        // I added 0.5 to it to make sure the number is precise.
        // For example, if the number is 121,101,161, its tens is 100,000,000.
        int tens = int(pow(TEN, --size) + HALF); 

        // Get the digit on the left most side.
        // For example 121,101,161 / 100,000,000 = 1
        arr[index] =  n / tens; 

        // Get rid of the digit on the left most side.
        // For example 121,101,161 = 121,101,161 - 1 * 100,000,000 = 21,101,161
        // Continue this process until it reaches last digit.
        n -= arr[index] * tens; 
        index++;
    }
}

void check_num(){
    const int ONE_MILLION = 1000000, SEVEN = 7, TWO = 2;
    int n, num_digits;
    vector<int> position;

    // user input and check input
    while(true){
        cout << "Please enter an integer greater than 1000000" << endl;
        cin >> n;
        if(n > ONE_MILLION){
            break;
        }
        cout << "Read the instruction more carefully PLEASE!" << endl;
    }

    // break down digits
    num_digits = int(log10(n)+1);
    int digits[num_digits] = {0};
    break_down_num(digits, num_digits, n);
    position.reserve(TWO);

    // get seven positions
    for (int i = num_digits - 1; i >= 0; i--){
        if(digits[i] == SEVEN){
            position.push_back(i);
            if(position.size() == TWO){
                break;
            }
        }
    }

    // different scenarios
    if(position.size() == TWO){
        for(int i = position.at(1) + 1; i < position.at(0) - 1; i++){
            cout << digits[i] << " ";
        }
        if(position.at(0) - position.at(1) == 1){
            cout << 0;
        }
    }else if(position.size() == 1){
        for(int i = 0; i < position.at(0) - 1; i++){
            cout << digits[i] << " ";
        }
        if(position.at(0) == 0){
            cout << 0;
        }
    }else{
        cout << 0;
    }
    // Test value 1:
    // 1234773 
    // output: 0
    // 2 sevens are next to each other.
    
    // Test value 2:
    // 7123457
     // output: 12345
    // 2 sevens are not next to each other.
    
    // Test value 3:
    // 71234455
     // output: 0
    // 1 seven and its in the front of the number

    // Test value 4:
    // 1003333
     // output: 0
    // no sevens

    // Test value 5: 
    // 1223437
     // output: 122343
    // 1 seven at the end of the number
}

int main(){
    check_num();
}