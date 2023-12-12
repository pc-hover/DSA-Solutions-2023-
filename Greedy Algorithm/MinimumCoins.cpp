#include <bits/stdc++.h>
using namespace std;

vector<int> MinimumCoins(int N)
{
    int arr[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int demand = N;
    vector<int> ans;
    for (int i = 9; i >= 0; i--)
    {
        if (demand >= arr[i])
        {
            demand = demand - arr[i];
            ans.push_back(arr[i]);
            i = i + 1;
        }
        if (demand == 0)
            break;
    }
    return ans;
}

int main()
{
    int V = 8098;
    vector<int> ans = MinimumCoins(V);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}
