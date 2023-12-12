#include <bits/stdc++.h>
using namespace std;
void func(int i, int sum, vector<int> &arr, vector<int> &ds, int n)
{
    if (i == n)
    {
        ds.push_back(sum);
        return;
    }
    // take it
    func(i + 1, sum + arr[i], arr, ds, n);

    // don't take it
    func(i + 1, sum, arr, ds, n);
}
int main()
{
    vector<int> ds;
    vector<int> arr = {5, 2, 1};
    func(0, 0, arr, ds, arr.size());
    sort(ds.begin(), ds.end());
    for (int i = 0; i < ds.size(); i++)
    {
        cout << " " << ds[i];
    }
    return 0;
}