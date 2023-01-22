#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = INT_MAX;

struct Node {
    int vertex;
    int key;
    Node(int v, int k) : vertex(v), key(k) {}
};

struct Compare {
    bool operator()(Node lhs, Node rhs) {
        return lhs.key > rhs.key;
    }
};

void prim(vector<vector<pair<int, int>>>& G, int r) {
    int n = G.size();
    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    key[r] = 0;
    priority_queue<Node, vector<Node>, Compare> Q;
    Q.push(Node(r, key[r]));

    while (!Q.empty()) {
        Node u = Q.top();
        Q.pop();
        int vertex = u.vertex;

        if (visited[vertex]) continue;
        visited[vertex] = true;

        // Update key value and parent of adjacent vertices
        for (auto& v : G[vertex]) {
            int to = v.first;
            int weight = v.second;

            if (!visited[to] && weight < key[to]) {
                key[to] = weight;
                parent[to] = vertex;
                Q.push(Node(to, key[to]));
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
