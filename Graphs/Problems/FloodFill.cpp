#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, vector<vector<bool>> &visit, int initial)
    {
        int n = image.size();
        int m = image[0].size();
        visit[sr][sc] = 1;
        image[sr][sc] = color;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visit[nrow][ncol] && image[nrow][ncol] == initial)
            {
                image[nrow][ncol] = color;
                dfs(image, nrow, ncol, color, visit, initial);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, 0));
        dfs(image, sr, sc, color, visit, image[sr][sc]);

        return image;
    }
    void display(vector<vector<int>> image)
    {
        for (auto it : image)
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
    vector<vector<int>> grid = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> ans = s.floodFill(grid, 1, 1, 2);

    return 0;
}