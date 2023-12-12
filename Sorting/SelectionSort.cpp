#include <bits/stdc++.h>
using namespace std;

void Selection_sort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (nums[j] < nums[j - 1])
            {
                swap(nums[j], nums[j - 1]);
            }
        }
    }
}
int main()
{
    vector<int> nums = {
        13,
        46,
        24,
        52,
        20,
    };
    Selection_sort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << " " << nums[i];
    }
    return 0;
}