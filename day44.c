// Day 44 - Question 1: Binary Tree Traversals
// Close
// Problem Statement:
// Perform inorder, preorder, and postorder traversals of a given binary tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)

// Output Format:
// - Print inorder, preorder, and postorder traversals

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4 2 5 1 6 3 7
// 1 2 4 5 3 6 7
// 4 5 2 6 7 3 1

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// --- Tree Building Logic (Queue based) ---
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

Node* createNode(int val) {
    if (val == -1) return NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// --- The Three Traversals ---

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);   // Visit Root First
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);   // Visit Root Middle
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);   // Visit Root Last
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Build Tree from Level Order
    Node* root = createNode(arr[0]);
    Queue q = {NULL, NULL};
    enqueue(&q, root);

    int i = 1;
    while (i < n) {
        Node* curr = dequeue(&q);
        if (i < n) {
            curr->left = createNode(arr[i++]);
            enqueue(&q, curr->left);
        }
        if (i < n) {
            curr->right = createNode(arr[i++]);
            enqueue(&q, curr->right);
        }
    }

    // Print results
    inorder(root);   printf("\n");
    preorder(root);  printf("\n");
    postorder(root); printf("\n");

    return 0;
}
