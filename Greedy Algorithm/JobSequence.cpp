#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;
    int dead;
    int profit;
};
class Solution
{
public:
    bool static comparison(Job a, Job b)
    {
        return (a.profit > b.profit);
    }

    pair<int, int> JobSequence(Job arr[], int n)
    {
        sort(arr, arr + n, comparison);
        int max_deadline = arr[0].dead;
        for (int i = 1; i < n; i++)
        {
            max_deadline = max(max_deadline, arr[i].dead);
        }
        int slot[max_deadline + 1];

        for (int i = 0; i <= max_deadline; i++)
            slot[i] = -1;

        int countJobs = 0;
        int jobProfit = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = arr[i].id;
                    jobProfit = jobProfit + arr[i].profit;
                    countJobs++;
                    break;
                }
            }
        }
        return make_pair(countJobs, jobProfit);
    }
};
int main()
{
    int n = 4;
    Job arr[n] = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};

    Solution ob;

    pair<int, int> ans = ob.JobSequence(arr, n);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}