#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph
{
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void dijkstra(int start);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int weight)
{
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight)); // For undirected graph
}

void Graph::dijkstra(int start)
{
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances from the start vertex
    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main()
{
    Graph g(6); // Create a graph with 6 vertices

    // Add edges with weights
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 5);

    int startVertex = 0; // Starting vertex for Dijkstra's algorithm

    g.dijkstra(startVertex);

    return 0;
}
