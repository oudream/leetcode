using namespace std;
#include <iostream>
#include <cstdio>

int getIndex()
{
    static int i = 0;
    return i++;
}

void hannoi (int n, char from, char buffer, char to)
{
    if (n == 0)
        return;
    hannoi (n - 1, from, to, buffer);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hannoi (n - 1, buffer, from, to);
}

void hannoiTrack (int n, char from, char buffer, char to)
{
    int iIndex = getIndex();
    printf("--%d-- : begin [%d , %c, %c, %c] \n", iIndex, n, from, buffer, to);
    if (n == 0)
    {
        printf("--%d-- : return [%d , %c, %c, %c] \n", iIndex, n, from, buffer, to);
        return;
    }
    printf("--%d-- : %d first -> hannoiTrack (%d , %c, %c, %c) \n", iIndex, iIndex, n-1, from, to, buffer);
    hannoiTrack (n - 1, from, to, buffer);
    printf("--%d-- : %d first <- hannoiTrack (%d , %c, %c, %c) \n", iIndex, iIndex, n-1, from, to, buffer);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    printf("--%d-- : %d second -> hannoiTrack (%d , %c, %c, %c) \n", iIndex, iIndex, n-1, buffer, from, to);
    hannoiTrack (n - 1, buffer, from, to);
    printf("--%d-- : %d second <- hannoiTrack (%d , %c, %c, %c) \n", iIndex, iIndex, n-1, buffer, from, to);
}

int main()
{
    int n;
    cout << ("please input hannoi n:\n");
    cin >> n;
//    hannoi (n, 'A', 'B', 'C');
    hannoiTrack (n, 'A', 'B', 'C');
    return 0;
}