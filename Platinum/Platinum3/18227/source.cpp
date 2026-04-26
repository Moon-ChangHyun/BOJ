// 228ms, 30908KB

#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

class segTree {
	int n;
	vector<ll> rangeSum;

	void addOne(int idx, int node, int nodeL, int nodeR) {
		if (idx < nodeL || nodeR < idx) return;
		++rangeSum[node];
		if (nodeL == nodeR)
			return;
		int childL = node << 1;
		int childR = childL + 1;
		int mid = (nodeL + nodeR) >> 1;
		addOne(idx, childL, nodeL, mid);
		addOne(idx, childR, mid + 1, nodeR);
	}

	ll querySum(int l, int r, int node, int nodeL, int nodeR) {
		if (r < nodeL || nodeR < l) return 0;
		if (l <= nodeL && nodeR <= r) return rangeSum[node];
		int childL = node << 1;
		int childR = childL + 1;
		int mid = (nodeL + nodeR) >> 1;
		return querySum(l, r, childL, nodeL, mid) + querySum(l, r, childR, mid + 1, nodeR);
	}

public:
	segTree(int sz) : n(sz), rangeSum(sz * 4) {
	}

	void addOne(int idx) {
		addOne(idx, 1, 0, n - 1);
	}

	ll querySum(int l, int r) {
		return querySum(l, r, 1, 0, n - 1);
	}
};

int N, C, Q, cnt = -1;
vector<vector<int>> adj;
vector<int> start, end, depth;

void dfs(int u, int d)
{
	if (depth[u] != 0) return;
	depth[u] = d;
	start[u] = ++cnt;
	for (auto next : adj[u])
		dfs(next, d + 1);
	::end[u] = cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> C;
	adj.resize(N + 1);
	start.resize(N + 1);
	::end.resize(N + 1);
	depth.resize(N + 1);
	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(C, 1);
	segTree st(N);
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int op, city;
		cin >> op >> city;
		if (op == 1) {
			st.addOne(start[city]);
		}
		else {
			cout << st.querySum(start[city], ::end[city]) * depth[city] << '\n';
		}
	}
}