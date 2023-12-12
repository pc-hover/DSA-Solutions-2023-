#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sum-of-subarray-minimums/solutions/178876/stack-solution-with-very-detailed-explanation-step-by-step/
int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    stack<int> s1, s2;
    vector<int> nse(n), pse(n);
    for (int i = 0; i < n; i++)
    {
        nse[i] = n - i - 1;
        pse[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        while (!s1.empty() && arr[s1.top()] > arr[i])
        {
            nse[s1.top()] = i - s1.top() - 1;
            s1.pop();
        }
        s1.push(i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s2.empty() && arr[s2.top()] >= arr[i])
        {
            pse[s2.top()] = s2.top() - i - 1;
            s2.pop();
        }
        s2.push(i);
    }
    long long ans = 0;
    long long mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        ans += ((long long)arr[i] * (nse[i] + 1) * (pse[i] + 1));
        ans = ans % mod;
    }
    return (int)ans;
}
int main()
{
    vector<int> nums = {3, 1, 2, 4};
    cout << sumSubarrayMins(nums);

    return 0;
}