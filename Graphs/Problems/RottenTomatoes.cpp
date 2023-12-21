#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int count = 0;
    int visit[grid.size()][grid[0].size()] = {0};
    queue<pair<int, int>> q;
    for (int i = 0, j = 0; i < grid.size(), j < grid[0].size(); i++, j++)
    {
        if (grid[i][j] == 2)
        {
            q.push({i, j});
            visit[i][j] = 1;
        }
    }
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            count++;
            pair<int, int> node;
            node = q.front();
            int a, b;
            a = node.first;
            b = node.second;
            q.pop();
            if (a < 0 && b < 0 && a > grid.size() && b < grid[0].size())
            {
                continue;
            }
            visit[a][b] = 1;
            if (!visit[a][b] && grid[a][b] != 0)
            {
                q.push({a - 1, b});
                q.push({a + 1, b});
                q.push({a, b + 1});
                q.push({a, b - 1});
            }
        }
    }
    return count;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid);

    return 0;
}