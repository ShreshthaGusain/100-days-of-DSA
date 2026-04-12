// Day 45 - Question 1: Height of a Binary Tree
// Close
// Problem Statement:
// Find the height (maximum depth) of a given binary tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)

// Output Format:
// - Print the height of the tree

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 -1

// Output:
// 3

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Standard helper to create a node
Node* createNode(int val) {
    if (val == -1) return NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// RECURSIVE FUNCTION TO FIND HEIGHT
int findHeight(Node* root) {
    if (root == NULL) {
        return 0; // Base case: height of empty tree is 0
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    // Return the taller side + 1 for the current node
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

// --- Logic to build tree from Level Order ---
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

    // Build the tree
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

    // Output the result
    printf("%d\n", findHeight(root));

    return 0;
}
