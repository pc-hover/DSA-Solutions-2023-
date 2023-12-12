#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &arr, int n, int x)
{

    int ans = n;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
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
int upperBound(vector<int> &arr, int n, int x)
{
    int ans = n;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
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
vector<int> firstLastOccurence(vector<int> &nums, int n, int target)
{
    int lb = lowerBound(nums, nums.size(), target);
    if (lb == nums.size() || nums[lb] != target)
    {
        return {-1, -1};
    }
    return {lb, upperBound(nums, nums.size(), target) - 1};
}
int main()
{
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int x = 8;
    vector<int> ans = firstLastOccurence(arr, arr.size(), x);
    for (int i = 0; i < 2; i++)
    {
        cout << " " << ans[i];
    }

    return 0;
}