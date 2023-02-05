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
    cout<<"Enter the number of Edges\n";
    int numberOfEdges;
    cin>>numberOfEdges;
    vector<Edge> edges;
   
    for(int i =0;i<numberOfEdges;i++){
        Edge edge;
        int src,dest;
        cout<<"Enter "<<i+1<<"th edge\n";
        
        cout<<"source: ";
        cin>>src;
        cout<<"destination: ";
        cin>>dest;
        
        edge.src = src;
        edge.dest = dest;
        edges.push_back(edge);
    }
    int n;
    cout<<"Enter number of nodes";
    cin>>n;
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
