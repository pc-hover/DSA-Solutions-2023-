#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    cout << s.searchInsert(nums, target) << endl;
    vector<int>::iterator lower, upper;
    lower = lower_bound(nums.begin(), nums.end(), target);
    upper = upper_bound(nums.begin(), nums.end(), target);
    cout << "lower_bound for 6 at index " << lower - nums.begin();
    cout << endl;
    cout << "upper_bound for 6 at index " << upper - nums.begin();

    return 0;
}