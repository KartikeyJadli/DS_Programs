#include<iostream>
using namespace std;

void merge(int *arr,int low,int mid,int high){
    int i,j,k,arr2[100];
    i = low;
    k = low;
    j = mid + 1;

    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            arr2[k] = arr[i];
            k++;
            i++;
        }

        else{
            arr2[k] = arr[j];
            k++;
            j++;
        }
    }

    while(i <= mid){
        arr2[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high){
        arr2[k] = arr[j];
        j++;
        k++;
    }

    for(i=low;i<k;i++){
        arr[i] = arr2[i];
    }
}

void mergesort(int *arr,int low,int high){
    if(low < high){
        int mid = low + (high - low)/2;

        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
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

    mergesort(arr,0,n-1);
    cout << endl;

    cout << "Elements after Merge sort: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}