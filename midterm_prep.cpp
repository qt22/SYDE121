#include <iostream>
using namespace std;

// week1_q1
void mile_to_km(double distance){
    const double RATE = 1.609347;  
    const int PRECISION = 4;
    double km = distance/RATE;
    // cout.setf(ios::fixed);
    // cout.setf(ios::showpoint);
    cout.precision(PRECISION);
    cout << "Distance in kilometers: " << km << endl;
}

// week1_q2
void polynomial(double x){

}
int main(){
    mile_to_km(3.2);
}