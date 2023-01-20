#include<iostream> 
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        swap(&arr[i],&arr[min]);
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

    selectionsort(arr,n);

    cout << "Elements after Selection sort: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}