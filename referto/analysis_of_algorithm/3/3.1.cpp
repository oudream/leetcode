// 暴力（三重循环）
#include<stdio.h>
#define n 6

int test1()
{
    int i, j, k;
    int a[n] = {-2, 11, -4, 13, -5, -2};
    int tempsum, max = 0;
    int besti, bestj;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            tempsum = 0;
            for (k = i; k <= j; k++)
                tempsum += a[k];
            if (tempsum > max)
            {
                max = tempsum;
                besti = i;
                bestj = j;
            }
        }
    }
    printf("the best position is %d ~ %d,the max sum is %d.", besti + 1, bestj + 1, max);
    return 0;
}

// 由三个循环变成两个循环的算法
int test2()
{
    int i, j, k;
    int a[n] = {-2, 11, -4, 13, -5, -2};
    int tempsum, max = 0;
    int besti, bestj;
    for (i = 0; i < n; i++)
    {
        tempsum = 0;
        for (j = i; j < n; j++)
        {
            tempsum += a[j];
            if (tempsum > max)
            {
                max = tempsum;
                besti = i;
                bestj = j;
            }
        }
    }
    printf("the best position is %d ~ %d,the max sum is %d.", besti + 1, bestj + 1, max);
    return 0;
}

// 一次循环解决所有问题
int test3()
{
    int i, j, k;
    int a[n] = {-2, 11, -4, 13, -5, -2};
    int besti, bestj;
    int sum = 0, b = 0;
    for (i = 0; i < n; i++)
    {
        if (b > 0)
            b += a[i];
        else
            b = a[i];
        if (b > sum)
            sum = b;
    }
    printf("the best position is,the max sum is %d.", sum);
    return 0;
}

int main(int argc, const char * argv[])
{
    printf("3.1 - begin:\n");

    test1();
    test2();
    test3();

    printf("3.1 - end.");
}