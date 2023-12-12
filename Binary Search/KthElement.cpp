#include <bits/stdc++.h>
using namespace std;

double medianOfSortes(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1 + n2;

    int i = 0;
    int j = 0;

    int count = 0;

    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int ind1el = -1;
    int ind2el = -1;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            if (count == ind1)
            {
                ind1el = arr1[i];
            }
            if (count == ind2)
            {
                ind2el = arr1[i];
            }
            count++;
            i++;
        }
        else
        {
            if (count == ind1)
            {
                ind1el = arr2[j];
            }
            if (count == ind2)
            {
                ind2el = arr2[j];
            }
            count++;
            j++;
        }
    }
    while (i < n1)
    {
        if (count == ind1)
        {
            ind1el = arr1[i];
        }
        if (count == ind2)
        {
            ind2el = arr1[i];
        }
        count++;
        i++;
    }
    while (j < n2)
    {
        if (count == ind1)
        {
            ind1el = arr2[j];
        }
        if (count == ind2)
        {
            ind2el = arr2[j];
        }
        count++;
        j++;
    }

    if (n % 2 == 1)
    {
        return (double)ind2el;
    }

    return (double)((double)ind1el + (double)ind2el) / 2.0;
}
int main()
{
    vector<int> arr1 = {1, 3, 8, 10, 11};
    vector<int> arr2 = {1, 2, 12};

    cout << "MEDIAN OF THE 2 SORTED ARRAYS IS " << medianOfSortes(arr1, arr2);

    return 0;
}