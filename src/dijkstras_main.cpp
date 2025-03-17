#include "dijkstras.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <graph_file>" << endl;
        return 1;
    }

    Graph G;
    try {
        file_to_graph(argv[1], G);
    } catch (const exception& e) {
        cout << e.what() << endl;
        return 1;
    }

    int source = 0;
    vector<int> previous(G.numVertices);
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    for (int i = 0; i < G.numVertices; i++) {
        vector<int> path = extract_shortest_path(distances, previous, i);
        print_path(path, distances[i]);
    }

    return 0;
}
