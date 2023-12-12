#include <bits/stdc++.h>
using namespace std;
// double squareRoot(int n)
// {
//     /* We are using n itself as initial approximation
//       This can definitely be improved */
//     double x = n;
//     double y = 1;

//     double e = 0.000001; /* e decides the accuracy level*/
//     while (x - y > e)
//     {
//         x = (x + y) / 2;
//         y = n / x;
//     }
//     return x;
// }
long long heightMax(long long n)
{
    long long x = 1 + 8 * n;
    long long maxH = (-1 + sqrt(x)) / 2;
    return maxH;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        cout << heightMax(n) << endl;
    }
}