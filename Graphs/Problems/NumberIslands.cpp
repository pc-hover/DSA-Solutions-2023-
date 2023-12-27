#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int r, int c, vector<vector<bool>> &visit, vector<vector<char>> &grid, int n, int m)
    {
        visit[r][c] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = drow[i] + r;
            int ncol = dcol[i] + c;

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visit[nrow][ncol] && grid[nrow][ncol] == '1')
            {
                dfs(nrow, ncol, visit, grid, n, m);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visit[i][j] && grid[i][j] == '1')
                {
                    count++;
                    dfs(i, j, visit, grid, n, m);
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    cout << s.numIslands(grid) << endl;

    return 0;
}