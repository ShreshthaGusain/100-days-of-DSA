// Day 66 - Question 1: Cycle Detection in Directed Graph
// Close
// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// --- CORE FUNCTION: DFS CYCLE DETECTION ---
int isCyclicUtil(int v, Node* adj[], int visited[], int recStack[]) {
    if (!visited[v]) {
        // Mark current node as visited and part of recursion stack
        visited[v] = 1;
        recStack[v] = 1;

        Node* temp = adj[v];
        while (temp != NULL) {
            int neighbor = temp->dest;
            
            // Recurse for unvisited neighbors
            if (!visited[neighbor] && isCyclicUtil(neighbor, adj, visited, recStack)) {
                return 1;
            }
            // If neighbor is already in the recursion stack, cycle found
            else if (recStack[neighbor]) {
                return 1;
            }
            temp = temp->next;
        }
    }

    // Remove node from recursion stack before backtracking
    recStack[v] = 0;
    return 0;
}

int hasCycle(int n, Node* adj[]) {
    int* visited = (int*)calloc(n, sizeof(int));
    int* recStack = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        if (isCyclicUtil(i, adj, visited, recStack)) {
            free(visited);
            free(recStack);
            return 1;
        }
    }

    free(visited);
    free(recStack);
    return 0;
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
