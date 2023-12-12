#include <bits/stdc++.h>
using namespace std;
void func(int i, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr, int n)
{
    if (i == n)
    {
        ans.push_back(ds);
        return;
    }

    // take
    ds.push_back(arr[i]);
    func(i + 1, ds, ans, arr, n);
    ds.pop_back();

    // not take
    func(i + 1, ds, ans, arr, n);
}
void display(vector<vector<int>> &ans)
{
    if (ans.empty())
    {
        cout << "{}";
        return;
    }
    for (const auto &vec : ans)
    {
        cout << "{ ";
        for (const auto &it : vec)
        {
            cout << it << " ";
        }
        cout << " }";
    }
}
int main()
{
    vector<int> ds;
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> ans;
    vector<vector<int>> ans2;
    func(0, ds, ans, arr, arr.size());
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        ans2.push_back(*it);
    }
    display(ans2);
    return 0;
}
