// Day 35 - Question 1: Queue Using Array
// Close
// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers

// Output:
// - Print queue elements from front to rear, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the Queue structure to keep track of both ends
typedef struct Queue {
    Node *front, *rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue: Add to the rear
void enqueue(Queue* q, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    // If queue is empty, both front and rear point to new node
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Add the new node at the end and update rear
    q->rear->next = newNode;
    q->rear = newNode;
}

// Display the queue from front to rear
void display(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL ? "" : " "));
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &val) == 1) {
            enqueue(&q, val);
        }
    }

    display(&q);

    return 0;
}
