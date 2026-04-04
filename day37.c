// Day 37 - Question 1: Priority Queue Using Array
// Close
// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20

#include <stdio.h>
#include <string.h>

#define CAPACITY 1000

typedef struct PriorityQueue {
    int data[CAPACITY];
    int size;
} PriorityQueue;

void initialize(PriorityQueue *pq) {
    pq->size = 0;
}

void insert(PriorityQueue *pq, int x) {
    if (pq->size < CAPACITY) {
        pq->data[pq->size++] = x;
    }
}

int getMinIndex(PriorityQueue *pq) {
    if (pq->size == 0) return -1;
    int minIdx = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->data[i] < pq->data[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}

void peek(PriorityQueue *pq) {
    int idx = getMinIndex(pq);
    if (idx == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", pq->data[idx]);
    }
}

void delete(PriorityQueue *pq) {
    int idx = getMinIndex(pq);
    if (idx == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", pq->data[idx]);
        // Shift elements to fill the gap
        for (int i = idx; i < pq->size - 1; i++) {
            pq->data[i] = pq->data[i + 1];
        }
        pq->size--;
    }
}

int main() {
    PriorityQueue pq;
    initialize(&pq);

    int n, val;
    char op[20];

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(&pq, val);
        } else if (strcmp(op, "delete") == 0) {
            delete(&pq);
        } else if (strcmp(op, "peek") == 0) {
            peek(&pq);
        }
    }

    return 0;
}
