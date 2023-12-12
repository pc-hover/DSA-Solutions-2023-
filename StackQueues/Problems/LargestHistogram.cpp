#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sum-of-subarray-minimums/solutions/178876/stack-solution-with-very-detailed-explanation-step-by-step/
int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    stack<int> s;
    vector<int> rightSmall(n), leftSmall(n);

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        if (s.empty())
            leftSmall[i] = 0;
        else
            leftSmall[i] = s.top() + 1; // Boundaries

        s.push(i);
    }
    // Clearing stack for re-use
    while (!s.empty())
        s.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        if (s.empty())
            rightSmall[i] = n - 1;
        else
            rightSmall[i] = s.top() - 1; // Boundaries

        s.push(i);
    }

    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxSum = max((rightSmall[i] - leftSmall[i] + 1) * arr[i], maxSum);
    }
    return maxSum;
}
int main()
{
    vector<int> nums = {2, 4};
    cout << sumSubarrayMins(nums);

    return 0;
}