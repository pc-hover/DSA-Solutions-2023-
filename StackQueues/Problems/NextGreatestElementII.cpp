#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:

    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> st;
        for (int i = (2 * n) - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[i % n] >= st.top())
            {
                st.pop();
            }
            if (i < n)
            {
                if (!st.empty())
                {
                    ans[i] = st.top();
                }
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 3};//2 3 4 -1 4 
    vector<int> ans = s.nextGreaterElements(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}