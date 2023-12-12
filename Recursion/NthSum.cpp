#include <iostream>
using namespace std;
// 2 ways to solve this problem
// 1.Prameterised
void func1(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    func1(i - 1, sum + i);
}
// 2.Functional approach
int func2(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + func2(n - 1);
}
int main()
{
    func1(3, 0);
    cout << endl
         << func2(5);
    return 0;
}