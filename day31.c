// Day 31 - Question 1: Stack Implementation using Array
// Close
// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

// Input:
// - First line: integer n (number of operations)
// - Next n lines: operation type and value (if applicable)
//   - 1 value: push value
//   - 2: pop
//   - 3: display

// Output:
// - For display: print stack elements from top to bottom
// - For pop: print popped element or 'Stack Underflow'

// Example:
// Input:
// 5
// 1 10
// 1 20
// 3
// 2
// 3

// Output:
// 20 10
// 20
// 10
#include <stdio.h>
#define CAPACITY 5

typedef struct Stack {
    int top;
    int data[CAPACITY];
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}
void push(Stack *s, int val) {
    if (s->top < CAPACITY - 1) {
        s->data[++(s->top)] = val;
    }
}
void pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", s->data[s->top--]);
    }
}
void display(Stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d%s", s->data[i], (i == 0 ? "" : " "));
    }
    printf("\n");
}

int main() {
    Stack myStack;
    initialize(&myStack);
    int n, op, val;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &op);
        if(op==1){
            scanf("%d", &val);
            push(&myStack, val);
        }
        else if(op==2){
            pop(&myStack);
        }
        else if(op==3){
            display(&myStack);
        }
    }
    return 0;
}
