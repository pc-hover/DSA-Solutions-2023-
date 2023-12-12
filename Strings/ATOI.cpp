#include <bits/stdc++.h>
using namespace std;

int atoi(string s)
{
    int n = s.length();

    if (n == 0)
        return 0;
    int i = 0;
    // Remove white spaces
    while (i < n && s[i] == ' ')
        i++;

    s = s.substr(i);

    // check for the sign
    int sign = 1;
    if (s[0] == '-')
    {
        sign = -1;
    }
    // int min and max conditions
    int max = INT_MAX;
    int min = INT_MIN;
    // change i if sign is their

    i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    long ans = 0; //!!!!!!!!!!!
    while (i < n)
    {
        if (!isdigit(s[i]) || s[i] == ' ')
        {
            break;
        }

        ans = ans * 10 + s[i] - '0';

        if (-1 * ans < min && sign == -1)
            return min;
        if (ans > max && sign == 1)
            return max;

        i++;
    }
    return (int)(ans * sign);
}
int main()
{
    string s = "4193 with words";
    cout << "ATOI == " << atoi(s);
}