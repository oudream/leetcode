#include <iostream>
#include <cstdio>

using namespace std;

int n = 12;
int k = 7;
int arr[7] = {0, 1, 2, 3, 4, 5, 6};
int arrMin[7] = {0, 1, 2, 3, 4, 5, 6};
int arrMax[7] = {5, 6, 7, 8, 9, 10, 11};

int iCount1 = 0;
int iCount2 = 0;

int * D(int *c)
{
    int i = k - 1;
    const int e = n - k;
    do
        c[i]++;
    while (c[i] > e + i && i--);
    if (c[0] > e)
    {
        iCount2++;printf("count : %d", iCount2);for (int j = 0; j < k; ++j) printf("%3d", c[j]); puts("");
        return c;
    }
    while (++i < k)
        c[i] = c[i - 1] + 1;
    iCount2++;printf("count : %d", iCount2);for (int j = 0; j < k; ++j) printf("%3d", c[j]); puts("");
    return c;
}

int * C(int m)
{
    iCount1++;
    if (m == 0)
    {
        return arr;
    }
    else
    {
        return D(C(m-1));
    }
}

int main()
{
//    while (scanf("%d%d", &n, &k) != EOF) {
    int m = 792 - 1;
    C(m);
    printf("\niCount1 = %d", iCount1);
    fflush(stdout);
    return 0;
}