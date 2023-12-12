#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // Precompute
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        // character ascii value minus ascii{will provide index}
        hash[s[i] - 'a'] += 1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // fetch
        cout << hash[c - 'a'];
    }
}