// 208ms, 9520KB

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, Nodes;
	cin >> N >> M;
	Nodes = N + M + 2;
	vector<vector<int>> adj(Nodes);
	vector<vector<int>> cap(Nodes, vector<int>(Nodes, 0));
	vector<vector<int>> flow(Nodes, vector<int>(Nodes, 0));
	vector<vector<int>> cost(Nodes, vector<int>(Nodes, 0));
	for (int i = 1; i <= N; ++i) {
		cap[0][i] = 1;
		adj[0].push_back(i);
	}
	for (int i = N + 1; i < Nodes - 1; ++i) {
		cap[i][Nodes - 1] = 1;
		adj[i].push_back(Nodes - 1);
	}
	for (int i = 1; i <= N; ++i) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j != cnt; ++j) {
			int work, ct;
			cin >> work >> ct;
			work += N;
			cap[i][work] = 1;
			adj[i].push_back(work);
			cost[i][work] = ct;
			cost[work][i] = -ct;
		}
	}

	int totalCost = 0;
	int maximumWork = 0;
	while (true) {
		vector<int> dist(Nodes, 987654321);
		vector<int> parent(Nodes, -1);
		vector<bool> inQ(Nodes, false);
		queue<int> q;
		dist[0] = 0;
		parent[0] = 0;
		q.push(0);
		inQ[0] = true;
		while (!q.empty()) {
			int here = q.front(); q.pop();
			inQ[here] = false;
			for (auto there : adj[here]) {
				if (cap[here][there] - flow[here][there] > 0 && dist[there] > dist[here] + cost[here][there]) {
					dist[there] = dist[here] + cost[here][there];
					parent[there] = here;
					if (!inQ[there]) {
						q.push(there);
						inQ[there] = true;
					}
				}
			}
		}
		if (parent[Nodes - 1] == -1) break;

		for (int p = Nodes - 1; p != 0; p = parent[p]) {
			totalCost += cost[parent[p]][p];
			flow[parent[p]][p] = 1;
			flow[p][parent[p]] = -1;
			adj[p].push_back(parent[p]);
		}
		++maximumWork;
	}
	cout << maximumWork << '\n' << totalCost;
}