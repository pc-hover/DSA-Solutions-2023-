#include <bits/stdc++.h>
using namespace std;

void printF(int i, vector<int> &ds, vector<int> arr, int n)
{
    if (i == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }

        if (ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // take or pick a particular index in subsequence
    ds.push_back(arr[i]);
    printF(i + 1, ds, arr, n);
    ds.pop_back();

    printF(i + 1, ds, arr, n);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "r", stdout);
    // #endif

    vector<int> arr = {5, 1, 3};
    vector<int> ds;
    printF(0, ds, arr, arr.size());
    return 0;
}