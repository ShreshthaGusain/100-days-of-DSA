// Day 55 - Question 1: Right View of Binary Tree
// Close
// Problem Statement:
// Print the nodes visible when the binary tree is viewed from the right side.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print right view nodes

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 1 3 6

// Explanation:
// At each level, the rightmost node is visible from the right view.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// --- Queue for Level Order ---
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
    if (!q->rear) q->front = q->rear = newN;
    else { q->rear->next = newN; q->rear = newN; }
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

int isEmpty(Queue* q) {
    return q->front == NULL;
}

// --- Right View Logic ---
void printRightView(Node* root) {
    if (!root) return;

    Queue q = {NULL, NULL};
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        // Number of nodes at the current level
        int levelSize = 0;
        QNode* temp = q.front;
        while(temp) { levelSize++; temp = temp->next; }

        for (int i = 0; i < levelSize; i++) {
            Node* curr = dequeue(&q);

            // If it's the last node of the current level, print it
            if (i == levelSize - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }
    }
    printf("\n");
}

// --- Helper to Build Tree from Level Order ---
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

    Node* root = createNode(arr[0]);
    Queue buildQ = {NULL, NULL};
    enqueue(&buildQ, root);

    int i = 1;
    while (i < n) {
        Node* curr = dequeue(&buildQ);
        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) enqueue(&buildQ, curr->left);
        }
        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) enqueue(&buildQ, curr->right);
        }
    }

    printRightView(root);
    return 0;
}
