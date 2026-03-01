/*
Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, k, i;
    scanf("%d", &n);

    if(n == 0)
        return 0;

    struct node *head = NULL, *temp = NULL, *newNode = NULL, *last = NULL;

    for(i = 0; i < n; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    k = k % n;

    if(k != 0)
    {
        last = head;
        int count = 1;
        while(last->next != NULL)
        {
            last = last->next;
            count++;
        }

        last->next = head;

        int steps = n - k;
        temp = head;

        for(i = 1; i < steps; i++)
            temp = temp->next;

        head = temp->next;
        temp->next = NULL;
    }

    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
