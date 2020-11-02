#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <ctime>
using namespace std;

int f(int n){
    return n*f(n-1);
}
int main(){
    string wife("Zelda");
    string husband("Link");
    wife.insert(3, husband + " loves ");
    cout << wife;
    
}