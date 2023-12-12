#include <bits/stdc++.h>
using namespace std;

int NumberOfRotations(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int minsofar = INT_MAX;
    int count = -1;
    if(nums[low]<nums[n-1]) return 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[low] <= nums[high])
        {
            if (minsofar > nums[low])
            {
                minsofar = nums[low];
                count = low;
            }
            break;
        }
        if (nums[low] <= nums[mid])
        {

            if (minsofar > nums[low])
            {
                minsofar = nums[low];
                count = low;
            }
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            if (minsofar > nums[low])
            {
                minsofar = nums[low];
                count = low;
            }
        }
    }
    return count;
}
int main()
{
    vector<int> nums = {27, 31, 43, 45, 46, 5, 11, 13, 18, 19, 20};
    cout << "Number of Rotations = " << NumberOfRotations(nums);
    return 0;
}
