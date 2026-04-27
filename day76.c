// Day 76 - Question 1: Count Connected Components (Undirected Graph)
// Close
// Problem Statement
// Using DFS or BFS, count number of connected components.

// Input Format
// n m
// edges

// Output Format
// Number of connected components.

// Sample Input
// 6 3
// 1 2
// 2 3
// 5 6

// Sample Output
// 3

// Explanation
// Components: {1,2,3}, {4}, {5,6}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

void dfs(int u, Node* adj[], int visited[]) {
    visited[u] = 1;
    Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->dest]) dfs(temp->dest, adj, visited);
        temp = temp->next;
    }
}

void addEdge(Node* adj[], int u, int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
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
        addEdge(adj, v, u);
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i, adj, visited);
        }
    }
    printf("%d\n", count);
    return 0;
}
