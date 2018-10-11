/***********************/
/** This is C++ code. **/
/**   Comb  Example   **/
/***********************/

#include <iostream>

using namespace std;

int comb_g[100];

bool next_comb2(int *comb, const int n, const int k)
{
    int comb2[7];
    memcpy(comb2, comb, k * sizeof(int));
    int i = k - 1;
    const int e = n - k;
    do
        comb2[i]++;
    while (comb2[i] > e + i && i--);
    if (comb2[0] > e)
    {
        memcpy(comb, comb2, k * sizeof(int));
        return 0;
    }
    while (++i < k)
        comb2[i] = comb2[i - 1] + 1;
    memcpy(comb, comb2, k * sizeof(int));
    return 1;
}


bool next_comb(int *comb, const int n, const int k)
{
    int i = k - 1;
    const int e = n - k;
    do
        comb[i]++;
    while (comb[i] > e + i && i--);
    if (comb[0] > e)
        return 0;
    while (++i < k)
        comb[i] = comb[i - 1] + 1;
    return 1;
}

void coutCount(int c)
{
    if (c == ',')
    {
        cout << ',';
    }
    else
    {
        static int iCount = 1;
        cout << '\n' << ++iCount << " : ";
    }
}

int main()
{
    int n, k;
    cout << "comb(n,k):" << endl;
    cin >> n >> k;
    if (n < k || k <= 0)
        return 0;
    int *comb = new int[k];
    for (int i = 0; i < k; i++)
        comb[i] = i;
    cout << '\n' << 1 << " : ";
    do
        for (int i = 0; i < k; coutCount((++i < k) ? ',' : '\n'))
            cout << comb[i] + 1;
    while (next_comb2(comb, n, k));
    delete[] comb;
    return 0;
}
