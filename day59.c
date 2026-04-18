// Day 59 - Question 1: Build Tree from Inorder & Postorder
// Close
// Problem Statement:
// Construct a binary tree from given inorder and postorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains inorder traversal
// - Third line contains postorder traversal

// Output Format:
// - Print preorder traversal of constructed tree

// Example:
// Input:
// 5
// 4 2 5 1 3
// 4 5 2 3 1

// Output:
// 1 2 4 5 3

// Explanation:
// Postorder gives root at end, inorder divides left and right subtrees.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Helper to find the index of a value in the inorder array
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// --- CORE FUNCTION: BUILD TREE ---
Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    // Base case
    if (inStart > inEnd) return NULL;

    // Pick the current node from postorder traversal using postIndex (moving backwards)
    int currVal = postorder[(*postIndex)--];
    Node* root = createNode(currVal);

    // If node has no children
    if (inStart == inEnd) return root;

    // Find the index of this node in Inorder traversal
    int inIndex = findIndex(inorder, inStart, inEnd, currVal);

    // IMPORTANT: In Postorder (Left-Right-Root), when moving backwards, 
    // the Right subtree appears before the Left subtree.
    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Helper: Preorder Traversal for output
void preorderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* inorder = (int*)malloc(n * sizeof(int));
    int* postorder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    // Start postIndex from the end of the array
    int postIndex = n - 1;
    Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorderTraversal(root);
    printf("\n");

    return 0;
}
