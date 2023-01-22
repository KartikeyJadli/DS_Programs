#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr,int low,int high){
    int pivot = arr[high];

    int i = low - 1;

    for(int j=low;j<high;j++){
        if(arr[j] <= pivot){
            i++;

            swap(&arr[j],&arr[i]);
        }
    }

    swap(&arr[i+1],&arr[high]);

    return (i + 1);
}

void quicksort(int *arr,int low,int high){
    if(low < high){
        int p = partition(arr,low,high);

        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
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

    quicksort(arr,0,n-1);

    cout << "Elements after Quick sort: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}