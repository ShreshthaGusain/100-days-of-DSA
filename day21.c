#include<stdio.h>
#include<stdlib.h>
// Day 21 - Question 1: Create and Traverse Singly Linked List
// Problem: Create and Traverse Singly Linked List

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
// 10 20 30 40 50

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

Node *IAtTail(Node *head,int value){
    if(head==NULL){
        return createNode(value);
    }
    Node *newNode=createNode(value);
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
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
        head=IAtTail(head,value);
    }
    display(head);

    return 0;
}

// 876. Middle of the Linked List
// Easy
// Topics
// premium lock icon
// Companies
// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:


// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

// Constraints:

// The number of nodes in the list is in the range [1, 100].
// 1 <= Node.val <= 100

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;  
        fast = fast->next->next;
    }

    return slow;
}
