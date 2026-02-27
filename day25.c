// Day 25 - Question 1: Count Occurrences of an Element in Linked List
// Problem: Count Occurrences of an Element in Linked List - 
// Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)

// Output:
// - Print the number of times the key appears in the linked list

// Example:
// Input:
// 6
// 10 20 30 20 40 20
// 20

// Output:
// 3

// Explanation:
// Traverse the linked list from head to end. 
// Each time a node's data matches the given key, increment a counter. After traversal, print the final count.


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

int CountKey(Node *head,int key){
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
        if(temp->data==key){
            count++;
        }
        temp=temp->next;
    }

    return count;
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
    int count=CountKey(myll,val);
    printf("%d",count);

    return 0;
}
