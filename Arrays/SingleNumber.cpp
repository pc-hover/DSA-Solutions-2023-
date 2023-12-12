#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
        mp[nums[i]]++;
    int x;
    for (auto it : mp)
    {
        if (it.second == 1)
            x = it.first;
    }
    return x;
}

int main()
{
    vector<int> nums = {2, 2, 1};
    cout << singleNumber(nums);
    return 0;
}