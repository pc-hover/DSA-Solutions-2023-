#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 10;

int tsp(int graph[MAX][MAX], int mask, int pos, int n, vector<vector<int>> &dp)
{
    if (mask == ((1 << n) - 1))
    {
        return graph[pos][0]; // Return to the starting city
    }

    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, n, dp);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main()
{
    int n; // Number of cities
    cout << "Enter the number of cities: ";
    cin >> n;

    int graph[MAX][MAX]; // Adjacency matrix representing distances between cities

    cout << "Enter the distance matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> dp(1 << MAX, vector<int>(MAX, -1));

    // Start from city 0 (assuming 0-based indexing)
    int minCost = tsp(graph, 1, 0, n, dp);

    cout << "Minimum cost of visiting all cities: " << minCost << endl;

    return 0;
}
