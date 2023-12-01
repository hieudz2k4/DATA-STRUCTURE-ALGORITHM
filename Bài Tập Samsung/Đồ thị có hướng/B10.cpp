#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

#define MAX_V 10001

int v, e;
vector<int> adj[MAX_V];
vector<int> revAdj[MAX_V];
bool visited[MAX_V];
stack<int> order;

// DFS trên đồ thị
void dfs(int u, vector<int> graph[MAX_V]) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, graph);
        }
    }
    order.push(u);
}

// DFS trên đồ thị ngược
void dfsReverse(int u) {
    visited[u] = true;
    for (int v : revAdj[u]) {
        if (!visited[v]) {
            dfsReverse(v);
        }
    }
}

// Kiểm tra đồ thị có liên thông mạnh hay không
bool isStronglyConnected() {
    memset(visited, false, sizeof(visited));

    // Bước 1: DFS trên đồ thị để lưu thứ tự đỉnh khi hoàn thành
    for (int i = 1; i <= v; ++i) {
        if (!visited[i]) {
            dfs(i, adj);
        }
    }

    memset(visited, false, sizeof(visited));

    // Bước 2: DFS trên đồ thị ngược theo thứ tự đã lưu
    while (!order.empty()) {
        int u = order.top();
        order.pop();
        if (!visited[u]) {
            dfsReverse(u);
            break;  // Chỉ cần thăm một đỉnh để kiểm tra liên thông mạnh
        }
    }

    // Kiểm tra xem tất cả các đỉnh đã được thăm hay chưa
    for (int i = 1; i <= v; ++i) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> v >> e;

    for (int i = 0; i < e; ++i) {
        int q, k;
        cin >> q >> k;
        adj[q].push_back(k);
        revAdj[k].push_back(q);
    }

    if (isStronglyConnected()) {
        cout << "Do thi co lien thong manh.";
    } else {
        cout << "Do thi khong lien thong manh.";
    }

    return 0;
}
