/* 
    Jerry Tian
    20894361
    2020-09-25
    SYDE 121
    Assignment #1
    a1_q2.cpp
*/

/*
    This program has four functions. 
    The first function computes the sum from 1 to 500.
    The second function computes the sum from 5 to 2020.
    The third function computes the sum from 42 to 32000.
    The fourth function asks the user to enter the first number,
    the last number and the difference to calculate the sum.
*/

/*
    Program Steps: 
    Step 1: declare and initialize 
        int LAST_NUMBER, the last number in the sequence;
        int FIRST_NUMBER, the first number in the sequence;
        int DIFFERENCE, the difference between each number;
        int sum, the summation of all the numbers.
    Step 2:
        calculate the sum using the formula: sum = (LAST_NUMBER/2)*(2*FIRST_NUMBER + (LAST_NUMBER-1)*DIFFERENCE)
    Step 3: 
        output the sum.

*/

/*
    Test values:
    First number: 1, last number: 500, difference: 1;
    First number: 5, last number: 2020, difference: 1;
    First number: 42, last number: 32000, difference: 1;
    First number: 2, last number: 10, difference: 2;
    First number: -20, last number: -2, difference: 2;
    First number: 50, last number: 100, difference: 1;
    First number: -1, last number: 8, difference: 3; => DOESN'T WORK!!!
    First number: -3, last number: 21, difference: 3; => DOESN'T WORK!!!
    First number: 1, last number: 10, difference: 3; => DOESN't WORK!!!
    First number: 1, last number: 1000000000, difference: 1; => sum becomes the lowest integer
    First number: 1, last number: 65535, difference: 1;
    First number: 1, last number: 65536, difference: 1;  => sum becomes the lowest integer

    Restrictions: 
    The first number and the last number have to have the same sign.(both positive or both negative)
    There has to be a number n such that a_n = 0. (The sequence must have a term equal to 0)  
    The sum cannot be greater than 2147483647 or less than -2147483648
*/

#include <iostream>
using namespace std;

void one_to_500(){
    int LAST_NUMBER = 500;
    int FIRST_NUMBER = 1;
    int DIFFERENCE = 1;
    int sum = 0;

    sum = (LAST_NUMBER/2)*(2*FIRST_NUMBER + (LAST_NUMBER - 1)*DIFFERENCE);
    cout << sum << endl;
}

void five_to_2020(){
    int LAST_NUMBER = 2020;
    int FIRST_NUMBER = 5;
    int DIFFERENCE = 1;
    int sum_first_element_to_end = 0;
    int sum_first_element_to_first_number= 0;
    int sum = 0;

    // substract the sum of 1 to 4 from the sum of 1 to 2020 to get the sum from 5 to 2020.
    sum_first_element_to_end = (LAST_NUMBER/2)*(2*1 + (LAST_NUMBER - 1)*DIFFERENCE);
    // FIRST_NUMBER-1 is 5-1 which is 4
    sum_first_element_to_first_number = ( (FIRST_NUMBER - 1)/2 )*( 2*1 + (FIRST_NUMBER - 1 - 1)*DIFFERENCE );
    sum = sum_first_element_to_end - sum_first_element_to_first_number;
    
    cout << sum << endl;
}

void fourtytwo_to_32000(){
    int LAST_NUMBER = 32000;
    int FIRST_NUMBER = 42;
    int DIFFERENCE = 1;
    int sum_first_element_to_end = 0;
    int sum_first_element_to_first_number= 0;
    int sum = 0;

    // substract the sum of 1 to 41 from the sum of 1 to 32000 to get the sum from 42 to 32000.
    sum_first_element_to_end = ( LAST_NUMBER/2 )*( 2*1 + (LAST_NUMBER - 1)*DIFFERENCE );
    

    // (42-1)/2 is a fraction. The computer automatically rounds it off.
    // I use a double variable here to represent the first number to avoid rounding.
    double first_number = FIRST_NUMBER;
    // FIRST_NUMBER-1 is 42-1 which is 41
    sum_first_element_to_first_number = ( (first_number - 1)/2 * (2*1 + (FIRST_NUMBER - 1 - 1)*DIFFERENCE) );
    sum = sum_first_element_to_end - sum_first_element_to_first_number;
    
    cout << sum << endl;
}

void summation(){
    // DIFFERENCE also means the next element in the sequence after 0.
    // It is always a positive number.
    int FIRST_NUMBER, LAST_NUMBER, DIFFERENCE;
    int sum_first_element_to_end, sum_first_element_to_first_number, sum;

    cout << "Enter the first number in the sequence.\n";
    cin >> FIRST_NUMBER;
    cout << "Enter the last number in the sequence.\n";
    cin >> LAST_NUMBER;
    cout << "Enter the difference between numbers.\n";
    cin >> DIFFERENCE;

    // The number of elements from DIFFERENCE to LAST_NUMBER
    double NUM_ELEMENTS_1 = (LAST_NUMBER - DIFFERENCE)/DIFFERENCE + 1;
    // The number of elements from DIFFERENCE to FIRST_NUMBER
    double NUM_ELEMENTS_2 = (FIRST_NUMBER - DIFFERENCE - DIFFERENCE)/DIFFERENCE + 1;

    sum_first_element_to_end = ( NUM_ELEMENTS_1/2 )*( 2*DIFFERENCE + (NUM_ELEMENTS_1 - 1)*DIFFERENCE );
    sum_first_element_to_first_number = ( (NUM_ELEMENTS_2)/2 * (2*DIFFERENCE + (NUM_ELEMENTS_2 - 1)*DIFFERENCE) );
    sum = sum_first_element_to_end - sum_first_element_to_first_number;

    cout << "The summation from " << FIRST_NUMBER << " to " << LAST_NUMBER << " is " << sum << "." << endl;
}

int main(){
    summation();
}