#include <iostream>
using namespace std;

void f1(){
    string first_name = "qi";
    char letterT = 116-32;

    string full_name = first_name + " tian";

    cout << full_name;
}
void f2() {
    int a = ( (42-1)/2 );
    int b = ( 2*1 + (42-1-1)*1 );
    
    cout << a << endl;
    cout << b << endl;
}

void f3(){
    int entry = 0;
    int valid_count = 1;
    bool continue_loop = true;
    bool is_valid_entry = false;
    for(entry; entry <= 10000; entry+=3){
        is_valid_entry = entry % 2 == 0 || entry % 3 == 0 || entry % 11 == 0;
        if(is_valid_entry){
            cout << entry << endl;
            valid_count++;
        }
        if(valid_count > 5){
            continue_loop = false;
        }
        if(!continue_loop){
            entry+=10000;
        }
    }
}


int nthdigit(int x, int n){
    while (--n) {
        x /= 10;
    }
    return (x % 10);
}

void f3(int& a, int b){
    a = 3;
    b = 32;
    cout << a << " + " << b << endl;
}

void f4(double& v1, int v2, double& v3){
    v1 = v3 = v2;  
}
int main(){
    double v1 = 4, v2 = 8, v3 = 12;
    f4(v1, v2, v3);
    cout << v1 << " " << v2 << " " << v3 << endl;
}