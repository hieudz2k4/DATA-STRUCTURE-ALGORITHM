#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

/**
 * v : vertex: 1....v
 * e : edge
 */
int v, e;
vector<int> adj[10001];
bool visited[10001];
int count = 0;


void bfs(int u) {
    visited[u] = true;
    queue<int> q;
    set<int> set;
    q.push(u);
    set.insert(u);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int adjTop : adj[top]) {
            if (set.count(adjTop) > 0) {
                ::count++;
                set.erase(adjTop);
            } else {
                set.insert(adjTop);
            }

            if (!visited[adjTop]) {
                visited[adjTop] = true;
                q.push(adjTop);
            }
        }
    }

}
int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, 0, sizeof visited);
    bfs(1);
    cout << ::count;
    return 0;
}