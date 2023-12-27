#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int startRow, int startCol, vector<vector<int>> &grid, vector<pair<int, int>> &coordinates, vector<vector<bool>> &visit, int rbase, int cbase)
    {
        visit[startRow][startCol] = 1;

        int m = grid[0].size(), n = grid.size();

        coordinates.push_back({startRow - rbase, startCol - cbase});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = startRow + drow[i];
            int ncol = startCol + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visit[nrow][ncol] && grid[nrow][ncol] == 1)
            {

                dfs(nrow, ncol, grid, coordinates, visit, rbase, cbase);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int m = grid[0].size(), n = grid.size();
        set<vector<pair<int, int>>> island;
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) // (n X m)
            {

                if (!visit[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> coordinates;
                    dfs(i, j, grid, coordinates, visit, i, j); //(n X m)
                    island.insert(coordinates);                //(log(n X m))
                }
            }
        }
        return island.size();
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};

    cout << s.countDistinctIslands(grid) << endl;

    return 0;
}