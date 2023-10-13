#include <iostream>
#include <vector>
using namespace std;


int V, E;
vector<int> adj[1000];
bool visited[1000];

void input() {
   cin >> V >> E;

    // tao cac canh ke
    for (int i = 0; i < E; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    memset(visited, false, sizeof visited);
}

void dfs(int u) {
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    input();
    dfs(1);
    return 0;
}
