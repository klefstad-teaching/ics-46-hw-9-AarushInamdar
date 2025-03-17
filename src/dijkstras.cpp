#include "dijkstras.h"
#include <algorithm>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> distances(n, INF);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& edge : G[u]) {
            int v = edge.dst, weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({distances[v], v});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    int pathLen = 0;
    for (int v = destination; v != -1; v = previous[v]) pathLen++;
    vector<int> path(pathLen);
    for (int v = destination, i = pathLen - 1; v != -1; v = previous[v], i--) path[i] = v;
    return path;
}

void print_path(const vector<int>& path, int total) {
    for (size_t i = 0; i < path.size(); ++i)  cout << path[i] << " ";
    cout << endl;
    cout << "Total cost is " << total << endl;
}
