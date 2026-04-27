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

#include <iostream>
#include <vector>

using namespace std;

// Standard DFS to mark all nodes in a component
void dfs(int u, vector<int> adj[], vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int countComponents(int n, vector<int> adj[]) {
    vector<bool> visited(n + 1, false);
    int components = 0;

    for (int i = 1; i <= n; i++) {
        // If we hit an unvisited node, it's a new island/component
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }
    return components;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << countComponents(n, adj) << endl;

    return 0;
}
