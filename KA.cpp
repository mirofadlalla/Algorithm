//Made By OmarYAsser FAried MOhamed

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

// Function to sort edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Union-Find helper functions
class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Kruskal's Algorithm
vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compareEdges);
    UnionFind uf(V);

    vector<Edge> mst;

    for (Edge& edge : edges) {
        if (uf.find(edge.src) != uf.find(edge.dest)) {
            mst.push_back(edge);
            uf.unionSets(edge.src, edge.dest);
        }
        if (mst.size() == V - 1) break;
    }

    return mst;
}

int main() {
    int V = 6; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 8}, {0, 3, 6},
        {1, 3, 12}, {2, 3, 7}, {3, 4, 5},
        {4, 5, 9}
    };


    vector<Edge> mst = kruskalMST(edges, V);

    cout << "Edges in the MST:\n";
    for (Edge& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }

    return 0;
}
