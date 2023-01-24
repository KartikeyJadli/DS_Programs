#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node *insertatfirst(node *head,int data){
    node *ptr = (node *)malloc(sizeof(node));
    node *temp = head->next;
    ptr->data = data;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}

node *deleteatfirst(node *head){
    node *ptr = head;
    node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    free(ptr);
    
    return head;
}

node *insertinbet(node *head,int data,int in){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    node *temp = head;
    int i = 0;
    while(i != in-1){
        temp = temp->next;
        i++;
    }

    ptr->next = temp->next;
    temp->next = ptr;
    
    return head;
}

node *deleteinbet(node *head,int n){
    node *ptr = head;
    int i = 0;
    while(i != n-1){
        ptr = ptr->next;
        i++;
    }

    node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    return head;
}

node * insertatend(node *head,int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;

    node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = head;

    return head;
}

node * deleteatend(node *head){
    node *ptr = head,*temp;
    while(ptr->next->next != head){
        ptr = ptr->next;
    }

    temp = ptr->next;
    ptr->next = head;
    free(temp);

    return head;
}

void display(node *head){
    node *ptr = head;
    do{
        cout << "Elements are: " << ptr->data << endl;
        ptr = ptr->next;
    }while(ptr != head);
    cout << endl;
}

int main(){
    node *head;
    node *a,*ptr,*temp;

    // In Heap
    head = (node *)malloc(sizeof(node));
    ptr = (node *)malloc(sizeof(node));
    temp = (node *)malloc(sizeof(node));
    a = (node *)malloc(sizeof(node));

    head->data = 4;
    head->next = ptr;

    ptr->data = 3;
    ptr->next = temp;

    temp->data = 6;
    temp->next = a;

    a->data = 1;
    a->next = head;

    display(head);

    // head = insertatfirst(head,5);
    // display(head);

    head = deleteatfirst(head);
    // head = insertinbet(head,76,11);
    // head = deleteinbet(head,2);
    // head = insertatend(head,89);
    display(head);

    // head = deleteatend(head);
    // display(head);

    return 0;
}