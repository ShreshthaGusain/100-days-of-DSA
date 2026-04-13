// Day 48 - Question 1: Count Leaf Nodes
// Close
// Problem: Count Leaf Nodes
// Implement the solution for this problem.

#include <stdio.h>
#include <stdlib.h>

// Standard Tree Node Structure
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Helper to create a new node
Node* createNode(int val) {
    if (val == -1) return NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// --- CORE FUNCTION: COUNT LEAVES ---
int countLeaves(Node* root) {
    if (root == NULL) return 0;

    // Check if current node is a leaf
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Otherwise, sum the leaves from left and right subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

// --- Tree Building Logic (Using Level Order Queue) ---
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

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Build tree from Level Order Input
    Node* root = createNode(arr[0]);
    Queue q = {NULL, NULL};
    enqueue(&q, root);

    int i = 1;
    while (i < n) {
        Node* curr = dequeue(&q);
        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) enqueue(&q, curr->left);
        }
        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) enqueue(&q, curr->right);
        }
    }

    // Result
    printf("%d\n", countLeaves(root));

    // Cleanup
    free(arr);
    return 0;
}
