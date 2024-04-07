#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // If the graph is undirected
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;

        visited[start] = true;
        s.push(start);

        while (!s.empty()) {
            int current = s.top();
            s.pop();
            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int V = 6; // Number of vertices
    Graph graph(V);

    // Adding edges to the graph (source, destination)
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
}
 

