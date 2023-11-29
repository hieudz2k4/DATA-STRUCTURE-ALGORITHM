#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<int>>& graph, int row, int col, int newColor, int originalColor) {
    int n = graph.size();

    if (row < 0 || row >= n || col < 0 || col >= n) {
        return;
    }

    if (graph[col][row] != originalColor) {
        return;
    }

    graph[col][row] = newColor;

    solve(graph, row + 1, col, newColor,  originalColor);
    solve(graph, row - 1, col, newColor,  originalColor);
    solve(graph, row, col + 1, newColor,  originalColor);
    solve(graph, row, col - 1, newColor,  originalColor);
}

int main() {
    vector<vector<int>> graph = {
            {1, 1, 1, 1, 0},
            {1, 1, 0, 1, 0},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1},
            {1, 0, 1, 0, 0}
    };

    int row = 1;
    int col = 1;
    int newColor = 5;
    int originalColor = graph[col][row];

    solve(graph, row, col, newColor, originalColor);

    cout << "Graph sau flood fill:" << endl;
    for (const auto& row : graph) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
