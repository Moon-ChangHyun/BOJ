// 36ms, 3560KB

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
constexpr int INF = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	for (cin >> T; ~--T; )
	{
		int n, m, t, s, g, h;
		cin >> n >> m >> t >> s >> g >> h;
		vector<vector<pair<int, int>>> adj(n + 1);
		for (int i = 0; i < m; ++i)
		{
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].emplace_back(b, d);
			adj[b].emplace_back(a, d);
		}
		vector<int> dst(t);
		for (int i = 0; i < t; ++i)
			cin >> dst[i];

		int sum = g + h, mul = g * h;
		vector<int> dist(n + 1, INF);
		vector<bool> check(n + 1);
		priority_queue<pair<int, pair<bool, int>>> pq;
		dist[s] = 0;
		pq.emplace(0, make_pair(false, s));
		while (!pq.empty())
		{
			auto path = pq.top(); pq.pop();
			bool c = path.second.first;
			int cur = path.second.second;
			int d = -path.first;
			if (dist[cur] < d) continue;

			for (auto& next : adj[cur])
			{
				int nextNd = next.first;
				int nextD = next.second + d;
				bool nextC = c || (sum == cur + nextNd && mul == cur * nextNd);
				if (nextD < dist[nextNd] || (nextD == dist[nextNd] && !check[nextNd] && nextC))
				{
					dist[nextNd] = nextD;
					check[nextNd] = nextC;
					pq.emplace(-nextD, make_pair(nextC, nextNd));
				}
			}
		}

		sort(dst.begin(), dst.end());
		for (auto x : dst)
		{
			if (dist[x] == INF) continue;
			if (check[x])
				cout << x << ' ';
		}
		cout << '\n';
	}
}