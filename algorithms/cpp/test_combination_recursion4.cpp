#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_K 12

int n;
int k;
int B[MAX_K];

int iCount1 = 0;
int iCount2 = 0;

void C(int ki)
{
    iCount1++;
    if (ki == k)
    {
        iCount2++;printf("count : %d", iCount2);for (int j = 0; j < k; ++j) printf("%3d", B[j]); puts("");
        return;
    }
    else
    {
        for (int m = 0; m < n; ++m)
        {
            B[ki] = m;
            if (ki <= 0 || B[ki] > B[ki - 1])
            {
                C(ki + 1);
            }
        }
    }
}

int main()
{
//    while (scanf("%d%d", &n, &k) != EOF) {
    printf("please input n, k:\n");
    if (scanf("%d%d", &n, &k) != EOF)
    {
        if (k > MAX_K)
        {
            printf("k is tool great! [k<12]");
            return 0;
        }
        for (int i = 0; i < k; ++i)
        {
            B[i] = 0;
        }
        C(0);
        printf("\niCount1 = %d", iCount1);
        fflush(stdout);
    }
    return 0;
}