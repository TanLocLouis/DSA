#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = INT_MAX;

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    vector<int> dijkstra(int source) {
        vector<int> distance(V, INF);
        distance[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (dist > distance[u])
                continue;

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                if (distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    pq.push({distance[v], v});
                }
            }
        }

        return distance;
    }
};

int main() {
    int V = 6;
    Graph graph(V);

    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 3, 6);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 4, 4);
    graph.addEdge(2, 5, 2);
    graph.addEdge(2, 3, 7);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 5, 2);

    int source = 0;
    vector<int> distances = graph.dijkstra(source);

    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}

