#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

/*
int v,e;
vector<int> adj[1000];
vector<int> topoSort;
set<int> s;
bool visited[1000];

void dfs(int u) {
    visited[u] = true;
    for(int k : adj[u]) {
        if (!visited[k]) dfs(k);
    }
    topoSort.push_back(u);
}

/*
int main() {
    memset(visited, 0, sizeof visited);
    ifstream input("jobs.txt");

    input >> v >> e;

    for(int i = 0; i < e; i++) {
        int u, k;
        input >> u >> k;
        adj[u].push_back(k);
        s.insert(u);
        s.insert(k);
    }


    reverse(topoSort.begin(), topoSort.end());
    for (auto x : topoSort) {
        cout << x << " ";
    }
    return 0;
}
*/