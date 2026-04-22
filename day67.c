// Day 67 - Question 1: Topological Sort (DFS)
// Close
// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// --- SIMPLE STACK FOR TOPOLOGICAL ORDER ---
int stack[1000];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

// --- CORE DFS FUNCTION ---
void topoSortDFS(int u, Node* adj[], int visited[]) {
    visited[u] = 1;

    Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->dest;
        if (!visited[v]) {
            topoSortDFS(v, adj, visited);
        }
        temp = temp->next;
    }

    // All neighbors explored, push current node to stack
    push(u);
}

// Helper: Add Directed Edge
void addEdge(Node* adj[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Node* adj[n];
    int* visited = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    // Perform DFS for every unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoSortDFS(i, adj, visited);
        }
    }

    // Print stack in reverse (LIFO) to get topological order
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");

    return 0;
}
