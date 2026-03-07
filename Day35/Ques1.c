/*
Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    
    int q[n];
    int front=0,rear=-1;
    
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        rear++;
        q[rear]=x;
    }
    
    for(int i=front;i<=rear;i++)
        printf("%d ",q[i]);
    
    return 0;
}