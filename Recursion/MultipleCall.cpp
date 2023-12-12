// Fibonacci
#include <iostream>
using namespace std;
int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int last = fibonacci(n - 1);
    int slast = fibonacci(n - 2);
    return last + slast;
}
int main()
{
    int n;
    cin >> n;//index 0-n
    cout << "Fibonacci sum = " << fibonacci(n);
    return 0;
}