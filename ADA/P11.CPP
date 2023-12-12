#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int n;                     // Number of cities
vector<vector<int>> graph; // Adjacency matrix representing distances between cities

int tsp(vector<int> &path, vector<bool> &visited, int currentLength, int count, int lowerBound)
{
    if (count == n && graph[path[n - 1]][path[0]] != 0)
    {
        return currentLength + graph[path[n - 1]][path[0]];
    }

    int minCost = INF;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && graph[path[count - 1]][i] != 0)
        {
            visited[i] = true;
            path[count] = i;
            int newLowerBound = lowerBound - graph[path[count - 1]][i];
            int currentCost = tsp(path, visited, currentLength + graph[path[count - 1]][i], count + 1, newLowerBound);
            minCost = min(minCost, currentCost);
            visited[i] = false;
        }
    }

    return minCost;
}

int travelingSalesman()
{
    vector<int> path(n, -1);
    vector<bool> visited(n, false);
    path[0] = 0;
    visited[0] = true;
    return tsp(path, visited, 0, 1, INT_MAX);
}

int main()
{
    cout << "Enter the number of cities: ";
    cin >> n;

    // Initialize the graph with distances between cities
    cout << "Enter the distance matrix (0 for self-loop and INF for unreachable cities):" << endl;
    graph.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }

    int minCost = travelingSalesman();
    cout << "Minimum Cost of Traveling Salesman Tour: " << minCost << endl;

    return 0;
}
