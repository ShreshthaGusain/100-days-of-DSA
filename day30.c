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

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* createTerm(int c, int e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

Node* insertTerm(Node* head, int c, int e) {
    Node* newNode = createTerm(c, e);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void displayPolynomial(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->exp == 0) {
            printf("%d", temp->coeff); 
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff); 
        } else {
            printf("%dx^%d", temp->coeff, temp->exp); 
        }

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* poly = NULL;
    int n, c, e;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        poly = insertTerm(poly, c, e);
    }

    displayPolynomial(poly);

    return 0;
}
