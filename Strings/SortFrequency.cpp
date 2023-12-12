#include <bits/stdc++.h>
using namespace std;
// int calculateFrequency(string s, char c)
// {
//     int count = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == c)
//         {
//             count++;
//         }
//     }
//     return count;
// }
static bool comparator(pair<int, char> a, pair<int, char> b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second - 'a' < b.second - 'a';
    }
}
//  string frequencySort(string s)
// {
//     int n = s.size();
//     vector<pair<int, char>> vp;
//     for (int i = 0; i < n; i++)
//     {
//         vp.push_back(make_pair(calculateFrequency(s, s[i]), s[i]));
//     }
//     sort(vp.begin(), vp.end(), comparator);
//     for (int i = 0; i < n; i++)
//     {
//         s[i] = vp[i].second;
//     }
//     return s;
// }

string frequencySort(string s)
{
    int n = s.size();
    vector<pair<int, char>> hash('z' + 1, {0, 0}); /*hash table of length 0 -- 122*/
    for (char ch : s)
    {
        hash[ch] = {hash[ch].first + 1, ch};
    }
    sort(hash.begin(), hash.end());

    s = "";
    for (auto p : hash)
    {
        s = string(p.first, p.second) + s;
    }
    return s;
}
int main()
{
    string s = "loveleetcode";
    string ans = frequencySort(s);
    for (auto it : ans)
    {
        cout << it;
    }
}