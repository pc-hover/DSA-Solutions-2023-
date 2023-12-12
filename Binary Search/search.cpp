
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> a, int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;

    if (a[mid] == target)
    {
        return mid + 1;
    }

    else if (target > a[mid])
    {
        return binarySearch(a, mid + 1, high, target);
    }
    else
    {
        return binarySearch(a, low, mid - 1, target);
    }
}

int main()
{
    vector<int> a = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << binarySearch(a, 0, a.size() - 1, target);
}