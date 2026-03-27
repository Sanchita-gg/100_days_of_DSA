/*
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }

    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }

    struct Node* root = nodes[0];

    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            struct Node* temp = queue[front++];
            if (i == size - 1) printf("%d ", temp->data);
            if (temp->left) queue[rear++] = temp->left;
            if (temp->right) queue[rear++] = temp->right;
        }
    }

    return 0;
}