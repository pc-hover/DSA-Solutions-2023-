#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int funct(vector<int> &nums, int max)
{
    int arrayCount = 1;
    int subArraySum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (subArraySum + nums[i] <= max)
        {
            subArraySum += nums[i];
        }
        else
        {
            arrayCount++;
            subArraySum = nums[i];
        }
    }
    return arrayCount;
}

int splitArray(vector<int> &nums, int m)
{
    int n = nums.size();
    if (m > n)
        return -1;

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int arrayCount = funct(nums, mid);

        if (arrayCount <= m)
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
    vector<int> nums = {7, 2, 5, 10, 8};
    int subArrays = 2;
    cout << splitArray(nums, subArrays);

    return 0;
}