// 344ms, 9956KB

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

constexpr int inf = 987654321;
int N, M, V;

vector<vector<int>> adj;
vector<vector<int>> cap;
vector<vector<int>> flow;
vector<vector<int>> cost;

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	V = N + M + 2;
	adj.resize(V);
	cap.resize(V, vector<int>(V));
	flow.resize(V, vector<int>(V));
	cost.resize(V, vector<int>(V));

	for (int i = 1; i <= N; ++i) {
		cap[0][i] = 1;
		adj[0].push_back(i);
		adj[i].push_back(0);
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; ++j) {
			int job, pay;
			cin >> job >> pay;
			job += N;
			pay *= -1;
			cap[i][job] = 1;
			adj[i].push_back(job);
			adj[job].push_back(i);
			cost[i][job] = pay;
			cost[job][i] = -pay;
		}
	}
	for (int i = N + 1; i <= N + M; ++i) {
		cap[i][V - 1] = 1;
		adj[i].push_back(V - 1);
		adj[V - 1].push_back(i);
	}

	int ans1 = 0, ans2 = 0;
	while (true) {
		queue<int> q;
		vector<bool> inQ(V);
		vector<int> dist(V, inf);
		vector<int> prev(V, -1);
		q.push(0);
		inQ[0] = true;
		dist[0] = 0;
		while (!q.empty()) {
			int here = q.front(); q.pop();
			inQ[here] = false;
			for (auto next : adj[here]) {
				if (cap[here][next] - flow[here][next] > 0 &&
					dist[next] > dist[here] + cost[here][next]) {
					dist[next] = dist[here] + cost[here][next];
					prev[next] = here;
					if (!inQ[next]) {
						q.push(next);
						inQ[next] = true;
					}
				}
			}
		}

		if (prev[V - 1] == -1)
			break;

		++ans1;
		for (int i = V - 1; i; i = prev[i]) {
			ans2 += cost[i][prev[i]];
			flow[prev[i]][i] += 1;
			flow[i][prev[i]] -= 1;
		}
	}
	cout << ans1 << '\n' << ans2;
}