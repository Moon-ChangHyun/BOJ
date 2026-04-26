// 52ms, 2516KB

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
	vector<vector<int>> cap(Nodes, vector<int>(Nodes, 0));
	vector<vector<int>> flow(Nodes, vector<int>(Nodes, 0));
	vector<vector<int>> cost(Nodes, vector<int>(Nodes, 0));
	for (int i = M + 1; i < Nodes - 1; ++i) {
		int need;
		cin >> need;
		cap[i][Nodes - 1] = need;
	}
	for (int i = 1; i <= M; ++i) {
		int book;
		cin >> book;
		cap[0][i] = book;
		
	}
	for (int i = 1; i <= M; ++i) {
		for (int j = M + 1; j < Nodes - 1; ++j) {
			int ct;
			cin >> ct;
			cap[i][j] = 987654321;
			cost[i][j] = ct;
			cost[j][i] = -ct;
		}
	}

	int totalCost = 0;
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
			for (int there = 0; there != Nodes; ++there) {
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

		int amount = 987654321;
		for (int p = Nodes - 1; p != 0; p = parent[p]) {
			amount = min(amount, cap[parent[p]][p] - flow[parent[p]][p]);
		}
		for (int p = Nodes - 1; p != 0; p = parent[p]) {
			totalCost += amount * cost[parent[p]][p];
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
	}
	cout << totalCost;
}