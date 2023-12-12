#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int InversionsArray(vector<int> arr)
    {
        int n = arr.size();
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[i])
                {
                    temp++;
                }
            }
        }
        return temp;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {5, 4, 3, 2, 1};
    cout << " NUmbers of Inversions = " << s.InversionsArray(nums);
    return 0;
}
