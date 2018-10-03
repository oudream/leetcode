#include <stdio.h>
#include <math.h>

int main()
{
    int c;
    int a, b;
    int i;
    int count = 0;
    scanf("%d", &c);
    for (i = 1; i < c; i++)
    {
        a = i * i;
        b = sqrt(c * c - a);
        if ((a + b * b) == c * c)
        {
            printf("%d \t %d.\n", i, b);
            count++;
        }
    }
    printf("%d", count / 2);
    return 0;
} 