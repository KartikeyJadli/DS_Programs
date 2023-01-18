#include<iostream>
using namespace std;

int binarysearch(int *arr,int low,int high,int target){
    int mid = 0;

    while(low < high){
        mid = (low + high)/2;

        if(arr[mid] == target){
            return mid;
        }

        else if(arr[mid] < target){
            return binarysearch(arr,mid+1,high,target);
        }

        else{
            return binarysearch(arr,low,mid-1,target);
        }
    }

    return -1;
}

int main(){
    int n;
    cout << "Enter Size of Array: ";
    cin >> n;
    int X[n];

    cout << "Enter Elements in Array(Sorted Order): ";
    for(int i=0;i<n;i++){
        cin >> X[i]; 
    }

    int a,b;
    cout << "Enter the elements to find in each array: ";
    cin >> a;
    int temp1 = binarysearch(X,0,n-1,a);

    if(temp1 == -1){
        cout << "Element not present in array!!";
        return 0;
    }

    cout << "Element " << a << " found at position: " << temp1;

    return 0;
}