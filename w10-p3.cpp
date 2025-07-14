#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
private:
    int V, E;

    vector<vector<int>> adjMatrix;
    vector<list<int>> adjList;
    vector<pair<int, int>> edgeList;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        // Adjacency Matrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph

        // Adjacency List
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph

        // Edge List
        edgeList.push_back({u, v});
        edgeList.push_back({v, u}); // For undirected graph
    }

    void inputGraph() {
        cout << "Enter number of edges: ";
        cin >> E;
        cout << "Enter edges (u v):\n";
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            if (u >= V || v >= V) {
                cout << "Invalid edge (" << u << ", " << v << ")\n";
                i--;
                continue;
            }
            addEdge(u, v);
        }
    }

    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void displayAdjList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void displayEdgeList() {
        cout << "\nEdge List:\n";
        for (auto edge : edgeList) {
            cout << edge.first << " - " << edge.second << endl;
        }
    }
};

int main() {
    int vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    g.inputGraph();

    int choice;
    do {
        cout << "\nGraph Representation Menu:\n";
        cout << "1. Display Adjacency Matrix\n";
        cout << "2. Display Adjacency List\n";
        cout << "3. Display Edge List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            g.displayAdjMatrix();
            break;
        case 2:
            g.displayAdjList();
            break;
        case 3:
            g.displayEdgeList();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
