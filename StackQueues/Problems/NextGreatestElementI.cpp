#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
//TC -> O(N+M)
//SC -> O(N)
    vector<int> nextGreaterElements(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> mp; // storing <element,nge element>
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums2[i] >= st.top())
            {
                st.pop();
            }
            if (!st.empty())
                mp[nums2[i]] = st.top();

            else
            {
                mp[nums2[i]] = -1;
            }

            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = s.nextGreaterElements(nums1, nums2);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}