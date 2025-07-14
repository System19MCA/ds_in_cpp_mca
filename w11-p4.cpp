#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1; // Directed edge
    }

    void warshall() {
        vector<vector<int>> reach = adjMatrix;

        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
                }
            }
        }

        // Output transitive closure matrix
        cout << "\nTransitive Closure Matrix (Reachability):\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << reach[i][j] << " ";
            }
            cout << endl;
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

    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= V || v >= V) {
            cout << "Invalid edge!\n";
            --i;
            continue;
        }
        g.addEdge(u, v);
    }

    g.warshall();

    return 0;
}
