#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int start, vector<bool> &visit, vector<int> adjList[])
    {
        visit[start] = 1;
        for (auto it : adjList[start])
        {
            if (!visit[it])
            {
                dfs(it, visit, adjList);
            }
        }
    }
    void bfs(int start, vector<bool> &visit, vector<int> adjList[])
    {
        queue<int> Q;
        Q.push(start);
        visit[start] = 1;
        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            for (auto it : adjList[node])
            {
                if (!visit[it])
                {
                    visit[it] = 1;
                    Q.push(it);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // input is given to be adjacency matrux
        int V = isConnected.size();

        // Created adjacency List
        vector<int> adjList[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (isConnected[i][j] && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<bool> visit(V, 0);
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visit[i])
            {
                count++;
                bfs(i, visit, adjList);
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    cout << s.findCircleNum(grid) << endl;

    return 0;
}