#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;   // {neighbour, weight}

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto& [next, weight] : adj[node]) {
            if (!visited[next]) {
                DFSUtil(next, visited);
            }
        }
    }

    // BFS that also tracks hop-distance from start and reports connectivity
    void BFS(int start) {
        vector<bool> visited(V, false);
        vector<int> dist(V, -1);
        queue<int> q;

        visited[start] = true;
        dist[start] = 0;
        q.push(start);

        int reachedCount = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            reachedCount++;

            cout << node << " ";

            for (auto& [next, weight] : adj[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    dist[next] = dist[node] + 1;
                    q.push(next);
                }
            }
        }

        cout << "\n\nShortest distance (hops) from vertex " << start << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "  Vertex " << i << ": ";
            if (dist[i] == -1)
                cout << "unreachable\n";
            else
                cout << dist[i] << "\n";
        }

        if (reachedCount == V)
            cout << "\nGraph is fully CONNECTED from vertex " << start << ".\n";
        else
            cout << "\nGraph is NOT fully connected from vertex " << start
                 << " (" << reachedCount << "/" << V << " vertices reached).\n";
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // DFS
    auto startDFS = high_resolution_clock::now();

    cout << "\nDFS Traversal: ";
    g.DFS(start);

    auto endDFS = high_resolution_clock::now();
    auto dfsTime = duration_cast<nanoseconds>(endDFS - startDFS);

    // BFS
    auto startBFS = high_resolution_clock::now();

    cout << "\nBFS Traversal: ";
    g.BFS(start);

    auto endBFS = high_resolution_clock::now();
    auto bfsTime = duration_cast<nanoseconds>(endBFS - startBFS);

    // Display execution time
    cout << "\n\nExecution Time:";
    cout << "\nDFS: " << dfsTime.count() << " ns";
    cout << "\nBFS: " << bfsTime.count() << " ns";

    return 0;
}
