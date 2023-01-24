#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int src, dest;
};
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);
        // add edges to the undirected graph
        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

// Function to perform DFS traversal
void DFS(Graph const &graph, int v, vector<bool> &visited)
{
    // mark the current node as discovered
    visited[v] = true;
    // print the current node
    cout << v << " ";
    // do for every edge (v, u)
    for (int u : graph.adjList[v])
    {
        // if `u` is not yet discovered
        if (!visited[u])
        {
            DFS(graph, u, visited);
        }
    }
}

int main()
{
    vector<Edge> edges = {
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4}, {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}};

    int n = 13;
    // build a graph from the given edges
    Graph graph(edges, n);
    vector<bool> visited(n);

    // Perform DFS traversal from all undiscovered nodes to
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            DFS(graph, i, visited);
        }
    }
    return 0;
}
