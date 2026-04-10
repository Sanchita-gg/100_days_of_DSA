/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct MinHeapNode {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    int* pos;
    struct MinHeapNode** array;
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
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

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

struct MinHeapNode* newMinHeapNode(int v, int dist) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return heap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;

    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        struct MinHeapNode* smallestNode = heap->array[smallest];
        struct MinHeapNode* idxNode = heap->array[idx];

        heap->pos[smallestNode->v] = idx;
        heap->pos[idxNode->v] = smallest;

        swapMinHeapNode(&heap->array[smallest], &heap->array[idx]);

        minHeapify(heap, smallest);
    }
}

int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

struct MinHeapNode* extractMin(struct MinHeap* heap) {
    if (isEmpty(heap))
        return NULL;

    struct MinHeapNode* root = heap->array[0];
    struct MinHeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;

    heap->pos[root->v] = heap->size - 1;
    heap->pos[lastNode->v] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->v] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isInMinHeap(struct MinHeap *heap, int v) {
    if (heap->pos[v] < heap->size)
        return 1;
    return 0;
}

void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[V];

    struct MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        heap->array[v] = newMinHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }

    heap->array[src] = newMinHeapNode(src, 0);
    heap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(heap, src, dist[src]);

    heap->size = V;

    while (!isEmpty(heap)) {
        struct MinHeapNode* minNode = extractMin(heap);
        int u = minNode->v;

        struct Node* temp = graph->adj[u];
        while (temp != NULL) {
            int v = temp->vertex;

            if (isInMinHeap(heap, v) && dist[u] != INT_MAX && temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 9);
    addEdge(graph, 0, 2, 6);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 0, 4, 3);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 2, 3, 4);

    dijkstra(graph, 0);

    return 0;
}