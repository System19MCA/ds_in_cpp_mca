#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Add edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    // BFS traversal from a given start node
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from node " << start << ": ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }

    // BFS traversal covering disconnected components
    void BFSFull() {
        vector<bool> visited(V, false);
        cout << "Full BFS Traversal of the graph: ";

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                queue<int> q;
                visited[i] = true;
                q.push(i);

                while (!q.empty()) {
                    int current = q.front();
                    q.pop();
                    cout << current << " ";

                    for (int neighbor : adj[current]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
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
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    if (start >= V) {
        cout << "Invalid starting vertex!\n";
    } else {
        g.BFS(start);
    }

    cout << "\nDo you want full BFS traversal to cover disconnected components? (y/n): ";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y') {
        g.BFSFull();
    }

    return 0;
}
