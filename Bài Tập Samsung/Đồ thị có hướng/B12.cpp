#include <iostream>
#include <vector>
#include <stack>

#define MAX_V 10001
using namespace std;

int v, e;
vector<int> adj[MAX_V];
bool visited[MAX_V];
stack<int> topoSort;

void dfs(int u) {
    visited[u] = true;
    for (int adjU : adj[u]) {
        if (visited[adjU]) break;
        if (!visited[adjU]) {
            dfs(adjU);
        }
    }
    topoSort.push(u);
}

void topologicalSort() {
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

bool check() {
    if (!v || !e) return false;

    topologicalSort();
    int cnt = 0;
    while (!topoSort.empty()) {
        int u = topoSort.top();
        topoSort.pop();
        for (int adjU : adj[u]) {
            if (adjU == topoSort.top()) cnt++;
        }
    }
    return cnt == v - 1;
}

int main() {
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int k, q;
        cin >> k >> q;
        adj[k].push_back(q);
    }

    if (check()) {
        cout << "Thứ tự topo là duy nhất" << endl;
    } else if (!check() && topoSort.size() == v) {
        cout << "Có nhiều thứ tự topo" << endl;
    } else {
        cout << "Không tồn tại thứ tự topo" << endl;
    }

    return 0;
}
