
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

int binary_search(const int arr[], int start, int end, int key) {
    int ret = -1;       // 未搜索到数据返回-1下标

    int mid;
    while (start <= end) {
        mid = start + (end - start) / 2; //直接平均可能會溢位，所以用此算法
        if (arr[mid] < key)
            start = mid + 1;
        else if (arr[mid] > key)
            end = mid - 1;
        else {            // 最後檢測相等是因為多數搜尋狀況不是大於要不就小於
            ret = mid;
            break;
        }
    }

    return ret;     // 单一出口
}

int test_binary1()
{
    int arr[] = {22, 24, 27, 29, 33, 55, 58, 61, 66, 77, 78, 88, 89, 970};
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int len = (int) sizeof(arr) / sizeof(*arr);
    int index = binary_search(arr, 0, len-1, 970);
    printf("%d ", index);
    return 0;
}

int main(int argc, const char *argv[])
{
    f_argc = argc;
    f_argv = argv;

    cout << "begin:" << endl;
    cout << "number sort1" << endl;

    test_binary1();

    cout << "end." << endl;
}
