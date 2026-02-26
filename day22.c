// Day 22 - Question 1: Count Nodes in Linked List
// Close
// Problem: Count Nodes in Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// // 10 20 30 40 50

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


int main() {
    int n,val;
    Node *myll=NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        myll=InsertAtEnd(myll,val);
    }

    int count=countNodes(myll);
    printf("%d",count);

    return 0;
}
