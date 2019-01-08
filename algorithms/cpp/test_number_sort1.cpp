
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <signal.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>

#include <typeinfo>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int f_argc = 0;
const char **f_argv = 0;

int getIndex()
{
    static int i = 0;
    return i++;
}

void swap(int *a, int *b) //交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

// 冒泡排序（英语：Bubble Sort）是一种简单的排序算法。
void bubble_sort(int arr[], int len)
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        for (int k = 0; k < len; ++k)
        {
            printf("%d ", arr[k]);
        }
        cout << endl;
    }

}

int test_bubble1()
{
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}

// 选择排序（Selection sort）是一种简单直观的排序算法。
void selection_sort(int arr[], int len)
{
    int i, j;

    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)     //走訪未排序的元素
            if (arr[j] < arr[min])    //找到目前最小值
                min = j;    //紀錄最小值
        swap(&arr[min], &arr[i]);    //做交換
        for (int k = 0; k < len; ++k)
        {
            printf("%d ", arr[k]);
        }
        cout << endl;
    }
}

int test_selection1()
{
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    selection_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}

// 归并排序（英语：Merge sort，或mergesort），是建立在归并操作上的一种有效的排序算法，
// 效率为 { O(n\log n)} { O(n\log n)}（大O符号）。
void merge_sort(int arr[], int len)
{
    int *a = arr;
    int *b = (int *) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg)
    {
        for (start = 0; start < len; start += seg * 2)
        {
            int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int *temp = a;
        a = b;
        b = temp;
        for (int i = 0; i < len; ++i)
        {
            printf("%d ", arr[i]);
        }
        cout << endl;
    }
    if (a != arr)
    {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}

int test_merge1()
{
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    merge_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}

// 插入排序（英语：Insertion Sort）是一种简单直观的排序算法。
// 它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
void insertion_sort(int arr[], int len)
{
    int i, j, key;
    for (i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        for (int i = 0; i < len; ++i)
        {
            printf("%d ", arr[i]);
        }
        cout << endl;
    }
}

int test_insertion1()
{
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    insertion_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}

typedef struct _Range {
    int start, end;
} Range;

Range new_Range(int s, int e)
{
    cout << "new_Range: " << s << " - " << e << endl;
    Range r;
    r.start = s;
    r.end = e;
    return r;
}

// 快速排序 Sorting quicksort .
// 使用快速排序法对一列数字进行排序的过程 分类 排序算法 数据结构 不定 
// 最坏时间复杂度 { O(n^{2})} O(n^{2})
// 最优时间复杂度 { O(n\log n)} O(n\log n)
// 平均时间复杂度 { O(n\log n)} O(n\log n)
// 最坏空间复杂度 根据实现的方式不同而不同
// 快速排序（英语：Quicksort），又称划分交换排序（partition-exchange sort），简称快排，
// 一种排序算法，最早由东尼·霍尔提出。
// 在平均状况下，排序 { n} n个项目要 { O(n\log n)} { O(n\log n)}（大O符号）次比较。
// 在最坏状况下则需要 { O(n^{2})} { O(n^{2})}次比较，
// 但这种状况并不常见。
// 事实上，快速排序 { O(n\log n)} { O(n\log n)}通常明显比其他演算法更快，
// 因为它的内部循环（inner loop）可以在大部分的架构上很有效率地达成。
void quick_sort(int arr1[], const int len)
{

    if (len <= 0)
        return; // 避免len等於負值時引發段錯誤（Segment Fault）
    // r[]模擬列表,p為數量,r[p++]為push,r[--p]為pop且取得元素
    Range r[14];
    int arr[14];
    memcpy(arr, arr1, len * sizeof(int));
    int p = 0;
    r[p++] = new_Range(0, len - 1);
    while (p)
    {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        int mid = arr[(range.start + range.end) / 2]; // 選取中間點為基準點
        int left = range.start, right = range.end;
        do
        {
            while (arr[left] < mid) ++left;   // 檢測基準點左側是否符合要求
            while (arr[right] > mid) --right; //檢測基準點右側是否符合要求
            if (left <= right)
            {
                swap(&arr[left], &arr[right]);
                left++;
                right--;               // 移動指針以繼續
            }
        }
        while (left <= right);
        if (range.start < right && range.end > left)
        {
            printf("");
        }
        if (range.start < right)
            r[p++] = new_Range(range.start, right);
        if (range.end > left)
            r[p++] = new_Range(left, range.end);
        for (int i = 0; i < len; ++i)
        {
            printf("%d ", arr[i]);
        }
        cout << endl;
    }
}

int test_quick1()
{
//    int arr[] = {22, 34, 3, 32, 82, 55, 2, 50, 37, 5, 64, 35, 9, 70};
//    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
//    int arr[] = {22, 34, 3, 32, 82, 55, 35, 50, 37, 5, 64, 36, 9, 70};
    int arr[] = {22, 34, 3, 2, 82, 55, 4, 12, 37, 5, 64, 35, 9, 70};
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int len = (int) sizeof(arr) / sizeof(*arr);
    quick_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}

int main(int argc, const char *argv[])
{
    f_argc = argc;
    f_argv = argv;

    cout << "begin:" << endl;
    cout << "number sort1" << endl;

//    test_bubble1();
//    test_selection1();
//    test_merge1();
//    test_insertion1();
    test_quick1();

    cout << "end." << endl;
}
