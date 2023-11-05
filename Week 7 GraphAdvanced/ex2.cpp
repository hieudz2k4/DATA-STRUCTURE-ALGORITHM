#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, d;

    Edge(int u, int v, int d) : u(u), v(v), d(d) {}

    bool operator<(const Edge& otherEdge) const {
        return d < otherEdge.d;
    }
};

int findParentVertex(vector<int>& parentVertex, int vertex) {
    if (parentVertex[vertex] == vertex) return vertex;
    return parentVertex[vertex] = findParentVertex(parentVertex, parentVertex[vertex]);
}

void unionSets(vector<int>& parentVertex, int u, int v) {
    u = findParentVertex(parentVertex, u);
    v = findParentVertex(parentVertex, v);
    if (u != v) parentVertex[u] = v;
}

int main() {
    ifstream input("connection.txt");
    ofstream output("connection.out");

    int v, e;
    input >> v >> e;

    vector<Edge> edges;
    for (int i = 0; i < e; ++i) {
        int u, k, d;
        input >> u >> k >> d;
        edges.push_back(Edge(u, k, d));
    }

    sort(edges.begin(), edges.end());

    vector<int> parentV(v + 1);
    for (int i = 1; i <= v; ++i) {
        parentV[i] = i;
    }

    int total = 0;
    vector<Edge> result;

    for (Edge edge : edges) {
        if (findParentVertex(parentV, edge.u) != findParentVertex(parentV, edge.v)) {
            total += edge.d;
            result.push_back(edge);
            unionSets(parentV, edge.u, edge.v);
        }
    }

    output << total << endl;
    for (Edge edge : result) {
        output << edge.u << " " << edge.v << " " << edge.d << endl;
    }

    return 0;
}