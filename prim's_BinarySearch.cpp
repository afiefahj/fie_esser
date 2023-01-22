//Prim's algorithm using binary search
#include <iostream>
#include <vector>
using namespace std;

const int INF = INT_MAX;

void prim(vector<vector<pair<int, int>>>& G, int r) {
    int n = G.size();
    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    key[r] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        int min_key = INF;

        // Find unvisited vertex with minimum key value
        for (int j = 0; j < n; j++) {
            if (!visited[j] && key[j] < min_key) {
                u = j;
                min_key = key[j];
            }
        }

        if (u == -1) break;
        visited[u] = true;

        // Update key value and parent of adjacent vertices
        for (auto& v : G[u]) {
            int to = v.first;
            int weight = v.second;

            if (!visited[to] && weight < key[to]) {
                key[to] = weight;
                parent[to] = u;
            }
        }
    }

    // Print minimum spanning tree
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
    }
}

int main() {
    vector<vector<pair<int, int>>> G = {{{1, 2}, {3, 4}}, {{0, 2}, {2, 3}}, {{1, 3}, {0, 4}}};
    prim(G, 0);

    return 0;
}
