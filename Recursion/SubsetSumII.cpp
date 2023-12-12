#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void func(int ind, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans)
    {
        ans.push_back(ds);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[i - 1])
            {
                continue;
            }
            ds.push_back(nums[i]);
            func(i + 1, ds, nums, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> SubsetSumII(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        func(0, ds, nums, ans);

        return ans;
    }
    void display(const vector<vector<int>> &ans)
    {
        if (ans.empty())
        {
            cout << "{}" << endl;
            return;
        }

        for (const auto &vec : ans)
        {
            cout << "{ ";
            for (const auto &it : vec)
            {
                cout << it << " ";
            }
            cout << "}" << endl;
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> answer;
    vector<int> nums = {1, 2, 2};
    answer = s.SubsetSumII(nums);
    s.display(answer);
    return 0;
}