#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int getIndex()
{
    static int i = 0;
    return i++;
}

int main()
{
    int m = 12;
    int n = 16;
    int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
    bool bFlag = false;
    while (iMin <= iMax)
    {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if (i < iMax)
        {
            iMin = i + 1; // i is too small
        }
        else if (i > iMin )
        {
            iMax = i - 1; // i is too big
        }
        else
        {
            break;
        }
        cout << "iMin: " << iMin << " - iMax: " << iMax << endl;
    }
    cout << " --- " << endl << endl << endl;
    iMin = 0, iMax = m;
    while (iMin <= iMax)
    {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if (i > iMin )
        {
            iMax = i - 1; // i is too big
        }
        else
        {
            break;
        }
        cout << "iMin: " << iMin << " - iMax: " << iMax << endl;
    }
    cout << " --- " << endl << endl << endl;
    iMin = 0, iMax = m;
    while (iMin < iMax)
    {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if (bFlag)
        {
            iMax = i - 1; // i is too big
        }
        else
        {
            iMin = i + 1; // i is too small
        }
        bFlag = !bFlag;
        cout << "iMin: " << iMin << " - iMax: " << iMax << endl;
    }
    return 0;
}