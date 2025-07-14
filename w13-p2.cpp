#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Disjoint Set Union (Union-Find) for cycle detection
class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false; // Same set → cycle
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

class Graph {
private:
    int V;
    vector<Edge> edges;

public:
    Graph(int vertices) {
        V = vertices;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end());

        DSU dsu(V);
        vector<Edge> mst;
        int totalWeight = 0;

        for (const Edge& e : edges) {
            if (dsu.unite(e.u, e.v)) {
                mst.push_back(e);
                totalWeight += e.weight;
            }
            if (mst.size() == V - 1) break;
        }

        cout << "\nEdges in the Minimum Spanning Tree (MST):\n";
        for (const Edge& e : mst)
            cout << e.u << " - " << e.v << " : " << e.weight << endl;

        cout << "Total weight of MST: " << totalWeight << endl;
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
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid edge! Try again.\n";
            --i;
            continue;
        }
        g.addEdge(u, v, w);
    }

    g.kruskalMST();

    return 0;
}
