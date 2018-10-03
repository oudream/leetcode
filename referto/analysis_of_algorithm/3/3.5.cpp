#include<stdio.h>
#define n 5

int main()
{
    int a[n][n] = {{7},
                   {3, 8},
                   {8, 1, 0},
                   {2, 7, 4, 4},
                   {4, 5, 2, 6, 5}};
    int i, j;
    int p, q;
    int t;
    for (i = n - 2; i >= 0; i--)
    {
        for (j = 0; j <= i; j++)
        {
            p = a[i][j] + a[i + 1][j];
            q = a[i][j] + a[i + 1][j + 1];
            t = p > q ? p : q;
            a[i][j] = t;
        }
    }
    printf("the max is %d.", a[0][0]);
    return 0;
}
