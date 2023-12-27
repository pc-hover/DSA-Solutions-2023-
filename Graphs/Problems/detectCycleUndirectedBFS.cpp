#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int start, int visit[], vector<int> adj[])
{

    queue<pair<int, int>> q;
    q.push({start, -1});
    visit[start] = 1;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;

        for (auto adjacentNode : adj[node])
        {
            if (!visit[adjacentNode])
            {
                visit[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if (adjacentNode != parent)
            {
                return 1;
            }
        }
    }
    return 0;
}
bool isCycle(vector<int> adj[], int V)
{
    int visit[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!visit[i])
        {
            if (detectCycle(i, visit, adj) == true)
            {
                return true;
            }
        }
    }
    return false;
}

// } Driver Code Ends
int main()
{
    vector<int> adj[] = {{1},
                         {0, 2, 4},
                         {1, 3},
                         {2, 4},
                         {1, 3}};
    int n = sizeof(adj) / sizeof(adj[0]);
    cout
        << isCycle(adj, n) << endl;
}