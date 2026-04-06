/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle. 

Output: - YES or NO
*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

int dfs(int node, int parent, int visited[], struct Node* adj[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj))
                return 1;
        } else if (neighbor != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}