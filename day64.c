// Day 64 - Question 1: Breadth First Search (BFS)
// Close
// Problem: Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// --- Queue Implementation for BFS ---
typedef struct Queue {
    int* items;
    int front, rear, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->items = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, int value) {
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    return q->items[q->front++];
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

// --- BFS Logic ---
void BFS(int startNode, Node* adj[], int n) {
    int* visited = (int*)calloc(n, sizeof(int));
    Queue* q = createQueue(n);

    visited[startNode] = 1;
    enqueue(q, startNode);

    while (!isEmpty(q)) {
        int u = dequeue(q);
        printf("%d ", u);

        Node* temp = adj[u];
        while (temp) {
            int v = temp->dest;
            if (!visited[v]) {
                visited[v] = 1;
                enqueue(q, v);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// --- Helper to add edges ---
void addEdge(Node* adj[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m, source;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        // addEdge(adj, v, u); // Uncomment for undirected
    }

    scanf("%d", &source);
    BFS(source, adj, n);

    return 0;
}
