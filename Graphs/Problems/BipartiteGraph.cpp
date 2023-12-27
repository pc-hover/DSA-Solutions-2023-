#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool bfs(int i, vector<vector<int>> &graph, vector<bool> &visit, vector<char> &color)
    {
        int n = graph.size();
        queue<pair<int, char>> Q;
        // R B
        Q.push({i, 'R'});
        visit[i] = 1;
        color[i] = 'R';

        while (!Q.empty())
        {
            int node = Q.front().first;
            char ncolor = Q.front().second;
            Q.pop();
            char oppcolor;

            ncolor == 'R' ? oppcolor = 'B' : oppcolor = 'R';

            for (auto it : graph[node])
            {
                if (!visit[it])
                {
                    Q.push({it, oppcolor});
                    visit[it] = 1;
                    color[it] = oppcolor;
                }
                else
                {
                    if (color[it] != oppcolor)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<bool> visit(n, 0);
        vector<char> color(n, 'x');

        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                if (bfs(i, graph, visit, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph = {{},
                                 {2, 4, 6},
                                 {1, 4, 8, 9},
                                 {7, 8},
                                 {1, 2, 8, 9},
                                 {6, 9},
                                 {1, 5, 7, 8, 9},
                                 {3, 6, 9},
                                 {2, 3, 4, 6, 9},
                                 {2, 4, 5, 6, 7, 8}};

    cout << s.isBipartite(graph) << endl;

    return 0;
}