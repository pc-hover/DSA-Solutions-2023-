#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> arr, int n, int x)
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

int main()
{
    vector<int> arr = {};
    int x = 3;
    cout << "Lower Bound = " << lowerBound(arr, x, arr.size());

    return 0;
}