#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &bloomDay, int day, int m, int k)
{
    int ct = 0, ans = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= day)
            ct++;

        else
        {
            ans += (ct / k);
            ct = 0;
        }
    }
    ans += (ct / k);
    if (ans >= m)
    {
        return true;
    }

    return false;
}
int minBouqets(vector<int> &bloomDay, int m, int k)
{
    if (bloomDay.size() < (double)m * (double)k)
        return -1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        maxi = max(maxi, bloomDay[i]);
        mini = min(mini, bloomDay[i]);
    }
    int low = mini;
    int high = maxi;
    int ans = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(bloomDay, mid, m, k))
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
    vector<int> BloomDays = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    cout << "Minimum Number of daysto satisfy requirements " << minBouqets(BloomDays, m, k);
    return 0;
}