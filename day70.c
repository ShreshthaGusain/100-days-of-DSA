// Day 70 - Question 1: Bellman-Ford Algorithm
// Close
// Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

// Input:
// - n vertices
// - m edges (u,v,w)

// Output:
// - Shortest distances OR NEGATIVE CYCLE

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1e9 // Using a large value for Infinity

typedef struct Edge {
    int u, v, w;
} Edge;

void bellmanFord(int n, int m, Edge edges[], int src) {
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    // Relax all edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    int hasNegativeCycle = 0;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasNegativeCycle = 1;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF) printf("INF ");
            else printf("%d ", dist[i]);
        }
        printf("\n");
    }
    free(dist);
}

int main() {
    int n, m, src;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Edge* edges = (Edge*)malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    scanf("%d", &src);
    bellmanFord(n, m, edges, src);

    free(edges);
    return 0;
}
