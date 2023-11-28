
/**
Chứng minh đồ thị có hương có chu trình euler khi và chỉ khi G liên thông và mỗi đỉnh đều có bậc ra bằng bậc vào.
- Giả sử đồ thi có hướng G tồn tại chu trình euler
- Vì chu trình euler đi qua tất cả các cạnh nên cũng đi qua các đỉnh có bậc > 0 -> đồ thị G liên thông
- Số lần đi vào 1 đỉnh cũng bằng số lần đi ra 1 đỉnh trong chu trình euler nên mỗi đỉnh đều có bậc ra bằng bậc vào
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <cstring>

using namespace std;

int v, e;
vector<vector<int>> adj;
map<int, int> edge;
int inDegree[10001];
int outDegree[1001];

bool solve() {
    for (int i = 0; i < v; i++) {
        edge[i] = adj[i].size();
        if (inDegree[i] != outDegree[i]) return false;
    }
    if (!adj.size()) return false;


    stack<int> tmp;
    vector<int> res;

    tmp.push(0);
    int curV = 0;

    while (!tmp.empty()) {
        if (edge[curV]) {
            tmp.push(curV);
            int nextV = adj[curV].back();
            edge[curV]--;
            adj[curV].pop_back();

            curV = nextV;
        } else{
            res.push_back(v);
            curV = tmp.top();
            tmp.pop();
        }
    }
    for (int i = 0; i < v; i++) {
        if (!adj[i].empty()) {
            return false;
        }
    }
    for (int i = 0; i < v; i++) {
        if (edge[i] > 0) {
            return false;
        }
    }
    return true;

}

int main() {
    cin >> v >> e;
    adj.resize(v);
    memset(inDegree, 0, sizeof inDegree);
    memset(outDegree, 0, sizeof outDegree);

    for (int i = 0; i < e; i++) {
        int k, q;
        cin >> k >> q;
        adj[k].push_back(q);
        outDegree[k]++;
        inDegree[q]++;
    }
    if (solve()) cout << "Do thi co chu trinh euler";
    else cout << "Do thi khong ton tai chu trinh euler";
    return 0;
}


