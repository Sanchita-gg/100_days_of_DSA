/*
Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3
*/


#include <stdio.h>
#include <stdlib.h>

int visited[1001];
int* adj[1001];
int size[1001];

void dfs(int u) {
    visited[u] = 1;
    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(sizeof(int) * (n + 1));
        size[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}