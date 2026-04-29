// Day 77 - Question 1: Check if Graph is Connected
// Close
// Problem Statement
// Using BFS or DFS, check if the entire graph is connected.

// Input Format
// n m
// edges

// Output Format
// CONNECTED
// NOT CONNECTED

// Sample Input
// 4 2
// 1 2
// 3 4

// Sample Output
// NOT CONNECTED

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Standard DFS to visit all reachable nodes
void dfs(int u, Node* adj[], int visited[]) {
    visited[u] = 1;
    Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->dest;
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
        temp = temp->next;
    }
}

// Helper to add undirected edges
void addEdge(Node* adj[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Handle edge case where there are no nodes
    if (n == 0) {
        printf("CONNECTED\n");
        return 0;
    }

    Node* adj[n + 1];
    int visited[n + 1];
    for (int i = 0; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    // Start DFS from the first node (node 1)
    dfs(1, adj, visited);

    // Check if all nodes from 1 to n were visited
    int allVisited = 1;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            allVisited = 0;
            break;
        }
    }

    if (allVisited) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}
