/**
check euler and hamilton cycle.3
- Đồ thị có chu trình euler khi và chỉ khi bậc của đỉnh chẵn và đỉnh có bậc khác 0 phải nằm cùng 1 thành phần liên thông.
 */
#include <iostream>
#include <vector>

#define MAX_V 10001
using namespace std;

//0-1 0-2 0-3 1-3 1-4 2-5 2-9 3-6 4-7 4-8 5-8 5-9 6-7 6-9 7-8
//0-1 0-2 0-3 1-3 0-3 2-5 5-6 3-6 4-7 4-8 5-8 5-9 6-7 6-9 8-8
//0-1 1-2 1-3 0-3 0-4 2-5 2-9 3-6 4-7 4-8 5-8 5-9 6-7 6-9 7-8
//4-1 7-9 6-2 7-3 5-0 0-2 0-8 1-6 3-9 6-3 2-8 1-5 9-8 4-5 4-7


int v, e;
vector<vector<int>> graph;
int degree[MAX_V];

bool checkEulerCycle() {
    for (int i = 0; i < v; ++i) {
        if (degree[i] % 2 != 0) return false;
    }
    return true;
}

bool check(int u, int pos, const vector<int>& path) {
    if (graph[path[pos - 1]][u] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == u) return false;

    return true;
}

bool hamiltonCycleUtil(vector<int>& path, int pos) {
    if (pos == v) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int u = 1; u < v; ++u) {
        if (check(u, pos, path)) {
            path[pos] = u;
            if (hamiltonCycleUtil(path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }

    return false;
}

void hamiltonianCycle() {
    vector<int> path(v, -1);
    path[0] = 0;

    if (!hamiltonCycleUtil(path, 1)) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
}

int main() {
    cin >> v >> e;
    graph.resize(v, vector<int>(v, 0));

    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = graph[y][x] = 1;
        degree[x]++;
        degree[y]++;
    }

    checkEulerCycle() ? (cout << "Yes" << endl) : (cout << "No" << endl);
    hamiltonianCycle();
    return 0;
}

/*
- Đồ thị thứ 1:
 No
 Yes
- Đồ thi thứ 2:
 Yes
 No
- Đồ thị thứ 3:
 No
 Yes
- Đồ thị thứ 4
 No
 Yes
 */
