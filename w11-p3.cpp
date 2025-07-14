#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define INF INT_MAX

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // For undirected graph
    }

    void primMST() {
        vector<int> parent(V, -1);       // To store MST
        vector<int> key(V, INF);         // Weights to pick minimum
        vector<bool> inMST(V, false);    // Visited nodes

        key[0] = 0; // Start from vertex 0

        for (int count = 0; count < V - 1; ++count) {
            // Find the minimum key vertex not yet included
            int u = -1, minKey = INF;
            for (int v = 0; v < V; ++v) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            inMST[u] = true;

            // Update keys and parents of adjacent vertices
            for (int v = 0; v < V; ++v) {
                if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    key[v] = adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }

        // Display the MST
        cout << "\nEdges in the Minimum Spanning Tree:\n";
        int totalCost = 0;
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << " (Weight: " << adjMatrix[i][parent[i]] << ")\n";
            totalCost += adjMatrix[i][parent[i]];
        }
        cout << "Total weight of MST: " << totalCost << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges in format (u v weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u >= V || v >= V) {
            cout << "Invalid vertex! Skipping this edge.\n";
            continue;
        }
        g.addEdge(u, v, w);
    }

    g.primMST();

    return 0;
}
