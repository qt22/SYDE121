#include <iostream>
#include <fstream>
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
    ifstream in;
    ofstream out;

    in.open("./input.txt"); // file location !!!
    out.open("./output.txt"); // file location !!!

    int a = 0;
    if(in.good() && out.good()){
        in >> a;
        out << a;

        in.close();
        out.close();
    }

}