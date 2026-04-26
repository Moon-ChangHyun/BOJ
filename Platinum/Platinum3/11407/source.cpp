// 436ms, 2688KB

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using ll = long long;

constexpr int inf = 987654321;
int N, M, V;
vector<vector<int>> adj;
vector<vector<int>> cap;
vector<vector<int>> flow;
vector<vector<int>> cost;

//S = idx 0, T = idx N + M + 1

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	V = N + M + 2;
	cap.resize(V, vector<int>(V));
	flow.resize(V, vector<int>(V));
	cost.resize(V, vector<int>(V));
	adj.resize(V);
	for (int i = 1; i <= N; ++i) {
		cin >> cap[0][i];
		adj[0].push_back(i);
		adj[i].push_back(0);
	}
	for (int i = N + 1; i <= N + M; ++i) {
		cin >> cap[i][V - 1];
		adj[i].push_back(V - 1);
		adj[V - 1].push_back(i);
	}
	for (int i = N + 1; i <= N + M; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> cap[j][i];
			adj[j].push_back(i);
			adj[i].push_back(j);
		}
	}
	for (int i = N + 1; i <= N + M; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> cost[j][i];
			cost[i][j] = -cost[j][i];
		}
	}

	ll ans1 = 0, ans2 = 0;
	while (true) {
		//spfa최단경로찾기
		queue<int> q;
		vector<bool> inQ(V);
		vector<int> prev(V, -1);
		vector<int> dist(V, inf);
		dist[0] = 0;
		inQ[0] = true;
		q.push(0);
		while (!q.empty()) {
			int here = q.front(); q.pop();
			inQ[here] = false;
			for (auto next : adj[here]) {
				if (cap[here][next] - flow[here][next] > 0 && dist[next] > dist[here] + cost[here][next]) {
					prev[next] = here;
					dist[next] = dist[here] + cost[here][next];
					if (!inQ[next]) {
						inQ[next] = true;
						q.push(next);
					}
				}
			}
		}

		if (dist[V - 1] == inf) {
			break;
		}

		//flow
		int minFlow = inf;
		for (int i = V - 1; i; i = prev[i]) {
			minFlow = min(minFlow, cap[prev[i]][i] - flow[prev[i]][i]);
		}
		ans1 += minFlow;
		for (int i = V - 1; i; i = prev[i]) {
			ans2 += cost[prev[i]][i] * minFlow;
			flow[prev[i]][i] += minFlow;
			flow[i][prev[i]] -= minFlow;
		}
	}
	cout << ans1 << '\n' << ans2;
}