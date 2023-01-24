#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
typedef struct node node;

node * createnode(int data){
    node *p = (node *)malloc(sizeof(node)); // Creating a node pointer & allocating memory in the heap 
    p->data = data; 
    p->left = NULL;
    p->right = NULL;

    return p;
}

// int height(node *root){
//     if(root == NULL){
//         return 0;
//     }

//     int leftheight = height(root->left);
//     int rightheight = height(root->right);

//     if(leftheight > rightheight){
//         return (leftheight + 1);
//     }

//     else{
//         return (rightheight + 1);
//     }
// }

// BFS without Queue
// void printbfs(node *root,int i){ 
//     if(root == NULL)
//         return;

//     if(i == 1){
//         cout << root->data << " ";
//     }

//     else if(i > 1){
//         printbfs(root->left,i-1);
//         printbfs(root->right,i-1);
//     }
// }

// void bfs(node *root){
//     int h = height(root);
    
//     for(int i=1;i<=h;i++){
//         printbfs(root,i);
//     }
// }

// BFS with Queue
void BFS(node *root){
    
    if(root == NULL)
        return;

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if(temp->left != NULL){
            q.push(temp->left);
        }

        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

int isBalanced(node* root)
{
    if(root == NULL){
        return 0;
    }

    int lefth = isBalanced(root->left);
    if(lefth == -1){
        return -1;
    }

    int righth = isBalanced(root->right);
    if(righth == -1){
        return -1;
    }
    
    if(abs(lefth - righth) > 1){
        return -1;
    }

    else{
        return max(lefth, righth) + 1;
    }
}

void preorder(node *root){
    
    if(root != NULL){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root){
    
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void inorder(node *root){

    if(root != NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void morristraversal(node *root){
    node *temp = root,*ptr;
    if(root == NULL){
        return;
    }

    while(temp != NULL){
        if(temp->left == NULL){
            cout << temp->data << " ";
            temp = temp->right;
        }

        else{
            ptr = temp->left;
            while(ptr->right != NULL && ptr->right != temp){
                ptr = ptr->right;
            }

            if(ptr->right == NULL){
                ptr->right = temp;
                temp = temp->left;
            }

            else{
                ptr->right = NULL;
                cout << temp->data << " ";
                temp = temp->right;
            }
        }

    }
}

int depth(node *root,int x){
    if(root == NULL)
        return -1;

    int dep = -1;

    if((root->data == x) || ((dep = depth(root->left,x)) >= 0) || ((dep = depth(root->right,x)) >=0)){
        return dep + 1;
    }

    return dep;
}

// int getheight(node *root,int x,int &height){
    
//     if(root == NULL){
//         return -1;
//     }

//     int leftheight = getheight(root->left,x,height);
//     // cout << leftheight << " ";
//     int rightheight = getheight(root->right,x,height);
//     // cout << rightheight << " ";
//     int ans = max(leftheight,rightheight) + 1;

//     if(root->data == x){
//         height = ans;
//     }

//     return ans;
// }

// int findheight(node *root,int x){
//     int h = -1;
//     int maxheight = getheight(root,x,h);

//     return h;
// }

int main(){
    // Constructing the root node
    node *p;

    p = (node *)malloc(sizeof(node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // Constructing the left node
    node *p1;
    p1 = (node *)malloc(sizeof(node));
    p1->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // Constructing the right node
    node *p2;
    p2 = (node *)malloc(sizeof(node));
    p2->data = 5;
    p2->left = NULL;
    p2->right = NULL;

    // Linking of nodes
    p->left = p1;
    p->right = p2;

    node *p3 = createnode(4);
    node *p4 = createnode(6);
    node *p5 = createnode(8);

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;

    // cout << "Preorder Traversal: ";
    // preorder(p);
    // cout << endl;

    // cout << "Postorder Traversal: ";
    // postorder(p);
    // cout << endl;

    // cout << "Inorder Traversal: ";
    // inorder(p);
    // cout << endl;

    // cout << "BFS Level Order Traversal Without Queue: ";
    // bfs(p);
    // cout << endl;

    // cout << "BFS Traversal With Queue: ";
    // BFS(p);
    // cout << endl;

    // int x;
    // cout << "Enter the node to find the depth: ";
    // cin >> x;

    // cout << "Depth of the node: " << depth(p,x);
    // cout << endl;

    // cout << "Height of the node: " << findheight(p,x);
    // cout << endl;
    // cout << "Morris Traversal: ";
    // morristraversal(p);

    if(isBalanced(p) > 0){
        cout << "Balanced Binary Tree" << endl;
    }

    else{
        cout << "Not Balanced Binary Tree" << endl;
    }
    

    return 0;
}