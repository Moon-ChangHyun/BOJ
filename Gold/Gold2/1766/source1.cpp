// 32ms, 3944KB

#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        ++inDegree[v];
        adj[u].push_back(v);
    }
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1; i <= n; ++i)
        if (!inDegree[i])
            pq.push(i);
    while (!pq.empty())
    {
        int x = pq.top(); pq.pop();
        cout << x << ' ';
        for (int y : adj[x]) {
            if (--inDegree[y] == 0)
                pq.push(y);
        }
    }
}