#include <iostream>
#include <cstdio>

using namespace std;

int max(int arr[], int n)
{
    if (n == 0)
    {
        return arr[0];
    }
    else
    {
        int iMax = max(arr, n - 1);
        if (iMax > arr[n])
        {
            return iMax;
        }
        else
        {
            return arr[n];
        }
    }
}

int main()
{
    int arr[10] = {7, 11, 1, 15, 8, 34, 13, 5, 22, 33};

//    while (scanf("%d%d", &n, &k) != EOF) {
    int iMax = max(arr, sizeof(arr) / sizeof(int));
    printf("arr :");
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
    {
        printf(" %d", arr[i]);
    }
    printf("\niMax = %d", iMax);
    fflush(stdout);
    return 0;
}