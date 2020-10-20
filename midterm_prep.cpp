#include <iostream>
using namespace std;

// week1_q1
void mile_to_km(double distance){
    const double RATE = 1.609347;  
    const int PRECISION = 4;
    double km = distance/RATE;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(PRECISION);
    cout << "Distance in kilometers: " << km << endl;
}

// week1_q2
void polynomial(double x){
    double p = x*x*x + 24*x*x + 12*x + 44;
    cout << p << endl;
}
int main(){
    polynomial(3);
}