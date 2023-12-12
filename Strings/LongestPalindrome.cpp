#include <bits/stdc++.h>
using namespace std;

// TC ->O(N^2)
// SC -> O(1)
string LongestPalindrome(string s)
{
    int n = s.length();
    int start = 0; // starting point of Longest Substring
    int end = 1;   // here end denotes the size of the longest Palindrome substring

    int low, high;
    for (int i = 0; i < n; i++)
    {
        // checking for even substring
        low = i - 1;
        high = i;

        while (low >= 0 && high < n && s[low] == s[high])
        {
            // check if new plaindrome length is greater then last one that is end
            if (end < high - low + 1)
            {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }

        // checking for odd substring
        low = i - 1;
        high = i + 1;

        while (low >= 0 && high < n && s[low] == s[high])
        {
            // check if new plaindrome length is greater then last one that is end
            if (end < high - low + 1)
            {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }
    }
    return s.substr(start, end); // parameters of substr are (start,length)
}
// bool checkPalindrome(string s)
// {
//     int start = 0;
//     int end = s.length() - 1;
//     while (start < end)
//     {
//         if (s[start] != s[end])
//             return false;

//         start++;
//         end--;
//     }
//     return true;
// }
// string LongestPalindrome(string s)
// {
//     int n = s.length();
//     if (n == 1)
//         return s;
//     string longest = "";
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             string subString = s.substr(i, j - i + 1);//substr(start,length that needs to be added after start)
//             if (checkPalindrome(subString) && longest.length() < subString.length())
//             {
//                 longest = subString;
//             }
//         }
//     }
//     return longest;
// }
int main()

{
    string s = "geeksskeeg";

    string ans = LongestPalindrome(s);
    cout << ans;

    return 0;
}