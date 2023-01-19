#include<iostream>
#include<cmath>
using namespace std;

/* In Jump search we take the Square root of the no. of elements and then jump through the array with those steps like if we have an array of length 16 then the 
jump size is sqrt(16) ,i.e., 4 so now we jump in the array with jumpsize = 4. After this we check whether the element at the jumped point is greater than our target
element or not, if the element is less than our target element then we move further in the array. But when we come to a point where the element at the current position
is greater than the target element, we jump backwards ,i.e., if we were at 12th position and the element was greater than our target so we move back to 8th position and
do a linear search from 8th index. */

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
