#include <bits/stdc++.h>
using namespace std;
//  USING DFS
bool detectCycle(int node, int parent, vector<int> adj[], int visit[])
{
    visit[node] = 1;
    for (auto it : adj[node])
    {
        if (visit[it] == 0)
        {
            if (detectCycle(it, node, adj, visit))
                return true;
        }
        // now only visited options left either its a parent or a new node which was previously touched
        else if (it != parent)
            return true;
    }
    return false;
}
bool isCycle(vector<int> adj[], int V)
{
    int visit[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (detectCycle(i, -1, adj, visit) == true)
        {
            return true;
        }
    }
    return false;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
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