// Day 28 - Question 1: Circular Linked List Creation and Traversal
// Close
// Problem: Circular Linked List Creation and Traversal -
// Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the circular linked list elements starting from head, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=newNode;
    return newNode;
}

struct Node * InsertAtHead(struct Node * head,int value){
    struct Node *temp=head;
    struct Node *newNode=createNode(value);
    if(head->next==head){
        head->next=newNode;
        newNode->next=head;
        return newNode;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    return newNode;
}

struct Node * InsertAtTail(struct Node * head,int value){
    if(head==NULL){
        head=createNode(value);
        return head;
    }
    struct Node *temp=head;
    struct Node *newNode=createNode(value);
    if(head->next==head){
        head->next=newNode;
        newNode->next=head;
        return head;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    return head;
}

void display(struct Node *head){
    struct Node * temp=head;
    printf("%d ",head->data);
    while(head->next!=temp){
        head=head->next;
        printf("%d ",head->data);
        
    }
}

int main(){
    struct Node* head=NULL;
    int n,val;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d ",&val);
        head=InsertAtTail(head,val);
    }
    display(head);
    return 0;
}
