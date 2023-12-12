#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<char, char> hash1;
    unordered_map<char, char> hash2;

    for (int i = 0; i < s.size(); i++)
    {
        if (hash1[s[i]] == 0)
        {
            hash1[s[i]] = t[i];
        }
        else if (hash1[s[i]] != t[i])
            return false;

        if (hash2[t[i]] == 0)
        {
            hash2[t[i]] = s[i];
        }
        else if (hash2[t[i]] != s[i])
            return false;
    }
    return true;
}
int main()
{
    string s = "foo";
    string t = "bar";
    cout << "isomorphic : " << isIsomorphic(s, t);

    return 0;
}