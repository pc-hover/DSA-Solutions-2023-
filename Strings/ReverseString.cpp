#include <iostream>
using namespace std;

void reverseString(string &arr)
{
    int start = 0;
    int end = arr.length() - 1;
    while (start < end)
    {
        swap(arr[start++], arr[end--]);
    }
}
int main()
{
    string arr;
    getline(cin, arr);
    reverseString(arr);
    cout << "Reversed String is " << arr;
    return 0;
}