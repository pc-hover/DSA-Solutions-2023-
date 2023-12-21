#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    // 1 queue and a visited array
    // 2 push rotten in queue and visit them
    // 3 take front out {{r,c},time} and push all four directions inside queue
    //-check1 outofbound
    //-check2 already visited
    //-check3 either 0 or 2 initially inside grid
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q; //{{r,c},time}
    int visit[n][m];
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                visit[i][j] = 2;
                q.push({{i, j}, time});
            }
        }
    }
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int tm = q.front().second;
        time = max(time, tm);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visit[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, tm + 1});
                visit[nrow][ncol] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && visit[i][j] != 2)
            {
                return -1;
            }
        }
    }
    return time;
}

int main()
{
    vector<vector<int>> grid = {{0, 2}};
    cout << orangesRotting(grid);
    return 0;
}