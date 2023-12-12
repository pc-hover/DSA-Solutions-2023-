#include <iostream>
using namespace std;
// 2 ways to solve this problem
// 1.Prameterised
void func1(int i, int fact)
{
    if (i < 1)
    {
        cout << fact;
        return;
    }
    func1(i - 1, fact * i);
}
// 2.Functional approach
// TC-->O(n)
// SC-->O(n)

int func2(int n)
{
    if (n < 1)
    {
        return 1;
    }
    return n * func2(n - 1);
}
int main()
{
    func1(3, 1);
    cout << endl
         << func2(5);
    return 0;
}