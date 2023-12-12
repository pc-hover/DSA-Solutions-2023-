#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int funct(vector<int> &arr, int max)
{
    int studentCount = 1;
    int pageCount = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (pageCount + arr[i] <= max)
        {
            pageCount += arr[i];
        }
        else
        {
            studentCount++;
            pageCount = arr[i];
        }
    }
    return studentCount;
}
int MinofMaxPages(vector<int> &arr, int m, int n)
{
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int studentCount = funct(arr, mid);

        if (studentCount <= m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int numberOfStudents = 2;
    cout << MinofMaxPages(arr, numberOfStudents, arr.size());

    return 0;
}