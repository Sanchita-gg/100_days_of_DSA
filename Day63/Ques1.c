/*
Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order
*/

#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int** adj, int* visited) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, n, adj, visited);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int s;
    scanf("%d", &s);

    int* visited = (int*)calloc(n, sizeof(int));

    dfs(s, n, adj, visited);

    return 0;
}