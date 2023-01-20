#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
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

    bubblesort(arr,n);

    cout << "Elements after Bubble sort: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}