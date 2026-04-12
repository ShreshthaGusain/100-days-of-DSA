// Day 46 - Question 1: Level Order Traversal
// Close
// Problem: Level Order Traversal

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// --- Queue Setup for Tree Nodes ---
typedef struct QNode {
    Node* tNode;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode *front, *rear;
} Queue;

void enqueue(Queue* q, Node* t) {
    if (!t) return;
    QNode* newN = (QNode*)malloc(sizeof(QNode));
    newN->tNode = t;
    newN->next = NULL;
    if (!q->rear) {
        q->front = q->rear = newN;
    } else {
        q->rear->next = newN;
        q->rear = newN;
    }
}

Node* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QNode* temp = q->front;
    Node* t = temp->tNode;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return t;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// --- Level Order Traversal Function ---
void levelOrder(Node* root) {
    if (!root) return;

    Queue q = {NULL, NULL};
    enqueue(&q, root);

    while (!isQueueEmpty(&q)) {
        Node* curr = dequeue(&q);
        printf("%d ", curr->data);

        if (curr->left) enqueue(&q, curr->left);
        if (curr->right) enqueue(&q, curr->right);
    }
    printf("\n");
}

// --- Helper to Build Tree from Level Order Input ---
Node* createNode(int val) {
    if (val == -1) return NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Build the tree first
    Node* root = createNode(arr[0]);
    Queue buildQ = {NULL, NULL};
    enqueue(&buildQ, root);

    int i = 1;
    while (i < n) {
        Node* parent = dequeue(&buildQ);
        if (i < n) {
            parent->left = createNode(arr[i++]);
            if (parent->left) enqueue(&buildQ, parent->left);
        }
        if (i < n) {
            parent->right = createNode(arr[i++]);
            if (parent->right) enqueue(&buildQ, parent->right);
        }
    }

    // Perform the Level Order Traversal
    levelOrder(root);

    return 0;
}
