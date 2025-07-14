#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

    // Helper function for backtracking
    bool isSafe(int v, vector<int>& path, int pos) {
        // Check if there's an edge from the last vertex in the path to v
        if (adj[path[pos - 1]][v] == 0)
            return false;

        // Check if v is already included in the path
        for (int i = 0; i < pos; i++)
            if (path[i] == v)
                return false;

        return true;
    }

    bool hamiltonianCycleUtil(vector<int>& path, int pos) {
        // Base case: if all vertices are included
        if (pos == V) {
            // Check if last vertex is connected to the first
            return adj[path[pos - 1]][path[0]] == 1;
        }

        for (int v = 1; v < V; v++) {
            if (isSafe(v, path, pos)) {
                path[pos] = v;

                if (hamiltonianCycleUtil(path, pos + 1))
                    return true;

                // Backtrack
                path[pos] = -1;
            }
        }

        return false;
    }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    void checkHamiltonianCycle() {
        vector<int> path(V, -1);
        path[0] = 0; // Start from vertex 0

        if (hamiltonianCycleUtil(path, 1)) {
            cout << "Hamiltonian Cycle exists:\n";
            for (int i = 0; i < V; i++)
                cout << path[i] << " ";
            cout << path[0] << " (back to start)" << endl;
        } else {
            cout << "No Hamiltonian Cycle exists in the graph.\n";
        }
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
            cout << "Invalid edge! Try again.\n";
            --i;
            continue;
        }
        g.addEdge(u, v);
    }

    g.checkHamiltonianCycle();

    return 0;
}
