#include <iostream>
#include <vector>
using namespace std;

bool isMonotonic(vector<int>& A) {
        bool prev = true;
        int direction = 1; 
        // 1 means same value, 2 means increasing, 3 means decreasing.
        
        if(A.size() <= 2){
            return true;
        }
        
        if(A.at(0) < A.at(1)){
            direction = 2;
        }
        else if(A.at(0) > A.at(1)){
            direction = 3;
        }
        
        for(unsigned int i = 1; i < A.size()-1; i++){
            if(A.at(i) < A.at(i+1) && direction == 3){
                return false;
            }
            if(A.at(i) > A.at(i+1) && direction == 2){
                return false;
            }
            
            if(direction == 1 && (A.at(i) < A.at(i+1))){
                direction = 2;
            }else if(direction == 1 && (A.at(i) > A.at(i+1))){
                direction = 3;
            }
        }
        
        return true;
}

int main(){
    vector<int> numbers = {1, 2, 3, 5, 5, 5, 2};
    cout << isMonotonic(numbers);
}