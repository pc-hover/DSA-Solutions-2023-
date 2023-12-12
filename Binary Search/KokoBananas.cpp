#include <bits/stdc++.h>
using namespace std;
int maxElement(vector<int> &piles)
{
    int maxi = INT_MIN;
    for (int i = 0; i < piles.size(); i++)
    {
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}
long long requiredTime(vector<int> &piles, int k)
{
    long long totalTime = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        totalTime += ceil((double)piles[i] / (double)k);
    }
    return totalTime;
}
int MinimumRate(vector<int> &piles, int h)
{
    int low = 1;
    int high = maxElement(piles);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (requiredTime(piles, mid) <= h)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << "Minimum Number of banas KoKo neeed to eat per hour is : " << MinimumRate(piles, h);
    return 0;
}