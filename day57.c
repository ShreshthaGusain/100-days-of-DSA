// Day 57 - Question 1: Mirror a Binary Tree
// Close
// Problem Statement:
// Convert a binary tree into its mirror image by swapping left and right children at every node.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print inorder traversal of mirrored tree

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 7 3 6 1 5 2 4

// Explanation:
// Each node’s left and right children are swapped recursively.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// --- CORE FUNCTION: MIRROR TREE ---
void mirror(Node* root) {
    if (root == NULL) return;

    // Swap the left and right pointers
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the subtrees
    mirror(root->left);
    mirror(root->right);
}

// --- Helper: Inorder Traversal to verify result ---
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// --- Tree Building Logic (Level Order) ---
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

    // Transform the tree into its mirror
    mirror(root);

    // Output the inorder traversal as requested
    inorder(root);
    printf("\n");

    return 0;
}
