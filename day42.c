// Day 42 - Question 1: Reverse a Queue Using Stack
// Close
// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10

#include <stdio.h>
#include <stdlib.h>

// --- Stack Definitions ---
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

void push(StackNode** top, int val) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(StackNode** top) {
    if (*top == NULL) return -1;
    StackNode* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

// --- Queue Definitions ---
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, int val) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = val;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1;
    QueueNode* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

// --- Main Logic ---
int main() {
    int n, val;
    Queue q;
    initQueue(&q);
    StackNode* s = NULL;

    if (scanf("%d", &n) != 1) return 0;

    // 1. Read into Queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    // 2. Transfer Queue -> Stack
    for (int i = 0; i < n; i++) {
        push(&s, dequeue(&q));
    }

    // 3. Transfer Stack -> Queue
    for (int i = 0; i < n; i++) {
        enqueue(&q, pop(&s));
    }

    // 4. Print results
    QueueNode* temp = q.front;
    while (temp) {
        printf("%d%s", temp->data, (temp->next == NULL ? "" : " "));
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
