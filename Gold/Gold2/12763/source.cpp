// 4ms, 2684KB

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
constexpr int INF = 987654321;

int main()
{
    ios::sync_with_stdio(false);
    int N, T, M, L;
    cin >> N >> T >> M >> L;
    vector<vector<vector<int>>> adj(N + 1); //adj[u] = [[v,t,m]...]

    for (int i = 0; i < L; ++i)
    {
        int u, v, t, m;
        cin >> u >> v >> t >> m;
        adj[u].push_back({ v, t, m });
        adj[v].push_back({ u, t, m });
    }

    vector<int> minCost(N + 1, INF);
    vector<int> minDist(N + 1, INF);
    priority_queue<vector<int>> pq; // {-mSum, -tSum, v}

    minCost[1] = 0;
    minDist[1] = 0;
    pq.push({ 0, 0, 1 });
    while (!pq.empty())
    {
        auto path = pq.top(); pq.pop();
        path[0] *= -1;
        path[1] *= -1;

        if (minCost[path[2]] < path[0] && minDist[path[2]] < path[1])
            continue;

        for (auto& next : adj[path[2]])
        {
            int nextCost = path[0] + next[2];
            int nextDist = path[1] + next[1];
            if (nextDist > T)
                continue;
            bool updateMinCost = nextCost < minCost[next[0]];
            bool updateMinDist = nextDist < minDist[next[0]];
            if (updateMinCost || updateMinDist)
                pq.push({ -nextCost, -nextDist, next[0] });
            if (updateMinCost)
                minCost[next[0]] = nextCost;
            if (updateMinDist)
                minDist[next[0]] = nextDist;
        }
    }

    if (minCost[N] <= M)
        cout << minCost[N];
    else
        cout << -1;
}