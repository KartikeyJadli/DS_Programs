#include<iostream> 
using namespace std;

struct queue{
    int size;
    int front,rear;
    int *arr;
};
typedef struct queue Q;

class Queue{
    public:
    void push(Q *q,int data){
        q->rear++;
        q->arr[q->rear] = data;
    }

    int pop(Q *q){
        q->front++;
        int temp = q->arr[q->front];

        return temp;
    }

    int isempty(Q *q){
        if(q->rear == q->front){
            return 1;
        }

        return 0;
    }
};

class BFS{
    public:
    void BFSTraversal(int *visited,int ar[][100],int i,int n){
        visited[i] = 1;
        Queue que;

        struct queue q;
        q.size = n;
        q.front = q.rear = 0;

        q.arr = (int *)malloc(sizeof(int));

        que.push(&q,i);
        cout << i << " ";
        while(!que.isempty(&q)){
            int node = que.pop(&q);
            for(int j=0;j<n;j++){
                if(ar[node][j] == 1 && visited[j] == 0){
                    cout << j << " ";
                    visited[j] = 1;
                    que.push(&q,j);
                }
            }
        }
    }
};

int main(){
    int n,start;
    cout << "Enter the no. of nodes in Graph: ";
    cin >> n;
    int visited[100],arr[100][100];

    cout << "Enter the adjacency matrix: \n";
    for(int i=0;i<n;i++){
        visited[i] = 0;
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    cout << "Enter the starting node: ";
    cin >> start;

    BFS bfs;
    bfs.BFSTraversal(visited,arr,start,n);

    return 0;
}