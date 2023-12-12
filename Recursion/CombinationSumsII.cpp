#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void func(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++)
        {
            if (i > ind && arr[i - 1] == arr[i])
                continue;
            if (arr[i] > target)
                break;

            ds.push_back(arr[i]);
            func(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> CombinationSumII(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, target, candidates, ans, ds);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1, 1, 2, 5};
    vector<vector<int>> comb = s.CombinationSumII(v, 3);
    cout << "[ ";
    for (int i = 0; i < comb.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < comb[i].size(); j++)
        {
            cout << comb[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]";
}