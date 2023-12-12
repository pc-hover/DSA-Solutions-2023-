#include <bits/stdc++.h>
using namespace std;

// {circular array i <-> i%n}

void nextGreatest(vector<int> nums1)
{
    int n = nums1.size();
    if (nums1.size() == 0)
        return;

    stack<int> s;

    vector<int> ans(n);
    ans[n - 1] = -1;
    s.push(nums1[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && nums1[i % n] <= s.top())
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i % n] = -1;
        }
        else
        {
            ans[i % n] = s.top();
        }
        s.push(nums1[i % n]);
    }
    for (auto it : ans)
    {
        cout << " " << it;
    }
    cout << endl;
}
int main()
{
    vector<int> nums1 = {4, 15, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    nextGreatest(nums1);
    return 0;
}