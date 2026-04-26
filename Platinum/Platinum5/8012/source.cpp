// 16ms, 5660KB

#include<iostream>
#include<vector>

using namespace std;

int n, m, depth[30001], parent[30001][15];
vector<vector<int>> adj;

void dfs(int nd, int p)
{
	depth[nd] = depth[p] + 1;
	parent[nd][0] = p;
	for (int next : adj[nd])
	{
		if (next == p) continue;
		dfs(next, nd);
	}
}

int lca(int u, int v)
{
	int dU = depth[u];
	int dV = depth[v];
	if (dU < dV) {
		swap(u, v);
		swap(dU, dV);
	}
	for (int i = 15; ~--i; )
		if (depth[parent[u][i]] >= dV)
			u = parent[u][i];
	if (u == v)
		return u;
	for (int i = 15; ~--i; )
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	return parent[u][0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	adj.resize(n + 1);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	for (int j = 1; j < 15; ++j)
		for (int i = 1; i <= n; ++i)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
	cin >> m;
	int prev = 1, ret = 0;
	for (int i = 0; i < m; ++i)
	{
		int x;
		cin >> x;
		ret += depth[prev] + depth[x] - (depth[lca(prev, x)] << 1);
		prev = x;
	}
	cout << ret;
}