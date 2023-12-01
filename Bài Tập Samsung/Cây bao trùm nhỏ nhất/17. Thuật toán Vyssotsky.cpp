#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Edge {
public:
    int s, t, w;
    Edge(int s, int t, int w) : s(s), t(t), w(w) {}
};

class Graph {
public:
    int v;
    vector<Edge> edges;
    int parent[10001];
    int rank[10001];

    void addEdge(int s, int t, int w) {
        edges.push_back(Edge(s, t, w));
    }

    void makeSet() {
        for (int i = 0; i < v; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] == u)
            return u;
        return find(parent[u]);
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else if (rank[rootU] > rank[rootV])
            parent[rootU] = rootV;
        else {
            parent[rootU] = rootV;
            rank[rootU]++;
        }
    }

    vector<Edge> vyssotskyAlgorithm() {
        memset(parent, 0, sizeof parent);
        memset(rank, 0, sizeof rank);

        makeSet();

        vector<Edge> res;
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.w < b.w;
        });

        for (Edge edge : edges) {
            int x = find(edge.s);
            int y = find(edge.t);
            if (x != y) {
                res.push_back(edge);
                unionSets(x, y);
            }
        }
        return res;
    }
};

int main() {
    Graph g;
    g.v = 4;
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 3, 6);

    vector<Edge> res = g.vyssotskyAlgorithm();

    cout << "Cây khung nhỏ nhất: " << endl;
    for (Edge edge : res) {
        cout << edge.s << " - " << edge.t << " : " << edge.w<< "\n";
    }
    return 0;
}
