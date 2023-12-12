
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        if (sx == fx && sy == fy)
        {
            return t != 1;
        }
        int dx = abs(fx - sx), dy = abs(fy - sy);
        return max(dx, dy) <= t;
    }
};
int main()
{
    Solution s;
    cout << s.isReachableAtTime(2, 4, 7, 7, 6);
    return 0;
}