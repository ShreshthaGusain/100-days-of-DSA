// Day 62 - Question 1: Graph Representation Using Adjacency List
// Close
// Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

// Input:
// - n (vertices)
// - m (edges)
// - edges (u, v)

// Output:
// - List of adjacency lists for each vertex

#include <stdio.h>
#include <stdlib.h>

// Node to represent a neighbor in the adjacency list
typedef struct AdjNode {
    int dest;
    struct AdjNode* next;
} AdjNode;

// Function to create a new adjacency node
AdjNode* createNode(int v) {
    AdjNode* newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->dest = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge
void addEdge(AdjNode* adj[], int u, int v) {
    // Add v to u's list
    AdjNode* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    // Uncomment for Undirected Graph
    /*
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
    */
}

void printGraph(AdjNode* adj[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        AdjNode* temp = adj[i];
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Array of heads for linked lists
    AdjNode* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    printGraph(adj, n);

    return 0;
}
