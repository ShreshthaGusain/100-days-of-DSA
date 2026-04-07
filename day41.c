// Day 41 - Question 1: Queue Using Linked List
// Close
// Problem Statement:
// Implement a Queue using a linked list supporting enqueue and dequeue operations.

// Input Format:
// - First line contains integer N
// - Next N lines contain queue operations

// Output Format:
// - Print dequeued elements
// - Print -1 if dequeue is attempted on an empty queue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *FRONT;
    Node *REAR;
    int currentCount;
    int CAP;
} Queue;

// Function Prototypes
Node* newNode(int data);
Queue* initQ(int capacity);
void EnQ(Queue *qP, int data, int *RES);
int DQ(Queue *qP, int *RES);

int main() {
    // Capacity set large to handle N operations if not specified
    Queue *myQ = initQ(1000); 
    int N, res, val;
    char op[20];

    if (scanf("%d", &N) != 1) return 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &val);
            EnQ(myQ, val, &res);
            // Result 0 means overflow, though problem usually assumes enough space
        } else if (strcmp(op, "dequeue") == 0) {
            int dequeuedVal = DQ(myQ, &res);
            if (res == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", dequeuedVal);
            }
        }
    }

    return 0;
}

Queue* initQ(int capacity) {
    Queue *qP = (Queue *)malloc(sizeof(Queue));
    qP->FRONT = NULL;
    qP->REAR = NULL;
    qP->CAP = capacity;
    qP->currentCount = 0;
    return qP;
}

Node* newNode(int data) {
    Node *newN = (Node *)malloc(sizeof(Node));
    newN->data = data;
    newN->next = NULL;
    return newN;
}

void EnQ(Queue *qP, int data, int *RES) {
    // Check for overflow
    if (qP->currentCount >= qP->CAP) {
        *RES = 0;
        return;
    }

    Node *newN = newNode(data);
    if (qP->FRONT == NULL) {
        qP->FRONT = qP->REAR = newN;
    } else {
        qP->REAR->next = newN;
        qP->REAR = newN;
    }
    qP->currentCount++;
    *RES = 1;
}

int DQ(Queue *qP, int *RES) {
    // Check for underflow
    if (qP->FRONT == NULL) {
        *RES = 0;
        return -1;
    }

    *RES = 1;
    int data = qP->FRONT->data;
    Node *tmp = qP->FRONT;

    if (qP->FRONT == qP->REAR) {
        qP->FRONT = qP->REAR = NULL;
    } else {
        qP->FRONT = qP->FRONT->next;
    }

    free(tmp);
    qP->currentCount--;
    return data;
}
