#include<iostream>
#include<stdlib.h>
using namespace std;

class DFS{
    public:
    void T(int *visited,int arr[][100],int i,int n){
        cout << i << " ";
        visited[i] = 1;

        for(int j=0;j<n;j++){
            if(arr[i][j] == 1 && !visited[j]){
                T(visited,arr,j,n);
            }
        }
    }
};

int main(){
    int n,i;
    cout << "Enter no. of nodes in Graph: ";
    cin >> n;
    int visited[100],arr[100][100];
    cout << "Enter the Adjacency Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }

        visited[i] = 0;
    } 

    cout << "Enter the starting node: ";
    cin >> i;
    
    DFS ob;

    ob.T(visited,arr,i,n);

    return 0;
}