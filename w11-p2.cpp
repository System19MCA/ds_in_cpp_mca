#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal starting from node " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void DFSFull() {
        vector<bool> visited(V, false);
        cout << "Full DFS Traversal of the graph: ";
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
        cout << endl;
    }
};

// Main function
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= V || v >= V) {
            cout << "Invalid edge! Skipping.\n";
            continue;
        }
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    if (start >= V) {
        cout << "Invalid starting vertex!\n";
    } else {
        g.DFS(start);
    }

    cout << "\nDo you want full DFS traversal to cover disconnected components? (y/n): ";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y') {
        g.DFSFull();
    }

    return 0;
}
