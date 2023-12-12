#include <bits/stdc++.h>
using namespace std;
bool rotateString(string s, string t)
{
    if (s.size() != t.size())
        return false;

    string ans = s + s;
    if (ans.find(t) != -1)
        return true;

    return false;
}
int main()
{
    string s = "abcde";
    string t = "abced";
    cout << "String Rotated : " << rotateString(s, t);

    return 0;
}