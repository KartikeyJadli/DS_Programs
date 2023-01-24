#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

node * createnode(int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

void insert(node *root,int key){
    node *prev = NULL;
    // Searching for the right position for insertion
    while(root != NULL){
        prev = root;
        if(root->data == key){
            cout << "Cannot insert " << key << " already in the BST";
            return;
        }

        else if(root->data < key){
            root = root->right;
        }

        else{
            root = root->left;
        }
    }

    // Linking and inserting the node
    node *ptr = createnode(key);
    if(key < prev->data){
        prev->left = ptr;
    }

    else{
        prev->right = ptr;
    }
}

node * inorderpredecessor(node *root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }

    return root;
}

node * deletenode(node *root,int key){
    node *ipre;
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    // Search for the node
    if(key < root->data){
        root->left = deletenode(root->left,key);
    }

    else if(key > root->data){
        root->right = deletenode(root->right,key);
    }

    // Deletion when node is found
    else{
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left,ipre->data);
    }

    return root;
}

void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
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

int isBST(node *root){
    static node *prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }

        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }

    else{
        return 1;
    }
}

// Recursive Search
node * search(node *root,int key){
    if(root == NULL){
        return NULL;
    }

    if(root != NULL){
        if(root->data == key){
            return root;
        }

        else if(root->data < key){
            return search(root->right,key);
        }

        else{
            return search(root->left,key);
        }
    }
}

// Iterative Search
node * itsearch(node *root,int key){
    
    while(root != NULL){
        if(key == root->data){
            return root;
        }

        else if(key < root->data){
            root = root->left;
        }

        else{
            root = root->right;
        }
    }

    return NULL;
}

int main(){
    node *root,*p,*p1,*p2,*p3,*p4,*p5,*p6,*p7;
    root = createnode(8);
    p = createnode(3);
    p1 = createnode(10);
    p2 = createnode(1);
    p3 = createnode(6);
    p4 = createnode(4);
    p5 = createnode(7);
    p6 = createnode(14);
    p7 = createnode(13);

    root->left = p;
    root->right = p1;

    p->left = p2;
    p->right = p3;

    p3->left = p4;
    p3->right = p5;

    p1->right = p6;
    // p5->right = p6;
    // p5->left = NULL;

    p6->left = p7;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    // cout << "Pre-Order Traversal: ";
    // preorder(root);
    // cout << endl;
    // cout << "Postorder Traversal: ";
    // postorder(root);
    
    // if(isBST(root)){
    //     cout << "The tree is a BST" << endl;
    // }

    // else if(!isBST(root)){
    //     cout << "The tree is not BST" << endl;
    // }

    // node * s = search(root,47);
    // if(s != NULL){
    //     cout << "Key is Found: " << s->data;
    // }

    // else{
    //     cout << "Key is not present";
    // }

    // if(itsearch(root,10)){
    //     cout << "Element Found" << endl;
    // }

    // else{
    //     cout << "Element not Found";
    // }

    // insert(root,11);
    // cout << root->right->right->left->left->data;

    cout << endl;
    deletenode(root,6);
    cout << "After Deletion: ";
    inorder(root);
    cout << endl;
    cout << root->left->right->data;

    return 0;
}