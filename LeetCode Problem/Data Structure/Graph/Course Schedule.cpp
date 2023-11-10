#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool visited[2001];
    bool dfs(int u, vector<vector<int>>& prerequisites) {
        visited[u] = true;
        for (vector<int> v : prerequisites) {
            if (v[1] == u && visited[v[0]] == false) {
                dfs(v[0], prerequisites);
            }
            else if (visited[v[1]]) return false;
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int first = prerequisites[0][1];
        if (prerequisites.empty()) return true;
        else return dfs(first, prerequisites);
    }
};

int main() {
    int n = 2;
    Solution solution;
    vector<vector<int>> prerequisites = {{0, 1}, {1, 0}};

    cout << solution.canFinish(n, prerequisites);



}