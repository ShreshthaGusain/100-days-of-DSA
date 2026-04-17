// Day 56 - Question 1: Symmetric Binary Tree Check
// Close
// Problem Statement:
// Check whether a given binary tree is symmetric around its center.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print YES if symmetric, otherwise NO

// Example:
// Input:
// 7
// 1 2 2 3 4 4 3

// Output:
// YES

// Explanation:
// Left subtree is a mirror image of the right subtree.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// --- CORE FUNCTION: IS MIRROR ---
int isMirror(Node* t1, Node* t2) {
    // Both empty is symmetric
    if (t1 == NULL && t2 == NULL) return 1;
    
    // One empty or values don't match is NOT symmetric
    if (t1 == NULL || t2 == NULL) return 0;
    if (t1->data != t2->data) return 0;

    // Check children in mirror order: (L1 with R2) and (R1 with L2)
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

int isSymmetric(Node* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
}

// --- Tree Building Helper (Level Order) ---
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

    // Build the tree
    Node* root = createNode(arr[0]);
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n) {
        Node* curr = queue[head++];
        if (curr) {
            if (i < n) {
                curr->left = createNode(arr[i++]);
                queue[tail++] = curr->left;
            }
            if (i < n) {
                curr->right = createNode(arr[i++]);
                queue[tail++] = curr->right;
            }
        }
    }

    if (isSymmetric(root)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
