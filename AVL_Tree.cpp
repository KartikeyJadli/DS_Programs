// AVL Tree
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
typedef struct node node;

int max(int a,int b){
    return (a>b)?a:b;
}

int getheight(node *n){

    if(n == NULL){
        return 0;
    }

    return n->height;
}

node * createnode(int key){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = key;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->height = 1;

    return ptr;
}

int getBalancedfactor(node *n){
    if(n == NULL){
        return 0;
    }

    return getheight(n->left) - getheight(n->right);
}

node *rightrotate(node *y){
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getheight(x->right),getheight(x->left)) + 1;
    y->height = max(getheight(y->right),getheight(y->left)) + 1;

    return x;
}

node *leftrotate(node *x){
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getheight(x->right),getheight(x->left)) + 1;
    y->height = max(getheight(y->right),getheight(y->left)) + 1;

    return y;
}

node *insert(node *root,int key){
    if(root == NULL){
        return createnode(key);
    }

    if(key < root->data){
        root->left = insert(root->left,key);
    }

    else if(key > root->data){
        root->right = insert(root->right,key);
    }

    root->height = 1 + max(getheight(root->left),getheight(root->right));
    int balancefactor = getBalancedfactor(root);

    // left-left case
    if(balancefactor > 1 && key < root->left->data){
        return rightrotate(root);
    }

    // right-right case
    if(balancefactor < -1 && key > root->right->data){
        return leftrotate(root);
    }

    // left-right case
    if(balancefactor > 1 && key > root->left->data){
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    // right-left case
    if(balancefactor < -1 && key < root->right->data){
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

void preorder(node *root){
    if(root != NULL){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    node *root = NULL;
    // Tree was balanced
    root = insert(root,7);
    root = insert(root,1);
    root = insert(root,10);
    root = insert(root,17);
    // Tree imbalanced
    root = insert(root,16);
    // root = insert(root,3);

    preorder(root);
    return 0;
}