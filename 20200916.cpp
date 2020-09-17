#include <iostream> 

using namespace std;

void function1(){
    // declare and initialize variables
    int in1 = 42;

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
    function2();
}
