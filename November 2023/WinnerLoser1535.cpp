#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int winner = arr[0];
        int win_count = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] < winner)
            {
                win_count++;
            }
            else
            {
                winner = arr[i];
                win_count = 1;
            }
            if (win_count == k)
            {
                return winner;
            }
        }
        // if k > arr.size() if nothing returned from here we know that winner will be the max number from the array

        // intuition behind this is in every iteration of whole array it is guarenteed that max will win each time where else for else their is not guarentee and will eventualy loose from amx in each whole iteration the the array. Hence max(arr) will be the answer incase k>arr.size();
        return winner;
    }
};
int main()
{
    vector<int> arr = {1, 11, 22, 33, 44, 55, 66, 77, 88, 99};
    Solution s;
    int k = 1000000000;
    cout << s.getWinner(arr, k);
}