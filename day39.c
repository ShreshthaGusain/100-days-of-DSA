// Day 39 - Question 1: Min Heap Implementation
// Close
// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

// Example:
// Input:
// 6
// insert 40
// insert 10
// insert 30
// peek
// extractMin
// peek

// Output:
// 10
// 10
// 30


#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct MinHeap {
    int data[MAX_SIZE];
    int size;
} MinHeap;

void initialize(MinHeap *h) {
    h->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MinHeap *h, int val) {
    if (h->size >= MAX_SIZE) return;
    
    // Place at the end
    int i = h->size++;
    h->data[i] = val;

    // Bubble Up (Heapify Up)
    while (i != 0 && h->data[(i - 1) / 2] > h->data[i]) {
        swap(&h->data[i], &h->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void minHeapify(MinHeap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->data[left] < h->data[smallest])
        smallest = left;
    if (right < h->size && h->data[right] < h->data[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&h->data[i], &h->data[smallest]);
        minHeapify(h, smallest);
    }
}

void extractMin(MinHeap *h) {
    if (h->size <= 0) {
        printf("-1\n");
        return;
    }
    if (h->size == 1) {
        printf("%d\n", h->data[--h->size]);
        return;
    }

    // Root is the min
    printf("%d\n", h->data[0]);
    
    // Move last element to root and bubble down
    h->data[0] = h->data[h->size - 1];
    h->size--;
    minHeapify(h, 0);
}

void peek(MinHeap *h) {
    if (h->size <= 0) {
        printf("-1\n");
    } else {
        printf("%d\n", h->data[0]);
    }
}

int main() {
    MinHeap h;
    initialize(&h);

    int n, val;
    char op[20];

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(&h, val);
        } else if (strcmp(op, "extractMin") == 0) {
            extractMin(&h);
        } else if (strcmp(op, "peek") == 0) {
            peek(&h);
        }
    }

    return 0;
}
