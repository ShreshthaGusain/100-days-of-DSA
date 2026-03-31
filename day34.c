// Day 34 - Question 1: Evaluate Postfix Expression
// Close
// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** top, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return; 
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    if (*top == NULL) return 0;
    Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int stringToInt(char *s) {
    int res = 0;
    int sign = 1;
    int i = 0;
    if (s[0] == '-') {
        sign = -1;
        i = 1;
    }
    while (s[i] != '\0') {
        res = res * 10 + (s[i] - '0');
        i++;
    }
    return res * sign;
}

int main() {
    Node* stack = NULL;
    char s[100];

    // Using a loop that is sensitive to the string length
    while (scanf("%s", s) == 1) {
        
        // CRITICAL CHECK: Is it a negative number or just a minus operator?
        // If it's just "-", it has length 1 and is NOT followed by a digit.
        if (isDigit(s[0]) || (s[0] == '-' && isDigit(s[1]))) {
            push(&stack, stringToInt(s));
        } else {
            // It's an operator
            int op2 = pop(&stack);
            int op1 = pop(&stack);

            if (s[0] == '+') push(&stack, op1 + op2);
            else if (s[0] == '-') push(&stack, op1 - op2);
            else if (s[0] == '*') push(&stack, op1 * op2);
            else if (s[0] == '/') {
                if (op2 != 0) push(&stack, op1 / op2);
                else push(&stack, 0); // Handle division by zero
            }
        }
        
        // Peek at the next character; if it's a newline, some judges need you to stop
        char next = getchar();
        if (next == '\n' || next == EOF) break;
    }

    if (stack != NULL) {
        printf("%d\n", pop(&stack));
    }

    return 0;
}
