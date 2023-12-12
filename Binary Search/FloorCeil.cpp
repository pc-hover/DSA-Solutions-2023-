
#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    pair<int, int> ans;
    sort(arr, arr + n);
    int low = 0;
    int high = n - 1;
    int ans1 = -1;
    int ans2 = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
        {
            low = mid + 1;
            ans1 = arr[mid];
        }
        else
        {
            high = mid - 1;
        }
    }
    ans.first = ans1;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            high = mid - 1;
            ans2 = arr[mid];
        }
        else
        {
            low = mid + 1;
        }
    }
    ans.second = ans2;
    return ans;
}

int main()
{
    int a[] = {4, 3, 8, 4, 7, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int target = 8;
    pair<int, int> ans = getFloorAndCeil(a, n, target);
    cout << ans.first;
    cout << endl;
    cout << ans.second;
    return 0;
}