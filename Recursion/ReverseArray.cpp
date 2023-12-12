#include <iostream>
using namespace std;
void display(int x[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}
void f1(int a[], int i, int n) // using single variable
{
    if (i >= n / 2)
    {
        return;
    }
    swap(a[i], a[n - 1 - i]);
    f1(a, i + 1, n);
}
void f2(int a[], int l, int r) // using s2 pointer appproach
{
    if (l >= r)
    {
        return;
    }
    swap(a[l], a[r]);
    l = l + 1;
    r = r - 1;
    f2(a, l, r);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    f1(arr, 0, n);
    display(arr, n);

    f2(arr, 0, n - 1);
    display(arr, n);
    return 0;
}