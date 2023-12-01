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

        if (rootU != rootV) parent[rootV] = rootU;
    }

    void boruvkaAlgo() {
        memset(parent, 0, sizeof parent);
        vector<Edge> lowCost(v, Edge(-1, -1, INT_MAX));
        makeSet();
        int initTreeNum = v;

        while (initTreeNum) {
            for (int i = 0; i < edges.size(); i++) {
                int rootS = find(edges[i].s);
                int rootT = find(edges[i].t);

                if (rootS != rootT) {
                    if (lowCost[rootS].w == -1
                    || edges[i].w < lowCost[rootS].w)lowCost[rootS] = edges[i];
                    if (lowCost[rootT].w == -1
                    || edges[i].w < lowCost[rootT].w) lowCost[rootT] = edges[i];
                }
            }

            for (int i = 0; i < v; i++) {
                if (lowCost[i].w != -1) {
                    int rootS = find(lowCost[i].s);
                    int rootT = find(lowCost[i].t);

                    if (rootS != rootT) {
                        cout << "Edge " << lowCost[i].s << " - " << lowCost[i].t << " : " << lowCost[i].w << endl;
                        unionSets(rootS, rootT);
                        initTreeNum--;
                    }
                }
                lowCost[i] = Edge(-1, -1, INT_MAX);
            }
        }
    }
};

int main() {
    Graph g;
    g.v = 4;
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.boruvkaAlgo();
}
