#include <iostream>
using namespace std;

// Compute the max, min and mean value of the given double values
void values(){
    int amount_of_values;
    double max = 0.0, min = 0.0, sum = 0.0, mean = 0.0;
    while(true){
        cout << "Please enter the amount of double values you will enter." << endl;
        cin >> amount_of_values;
        if(amount_of_values > 0){
            break;
        }
        cout << "Please read the instruction carefully!" << endl;
    }
    
    for (unsigned int i = 0; i < amount_of_values; i++){
        double value;
        cout << "Enter a double value." << endl;
        cin >> value;

        if(value < min){
            min = value;
        }
        if(value > max){
            max = value;
        }
        sum += value;
    }
    
    mean = sum / amount_of_values;

    cout << "The maximum value is " << max << '\n'
        << "The minimum value is " << min << '\n'
        << "The average value is " << mean << endl;
        
    
}


int main(){
    values();
}