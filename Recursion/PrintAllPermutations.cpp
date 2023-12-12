#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void func(vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans, int freq[])
    {
        if (arr.size() == ds.size())
        {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (!freq[i])
            {
                ds.push_back(arr[i]);
                freq[i] = 1;
                func(ds, arr, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> PrintPermutations(vector<int> &arr)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[arr.size()] = {0};
        func(ds, arr, ans, freq);

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
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    ans = s.PrintPermutations(nums);
    s.display(ans);

    return 0;
}