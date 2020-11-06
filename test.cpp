#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <ctime>
using namespace std;

void function(unsigned int n){
    if(n/10 == 0){
        cout << n << endl;
    }else{
        function(n/10);
        cout << n%10 << endl;
        
    }
}

int main(){
    cout << "test";
}