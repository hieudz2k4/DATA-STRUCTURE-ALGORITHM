#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

int v, e = 0; // vertex: dinh, edge: canh
vector<int> adj[1000]; // luu dinh ke dung sau
int indegree[1000], a[1000] ; // luu luong cung cua moi dinh
vector<int> topoSort;
queue<int> list; // luu danh sach cac dinh khong co cung nao

int main() {

    memset(indegree, 0, sizeof indegree);

    ifstream input("jobs.txt");
    ofstream output("jobs.out");

    if (!input) cout << "Loi file";

    input >> v >> e;

    for (int i = 0; i < e; i++) {
        int u, k;
        input >> u >> k;
        adj[u].push_back(k);
        indegree[k]++;
    }

    for (int i = 1; i <= v; i++) {
        if (!indegree[i]) list.push(i);
    }

    while(!list.empty()) {
        int front = list.front();
        list.pop();
        topoSort.push_back(front);
        for(int k : adj[front]) {
            indegree[k]--;
            if(!indegree[k]) list.push(k);
        }
    }

    for (auto x : topoSort) output << x << " ";
}
