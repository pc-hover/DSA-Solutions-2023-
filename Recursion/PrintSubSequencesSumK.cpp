#include <iostream>
#include <vector>
using namespace std;
// Printing Subsequence whose Sum is K
void func(int i, vector<int> &ds, int sum, vector<int> arr)
{

    if (i == arr.size())
    {
        if (sum == 2)
        {
            for (auto it : ds)
            {
                cout << " " << it;
            }
            cout << endl;
        }
        return;
    }

    // take a[i] in stack
    ds.push_back(arr[i]);
    func(i + 1, ds, sum + arr[i], arr);

    // Do not take a[i] inside stack
    ds.pop_back();
    func(i + 1, ds, sum, arr);
}
// Printing only one Subsequence whose Sum is K
bool func2(int i, vector<int> &ds, int sum, vector<int> arr)
{

    if (i == arr.size())
    {
        // condition satisfied
        if (sum == 2)
        {
            for (auto it : ds)
            {
                cout << " " << it;
            }
            cout << endl;
            return true;
        }
        // condition not satisfied
        else
            return false;
    }

    // take a[i] in stack
    ds.push_back(arr[i]);
    if ((func2(i + 1, ds, sum + arr[i], arr)) == true)
    {
        return true;
    }

    // Do not take a[i] inside stack
    ds.pop_back();
    if ((func2(i + 1, ds, sum, arr) == true))
    {
        return true;
    }
    return false;
}
//Count the Number of Subsequences which give sum k
int func3(int i, int sum, vector<int> arr)
{

    if (i == arr.size())
    {
        // condition satisfied
        if (sum == 2)
        {
            return 1;
        }
        // condition not satisfied
        else
            return 0;
    }

    // take a[i] in stack

    int lt = func3(i + 1, sum + arr[i], arr);

    // Do not take a[i] inside stack

    int rt = func3(i + 1, sum, arr);
    return lt + rt;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> ds;
    int k = 0;
    func(0, ds, 0, arr);
    func2(0, ds, 0, arr);
    cout << endl
         << "Number of count = " << func3(0, 0, arr);

    return 0;
}
 