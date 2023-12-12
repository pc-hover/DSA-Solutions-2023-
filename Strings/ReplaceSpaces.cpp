#include <iostream>
#include <string.h>
using namespace std;

int replaceSpaces(string &s)
{
    int spaceCount = 0, i;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            spaceCount++;
    }
    // i=s.length();
    // trim end spaces or trailing spaces
    while (s[i - 1] == ' ')
    {
        i--;
        spaceCount--;
    }
    // i=s.length();
    int new_length = i + spaceCount * 2 + 1;

    int index = new_length - 1;
    s[index] = '\0';
    index--;

    for (int j = i - 1; j >= 0; j--)
    {
        if (s[j] == ' ')
        {
            s[index] = '0';
            s[index - 1] = '2';
            s[index - 2] = '%';
            index = index - 3;
        }
        else
        {
            s[index] = s[j];
            index--;
        }
    }
    return new_length;
}
// string replaceSpaces(string &s)
// {
//     string temp;
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == ' ')
//         {
//             temp.push_back('@');
//             temp.push_back('4');
//             temp.push_back('0');
//         }
//         else
//         {
//             temp.push_back(s[i]);
//         }
//     }
//     return temp;
// }
int main()
{
    string s;
    getline(cin, s);
    int n = replaceSpaces(s);
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }

    return 0;
}
