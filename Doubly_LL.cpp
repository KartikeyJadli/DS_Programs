#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node node;

node * insertatfirst(node *head,int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;

    ptr->next = head;
    ptr->prev = NULL;
    head->prev = ptr;
    head = ptr;

    return head;
}

node * deleteatfirst(node *head){
    node *ptr = head;

    head = head->next;
    head->prev = NULL;
    free(ptr);

    return head;
}

node * insertinbet(node *head,int data,int n){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;

    node *temp = head;
    int i = 0;
    while(i != n-1){
        temp = temp->next;
        i++;
    }

    temp->next->prev = ptr;
    ptr->next = temp->next;
    temp->next = ptr;
    ptr->prev = temp;

    return head;
}

node * deleteinbet(node *head,int n){
    node *temp = head;
    int i = 0;
    while(i != n-1){
        temp = temp->next;
        i++;
    }

    node *ptr = temp->next;
    temp->next = ptr->next;
    ptr->next->prev = temp;
    free(ptr);

    return head;
}

node * insertatend(node *head,int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;

    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = ptr;
    ptr->prev = temp;
    ptr->next = NULL;

    return head;
}

node * deleteatend(node *head){
    node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    node *ptr = temp->next;
    temp->next = NULL;
    free(ptr);

    return head;
}

void display(node *head){
    node *ptr = head;

    while(ptr != NULL){
        cout << "Elements are: " << ptr->data << endl;
        ptr = ptr->next;
    }
    cout << endl;
}

int main(){
    node *head,*ptr,*temp,*ptr1,*ptr2;

    head = (node *)malloc(sizeof(node));
    ptr = (node *)malloc(sizeof(node));
    temp = (node *)malloc(sizeof(node));
    ptr1 = (node *)malloc(sizeof(node));
    ptr2 = (node *)malloc(sizeof(node));

    head->data = 23;
    head->prev = NULL;
    head->next = ptr;

    ptr->data = 34;
    ptr->prev = head;
    ptr->next = temp;

    temp->data = 56;
    temp->prev = ptr;
    temp->next = ptr1;

    ptr1->data = 52;
    ptr1->prev = temp;
    ptr1->next = ptr2;

    ptr2->data = 62;
    ptr2->prev = ptr1;
    ptr2->next = NULL;

    cout << "Before Any Operation: " << endl; 
    display(head);

    // head = insertatfirst(head,88);
    // head = insertinbet(head,67,3);
    // head = insertatend(head,33);
    cout << "After Any Operation: " << endl;
    // display(head);

    // head = deleteatfirst(head);
    // head = deleteinbet(head,3);
    head = deleteatend(head);
    display(head);

    return 0;

}