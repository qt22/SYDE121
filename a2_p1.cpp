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

// Program steps:
// Step 1: Ask the user for the input integer
// Step 2: Go through all integers from 1 to the input integer (inclusive).
// Step 3: Check if the integer is prime
// Step 4: If the integer is prime, check if it is palindromic, or it's sum 
//         of digits is odd or both.
// Step 5: Introduce functions for checking prime numbers, palindrome and odd sum of digits.
// Step 6: Output the properties of the integer.
//
// Test cases: 
//             102, char, 2, 1, 2.5, 500000, 11312, 2334, -2147483647, -2147483650, -21474899999
//             -9223372036854775807, -92233729999999999999, 2147483647, 2147483659.
// Valid range: negative infinity to 2147483647 
//              The input has to be an integer, otherwise it will be round down to an integer.
//              Don't enter other data types like string, it may result in breaking the program.

#include <iostream>
#include <cmath>
using namespace std;

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
    // Declare and initialize required variables.
    int num_digits = 1; // number of digits
    const int TEN = 10; 

    // Step 1: Compute the number of digits of the integer n
    //         using a while loop.
    // Explanation: Divide by 10 every time to get rid of one digit
    //              and count the digit using the variable num_digits.
    //              When n only has one digit left, exit the loop.
    while(n/TEN){
        num_digits++;
        n /= TEN;
    }
    
    // Step 2: Return the number of digits
    return num_digits;
}

void break_down_digits(int digits[], int size, long int n){
    // Declare and initialize variables
    const int TEN = 10;
    const double HALF = 0.5;
    int NUM_DIGITS = num_of_digits(n), // Get the number of digits 
                                       // by calling the function. 
        index = 0;

    // Step 1: write the n-th digit to the array
    //         e.g. 2341 becomes {2, 3, 4, 1}
    while(n){
        NUM_DIGITS--;
        int tens = int(pow(TEN, NUM_DIGITS) + HALF); // Get 10 to the power of
                                                     // number of digits -1.
                                                     // pow() function stores double,
                                                     // add 0.5 to make sure the number 
                                                     // is precise.
        digits[index] =  n / tens; // Get the digit on the left most side.
        n = n - digits[index] * tens; // Get rid of the digit on the left most side.
        index++;
    }
}

bool odd_sum_of_digits(long int n){
    // Declare and initialize variables.
    const int NUM_DIGITS = num_of_digits(n),
              DEFAULT_VALUE = 0;
    int copy_num_digits = NUM_DIGITS, index = 0, sum = 0;
    int digits[NUM_DIGITS] = { DEFAULT_VALUE }; // Initialize the array with 0s.

    // Step 1: Write the digits into the array.
    break_down_digits(digits, NUM_DIGITS, n); 
    
    // Step 2: Compute the sum of digits.
    for(int index = 0; index < NUM_DIGITS; index++){
        sum += digits[index];
    }

    // Step 3: Return true if the sum is odd;
    //         Return false if the the sum is even.
    bool even = sum % 2 == 0;
    if(even){
        return false;
    }else{
        return true;
    }
}

bool palindrome(long int n){
    // Declare and Initialize variables.
    const int NUM_DIGITS = num_of_digits(n), HALF = NUM_DIGITS/2,
              DEFAULT_VALUE = 0;
    int copy_of_num_digits = NUM_DIGITS;
    int digits[NUM_DIGITS] = { DEFAULT_VALUE }; // Initialize the array with 0s.

    // Step 1: Write the digits into the array.
    break_down_digits(digits, NUM_DIGITS, n);


    // Step 2: Compare the first digit and the last digit,
    //         Move on if they are the same, return false if they are different.
    //         Repeat the step above till the pointer reaches the middle digit.
    for(int index = 0; index < HALF; index++){
        if(digits[index] != digits[--copy_of_num_digits]){
            return false;
        }
    }
    
    return true;

}

bool prime(long int n){
    // Declare and initialize variables. 
    bool if_prime = false;
    const int LEAST_PRIME_NUM = 2;

    // Consider special case when n=2
    // because 2 is a prime number.
    if(n == LEAST_PRIME_NUM){
        return true;
    }
    // Step 1: Divide the number with all integers less than itself 
    //         to check if it has other divisors other than itself and 1.
    //         Return true if doesn't have other divisors.
    //         Return false if it has other divisor(s).
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
    // Declare and initialize variables.
    long int n = 0;
    const int LOWER_LIMIT = 1, START_NUM = 2, 
              TEN_THOUSAND = 10000, HUNDRED_THOUSAND = 100000;
    
    // Step 1: Get the integer n from the user.
    while(true){
        cout << "Please only enter integer values! The program will break if you enter a value in other data types!"
        << '\n' << "Please choose an integer that is greater than 1: " << endl;
        double value = 0;
        cin >> value;
        cin.get(); // wait till the user enters a value.
        if(value > LOWER_LIMIT){ // If it satisfies the requirement 
                                 // then store the value and exit the loop.
            n = int(value);
            break;
        }
        cout << "Please read the instruction carefully!" << endl; 
        // If the input value doesn't satisfy the requirement, 
        // ask the user to input another value.
    }

    // Step 2: Output the properties of from 1 to the given integer n.
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
            cout << '\n'; // If a special case happened, switch to next line.
        }
    }
}

int main(){
    compute_prime_numbers();
}