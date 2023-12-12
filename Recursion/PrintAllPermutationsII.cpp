#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void func(int ind, vector<int> &arr)
    {
        if (ind == arr.size())
        {
            display(arr);
            return;
        }
        for (int i = ind; i < arr.size(); i++)
        {
            swap(arr[ind], arr[i]);
            func(ind + 1, arr);
            swap(arr[ind], arr[i]);
        }
    }
    void display(vector<int> &nums)
    {
        for (auto it : nums)
        {
            cout << " " << it;
        }
        cout << endl;
    }
};
int main()
{
    Solution s;
    vector<int> array = {1, 2, 3};
    s.func(0, array);
    return 0;
}