// Day 68 - Question 1: Topological Sort (Kahnâ€™s BFS Algorithm)
// Close
// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// --- Helper: Add Directed Edge ---
void addEdge(Node* adj[], int u, int v, int in_degree[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
    in_degree[v]++; // Increment in-degree of the destination node
}

// --- CORE FUNCTION: KAHN'S ALGORITHM ---
void kahnTopoSort(int n, Node* adj[], int in_degree[]) {
    int queue[n];
    int front = 0, rear = -1;
    int topoOrder[n];
    int count = 0;

    // 1. Enqueue all nodes with in-degree 0
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[++rear] = i;
        }
    }

    // 2. Process the queue
    while (front <= rear) {
        int u = queue[front++];
        topoOrder[count++] = u;

        // "Remove" edges from u to its neighbors
        Node* temp = adj[u];
        while (temp) {
            int v = temp->dest;
            in_degree[v]--;
            
            // If in-degree becomes 0, add to queue
            if (in_degree[v] == 0) {
                queue[++rear] = v;
            }
            temp = temp->next;
        }
    }

    // 3. Print result or detect cycle
    if (count != n) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", topoOrder[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Node* adj[n];
    int* in_degree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v, in_degree);
    }

    kahnTopoSort(n, adj, in_degree);

    return 0;
}
