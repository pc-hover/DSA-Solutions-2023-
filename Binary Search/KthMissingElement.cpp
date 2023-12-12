#include <bits/stdc++.h>
using namespace std;
int KthMissing(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high + k + 1;
}
int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << "Kth missing element is : " << KthMissing(arr, k);
    return 0;
}