
#include <bits/stdc++.h>
using namespace std;
int checthresholdSum(vector<int> &nums, int threshold)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += ceil((double)(nums[i]) / (double)(threshold));
    }

    return sum;
}
int SmallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    if (n > threshold)
        return -1;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(nums[i], maxi);
    }
    int low = 1;
    int high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (checthresholdSum(nums, mid) <= threshold)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Single Divisor in Array is : " << SmallestDivisor(nums, 8);
    return 0;
}