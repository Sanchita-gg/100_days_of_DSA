/*
Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int** adj, int* adjSize, bool* visited, bool* recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];

        if (!visited[next]) {
            if (dfs(next, adj, adjSize, visited, recStack))
                return true;
        } else if (recStack[next]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int));
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}