// 152ms, 20412KB

#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<char> milk;
vector<int> HCnt, GCnt;
int parent[100001][17];

void dfs(int nd, int p, int h, int g)
{
	parent[nd][0] = p;
	if (milk[nd] == 'H')
		++h;
	else
		++g;
	HCnt[nd] = h;
	GCnt[nd] = g;
	for (auto child : adj[nd])
	{ 
		if (child == p) continue;
		dfs(child, nd, h, g);
	}
}

int lca(int u, int v)
{
	int dU = HCnt[u] + GCnt[u];
	int dV = HCnt[v] + GCnt[v];
	if (dU < dV) {
		swap(u, v);
		swap(dU, dV);
	}
	int lo = 0, hi = 18;
	while (dU > dV)
	{
		lo = 0;
		--hi;
		while (lo + 1 != hi)
		{
			int mid = (lo + hi) >> 1;
			int tmp = parent[u][mid];
			if (HCnt[tmp] + GCnt[tmp] < dV)
				hi = mid;
			else
				lo = mid;
		}
		u = parent[u][lo];
		dU = HCnt[u] + GCnt[u];
	}
	//dU == dV
	if (u == v)
		return u;
	lo = 0, hi = 18;
	while (u != v)
	{
		if (parent[u][0] == parent[v][0])
			return parent[u][0];
		lo = 0;
		--hi;
		while (lo + 1 != hi)
		{
			int mid = (lo + hi) >> 1;
			int tmpU = parent[u][mid];
			int tmpV = parent[v][mid];
			if (tmpU == tmpV)
				hi = mid;
			else
				lo = mid;
		}
		u = parent[u][lo];
		v = parent[v][lo];
	}
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> N >> M;
	milk.resize(N + 1);
	adj.resize(N + 1);
	HCnt.resize(N + 1);
	GCnt.resize(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> milk[i];
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, 0, 0);

	for (int j = 1; j < 17; ++j)
		for (int i = 1; i <= N; ++i)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];

	for (int i = 0; i < M; ++i)
	{
		int s, d;
		char pref;
		cin >> s >> d >> ws >> pref;
		int x = lca(s, d);
		int numH = HCnt[s] + HCnt[d] - (HCnt[x] << 1) + (milk[x] == 'H');
		int numG = GCnt[s] + GCnt[d] - (GCnt[x] << 1) + (milk[x] == 'G');
		if (pref == 'H')
			cout << (numH > 0);
		else
			cout << (numG > 0);
	}
}