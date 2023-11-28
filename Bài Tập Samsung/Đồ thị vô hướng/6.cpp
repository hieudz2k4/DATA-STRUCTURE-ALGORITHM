#include <iostream>
#include <vector>
#include <cstring> // Thêm thư viện để sử dụng hàm memset

#define MAX_V 10001
using namespace std;

int v, e;
vector<int> adj[MAX_V];
bool visited[MAX_V];
int discTime[MAX_V];
int low[MAX_V];

bool check(int u, int p) {
    static int t = 0;
    int a = 0;
    discTime[u] = low[u] = t++;
    visited[u] = true;

    for (int adjU : adj[u]) {
        if (!visited[adjU]) {
            a++;
            if (check(adjU, u)) return true;

            low[u] = min(low[u], low[adjU]);

            if (low[adjU] > discTime[u]) return true;
        } else if (adjU != p) low[u] = min(low[u], discTime[adjU]);
    }

    return false;
}

bool lienThongCanh() {
    for (int i = 0; i < v; i++) {
        if (!visited[i])
            if (check(i, -1)) return false;
    }

    return true;
}

int main() {
    cin >> v >> e;
    memset(adj, 0, sizeof adj);
    memset(visited, 0, sizeof visited);
    memset(discTime, 0, sizeof discTime);
    memset(low, 0, sizeof low);

    for (int i = 0; i < e; i++) {
        int k, q;
        cin >> k >> q;
        adj[k].push_back(q);
        adj[q].push_back(k);
    }

    if (lienThongCanh()) cout << "Do thi co tinh chat lien thong canh" << endl;
    else cout << "Do thi khong co tinh chat lien thong canh";

    return 0;
}
