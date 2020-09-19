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
    char mingzi = 'q';
    switch (mingzi){
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

void test(){
    int a = 29;
    int b = 30;
    int c = a/b;
    cout << c;
}
int main(){
    function2();
}
