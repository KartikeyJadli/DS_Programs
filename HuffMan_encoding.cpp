#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Min heap for huffman encoding
struct Node{
    char data;
    int freq;
    Node *left,*right;

    Node(char x,int y):
    data(x),freq(y),left(NULL),right(NULL){}
};
// typedef struct Node node;

struct compare{
    bool operator()(Node* l,Node* r){
        return (l->freq > r->freq);
    }
};

void display(Node* root,string str){
    if (root == NULL)
        return;
 
    if (root->data != '#')
        cout << root->data << ": " << str << "\n";
 
    display(root->left, str + "0");
    display(root->right, str + "1");
}

void huffmancode(vector<char> &data,vector<int> &fre,int n){
    priority_queue<Node*,vector<Node*>,compare> pq;
    for(int i=0;i<n;i++){
        Node *temp = new Node(data[i],fre[i]);
        pq.push(temp);
    }

    while(pq.size() != 1){
        Node *left1 = pq.top();
        pq.pop();

        Node *right1 = pq.top();
        pq.pop();
        Node *ptr = new Node('#',left1->freq + right1->freq);
        ptr->left = left1;
        ptr->right = right1;

        pq.push(ptr);
    }

    display(pq.top(),"");
}

int main(){ 
    int n;
    cout << "Enter number of characters: ";
    cin >> n; 
    vector<char> data(n);
    vector<int> fre(n);

    cout << "Enter Data: ";
    for(auto &x: data){
        cin >> x;
    }

    cout << "Enter frequency: ";
    for(auto &x: fre){
        cin >> x;
    }

    huffmancode(data,fre,n);

    return 0;
}