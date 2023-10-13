#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int V, E;
vector<int> adj[10000];
bool visited[10000];


void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()) {
        int s = q.front(); q.pop();
        cout << s << " ";
        for(int adjS : adj[s]) {
            if (!visited[adjS]) {
                visited[adjS] = 1;
                q.push(adjS);
            }
        }
    }

}

int main() {
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    bfs(1);
    return 0;
}
