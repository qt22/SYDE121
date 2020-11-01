#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void f(){
    srand(1);
    for(int i = 0; i <= 10; i++){
        cout << rand() << endl;
    }
}
int main(){
    f();
}