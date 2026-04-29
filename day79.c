// Day 79 - Question 1: Single Source Shortest Path using Dijkstra’s Algorithm
// Close
// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

// Sample Input
// 5 6
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// 1

// Sample Output
// 0 2 3 9 6

// Explanation
// Shortest distances computed via priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Function to find the node with the minimum distance
int findMinDistance(int n, int dist[], int visited[]) {
    int min = INF, min_index = -1;

    for (int v = 1; v <= n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int n, int graph[n+1][n+1], int src) {
    int dist[n + 1];
    int visited[n + 1];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n; count++) {
        int u = findMinDistance(n, dist, visited);

        // If u is -1, remaining nodes are unreachable
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            // Update dist[v] only if it's not visited, there is an edge,
            // and the total weight of path from src to v through u is 
            // smaller than current value of dist[v]
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Static-ish allocation for the adjacency matrix
    int graph[n+1][n+1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Assuming undirected based on sample
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, graph, source);

    return 0;
}
