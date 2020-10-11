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
// Test cases: 
#include <iostream>
#include <cmath>
using namespace std;
// use long int

int num_of_digits(long int n);
// PURPOSE: This function computes the number of digits of the given integer.

void break_down_digits(int digits[], int size, int n);
// PURPOSE: This function assign digits of an integer into an array.
// INPUT: An array, its size and the integer provided by user.
// OUTPUT: N/A 

bool odd_sum_of_digits(long int n);
// PURPOSE: This function checks if the sum of the given integer is odd.
// INPUT: n, the integer received from the user.
// OUTPUT: 1 if the sum of digits of n is odd, 0 if the sum of digits 
//         of n is even.

bool palindrome(long int n);
// PURPOSE: This function checks if the given integer is palindromic.
// INPUT: n, the integer received from the user.
// OUTPUT: 1 if the integer n is palindromic, 0 if the integer n 
//         is not palindromic.

bool prime(long int n);
// PURPOSE: This function checks if the given integer is a prime number.
// INPUT: n, the integer received from the user.
// OUTPUT: 1 if the integer n is a prime number, 0 if the integer n 
//         is not a prime number.

void compute_prime_numbers();
// PURPOSE: Find all the prime numbers from 1 to the positive integer 
//          provided by user and identify those with special cases.
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

void break_down_digits(int digits[], int size, long int n){
    const int TEN = 10, NUM_DIGITS = num_of_digits(n);
    const double HALF = 0.5;

    int copy_num_digits = NUM_DIGITS, index = 0;

    while(n){
        copy_num_digits--;
        int tens = int(pow(TEN, copy_num_digits) + HALF);
        digits[index] =  n / tens;
        n = n - digits[index] * tens;
        index++;
    }
}

bool odd_sum_of_digits(long int n){
    const int NUM_DIGITS = num_of_digits(n),
              DEFAULT_VALUE = 0;
    int copy_num_digits = NUM_DIGITS, index = 0, sum = 0;

    int digits[NUM_DIGITS] = { DEFAULT_VALUE };

    break_down_digits(digits, NUM_DIGITS, n);

    for(int index = 0; index < NUM_DIGITS; index++){
        // cout << digits[index] << '\n';
        sum += digits[index];
    }

    bool even = sum % 2 == 0;
    if(even){
        return false;
    }else{
        return true;
    }
}

bool palindrome(long int n){
    const int NUM_DIGITS = num_of_digits(n), HALF = NUM_DIGITS/2,
              DEFAULT_VALUE = 0;
    int copy_of_num_digits = NUM_DIGITS;
    int digits[NUM_DIGITS] = { DEFAULT_VALUE };

    break_down_digits(digits, NUM_DIGITS, n);

    for(int index = 0; index < HALF; index++){
        if(digits[index] != digits[--copy_of_num_digits]){
            return false;
            break;
        }
    }
    
    return true;

}

bool prime(long int n){
    bool if_prime = false;
    const int LEAST_PRIME_NUM = 2;

    if(n == LEAST_PRIME_NUM){
        return true;
    }
    for(int index = LEAST_PRIME_NUM; index < n; index++){
        if(n % index == 0){
            if_prime = false;
            break;
        }else{
            if_prime = true;
        }
    }
    return if_prime;
}

void compute_prime_numbers(){
    long int n = 0;
    const int LOWER_LIMIT = 1, START_NUM = 2, 
              TEN_THOUSAND = 10000, HUNDRED_THOUSAND = 100000;
    
    while(true){
        cout << "Please choose an integer that is greater than 1: " << endl;
        double value = 0;
        cin >> value;
        cin.get();
        if(value > LOWER_LIMIT){
            n = int(value);
            break;
        }
        cout << "Please read the instruction carefully!" << endl;
    }

    for(int index = START_NUM; index <= n; index++){
        bool condition1 = prime(index);
        if(condition1){
            cout << index << " is a prime number. ";
        }
        bool condition2 = prime(index) && palindrome(index);
        if(condition2 && index < TEN_THOUSAND){
            cout << "It is also palindromic. ";
        }
        bool condition3 = prime(index) && odd_sum_of_digits(index);
        if(condition3 && index < HUNDRED_THOUSAND){
            cout << "Its sum of digits is odd as well.";
        }
        if(condition1 || condition2 || condition3){
            cout << '\n';
        }
    }
}

int main(){
    compute_prime_numbers();
}