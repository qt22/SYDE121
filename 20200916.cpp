#include <iostream> 
#include <cassert>

using namespace std;
 int in1;

void function1(){
    // declare and initialize variables
    in1 = 1;

    // perform computation and output value
    if(in1 > 42){
        cout << 21;
    }
    else if(in1 < 75){
        cout << 31;
    }
    else{
        cout << 41;
    }
    assert(2 > 32);
}

void function2(){
    char name = 't';

    switch (name){
        case 'q':
            cout << "qi";
        case 'j':
            cout << "jerry";
        case 't':
            cout << "tian";
        default:
            cout << "Tian Qi";
    }

}
int main(){
    function1();
}
