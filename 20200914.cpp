#include <iostream>
using namespace std;

void temp_conversion_demo(){
    double temp_f = 70;
    double temp_c = 0;

    temp_c = (temp_f - 32) *5 /9;
    cout << temp_c;
}

int main(){
    temp_conversion_demo();
}