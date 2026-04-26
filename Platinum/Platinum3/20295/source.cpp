// 152ms, 21864KB

#include<iostream>
#include<vector>

using namespace std;

int N, M;
int candyCnt[6];
int trailCandy[100001][6];
int candy[100001], depth[100001];
int parent[100001][17];
vector<int> adj[100001];

void dfs(int nd, int p)
{
	parent[nd][0] = p;
	depth[nd] = depth[p] + 1;
	for (int i = 1; i <= 5; ++i)
		trailCandy[nd][i] = trailCandy[p][i];
	++trailCandy[nd][candy[nd]];
	for (auto x : adj[nd])
		if (x != p)
			dfs(x, nd);
}

int lca(int u, int v)
{
	int dU = depth[u];
	int dV = depth[v];
	if (dU < dV) {
		swap(u, v);
		swap(dU, dV);
	}
	for (int i = 17; ~--i; )
		if (depth[parent[u][i]] >= dV)
			u = parent[u][i];
	if (u == v)
		return u;
	for (int i = 17; ~--i; )
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
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> candy[i];
		++candyCnt[candy[i]];
	}
	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for (int j = 1; j < 17; ++j)
		for (int i = 1; i <= N; ++i)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
	cin >> M;
	int prev, a, b; //위치, 사탕
	cin >> a >> b;
	if (candyCnt[b] > 0)
		cout << "PLAY\n";
	else
		cout << "CRY\n";
	prev = a;
	for (int i = 1; i < M; ++i)
	{
		cin >> a >> b;
		int x = lca(prev, a);
		if (trailCandy[prev][b] + trailCandy[a][b] - (trailCandy[x][b] << 1) + (candy[x] == b) > 0)
			cout << "PLAY\n";
		else
			cout << "CRY\n";
		prev = a;
	}
}