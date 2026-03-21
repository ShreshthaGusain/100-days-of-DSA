// Day 23 - Question 1: Merge Two Sorted Linked Lists
// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL) {
        return newNode;
    }
    struct Node* temp=head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy; 
    struct Node* tail=&dummy;
    dummy.next=NULL;

    while (l1!=NULL && l2!=NULL) {
        if (l1->data<=l2->data) {
            tail->next=l1;
            l1=l1->next;
        } else {
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }

    if (l1!=NULL){
        tail->next=l1;
    }
    else tail->next=l2;

    return dummy.next;
}

void printList(struct Node* head) {
    while (head!=NULL) {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main() {
    struct Node *list1=NULL,*list2=NULL;
    int n,m,val;

    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&val);
        list1=insertAtEnd(list1,val);
    }

    scanf("%d", &m);
    for (int i=0;i<m;i++) {
        scanf("%d", &val);
        list2=insertAtEnd(list2, val);
    }

    struct Node* mergedHead=mergeLists(list1, list2);
    printList(mergedHead);

    return 0;
}
