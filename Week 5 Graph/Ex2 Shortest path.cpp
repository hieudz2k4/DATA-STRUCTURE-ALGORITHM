#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
vector<int> adj[10000];
bool visited[10000];
int X, Y;

int shortestPath() {
    // dung queue luu dinh hien tai va khoang cach, dung bfs(breath first search)
    queue<pair<int, int>> q;
    q.push({X, 0});
    visited[X] = 1;
    while(!q.empty()) {
        int curVertex = q.front().first; // lay current vertex
        int curDist = q.front().second; // lay current Dist
        q.pop();
        if (Y == curVertex) return curDist; // Neu Y == current vertex return current distant
        else {
            for(int adjCurVertex : adj[curVertex]) {
                if (!visited[adjCurVertex]) {
                    visited[adjCurVertex] = 1;
                    q.push({adjCurVertex, curDist + 1});
                }
            }
        }
    }

    return -1; // khong co duong di tu X -> Y
}

int main() {
    cin >> V >> E >> X >> Y;
    memset(visited, false, sizeof visited);
    for(int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    cout << shortestPath();
    return 0;
}