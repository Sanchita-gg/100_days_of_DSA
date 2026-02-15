/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15
*/

#include <stdio.h>

int main()
{
    int m, n, i, j;
    int matrix[100][100];
    int sum = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    if(m == n)
    {
        for(i = 0; i < m; i++)
        {
            sum = sum + matrix[i][i];
        }

        printf("Sum of primary diagonal = %d", sum);
    }
    else
    {
        printf("Primary diagonal exists only for square matrix");
    }

    return 0;
}
