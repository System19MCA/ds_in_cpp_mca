#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj; // pair: (neighbor, weight)

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        // If undirected graph, uncomment the following line:
        // adj[v].push_back({u, weight});
    }

    void dijkstra(int source) {
        vector<int> dist(V, INF);
        dist[source] = 0;

        // Min-heap: (distance, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (currentDist > dist[u]) continue; // Skip outdated pairs

            for (auto& [v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Display result
        cout << "\nShortest distances from source " << source << ":\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INF)
                cout << "Vertex " << i << ": Unreachable\n";
            else
                cout << "Vertex " << i << ": " << dist[i] << endl;
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
    cout << "Enter edges in format (u v weight):\n";

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u >= V || v >= V || w < 0) {
            cout << "Invalid input! Skipping this edge.\n";
            --i;
            continue;
        }
        g.addEdge(u, v, w);
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    if (source >= V) {
        cout << "Invalid source vertex!\n";
        return 1;
    }

    g.dijkstra(source);

    return 0;
}
