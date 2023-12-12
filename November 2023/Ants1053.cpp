#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        if (left.empty() && right.empty())
        {
            return 0;
        }
        else if (left.empty())
        {
            return n - right[0];
        }
        else if (right.empty())
        {
            return left.back();
        }

        return max(n - right[0], left.back());
    }
};
int main()
{
    vector<int> left = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> right = {};
    Solution s;
    int n = 7;
    cout << s.getLastMoment(n, left, right);
}