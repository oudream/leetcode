#include<stdio.h>
#define n 4

int a[n] = {5, 12, 4, 8}; //m1
int b[n] = {6, 2, 14, 7}; //m2
int index[n] = {0, 1, 2, 3}; //方便全排列

int work(int i, int t)
{
    //work(int i,int t)表示作业i的前一个作业在机器2上用的时间为t
    if (i == n - 1)
    {
        if (t > a[index[i]])
        {
            return t - a[index[i]] + a[index[i]] + b[index[i]];
        }
        else
        {
            return a[index[i]] + b[index[i]];
        }
    }
    int minvalue;
    int tempvalue, temp;
    int tt;
    int j;
    tt = (t - a[index[i]]) > 0 ? (t - a[index[i]]) : 0;
    minvalue = a[index[i]] + work(i + 1, tt + b[index[i]]);
    for (j = i + 1; j < n; j++)
    {
        temp = index[i];
        index[i] = index[j];
        index[j] = temp;
        tt = (t - a[index[i]]) > 0 ? (t - a[index[i]]) : 0;
        tempvalue = a[index[i]] + work(i + 1, tt + b[index[i]]);
        if (tempvalue < minvalue)
        {
            minvalue = tempvalue;
        }
        temp = index[i];
        index[i] = index[j];
        index[j] = temp;
    }
    return minvalue;
}

int main()
{
    printf("the min is %d.", work(0, 0));
    return 0;
}
