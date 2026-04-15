// Day 52 - Question 1: LCA in Binary Tree
// Close
// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7
// 4 5

// Output:
// 2

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// --- CORE FUNCTION: LCA IN GENERAL BINARY TREE ---
Node* findLCA(Node* root, int p, int q) {
    if (root == NULL) return NULL;

    // If we find either p or q, return this node
    if (root->data == p || root->data == q) {
        return root;
    }

    // Look for p and q in left and right subtrees
    Node* leftLCA = findLCA(root->left, p, q);
    Node* rightLCA = findLCA(root->right, p, q);

    // If both return non-NULL, current node is the LCA
    if (leftLCA && rightLCA) {
        return root;
    }

    // Otherwise return the one that is not NULL
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// --- Standard Tree Building & Queue Helpers ---
Node* createNode(int val) {
    if (val == -1) return NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

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
