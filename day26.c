// Day 26 - Question 1: Doubly Linked List Insertion and Traversal
// Close
// Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the linked list elements in forward order, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *createNode(int value){
    Node *new=(Node *)malloc(sizeof(Node));
    new->data=value;
    new->next=NULL;
    new->prev=NULL;
    return new;
}

Node *IAtEnd(Node *head,int value){
    if(head==NULL){
        return createNode(value);
    }
    Node *newNode=createNode(value);
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}

void display(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    Node *head = NULL;
    int n,value;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        head=IAtEnd(head,value);
    }
    display(head);

    return 0;
}
