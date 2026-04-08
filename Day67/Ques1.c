/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

void dfs(int v, int visited[], int stack[], int* top, struct Graph* graph) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->vertex])
            dfs(temp->vertex, visited, stack, top, graph);
        temp = temp->next;
    }

    stack[(*top)++] = v;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int stack[V];
    int top = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i, visited, stack, &top, graph);
    }

    for (int i = top - 1; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}