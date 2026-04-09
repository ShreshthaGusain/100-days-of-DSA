// Day 43 - Question 1: Binary Tree Construction (Level Order)
// Close
// Problem Statement:
// Construct a Binary Tree from the given level-order traversal.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers (-1 represents NULL)

// Output Format:
// - Print inorder traversal of the constructed tree

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 4 2 5 1 3 6

#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue Node for Tree Nodes
typedef struct QNode {
    Node* treeNode;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode *front, *rear;
} Queue;

Node* createNode(int data) {
    if (data == -1) return NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Simple Queue operations for Level Order
void enqueue(Queue* q, Node* tNode) {
    if (tNode == NULL) return;
    QNode* newQN = (QNode*)malloc(sizeof(QNode));
    newQN->treeNode = tNode;
    newQN->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newQN;
        return;
    }
    q->rear->next = newQN;
    q->rear = newQN;
}

Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QNode* temp = q->front;
    Node* tNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return tNode;
}

// Inorder Traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // 1. Initialize root
    Node* root = createNode(arr[0]);
    if (!root) return 0;

    Queue q = {NULL, NULL};
    enqueue(&q, root);

    int i = 1;
    while (i < n) {
        Node* parent = dequeue(&q);

        // 2. Handle Left Child
        if (i < n) {
            parent->left = createNode(arr[i++]);
            if (parent->left) enqueue(&q, parent->left);
        }

        // 3. Handle Right Child
        if (i < n) {
            parent->right = createNode(arr[i++]);
            if (parent->right) enqueue(&q, parent->right);
        }
    }

    inorder(root);
    printf("\n");

    return 0;
}
