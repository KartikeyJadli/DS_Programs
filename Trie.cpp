#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct node{
    struct node* child[26];
    bool isword;
};
typedef struct node node;

node *createnode(){
    node *temp = new node;
    temp->isword = false;

    for(int i=0;i<26;i++){
        temp->child[i] = NULL;
    }

    return temp;
}

void insert(node *root,string str){
    node *temp = root;
    int n = str.length();
    for(int i=0;i<n;i++){
        if(!temp->child[str[i] - 'a']){
            temp->child[str[i] - 'a'] = createnode();
        }
        temp = temp->child[str[i] - 'a'];
    }

    temp->isword = true;
}

bool search(node *root,string str){
    node *temp = root;
    for(int i=0;i<str.length();i++){
        if(!temp->child[str[i] - 'a']){
            return false;
        }   

        temp = temp->child[str[i] - 'a'];
    }

    return temp->isword;
}

int main(){
    node *root = createnode();
    string str;
    vector<string> v;
    int n;
    cout << "Enter Number of strings: ";
    cin >> n;

    cout << "Enter the strings: ";
    for(int i=0;i<n;i++){
        cin >> str;
        v.push_back(str);
    }

    for(int i=0;i<n;i++){
        insert(root,v[i]);
    }

    cout << "Enter the string to search: ";
    cin >> str;
    search(root,str) ? cout << str << " Present" : cout << str << " Not Present";

    return 0;
}