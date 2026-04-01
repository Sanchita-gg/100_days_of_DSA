/*
Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n) return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

int isComplete(struct Node* root, int index, int n) {
    if (!root) return 1;
    if (index >= n) return 0;

    return isComplete(root->left, 2*index + 1, n) &&
           isComplete(root->right, 2*index + 2, n);
}

int isHeap(struct Node* root) {
    if (!root->left && !root->right)
        return 1;

    if (!root->right)
        return (root->data <= root->left->data) && isHeap(root->left);

    return (root->data <= root->left->data &&
            root->data <= root->right->data &&
            isHeap(root->left) &&
            isHeap(root->right));
}

int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int isMinHeap(struct Node* root) {
    int n = countNodes(root);
    if (isComplete(root, 0, n) && isHeap(root))
        return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    if (isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}