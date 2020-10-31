#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void f(){
    srand(time(0));
    for(int i = 0; i <= 10; i++){
        cout << rand() % 10 << endl;
    }
    cout << "...\n" << "...\n" << "...\n";
    for(int i = 0; i <= 10; i++){
        cout << rand() % 10 << endl;
    }
}
int main(){
    f();
}