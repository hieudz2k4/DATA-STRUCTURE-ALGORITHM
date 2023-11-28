#include <iostream>
#include <vector>
#include <queue>

#define MAX_V 10001
using namespace std;

int v, e;
vector<int> adj[MAX_V];
int inDegree[MAX_V];
vector<int> topoSort;

void solve() {
    queue<int> q;

    for (int i = 0; i < v; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoSort.push_back(u);

        for (int adjU : adj[u]) {
            inDegree[adjU]--;
            if (inDegree[adjU] == 0) q.push(adjU);
        }
    }
}

int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int k, q;
        cin >> k >> q;
        adj[k].push_back(q);
        inDegree[q]++;
    }
    solve();
    if (topoSort.size() == v) {
        cout << "Có thứ tự topo" << endl;
    } else {
        cout << "Không tồn tại thứ tự topo" << endl;
    }
    return 0;
}