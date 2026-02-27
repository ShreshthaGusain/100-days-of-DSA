// Day 24 - Question 1: Delete First Occurrence of a Key
// Close
// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.


#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *createNode(int value){
    Node *new=(Node *)malloc(sizeof(Node *));
    new->data=value;
    new->next=NULL;
    return new;
}

Node *InsertAtEnd(Node *head,int value){
    if(head==NULL){
        head=createNode(value);
    }
    else{
        Node *temp=head;
        Node *new=createNode(value);
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;

    }
    return head;
}

int countNodes(Node* head){
    Node *temp=head;
    int c=1;
    while(temp->next!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}

Node *DeleteFirstKey(Node *head,int key){
    Node *curr=head;
    Node *temp=curr->next;
    while(temp!=NULL && temp->data!=key){
        temp=temp->next;
        curr=curr->next;
    }
    curr->next=temp->next;
    free(temp);
    return head;
}

void Display(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return;
}

int main() {
    int n,val;
    Node *myll=NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        myll=InsertAtEnd(myll,val);
    }

    scanf("%d",&val);
    myll=DeleteFirstKey(myll,val);

    Display(myll);

    return 0;
}
