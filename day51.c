// Day 51 - Question 1: Lowest Common Ancestor in BST
// Close
// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 6 2 8 0 4 7 9
// 2 8

// Output:
// 6

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int val) {
    if (val == -1) return NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// --- CORE FUNCTION: LCA IN BST ---
Node* findLCA(Node* root, int p, int q) {
    if (root == NULL) return NULL;

    // If both nodes are smaller than root, LCA is in left
    if (p < root->data && q < root->data) {
        return findLCA(root->left, p, q);
    }

    // If both nodes are larger than root, LCA is in right
    if (p > root->data && q > root->data) {
        return findLCA(root->right, p, q);
    }

    // Otherwise, we found the split point (the LCA)
    return root;
}

// --- Tree Building (Level Order) ---
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
    int n, p, q;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &p, &q);

    // Build the tree
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

    Node* lca = findLCA(root, p, q);
    if (lca) printf("%d\n", lca->data);

    return 0;
}
