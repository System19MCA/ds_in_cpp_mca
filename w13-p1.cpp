#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V, E;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
        E = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        E++;
    }

    bool isPossiblyPlanar() {
        if (V < 3)
            return true;

        return E <= 3 * V - 6;
    }

    void checkPlanarity() {
        cout << "\nVertices (V): " << V << ", Edges (E): " << E << endl;
        if (isPossiblyPlanar())
            cout << "The graph **may be planar** based on Euler's inequality (E ≤ 3V - 6).\n";
        else
            cout << "The graph is **not planar** based on Euler's inequality.\n";
        cout << "Note: This is only a necessary condition, not a complete test.\n";
    }
};

int main() {
    int V, edgeCount;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> edgeCount;

    cout << "Enter undirected edges (u v):\n";
    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid edge. Try again.\n";
            --i;
            continue;
        }
        g.addEdge(u, v);
    }

    g.checkPlanarity();

    return 0;
}
