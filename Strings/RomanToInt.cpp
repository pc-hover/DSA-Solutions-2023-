#include <bits/stdc++.h>
using namespace std;
int getValue(char c)

{
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;

    return 0;
}

int RomanToInt(string s)
{
    int n = s.length();
    int sum = 0;
    int value = 0;
    for (int i = 0; i < n;)
    {
        if (i == n - 1 || getValue(s[i]) >= getValue(s[i + 1]))
        {
            value = getValue(s[i]);
            i++;
        }
        else
        {
            value = getValue(s[i + 1]) - getValue(s[i]);
            i = i + 2;
        }
        sum += value;
    }

    return sum;
}

int main()
{
    string s = "MCMXCIV";

    cout << RomanToInt(s);

    return 0;
}
