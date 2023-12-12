#include <bits/stdc++.h>
using namespace std;
void reverse(int low, int high, string &s)
{
    while (low <= high)
    {
        swap(s[low++], s[high--]);
    }
}
string reverseWords(string s)
{
    int n = s.length();
    int low = 0;
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        swap(s[start++], s[end--]);
    }
    for (int i = 0; i < n; i++)
    {

        if (s[i] == ' ') // characters are not in " " but inside ' '
        {
            reverse(low, i - 1, s);
            low = i + 1;
        }
    }
    reverse(low, n - 1, s);
    return s;
}
string reverseWords2(string s)
{
    int n = s.length();
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {

        if (s[i] == ' ')
        {
            end = i - 1;
            while (start < end)
            {
                swap(s[start], s[end]);
                start++;
                end--;
            }
            start = i + 1;
        }
    }
    // For Last word
    end = n - 1;
    while (start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}
int main()
{
    string s;
    getline(cin, s);
    // string ans = reverseWords(s);
    string ans2 = reverseWords(s);
    cout << endl
         << ans2;
    return 0;
}
