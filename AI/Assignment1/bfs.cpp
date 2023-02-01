#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Edge{
    int src,dest;
};

class Graph{
    public:
    vector<vector<int>> adjlist;   //adjacenecy list is created
    //class constructor
    Graph(vector<Edge> const&edges,int n){
        //for holding n vectors of type int
        adjlist.resize(n);

        for(auto &edge:edges){
            //connecting the edges of undirected graph
            adjlist[edge.src].push_back(edge.dest);
            adjlist[edge.dest].push_back(edge.src);
        }
    }
};

void recursive_bfs(Graph const &graph, queue<int> &q, vector<bool> &visited){
    if(q.empty()){
        return;
    }
    //getting first source node 
    int v= q.front();
    //pop it
    q.pop();
    cout<<v<<" ";
    // do for every edge (v, u)
    for (int u: graph.adjlist[v])
    {
        if (!visited[u])
        {
            // mark it as discovered and enqueue it
            visited[u] = true;
            q.push(u);
        }
    }
    recursive_bfs(graph, q, visited);
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
    Graph graph(edges, n);
    // to check whether a vertex is visited or not
    //in starting
    vector<bool> visited(n, false);
    queue<int> q;
    // Perform BFS traversal 
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            q.push(i);
            recursive_bfs(graph, q, visited);
        }
    }
    return 0;
}

// vector<Edge> edges={
    //     // {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
    //     // {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}

    //     {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4}, {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
    // };