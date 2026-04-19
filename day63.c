// Day 63 - Question 1: Depth First Search (DFS)
// Close
// Problem: Perform DFS starting from a given source vertex using recursion.

// Input:
// - n
// - adjacency list
// - starting vertex s

// Output:
// - DFS traversal order

#include <stdio.h>
#include <stdlib.h>

// Node for Adjacency List
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// DFS Recursive Function
void DFS(int u, Node* adj[], int visited[]) {
    // 1. Mark the current node as visited
    visited[u] = 1;
    
    // 2. Print the vertex (or store it in an array)
    printf("%d ", u);

    // 3. Recurse for all unvisited neighbors
    Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->dest;
        if (!visited[v]) {
            DFS(v, adj, visited);
        }
        temp = temp->next;
    }
}

// Helper to add edges (Directed)
void addEdge(Node* adj[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m, startNode;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Node* adj[n];
    int* visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) adj[i] = NULL;

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        // addEdge(adj, v, u); // Uncomment for Undirected
    }

    scanf("%d", &startNode);

    // Perform DFS
    DFS(startNode, adj, visited);
    printf("\n");

    return 0;
}
