#include <iostream>
using namespace std;

// Part A:
// Output:
// 0&4
// Explanation: 
// The given array is a two-dimension array. 
// It has 4 arrays with 3 elements in each array.
// test_array[3][1] accesses the 2nd element in the 4th array.
// However, the 4th array was not assigned an value therefore it is 0.
// test_array[0][2] accesses the 3rd element in the 1st array, which is 4.
//
//
//
// Part B:
// Output:
// 11211
// Explanation:
// The sneaky function calls b by value passing but calls a and c by reference.
// That means the value of b stays the same but the value of a and c are going to change.
// When the code x = --y = z += 4; is first execeuted, 
// the value of y decreases by 1 and the value of z is increased by 4.
// We know that a is y and c is z, so a becomes 4 and z becomes 11 now, b stays at 2.
// Then the value of y is assigned to the value of z which is 11,
// this changes the value of a to 11.
// The value of x is also eleven but we call the variable b by value passing so b doesn't change.
// Therefore, the output is 11211.
//
//
//
// Part C: 
void starwars(){
    int darth_vader = 6, darth_maul = 5, darth_sidious = 7;
    int anakin = 6, leia = 7, luke = 7, yoda = 8;
    bool dark_syde_is_strong = darth_sidious + darth_maul > yoda || darth_vader + darth_sidious > luke;
    bool light_syde_is_stronger = darth_sidious + darth_maul < yoda + anakin
                                 && darth_vader + darth_sidious < luke + leia;

    if(dark_syde_is_strong){
        if(light_syde_is_stronger)
            cout << "Jedi win!" << endl;
        else
            cout << "Sith win!" << endl;
    }
}
int main(){
    starwars();
}
//
//
//
// Part D:
// Output: 
// 75
// Explanation:
// The for loop doesn't have a restriction so the loop behaves like a while loop.
// The in1 value increases as shown below:
// 23 (less than 70, continue), 33 (go back to the beginning of the loop), 
// 36 (less than 70, continue), 46 (go back to the beginning of the loop),
// 49 (less than 70, continue), 59 (go back to the beginning of the loop),
// 62 (less than 70, continue), 72 (go back to the beginning of the loop),
// 75 (greater than 70, break!)