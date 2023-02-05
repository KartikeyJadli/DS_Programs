#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;

// This Class will contain all the frequently asked sorting techniques without the use of STL
class Sort{
    public:
    // Bubble Sort
    void bubblesort(int *arr,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }

        cout << endl;
    }

    // Insertion Sort
    void insertionsort(int *arr,int n){
        for(int i=0;i<n;i++){
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

    // Selection Sort
    void selectionsort(int *arr,int n){
        for(int i=0;i<n;i++){
            int min = i;
            for(int j=i+1;j<n;j++){
                if(arr[j] < arr[min]){
                    min = j;
                }
            }

            swap(arr[i],arr[min]);
        }

        cout << endl;
    }

    // QuickSort
    int partition(int *arr,int low,int high){
        int pivot = arr[high];

        int i = low - 1;

        for(int j=low;j<high;j++){
            if(arr[j] <= pivot){
                i++;

                swap(arr[j],arr[i]);
            }
        }

        swap(arr[i+1],arr[high]);

        return (i + 1);
    }

    void quicksort(int *arr,int low,int high){
        if(low < high){
            int p = partition(arr,low,high);

            quicksort(arr,low,p-1);
            quicksort(arr,p+1,high);
        }
    }

    // Randomized Quick Sort
    int rpartition(int *arr,int low,int high){
        srand(time(NULL));
        int r = low + rand() % (high - low);

        swap(arr[r],arr[high]);

        return partition(arr,low,high);
    }

    void rquicksort(int *arr,int low,int high){
        if(low < high){
            int p = rpartition(arr,low,high);

            rquicksort(arr,low,p-1);
            rquicksort(arr,p+1,high);
        }
    }

    // Heap Sort
    void heapify(int *arr,int n,int i){
        int c1 = 2*i + 1,c2 = 2*i + 2;

        int max = i;
        if(c1 < n && arr[c1] > arr[max]){
            max = c1;
        }

        if(c2 < n && arr[c2] > arr[max]){
            max = c2;
        }

        if(max != i){
            swap(arr[i],arr[max]);
            heapify(arr,n,max);
        }
    }

    void heapsort(int *arr,int n){
        for(int i=(n/2) - 1;i>=0;i--){
            heapify(arr,n,i);
        }

        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }

    // Merge Sort
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

    void display(int *arr,int n){
        for(int i=0;i<n;i++){
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main(){
    Sort sort;
    int choice = 0,n;
    cout << "Enter the size of array: ";
    cin >> n;
    int v[n];

    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    do{
        cout << "-----------Sorting Techniques-----------" << endl;
        cout << "1. Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n4.Quick Sort\n5.Randomized Quick Sort\n";
        cout << "6. Heap Sort\n7. Merge Sort\n8. Exit\n";
        cout << "Enter the choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            sort.bubblesort(v,n);
            break;

            case 2:
            sort.insertionsort(v,n);
            break;

            case 3:
            sort.selectionsort(v,n);
            break;

            case 4:
            sort.quicksort(v,0,n-1);
            break;

            case 5:
            sort.rquicksort(v,0,n-1);
            break;

            case 6:
            sort.heapsort(v,n);
            break;

            case 7:
            sort.mergesort(v,0,n-1);
            break;

            case 8:
            exit;
        }
    }while(choice != 8);

    sort.display(v,n);

    cout << "Execution Completed!!!!" << endl;
    return 0;
}
