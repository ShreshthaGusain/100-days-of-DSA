// Day 54 - Question 1: Zigzag Traversal
// Close
// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print traversal in zigzag order

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 1 3 2 4 5 6 7

// Explanation:
// Level 1 is printed left-to-right, level 2 right-to-left, and so on.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// --- Simple Stack for Tree Nodes ---
typedef struct StackNode {
    Node* tNode;
    struct StackNode* next;
} StackNode;

void push(StackNode** top, Node* n) {
    if (!n) return;
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->tNode = n;
    newNode->next = *top;
    *top = newNode;
}

Node* pop(StackNode** top) {
    if (*top == NULL) return NULL;
    StackNode* temp = *top;
    Node* n = temp->tNode;
    *top = (*top)->next;
    free(temp);
    return n;
}

int isEmpty(StackNode* top) {
    return top == NULL;
}

// --- Zigzag Traversal Logic ---
void printZigZag(Node* root) {
    if (!root) return;

    StackNode* s1 = NULL; // Current level
    StackNode* s2 = NULL; // Next level

    push(&s1, root);
    int leftToRight = 1;

    while (!isEmpty(s1)) {
        while (!isEmpty(s1)) {
            Node* curr = pop(&s1);
            printf("%d ", curr->data);

            if (leftToRight) {
                // For next level: Left then Right
                if (curr->left) push(&s2, curr->left);
                if (curr->right) push(&s2, curr->right);
            } else {
                // For next level: Right then Left
                if (curr->right) push(&s2, curr->right);
                if (curr->left) push(&s2, curr->left);
            }
        }
        // Swap stacks and flip direction
        s1 = s2;
        s2 = NULL;
        leftToRight = !leftToRight;
    }
    printf("\n");
}

// --- Tree Building Helper ---
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
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n) {
        Node* curr = queue[head++];
        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }

    printZigZag(root);
    return 0;
}
