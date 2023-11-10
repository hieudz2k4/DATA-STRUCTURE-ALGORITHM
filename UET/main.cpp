#include <vector>
#include <iostream>

using namespace std;

int heightOfNode(vector<int> adj[], int visit[], int x)
{
    visit[x] = 1;
    int maxHeightNode = 1;
    for(int v: adj[x])
    {
        if(visit[v] == 0)
        {
            int tmp = 1 + heightOfNode(adj, visit, v);
            if(tmp > maxHeightNode) maxHeightNode = tmp;
        }
    }
    return maxHeightNode;
}

int main() {
    int n, x, y;
    cin >> n;
    vector<int> adj[n+1];
    int visit[n+1];
    for(int i = 0; i < n; i++)
    {
        visit[i] = 0;
    }

    for(int i = 0; i < n -1 ; i ++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int s[n];
    int minHeightNode = 100000;
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n ; j ++)
        {
            visit[j] = 0;
        }
        s[i] = heightOfNode(adj,visit,i);
        minHeightNode = min(s[i], minHeightNode);
    }
    for(int i = 0; i < n; i ++)
    {
        if(s[i] == minHeightNode) cout << i << " ";
    }

}
