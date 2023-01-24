#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node * insertatfirst(node *head,int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head;
    // head = ptr;

    return ptr;
}

node * deleteatfirst(node *head){
    node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

node * insertatbet(node *head,int data,int in){
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

node * deleteinbet(node *head,int in){
    node *ptr = head;
    int i = 0;
    while(i != in-1){
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
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = ptr;
    ptr->next = NULL;

    return head;
}

node * deleteatend(node *head){
    node *ptr = head;
    
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }

    node *temp = ptr->next;
    ptr->next = NULL;
    free(temp);

    return head;
}

node * insertafteranode(node *head,node *prev,int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;

    ptr->next = prev->next;
    prev->next = ptr;

    return head;
}

node * deletewithvalue(node *head,int data){
    node *ptr = head;

    while(ptr->next->data != data){
        ptr = ptr->next;
    }

    node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    return head;
}

void display(node *head){
    node *temp = head;
    while(temp != NULL){
        cout << "Elements are: " << temp->data << endl;
        temp = temp->next;
    }

    cout << endl;
}

int main(){
    node *head;
    node *ptr,*temp,*ptr2;
    // In Heap
    head = (node *)malloc(sizeof(node));
    ptr = (node *)malloc(sizeof(node));
    temp = (node *)malloc(sizeof(node));
    ptr2 = (node *)malloc(sizeof(node));

    head->data = 7;
    head->next = ptr;

    ptr->data = 11;
    ptr->next = temp;

    temp->data = 22;
    temp->next = ptr2;

    ptr2->data = 44;
    ptr2->next = NULL;

    display(head);
    cout << endl;
    // head = insertatfirst(head,79);
    // head = insertatbet(head,89,3);
    // head = insertatend(head,6);
    // head = insertafteranode(head,temp,45);
    // display(head);

    // head = deleteatfirst(head);
    // head = deleteinbet(head,1);
    // head = deleteatend(head);
    // head = deletewithvalue(head,7);
    display(head);
    cout << head->data;
    return 0;
}