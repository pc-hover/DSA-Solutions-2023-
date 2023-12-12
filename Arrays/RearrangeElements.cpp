#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> pos, neg;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }
        if (pos.size() > neg.size())
        {
            for (int i = 0; i < neg.size(); i++)
            {
                nums[i * 2] = pos[i];
                nums[i * 2 + 1] = neg[i];
            }
            int index = neg.size() * 2;
            for (int i = neg.size(); i < pos.size(); i++)
            {
                nums[index] = pos[i];
                index++;
            }
        }
        else
        {
            for (int i = 0; i < pos.size(); i++)
            {
                nums[i * 2] = pos[i];
                nums[i * 2 + 1] = neg[i];
            }
            int index = pos.size() * 2;
            for (int i = pos.size(); i < neg.size(); i++)
            {
                nums[index] = neg[i];
                index++;
            }
        }
        return nums;
    }
    // TC -> O(N)
    // SC ->O(N)
    // vector<int> rearrangeArray(vector<int> &nums)
    // {
    //     vector<int> nums(n, 0);
    //     int pos = 0;
    //     int neg = 1;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (nums[i] > 0)
    //         {
    //             nums[pos] = nums[i];
    //             pos += 2;
    //         }
    //         else
    //         {
    //             nums[neg] = nums[i];
    //             neg += 2;
    //         }
    //     }
    //     return nums;
    // }
};
int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    Solution s;
    vector<int> ans = s.rearrangeArray(nums);
    for (auto it : ans)
    {
        cout << " " << it;
    }

    return 0;
}