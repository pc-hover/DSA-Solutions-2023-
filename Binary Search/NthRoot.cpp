#include <bits/stdc++.h>
using namespace std;
int NthRoot(int m, int n)
{
    long long low = 1;
    int high = m;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (pow(mid, n) == m)
        {
            return mid;
        }
        else if (pow(mid, n) > m)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    cout << NthRoot(69, 4);
    return 0;
}