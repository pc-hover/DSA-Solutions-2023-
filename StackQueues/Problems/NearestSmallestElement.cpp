#include <bits/stdc++.h>
using namespace std;

vector<int> NSE(vector<int> &nums)
{
    stack<int> str;
    int n = nums.size();
    vector<int> ans(nums.size(), -1); // assign initial value else will not work

    for (int i = 0; i < n; i++)
    {
        while (!str.empty() && str.top() >= nums[i])
        {
            str.pop();
        }
        if (!str.empty())
        {
            ans[i] = str.top();
        }

        str.push(nums[i]);
    }
    return ans;
}
int main()
{
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> ans = NSE(nums);

    for (auto it : ans)
    {
        cout << " " << it;
    }
    return 0;
}