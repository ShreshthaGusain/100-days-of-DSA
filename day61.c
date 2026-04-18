// Day 61 - Question 1: Graph Representation Using Adjacency Matrix
// Close
// Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
// The graph may be directed or undirected.

// Input:
// - n (vertices)
// - m (edges)
// - m pairs (u, v)

// Output:
// - n x n adjacency matrix

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    // Get number of vertices and edges
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Dynamically allocate a 2D array (Adjacency Matrix)
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int)); // Initialize with 0s
    }

    // Read m edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Edge from u to v
        matrix[u][v] = 1;
        
        // Uncomment the line below if the graph is UNDIRECTED
        // matrix[v][u] = 1; 
    }

    // Output the resulting matrix
    printMatrix(matrix, n);

    // Free memory
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);

    return 0;
}
