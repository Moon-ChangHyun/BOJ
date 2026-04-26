// 2980ms, 18140KB

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

constexpr ll inf = 400'000'000'000'001;

int N, M, X;
vector<vector<pair<pair<int, int>, int>>> adj; //<<길이,색상>, 연결노드>

ll dijkstra(int r)
{
	int b = X - r;
	vector<ll> dist(N + 1, inf);
	dist[1] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.emplace(0, 1);
	while (true)
	{
		auto cur = pq.top(); pq.pop();
		if (cur.second == N)
			break;
		if (dist[cur.second] < -cur.first)
			continue;
		for (auto& nextEdge : adj[cur.second])
		{
			ll nextDist = -cur.first + nextEdge.first.first;
			if (nextEdge.first.second == 1)
				nextDist += r;
			else if (nextEdge.first.second == 2)
				nextDist += b;
			if (dist[nextEdge.second] <= nextDist)
				continue;
			dist[nextEdge.second] = nextDist;
			pq.emplace(-nextDist, nextEdge.second);
		}
	}
	return dist[N];
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M >> X;
	adj.resize(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int u, v, w, p;
		cin >> u >> v >> w >> p;
		adj[u].emplace_back(make_pair(w, p), v);
		adj[v].emplace_back(make_pair(w, p), u);
	}
	int lo = 0, hi = X;
	while (lo + 2 < hi)
	{
		int m1 = (lo + hi) >> 1;
		int m2 = m1 + 1;
		if (dijkstra(m1) < dijkstra(m2))
			lo = m1;
		else
			hi = m2;
	}
	ll result = 0;
	for (int i = lo; i <= hi; ++i)
		result = max(result, dijkstra(i));
	cout << result;
}