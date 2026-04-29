// Day 78 - Question 1: Minimum Spanning Tree using Prim’s Algorithm
// Close
// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Function to find the vertex with the minimum key value
int minKey(int n, int key[], int mstSet[]) {
    int min = INF, min_index;
    for (int v = 1; v <= n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST(int n, int graph[n + 1][n + 1]) {
    int key[n + 1];    // Minimum weights to include node in MST
    int mstSet[n + 1]; // To keep track of vertices included in MST
    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    // Start with the first vertex
    key[1] = 0;

    for (int count = 0; count < n; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(n, key, mstSet);
        
        // Add the picked vertex to the MST Set
        mstSet[u] = 1;
        totalWeight += key[u];

        // Update key values of the adjacent vertices
        for (int v = 1; v <= n; v++) {
            // graph[u][v] is non-zero only for adjacent vertices
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Use a static-sized or dynamically allocated matrix
    int graph[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("%d\n", primMST(n, graph));

    return 0;
}
