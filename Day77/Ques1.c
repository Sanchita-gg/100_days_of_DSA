/*
Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED
*/


#include <stdio.h>
#include <stdlib.h>

void dfs(int u, int** adj, int* adjSize, int* visited) {
    visited[u] = 1;
    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) dfs(v, adj, adjSize, visited);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* adjSize = (int*)calloc(n + 1, sizeof(int));
    int** edges = (int**)malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        edges[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 1; i <= n; i++)
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));

    int* idx = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][idx[u]++] = v;
        adj[v][idx[v]++] = u;
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));

    dfs(1, adj, adjSize, visited);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}