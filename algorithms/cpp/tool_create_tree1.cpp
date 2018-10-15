#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int getIndex()
{
    static int i = 0;
    return i++;
}

void createTree (int n)
{
    int iIndex = getIndex();
    if (n <= 0)
    {
        return;
    }
    createTree (n - 1);
    printf("%4d ", iIndex);
//    for (int i = 0; i < pow(2, n); ++i)
//    {
//        cout << "-";
//    }
    cout << n;
    cout << "\n";
//    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    createTree (n - 3);
}

int main()
{
    int n;
    cout << ("please input tree deep n:\n");
    cin >> n;
//    hannoi (n, 'A', 'B', 'C');
    createTree (n);
    return 0;
}