/* 
    Jerry Tian
    20894361
    2020-09-18
    SYDE 121
    Assignment #1
    a1_q1.cpp
*/

/*
    This program computes the amount of weight is required for the given weight
    or the input weight. The user can decide which function to use by typing
    the function's name in int main().
*/

/*
    Program Steps:
    1. Ask the user for the weight that is used to measure.
    2. Compute the amount of weight that is required for the 125lb weight.
    3. Repeat step 2 for other weights. 
    4. Print out the number of each type of weight that is required.
*/

/*
    Test cases: 2048, 18, -34, 0, 41, 124, 29458324, 2684354560, 
    2147483647, 2147483648, 345.234
    Input range: [0, 2147483647] and input has to be an integer
*/

#include <iostream>
using namespace std;

void scale(){
    // Ask the user to enter the weight and then store the value in the variable object_weight.
    int object_weight;
    cout << "Please enter the weight of the object.\n";
    cin >> object_weight;

    int remaining_weight = object_weight;

    // The amount of weight used is stored in num_weight variables.
    int num_weight_125 = remaining_weight / 125;
    remaining_weight %= 125;
    
    int num_weight_75 = remaining_weight / 75;
    remaining_weight %= 75;

    int num_weight_42 = remaining_weight / 42;
    remaining_weight %= 42;

    int num_weight_15 = remaining_weight / 15;
    remaining_weight %= 15;

    int num_weight_1 = remaining_weight;

    // outputs
    cout << "You need to weigh by using 125lb weight " << num_weight_125 << " times.\n"
    << "Then you need to weigh by using 75lb weight " << num_weight_75 << " times.\n"
    << "Then you need to weigh by using 42lb weight " << num_weight_42 << " times.\n"
    << "Then you need to weigh by using 15lb weight " << num_weight_15 << " times.\n"
    << "At last you need to weigh by using 1lb weight " << num_weight_1 << " times.";
    
}

void scale_2048(){
    int object_weight = 2048;

    int remaining_weight = object_weight;

    // The amount of weight used is stored in num_weight variables.
    int num_weight_125 = remaining_weight / 125;
    remaining_weight %= 125;
    
    int num_weight_75 = remaining_weight / 75;
    remaining_weight %= 75;

    int num_weight_42 = remaining_weight / 42;
    remaining_weight %= 42;

    int num_weight_15 = remaining_weight / 15;
    remaining_weight %= 15;

    int num_weight_1 = remaining_weight;

    // outputs
    cout << "You need to weigh by using 125lb weight " << num_weight_125 << " times.\n"
    << "Then you need to weigh by using 75lb weight " << num_weight_75 << " times.\n"
    << "Then you need to weigh by using 42lb weight " << num_weight_42 << " times.\n"
    << "Then you need to weigh by using 15lb weight " << num_weight_15 << " times.\n"
    << "At last you need to weigh by using 1lb weight " << num_weight_1 << " times."; 
}

int main(){
    scale();
}