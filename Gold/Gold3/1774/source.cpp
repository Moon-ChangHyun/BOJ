// 48ms, 9996KB

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
using ll = long long;

struct disjointSet
{
    disjointSet(int num) : parent(num), rank(num), size(num, 1)
    {
        for (int i = 0; i < num; ++i)
            parent[i] = i;
    }
    int find(int u)
    {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    int merge(int u, int v)
    {
        u = find(u), v = find(v);
        if (u == v) return size[u];
        if (rank[u] < rank[v])
        {
            u ^= v;
            v ^= u;
            u ^= v;
        }
        parent[v] = u;
        size[u] += size[v];
        if (rank[u] == rank[v])
            ++rank[u];
        return size[u];
    }
private:
    vector<int> parent, rank, size;
};

int main()
{
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pos;
    pos.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        pos.emplace_back(x, y);
    }
    disjointSet ds(N + 1);
    int total = 0;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        total = ds.merge(u - 1, v - 1);
    }
    if (total == N)
    {
        cout << "0.00";
        return 0;
    }
    vector<pair<ll, pair<int, int>>> edges;
    edges.reserve(N * (N + 1) / 2);
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (ds.find(i) != ds.find(j))
            {
                ll dx = (pos[i].first - pos[j].first);
                ll dy = (pos[i].second - pos[j].second);
                edges.emplace_back(dx * dx + dy * dy, pair<int,int>{ i, j });
            }
        }
    }
    sort(edges.begin(), edges.end());
    double ret = 0;
    auto iter = edges.begin();
    for (auto& edge : edges)
    {
        auto p = edge.second;
        if (ds.find(p.first) != ds.find(p.second))
        {
            ret += sqrt(edge.first);
            if (ds.merge(p.first, p.second) == N)
                break;
        }
    }
    cout.precision(2);
    cout << fixed << ret;
}