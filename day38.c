// Day 38 - Question 1: Deque Operations
// Close
// Problem: Deque (Double-Ended Queue)

// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

// Common Operations:
// 1. push_front(value): Insert an element at the front of the deque.
// 2. push_back(value): Insert an element at the rear of the deque.
// 3. pop_front(): Remove an element from the front of the deque.
// 4. pop_back(): Remove an element from the rear of the deque.
// 5. front(): Return the front element of the deque.
// 6. back(): Return the rear element of the deque.
// 7. empty(): Check whether the deque is empty.
// 8. size(): Return the number of elements in the deque.

// Additional Operations:
// - clear(): Remove all elements from the deque.
// - erase(): Remove one or more elements from the deque.
// - swap(): Swap contents of two deques.
// - emplace_front(): Insert an element at the front without copying.
// - emplace_back(): Insert an element at the rear without copying.
// - resize(): Change the size of the deque.
// - assign(): Replace elements with new values.
// - reverse(): Reverse the order of elements.
// - sort(): Sort the elements in ascending order.

// Time Complexity:
// - push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
// - clear, erase, resize, assign, reverse: O(n)
// - sort: O(n log n)

// Input:
// - Sequence of deque operations with values (if applicable)

// Output:
// - Results of operations such as front, back, size, or the final state of the deque after all operations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 1000

typedef struct Deque {
    int data[CAPACITY];
    int front;
    int rear;
    int size;
} Deque;

void initialize(Deque *dq) {
    dq->front = 0;
    dq->rear = CAPACITY - 1;
    dq->size = 0;
}

int isEmpty(Deque *dq) {
    return dq->size == 0;
}

void push_back(Deque *dq, int val) {
    if (dq->size == CAPACITY) return;
    dq->rear = (dq->rear + 1) % CAPACITY;
    dq->data[dq->rear] = val;
    dq->size++;
}

void push_front(Deque *dq, int val) {
    if (dq->size == CAPACITY) return;
    dq->front = (dq->front - 1 + CAPACITY) % CAPACITY;
    dq->data[dq->front] = val;
    dq->size++;
}

void pop_front(Deque *dq) {
    if (isEmpty(dq)) return;
    dq->front = (dq->front + 1) % CAPACITY;
    dq->size--;
}

void pop_back(Deque *dq) {
    if (isEmpty(dq)) return;
    dq->rear = (dq->rear - 1 + CAPACITY) % CAPACITY;
    dq->size--;
}

void get_front(Deque *dq) {
    if (isEmpty(dq)) printf("-1\n");
    else printf("%d\n", dq->data[dq->front]);
}

void get_back(Deque *dq) {
    if (isEmpty(dq)) printf("-1\n");
    else printf("%d\n", dq->data[dq->rear]);
}

void print_size(Deque *dq) {
    printf("%d\n", dq->size);
}

int main() {
    Deque dq;
    initialize(&dq);

    char op[30];
    int val, n;

    // Assuming N operations as per previous patterns
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "push_back") == 0) {
            scanf("%d", &val);
            push_back(&dq, val);
        } else if (strcmp(op, "push_front") == 0) {
            scanf("%d", &val);
            push_front(&dq, val);
        } else if (strcmp(op, "pop_front") == 0) {
            pop_front(&dq);
        } else if (strcmp(op, "pop_back") == 0) {
            pop_back(&dq);
        } else if (strcmp(op, "front") == 0) {
            get_front(&dq);
        } else if (strcmp(op, "back") == 0) {
            get_back(&dq);
        } else if (strcmp(op, "size") == 0) {
            print_size(&dq);
        }
    }

    return 0;
}
