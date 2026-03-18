// Day 29 - Question 1: Rotate Linked List Right by k Places
// Close
// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node *n=malloc(sizeof(struct Node));
    n->data=value;
    n->next=NULL;
    return n;
}

struct Node* insertAtEnd(struct Node *head, int value) {
    struct Node *newNode=createNode(value);
    if (head==NULL) {
        head=newNode;
        return head;
    } 
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

int countNodes(struct Node *head){
    struct Node *temp=head;
    int i=0;
    while(temp!=NULL){
        temp=temp->next;
        i++;
    }
    return i;
}

struct Node* RotateLL(struct Node* head,int k){
    struct Node* temp=head;
    int i=0,size;
    size=countNodes(head);
    while(temp!=NULL && i!=size-k){
        temp=temp->next;
        i++;
    }
    struct Node* NewL=createNode(temp->data);
    temp=temp->next;
    while(temp!=NULL){
        NewL=insertAtEnd(NewL,temp->data);
        temp=temp->next;
    }
    while(head!=NULL && i!=0){
        NewL=insertAtEnd(NewL,head->data);
        head=head->next;
        i--;
    }
    return NewL;
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct Node* myll=NULL;
    struct Node* myll2=NULL;
    int n,value,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        myll=insertAtEnd(myll,value);
    }
    scanf("%d",&k);
    myll2=RotateLL(myll,k);
    display(myll2);
}
