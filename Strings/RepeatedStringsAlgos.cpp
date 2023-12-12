#include <bits/stdc++.h>
using namespace std;
int repeatedStringsMatch(string a, string b)
{
    int alen = a.length();
    int blen = b.length();

    int n = blen / alen;
    int cnt = n;

    string na = "";
    while (cnt--)
    {
        na = na + a;
    }
    // n*a
    if (na.find(b) != string::npos)
    {
        return n;
    }
    // For both cases
    //  sufialen + n*a
    //  n*a + prefialen
    na = na + a;
    if (na.find(b) != string::npos)
    {
        return n + 1;
    }

    // sufialen + n*a + prefialen
    na = na + a;
    if (na.find(b) != string::npos)
    {
        return n + 2;
    }

    return -1;
}
int main()
{
    string a = "abc";
    string b = "cabcabca";

    cout << repeatedStringsMatch(a, b);
}