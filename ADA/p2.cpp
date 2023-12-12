
#include <bits/stdc++.h>
using namespace std;

// int binarySearch(vector<int> &arr, int low, int high, int target)
// {
//     if (low <= high)
//     {
//         int mid = low + (high - low) / 2;

//         if (arr[mid] == target)
//         {
//             return mid; // Element found, return index
//         }
//         else if (arr[mid] < target)
//         {
//             return binarySearch(arr, mid + 1, high, target); // Search in the right half
//         }
//         else
//         {
//             return binarySearch(arr, low, mid - 1, target); // Search in the left half
//         }
//     }

//     return -1; // Element not found
// }

int linearSearch(const vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == target)
        {
            return i; // Element found, return index
        }
    }
    return -1; // Element not found
}

int main()
{
    int n;
    cout << "Enter the length of array: ";
    cin >> n;

    vector<int> arr(n); // Resize the vector to hold n elements

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    int result = linearSearch(arr, target);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

// linear search

// int main()
// {
//     vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
//     int target = 7;
//     int result = linearSearch(arr, target);

//     if (result != -1)
//     {
//         cout << "Element found at index: " << result << endl;
//     }
//     else
//     {
//         cout << "Element not found in the array." << endl;
//     }

//     return 0;
