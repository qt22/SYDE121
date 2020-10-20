#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>
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

// week2_q2
void find_zodiac_sign(int month, int day){
    const int TOTAL_MONTHS = 12;
    bool Aquarius = (month==1 && day>=20) || (month==2 && day<=18),
        Pisces = (month==2 && day >= 19) || (month==3 && day<=20),
        Aries = (month==3 && day >= 20) || (month==4 && day<=19),
        Taurus = (month==4 && day >= 20) || (month==5 && day<=20),
        Gemini = (month==5 && day >= 21) || (month==6 && day<=20),
        Cancer = (month==6 && day >= 21) || (month==7 && day<=22),
        Ieo = (month==7 && day >= 23) || (month==8 && day<=22),
        Virgo = (month==8 && day >= 23) || (month==9 && day<=22),
        Libra = (month==9 && day >= 23) || (month==10 && day<=22),
        Scorpio = (month==10 && day >= 23) || (month==11 && day<=21),
        Sagittarius = (month==11 && day >= 22) || (month==11 && day<=21),
        Capricorn = (month==12 && day >= 22) || (month==1 && day<=19);
    
    if(Aquarius)
        cout << "Your Zodiac sign is: " << "Aquarius" << endl;
    if(Pisces)
        cout << "Your Zodiac sign is: " << "Pisces" << endl;
    if(Aries)
        cout << "Your Zodiac sign is: " << "Aries" << endl;
    if(Taurus)
        cout << "Your Zodiac sign is: " << "Taurus" << endl;
    if(Gemini)
        cout << "Your Zodiac sign is: " << "Gemini" << endl;
    if(Cancer)
        cout << "Your Zodiac sign is: " << "Cancer" << endl;
    if(Ieo)
        cout << "Your Zodiac sign is: " << "Ieo" << endl;
    if(Virgo)
        cout << "Your Zodiac sign is: " << "Virgo" << endl;
    if(Libra)
        cout << "Your Zodiac sign is: " << "Libra" << endl;
    if(Scorpio)
        cout << "Your Zodiac sign is: " << "Scorpio" << endl;
    if(Sagittarius)
        cout << "Your Zodiac sign is: " << "Sagittarius" << endl;
    if(Capricorn)
        cout << "Your Zodiac sign is: " << "Capricorn" << endl;
}

// week3_q1: compute approximate value of the Pi (π) constant
void pi(int n){
    double pi = 0;
    for(int index = 0; index <= n; index++){
        double numerator = pow(-1, index);
        double denominator = 2*index + 1;
        pi += numerator/denominator;
    }
    pi *= 4;
    cout << "The PI value you want is: " << pi << endl;
}

// week3_q2
void hypotenuse(){
    double side1, side2;
    cout << "Please enter the side length of side 1." << endl;
    cin >> side1;
    cout << "Please enter the side length of side 2." << endl;
    cin >> side2;

    double hypo = sqrt(side1 * side1 + side2 * side2);
    cout << "The hypotenuse of the triangle is " << hypo << endl;
}

// week5_q1
void mark_data(){
    int num, 
    sum = 0 , min = 100, max = 1,
    first_mark;

    cout << "Enter the total amount of students " << endl;
    cin >> num;

    vector<int> marks(0);
    srand(time(0));

    // first_mark = rand() % 100 + 1;
    // marks.push_back(first_mark);

    for(int index = 0; index < num; index++){
        int mark = rand() % 100 + 1;
        marks.push_back(mark);
        sum += mark;

        if(marks.at(index) < min){
            min = marks.at(index);
        }
        if(marks.at(index) > max){
            max = marks.at(index);
        }
        cout << marks.at(index) << endl;
    }
    
    
    double mean = sum*1.0 / num;
    double standard_dev = 0;
    for(int index = 0; index < num; index++){
        standard_dev += (marks.at(index) - mean) * (marks.at(index) - mean);
    }
    standard_dev = sqrt(standard_dev / mean);

    cout << "The mean mark is " << mean << '\n'
        << "The maximum mark is " << max << '\n'
        << "The minimum mark is " << min << '\n'
        << "The standard deviation is " << standard_dev << endl;

}
int main(){
    mark_data();
}