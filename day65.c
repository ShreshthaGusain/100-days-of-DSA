// Day 65 - Question 1: Cycle Detection in Undirected Graph (DFS)
// Close
// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// --- CORE FUNCTION: DFS CYCLE DETECTION ---
int isCyclicUtil(int v, Node* adj[], int visited[], int parent) {
    // Mark the current node as visited
    visited[v] = 1;

    Node* temp = adj[v];
    while (temp != NULL) {
        int neighbor = temp->dest;

        // If neighbor is not visited, recurse
        if (!visited[neighbor]) {
            if (isCyclicUtil(neighbor, adj, visited, v))
                return 1;
        }
        // If neighbor is visited and NOT the parent of current node, 
        // then there is a cycle.
        else if (neighbor != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int hasCycle(int n, Node* adj[]) {
    int* visited = (int*)calloc(n, sizeof(int));

    // Check for every component (in case the graph is disconnected)
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, adj, visited, -1)) {
                free(visited);
                return 1;
            }
        }
    }
    free(visited);
    return 0;
}

// Helper to add edges (Undirected)
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

    Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    if (hasCycle(n, adj)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
