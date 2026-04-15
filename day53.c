// Day 53 - Question 1: Print Binary Tree Vertical Order
// Close
// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.#include <stdio.h>
// #include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Find the min and max horizontal distance
void findMinMax(Node* node, int* min, int* max, int hd) {
    if (node == NULL) return;

    if (hd < *min) *min = hd;
    else if (hd > *max) *max = hd;

    findMinMax(node->left, min, max, hd - 1);
    findMinMax(node->right, min, max, hd + 1);
}

// Print all nodes for a specific horizontal distance
// We use level order logic here to ensure top-to-bottom printing
typedef struct QNode {
    Node* tNode;
    int hd;
    struct QNode* next;
} QNode;

void printVerticalLine(Node* root, int line_no) {
    if (root == NULL) return;

    // We use a Queue for BFS to satisfy "top to bottom" requirement
    QNode *front = NULL, *rear = NULL;
    
    // Manual Enqueue helper
    auto void enqueue(Node* n, int h) {
        if (!n) return;
        QNode* temp = (QNode*)malloc(sizeof(QNode));
        temp->tNode = n; temp->hd = h; temp->next = NULL;
        if (!rear) front = rear = temp;
        else { rear->next = temp; rear = temp; }
    }

    enqueue(root, 0);
    int first = 1;

    while (front) {
        QNode* temp = front;
        front = front->next;
        if (!front) rear = NULL;

        if (temp->hd == line_no) {
            printf("%s%d", first ? "" : " ", temp->tNode->data);
            first = 0;
        }

        if (temp->tNode->left) enqueue(temp->tNode->left, temp->hd - 1);
        if (temp->tNode->right) enqueue(temp->tNode->right, temp->hd + 1);
        free(temp);
    }
}

// --- Tree Building and Main ---
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

    // Build tree logic
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

    // Solve Vertical Order
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    for (int line = min; line <= max; line++) {
        printVerticalLine(root, line);
        printf("\n");
    }

    return 0;
}
