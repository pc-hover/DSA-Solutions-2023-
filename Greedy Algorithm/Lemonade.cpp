#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    int five = 0;
    int tens = 0;
    for (int i = 0; i < bills.size(); i++)
    {

        if (bills[i] == 5)
        {
            five++;
        }
        if (bills[i] == 10)
        {
            tens++;
            five--;
        }
        else
        {
            if (bills[i] == 20)
            {
                if (tens > 0)
                {
                    tens--;
                    five--;
                }
                else
                {
                    five -= 3;
                }
            }
        }
        if (five < 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> bills = {5, 5, 10, 10, 20};
    cout << lemonadeChange(bills);

    return 0;
}