/*
Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    scanf("%d",&n);
    int *q=(int*)malloc(n*sizeof(int));
    int front=0,rear=-1,count=0;

    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        rear=(rear+1)%n;
        q[rear]=x;
        count++;
    }

    scanf("%d",&m);

    for(int i=0;i<m;i++)
    {
        if(count>0)
        {
            front=(front+1)%n;
            count--;
        }
    }

    int temp=count;
    int i=front;
    while(temp--)
    {
        printf("%d ",q[i]);
        i=(i+1)%n;
    }

    return 0;
}