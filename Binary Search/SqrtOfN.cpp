#include <bits/stdc++.h>
using namespace std;
int SqrtOfN(int n)
{
    int low = 1;
    int high = n;

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (mid * mid <= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
int main()
{
    cout << "Enter the Number ";
    int n;
    cin >> n;
    cout << "SquareRoot is " << SqrtOfN(n);
    return 0;
}