#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1000];
bool visited[1000];
int V, E;

// duyet dfs
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

// tinh so thanh phan lien thong
int connectedComponent() {
    int cnt = 0;
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int main() {
    cin >> V >> E;
    memset(visited, false, sizeof visited);
    for (int i = 0; i < V; i++) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
    }
    cout << connectedComponent();
}