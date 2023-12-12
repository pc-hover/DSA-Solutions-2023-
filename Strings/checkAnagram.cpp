#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    for (int i = 0; i < s.size(); i++)
    {
        mp1[s[i]]++;
        mp2[t[i]]++;
    }
    for (auto it : mp1)
    {
        if (mp1[it.first] != mp2[it.first])
            return false;
    }
    return true;
}
// very nice ***********************************************************************************************
bool checkPalindrome_II(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> checkCount;

    for (int i = 0; i < s.size(); i++)
    {
        checkCount[s[i]]++;
        checkCount[t[i]]--;
    }
    for (auto it : checkCount)
    {
        if (it.second != 0)
            return false;
    }
    return true;
}
int main()
{
    string s = "rat";
    string t = "car";
    cout << checkPalindrome(s, t) << "\n";
    cout << checkPalindrome_II(s, t);

    return 0;
}