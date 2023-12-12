// 1.Print Names 5 times
// 2.Print 1-N numbers
// 3.Print N-1 numbers
// 4.Print 1-N numbers using Backtrack method
// 5.Print N-1 numbers using Backtrack method
#include <iostream>
using namespace std;
// TC--> O(n)
// SC--> O(n)
void func1(int a)
{
    if (a == 5)
    {
        return;
    }

    cout << "Priyanshu" << endl;
    func1(a + 1);
}
void func2(int n, int b)
{
    if (b > n)
    {
        return;
    }
    cout << b << " ";
    func2(n, b + 1);
}
void func3(int n)
{

    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    func3(n - 1);
}
void func4(int n, int i)
{
    if (i < 1)
    {
        return;
    }
    func4(n, i - 1);
    cout << i << endl;
}
void func5(int n, int i)
{
    if (i > n)
    {
        return;
    }
    func5(n, i + 1);
    cout << i << endl;
}
int main()
{
    func1(0);
    func2(5, 1);
    cout << endl;
    func3(5);
    cout << endl;
    func4(3, 3);
    func5(3, 1);
    return 0;
}