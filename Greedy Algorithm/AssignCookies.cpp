#include <bits/stdc++.h>
using namespace std;

bool comparator(int a, int b)
{
    return a > b;
}
int findContentChildren(vector<int> &g, vector<int> &s)
{

    if (s.size() == 0)
    {
        return 0;
    }
    sort(g.begin(), g.end(), comparator);
    sort(s.begin(), s.end(), comparator);

    int count = 0;
    int i = 0;
    int j = 0;
    while (i < g.size() && j < s.size())
    {
        if (g[i] <= s[j])
        {
            count = count + 1;
            j++;
            i++;
        }

        else
        {
            i++;
        }
    }

    return count;
}

int main()
{

    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << findContentChildren(g, s);
}