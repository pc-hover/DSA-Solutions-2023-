#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string &arr)
{
    int left = 0;
    int right = arr.length() - 1;
    while (left < right)
    {
        while (left < right && !isalnum(arr[left]))
            left++;
        while (left < right && !isalnum(arr[right]))
            right--;

        if (left < right && tolower(arr[left]) != tolower(arr[right]))
            return false;

        left++;
        right--;
    }
    return true;
}
int main()
{
    string arr;
    cout << "Enter String :";
    getline(cin, arr);

    if (checkPalindrome(arr))
        cout << "String is Palindrome ";
    else
        cout << "String is not a Palindrome";

    return 0;
}