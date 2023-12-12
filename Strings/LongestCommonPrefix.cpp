#include <bits/stdc++.h>
using namespace std;
string getCommonStr(string a, string b)
{
    int i = 0;
    if (a[0] != b[0])
        return "";
    while (i < a.length() && i < b.length())
    {
        if (a[i] != b[i])
        {

            break;
        }

        else
        {
            i++;
        }
    }
    return a.substr(0, i);
}
string LongestCommonPrefix(vector<string> str)
{
    string CommonString = "";
    for (int i = 0; i <= str.size() - 2; i++)

    {

        if (CommonString.length() > getCommonStr(str[i], str[i + 1]).length() || CommonString.length() == 0)
        {
            CommonString = getCommonStr(str[i], str[i + 1]);
        }
        if ((getCommonStr(str[i], str[i + 1])) == "")
            return "";
    }
    return CommonString;
}

string longestCommonPrefix(string arr[], int n)
{
    // take temp_prefix string and assign first element of
    // arr : a.
    string result = arr[0];
    int len = result.length();

    // Iterate for rest of element in string.
    for (int i = 1; i < n; i++)
    {
        // .find() return index of that substring from
        // string.
        while (arr[i].find(result) != 0)
        {

            // update matched substring prefx
            result = result.substr(0, len - 1);
            len--;

            // check for empty case. direct return if true..
            if (result.empty())
            {
                return "-1";
            }
        }
    }
    return result;
}
int main()
{
    vector<string> s = {"flower", "flower", "flight"};
    cout << LongestCommonPrefix(s);

    return 0;
}