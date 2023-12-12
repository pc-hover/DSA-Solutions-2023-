#include <iostream>
using namespace std;

bool func(string &str, int i, int n)
{
    if (i >= n / 2)
    {
        return 1;
    }
    if (str[i] != str[n - i - 1])
    {
        return 0;
    }
    else
    {
        func(str, i + 1, n);
    }
}

int main()
{
    string a = {"MADSAM"};
    cout << func(a, 0, a.size());
    return 0;
}