#include <bits/stdc++.h>
#define endl "\n"
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

// Structure to represent a weighted edge in the graph
struct Edge {
    int src, dest, weight;  // Source node, destination node, and weight of the edge
};

// Structure to represent a connected, directed, and weighted graph
struct Graph {
    int V, E;  // Number of vertices (V) and edges (E)

    // The graph is represented as a vector of edges
    vector<Edge>edge;
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E, vector<Edge> edge)
{
    struct Graph* graph = new Graph;  // Allocate memory for the graph
    graph->V = V;  // Set the number of vertices
    graph->E = E;  // Set the number of edges
    graph->edge = edge;  // Set the edges
    return graph;  // Return the newly created graph
}

// Function to check if the graph contains any negative cycles
// This can only be run after you run BellmanFord() on the graph
bool hasNegativeCycles(struct Graph* graph, vector<int>& dist) {
    int E = graph->E;
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        // If the distance to the source node plus the weight of the edge is less than the distance to the destination node,
        // then a negative cycle exists
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            return true;
        }
    }
    return false;  // No negative cycles found
}

// Function to find the shortest distances from the source node to all other nodes using the Bellman-Ford algorithm
vector<int> BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    vector<int> dist(V);

    // Initialize distances from the source node to all other nodes as infinite
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;  // The distance from the source node to itself is 0

    // Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            // If the current distance is not infinite and the distance through this edge is shorter, update the distance
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Check for negative-weight cycles
    if(hasNegativeCycles(graph, dist))
        cout<<"The graph contains a negative cycle"<<endl;

    return dist;  // Return the shortest distances from the source node to all other nodes
}

int main()
{
    IOS;

    int cases; cin>>cases;
    while(cases--){
        int V, E;  // Number of vertices (V) and edges (E) in the graph
        cin>>V>>E;

        vector<Edge> edge(E);  // Vector to hold the edges

        // Read the edges
        for(int i=0; i<E; i++){
            int src, dest, weight;  // Source node, destination node, and weight of the edge
            cin>>src>>dest>>weight;
            Edge temp;  // Temporary edge
            temp.src = src;
            temp.dest = dest;
            temp.weight = weight;
            edge[i] = temp;  // Add the edge to the vector
        }

        Graph* graph = createGraph(V, E, edge);  // Create the graph
    
        vector<int> distances = BellmanFord(graph, 0);  // Find the shortest distances from the source node to all other nodes

        // Print the distances
        for(int i=0; i<distances.size(); i++){
            cout<<"The shortest distance from node "<<i<<" to source is "<<distances[i]<<endl;
        }
    }

    return 0;
}