#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, -1));

        queue<pair<pair<int, int>, int>> Q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    Q.push({{i, j}, 0});
                    visit[i][j] = 1;
                }
            }
        }
        while (!Q.empty())
        {
            int r = Q.front().first.first;
            int c = Q.front().first.second;
            int dist = Q.front().second;

            dis[r][c] = dist;

            Q.pop();
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visit[nrow][ncol] && mat[nrow][ncol] == 1)
                {
                    Q.push({{nrow, ncol}, dist + 1});
                    visit[nrow][ncol] = 1;
                }
            }
        }
        display(dis);
        return dis;
    }

    void display(vector<vector<int>> mat)
    {
        for (auto it : mat)
        {
            for (auto it2 : it)
            {
                cout << " " << it2;
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    s.updateMatrix(grid);

    return 0;
}