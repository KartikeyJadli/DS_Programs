#include<iostream>
#include<cmath>
using namespace std;

int jumpsearch(int *arr,int high,int target){
    int low = 0;

    int end = sqrt(high);

    while(arr[end] <= target && end < high){
        low = end;
        end = end + sqrt(high);

        if(end > high - 1){
            end = high;
        }
    }

    for(int i=low;i<end;i++){
        if(arr[i] == target){
            return i;
        }
    }

    return -1;
}

int main(){
    int n,target;

    cout << "Enter the no. of elements: ";
    cin >> n;
    int X[n];

    cout << "Enter the array elements (Sorted Order): ";
    for(int i=0;i<n;i++){
        cin >> X[i];
    }

    cout << "Enter element for search: ";
    cin >> target;

    int temp = jumpsearch(X,n,target);

    if(temp == -1){
        cout << "Element not in the array!!!!";
        return 0;
    }

    cout << "Element " << target << " present at index " << temp;

    return 0;
}