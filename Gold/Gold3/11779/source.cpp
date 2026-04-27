// 28ms, 4752KB

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

constexpr int INF = 987654321;

int main()
{
    ios::sync_with_stdio(false);
    int n, m, s, d;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    cin >> s >> d;
    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1);
    priority_queue<pair<int,int>> pq;
    dist[s] = 0;
    pq.emplace(0, s);
    while(true)
    {
        auto path = pq.top(); pq.pop();
        int nd = path.second;
        int curDist = -path.first;
        if (dist[nd] < curDist) continue;
        if (nd == d) break;
        for(auto& next : adj[nd])
        {
            int nextDist = next.second + curDist;
            if (nextDist < dist[next.first])
            {
                dist[next.first] = nextDist;
                parent[next.first] = nd;
                pq.emplace(-nextDist, next.first);
            }
        }
    }
    
    vector<int> reversePath;
    for (int v = d; v; v = parent[v])
        reversePath.push_back(v);
    cout << dist[d] << '\n';
    cout << reversePath.size() << '\n';
    for (auto iter = reversePath.rbegin(); iter != reversePath.rend(); ++iter)
        cout << *iter << ' ';
}