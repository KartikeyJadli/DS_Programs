#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};
typedef struct node TreeNode;

class Tree{
    public:
    TreeNode *createnode(int data){
        TreeNode *ptr = (TreeNode *)malloc(sizeof(TreeNode));
        ptr->data = data;
        ptr->left = NULL;
        ptr->right = NULL;

        return ptr;
    }
};

class DFS{
    public:
    void preorder(TreeNode *root){
        if(root != NULL){
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(TreeNode *root){
        if(root != NULL){
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void postorder(TreeNode *root){
        if(root != NULL){
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
};


int main(){
    int n;
    Tree ob;
    DFS obj;
    TreeNode *root,*p1,*p2,*p3,*p4,*p5,*p6;
    root = ob.createnode(7);
    p1 = ob.createnode(6);
    p2 = ob.createnode(3);
    p3 = ob.createnode(1);
    p4 = ob.createnode(2);
    p5 = ob.createnode(9);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    /* A Representation of the Binary Tree

                 7
                / \
               6   3
              / \   \ 
             1   2   9
    
    */
    cout << "The Following are the 3 DFS Traversals in a Binary Tree or Tree" << endl;
    cout << "1. Preorder Traversal -> ";
    obj.preorder(root);
    cout << endl;
    cout << "2. Inorder Traversal -> ";
    obj.inorder(root);
    cout << endl;
    cout << "3. Postorder Traversal -> ";
    obj.postorder(root);

    return 0;
}