#include <bits/stdc++.h>
using namespace std;

bool SearchinRotatedII(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    // first check which part of array is sorted
    // check if the target is in range of sorted
    // if yes eleminate non sorted partial_sortig no eliminate sorted part
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[mid] == nums[low] && nums[mid] == nums[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }

        if (nums[low] <= nums[mid])
        {
            if (target >= nums[low] && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {

            if (target >= nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}
int main()
{
    vector<int> arr = {1, 2, 3, 7};
    int k = 1;
    int ans = SearchinRotatedII(arr, k);
    cout << "Target in Array = " << ans;
    return 0;
}