//*****************************************************************************
// Student Name: Jerry Tian
// Student Number: 20894361
//
// SYDE 121 Assignment: Assignment #2
// Filename: a2_p1.cpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Prime number with special cases
// Purpose: Find all palindromic prime numbers less than 10000 and 
//          prime numbers with odd sum of digits less than 100000.
// Due Date: Friday, October 9, 2020
//**************************************************************

// program steps:
// 
// Test cases
#include <iostream>
#include <cmath>
using namespace std;
// use long int

int num_of_digits(long int n);
// PURPOSE: This function computes the number of digits of the given integer.

bool odd_sum_of_digits(long int n);
// PURPOSE: This function checks if the sum of the given integer is odd.
// INPUT: n, the integer received from the user
// OUTPUT: 1 if the sum of digits of n is odd, 0 if the sum of digits 
//         of n is even.

bool palindrome(long int n);
// PURPOSE: This function checks if the given integer is palindromic.
// INPUT: n, the integer received from the user
// OUTPUT: 1 if the integer n is palindromic, 0 if the integer n 
//         is not palindromic.

void compute_prime_numbers();
// PURPOSE: Find all the prime numbers from 1 to the positive integer 
//          provided by user.
// INPUT: The upper bond of the prime number inputted via console.
// OUTPUT: Palindromic prime numbers less than 10000, odd sum of digits  
//         prime numbers less than 100000 and all other prime numbers  
//         from 1 to the upper bond will be displayed via console.

int num_of_digits(long int n){
    int num_digits = 1;
    const int TEN = 10;
    while(n/TEN){
        num_digits++;
        n /= TEN;
    }
    return num_digits;
}

bool odd_sum_of_digits(long int n){
    const int TEN = 10, EVEN = 2;
    const double HALF = 0.5;
    int num_digits = num_of_digits(n);
    int copy_num_digits = num_digits, index = 0, sum = 0;

    int digits[num_digits] = { 0 };

    
    while(n){
        copy_num_digits--;
        int thousand = int(pow(TEN, copy_num_digits) + HALF);
        digits[index] =  n / thousand;
        n = n - digits[index] * thousand;
        index++;
    }

    for(int index = 0; index < num_digits; index++){
        cout << digits[index] << '\n';
        sum += digits[index];
    }

    if(sum % EVEN == 0){
        return false;
    }else{
        return true;
    }
}

bool palindrome(long int n){
    int num_digits = num_of_digits(n);
    if(num_digits % 2 == 0){
        
    }

}
int main(){
    cout << "odd sum: " << odd_sum_of_digits(2314);
}