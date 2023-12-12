#include <bits/stdc++.h>
using namespace std;
bool checkDays(vector<int> &weights, int capacity, int days)
{
    int count = 0;
    int weightSum = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (weightSum + weights[i] > capacity)
        {

            count += 1;
            // weightSum = 0;
            // i = i - 1;
            // or
            weightSum = weights[i];
        }
        else
        {
            weightSum += weights[i];
        }
    }
    count += 1;
    if (count <= days)
    {
        return true;
    }
    return false;
}
int LeastCapacity(vector<int> &weights, int days)
{

    int n = weights.size();
    if (n < days)
        return -1;
    int totalweights = accumulate(weights.begin(), weights.end(), 0);
    int maxi = *max_element(weights.begin(), weights.end());
    // int maxi = INT_MIN;
    // int totalweights = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     maxi = max(maxi, weights[i]);
    //     totalweights += weights[i];
    // }
    int low = maxi;
    int high = totalweights;
    int capacity = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (checkDays(weights, mid, days))
        {
            capacity = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return capacity; // or return low;
}
int main()
{
    vector<int> arr = {3, 2, 2, 4, 1, 4};
    int days = 3;
    cout << LeastCapacity(arr, days);
}