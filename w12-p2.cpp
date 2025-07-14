#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u])
                DFSUtil(u, visited);
        }
    }

    // Check if all non-zero degree vertices are connected
    bool isConnected() {
        vector<bool> visited(V, false);
        int nonZeroDegreeVertex = -1;

        for (int i = 0; i < V; ++i) {
            if (adj[i].size() > 0) {
                nonZeroDegreeVertex = i;
                break;
            }
        }

        // If no edges in graph
        if (nonZeroDegreeVertex == -1)
            return true;

        DFSUtil(nonZeroDegreeVertex, visited);

        for (int i = 0; i < V; ++i) {
            if (adj[i].size() > 0 && !visited[i])
                return false;
        }

        return true;
    }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void checkEulerian() {
        if (!isConnected()) {
            cout << "Graph is not connected, so no Eulerian Path or Circuit exists.\n";
            return;
        }

        int oddDegreeCount = 0;
        for (int i = 0; i < V; ++i) {
            if (adj[i].size() % 2 != 0)
                oddDegreeCount++;
        }

        if (oddDegreeCount == 0)
            cout << "Graph has an Eulerian Circuit.\n";
        else if (oddDegreeCount == 2)
            cout << "Graph has an Eulerian Path.\n";
        else
            cout << "Graph has neither Eulerian Path nor Eulerian Circuit.\n";
    }
};

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
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid edge! Please enter valid vertices.\n";
            --i;
            continue;
        }
        g.addEdge(u, v);
    }

    g.checkEulerian();

    return 0;
}
