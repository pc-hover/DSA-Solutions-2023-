#include <bits/stdc++.h>
using namespace std;

void Insertion_Sort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i <= n - 2; i++)
    {
        int minIndex = i;
        for (int j = i; j < n; j++)
        {
            if (nums[j] < nums[i])
            {
                minIndex = j;
            }
        }
        swap(nums[minIndex], nums[i]);
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
    Insertion_Sort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << " " << nums[i];
    }
    return 0;
}