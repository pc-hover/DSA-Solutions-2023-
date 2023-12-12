#include <bits/stdc++.h>
using namespace std;

int getIndex(vector<int> &arr, int low, int high)
{
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= arr[low] && i <= high - 1) //!!
            i++;
        while (arr[j] > arr[low] && j >= low + 1) //!!
            j--;

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return i;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[low];
        int pIndex = getIndex(arr, low, high);

        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}
int main()
{
    vector<int> nums = {4, 3, 8, 4, 6, 5};

    cout << "Entered array:";
    for (auto it : nums)
    {
        cout << " " << it;
    }
    quickSort(nums, 0, nums.size() - 1);
    cout << "\nSorted Array: ";
    for (auto it : nums)
    {
        cout << " " << it;
    }
}
