/*
Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100005

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

void addEdge(int u, int v, int w) {
    Node* n1 = (Node*)malloc(sizeof(Node));
    n1->v = v; n1->w = w; n1->next = adj[u];
    adj[u] = n1;

    Node* n2 = (Node*)malloc(sizeof(Node));
    n2->v = u; n2->w = w; n2->next = adj[v];
    adj[v] = n2;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int key[MAX];
    bool vis[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        vis[i] = false;
    }

    key[1] = 0;
    int total = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1, mn = INT_MAX;

        for (int j = 1; j <= n; j++) {
            if (!vis[j] && key[j] < mn) {
                mn = key[j];
                u = j;
            }
        }

        vis[u] = true;
        total += key[u];

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;
            if (!vis[v] && w < key[v]) {
                key[v] = w;
            }
            temp = temp->next;
        }
    }

    printf("%d", total);
    return 0;
}