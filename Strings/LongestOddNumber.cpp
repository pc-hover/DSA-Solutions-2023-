#include <bits/stdc++.h>
using namespace std;

string LongestOddNumber(string nums)
{
    int flag = 0;
    int n = nums.length();
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] % 2 == 1)
        {
            nums.erase(i + 1, n - 1);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        return "";
    }
    return nums;
}
int main()
{
    string nums = "35427";
    cout << LongestOddNumber(nums);
    return 0;
}