#include<iostream>
using namespace std;

void insertionsort(int *arr,int n){
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j = i - 1;

        while(temp < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }

    cout << endl;
}

int main(){
    int n;
    cout << "Enter the no. of elements in array: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "\n";
    cout << "Elements before sorting: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    insertionsort(arr,n);

    cout << "Elements after Insertion sort: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}