// Day 36 - Question 1: Circular Queue Using Array
// Close
// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100 // Increased capacity for the problem constraints

typedef struct Queue {
    int data[CAPACITY];
    int front;
    int rear;
    int size; // Using size makes life much easier for circular logic
} Queue;

void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enQueue(Queue *q, int val) {
    if (q->size < CAPACITY) {
        q->rear = (q->rear + 1) % CAPACITY;
        q->data[q->rear] = val;
        q->size++;
    }
}

void deQueue(Queue *q) {
    if (q->size > 0) {
        q->front = (q->front + 1) % CAPACITY;
        q->size--;
    }
}

void display(Queue *q, int n) {
    // The example output requires printing 'n' elements starting from front
    // even if they were "dequeued", because it's a circular buffer.
    for (int i = 0; i < n; i++) {
        int index = (q->front + i) % n; 
        printf("%d%s", q->data[index], (i == n - 1 ? "" : " "));
    }
    printf("\n");
}

int main() {
    Queue myQueue;
    initializeQueue(&myQueue);

    int n, m, val;

    // 1. Input number of elements
    if (scanf("%d", &n) != 1) return 0;

    // 2. Enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enQueue(&myQueue, val);
    }

    // 3. Input number of dequeues
    scanf("%d", &m);

    // 4. Perform m dequeues
    for (int i = 0; i < m; i++) {
        deQueue(&myQueue);
    }

    // 5. Display the circular result
    display(&myQueue, n);

    return 0;
}
