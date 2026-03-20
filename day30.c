// Day 30 - Question 1: Polynomial Using Linked List
// Close
// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Example:
// Input:
// 5
// 10 4
// 20 3
// 30 2
// 40 1
// 50 0

// Output:
// 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Explanation:
// Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.

#include <stdio.h>
#include <stdlib.h>

typedef struct poly{
    int pow;
    float coeff;
    struct poly *next;
}poly;

poly *createNode(int p,float c){
    poly *newN=(poly *)malloc(sizeof(poly));
    newN->next=NULL;
    newN->coeff=c;
    newN->pow=p;
    return newN;
}

poly *IAtEnd(poly *head,int pow,float coeff){
    poly *nnode=createNode(pow,coeff);
    if(head==NULL){
        return nnode;
    }
    poly *tnode=head;
    while(tnode->next!=NULL){
        tnode=tnode->next;
    }
    tnode->next=nnode;
    return head;
}

void display(poly *head){
    poly *temp=head;
    while(temp!=NULL){
        if(temp->pow>1){
            printf("%.0fx^%d",temp->coeff,temp->pow);
        }
        else if(temp->pow==1){
            printf("%.0fx",temp->coeff);
        }
        else{
            printf("%.0f",temp->coeff);
        }
        if(temp->next!=NULL){
        printf(" + ");
        }
        temp=temp->next;
    }
    
    return;
}


int main() {
    poly *poly=NULL;
    int n,pow;
    float coeff;

    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        scanf("%f %d",&coeff,&pow);
        poly=IAtEnd(poly,pow,coeff);
    }

    display(poly);

    return 0;
}
