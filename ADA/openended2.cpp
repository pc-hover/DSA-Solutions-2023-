#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

class Graph
{
private:
    int V;
    vector<vector<int>> graph;

public:
    Graph(int vertices) : V(vertices), graph(vertices, vector<int>(vertices, 0)) {}

    void addEdge(int u, int v, int weight)
    {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int tsp(int mask, int pos, vector<vector<int>> &dp)
    {
        if (mask == (1 << V) - 1)
        {
            return graph[pos][0]; // Return to the starting city
        }

        if (dp[mask][pos] != -1)
        {
            return dp[mask][pos];
        }

        int minCost = INF;
        for (int city = 0; city < V; ++city)
        {
            if ((mask & (1 << city)) == 0)
            { // If city is not visited
                int newCost = graph[pos][city] + tsp(mask | (1 << city), city, dp);
                minCost = min(minCost, newCost);
            }
        }

        return dp[mask][pos] = minCost;
    }

    int solveTSP()
    {
        vector<vector<int>> dp(1 << V, vector<int>(V, -1)); // DP table
        return tsp(1, 0, dp);                               // Start from the first city (0) and visit all cities
    }
};

int main()
{
    int numCities, u, v, weight;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    Graph g(numCities);

    cout << "Enter the edges and weights (u v weight), type -1 to stop:\n";
    while (true)
    {
        cin >> u;
        if (u == -1)
        {
            break;
        }
        cin >> v >> weight;
        g.addEdge(u, v, weight);
    }

    int minCost = g.solveTSP();
    cout << "Minimum cost of TSP: " << minCost << endl;

    return 0;
}
