// 12ms, 2688KB

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
constexpr int inf = 987654321;

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int V = N + N + 2;
	vector<vector<int>> adj(V);
	vector<vector<int>> cap(V, vector<int>(V));
	vector<vector<int>> flow(V, vector<int>(V));
	vector<vector<int>> cost(V, vector<int>(V));
	for (int i = 1; i <= N; ++i) {
		cap[0][i] = 1;
		adj[0].push_back(i);
		adj[i].push_back(0);
		cap[i + N][V - 1] = 1;
		adj[i + N].push_back(V - 1);
		adj[V - 1].push_back(i + N);
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = N + 1; j < V - 1; ++j) {
			int x;
			cin >> x;
			cost[i][j] = x;
			cost[j][i] = -x;
			cap[i][j] = 1;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}

	int ans = 0;
	while (true) {
		vector<int> dist(V, inf);
		vector<int> prev(V, -1);
		vector<bool> inQ(V);
		queue<int> q;
		dist[0] = 0;
		q.push(0);
		inQ[0] = true;
		while (!q.empty()) {
			int nd = q.front(); q.pop();
			inQ[nd] = false;
			for (auto next : adj[nd]) {
				if (cap[nd][next] - flow[nd][next] > 0 && dist[next] > dist[nd] + cost[nd][next]) {
					dist[next] = dist[nd] + cost[nd][next];
					prev[next] = nd;
					if (!inQ[next]) {
						inQ[next] = true;
						q.push(next);
					}
				}
			}
		}

		if (prev[V - 1] == -1)
			break;

		for (int i = V - 1; i; i = prev[i]) {
			int& j = prev[i];
			ans += cost[j][i];
			++flow[j][i];
			--flow[i][j];
		}
	}
	cout << ans;
}