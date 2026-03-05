// Day 27 - Question 1: Find Intersection Point of Two Linked Lists
// Close
// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// // Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *createNode(int value){
    Node *new=(Node *)malloc(sizeof(Node));
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

int CountN(Node *head){
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }

    return count;
}

int Intersect(Node *h1,Node *h2){
    int l1=CountN(h1);
    int l2=CountN(h2);
    int diff=0;
    Node *ptr1;
    Node *ptr2;
    if(l1>l2){
        diff=l1-l2;
        ptr1=h1;
        ptr2=h2;
    }
    else{
        diff=l2-l1;
        ptr1=h2;
        ptr2=h1;
    }
    while(diff){
        ptr1=ptr1->next;
        diff--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data==ptr2->data){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

int main() {
    int n,val;
    Node *ll1=NULL;
    Node *ll2=NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        ll1=InsertAtEnd(ll1,val);
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        ll2=InsertAtEnd(ll2,val);
    }
    int a;
    a=Intersect(ll1,ll2);
    
    printf("%d",a);
    return 0;
}
