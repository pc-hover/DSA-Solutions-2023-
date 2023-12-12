#include <bits/stdc++.h>
using namespace std;

int main()
{
    string arr = {"puipaaspu"};
    // map<value,frequency>
    unordered_map<char, int> mp;
    // pre-compute
    for (int i = 0; i < 9; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        cout << it.first << "->" << it.second;
        cout << endl;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char num;
        cin >> num;
        // fetch
        cout << mp[num];
    }
}
