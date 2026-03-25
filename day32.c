// Day 32 - Question 1: Push and Pop in Stack
// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 20 10

#include <stdio.h>
#define MAX 1000

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}
void push(Stack *s, int val) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = val;
    }
}
void pop(Stack *s) {
    if (s->top != -1) {
        s->top--;
    }
}
void display(Stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d%s", s->data[i], (i == 0 ? "" : " "));
    }
    printf("\n");
}
int main() {
    Stack s;
    init(&s);
    int n, m, val;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(&s, val);
    }
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop(&s);
    }

    display(&s);

    return 0;
}
