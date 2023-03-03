/*  Square root of a number
    Time Complexity: O(log(N))
    Space Complexity: O(1)
*/ 

#include<iostream>
using namespace std;

int squareroot(int num){
    int low = 1,high = num;
    int sq = 0,mid = 0;

    while(low <= high){
        mid = (low + high)/2;

        int s = mid * mid;

        if(s == num){
            cout << "The square root of " << num << "is: " << mid << endl;
            break;
        }

        else if(s < num){
            sq = mid;
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
    }

    return sq;
}

int main(){
    int num;
    cout << "Enter the number: ";
    cin >> num;

    int sq = squareroot(num);
    cout << "The square root of " << num << " is: " << sq << endl;

    return 0;
}