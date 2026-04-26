#include<iostream>
#include<vector>
// 148ms, 24188KB

#include<functional>
#include<cmath>

using namespace std;

constexpr int upperD = 17;

vector<int> depth;
vector<vector<int>> parent;

void makeSPT() {
	int N;
	cin >> N;
	vector<vector<int>> adj(N + 1);
	depth.resize(N + 1);
	parent.resize(N + 1, vector<int>(upperD, 0));

	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	function<void(int,int)> dfs = [&adj, &dfs](int nd, int p) {
		depth[nd] = depth[p] + 1;
		parent[nd][0] = p;
		for (auto child : adj[nd]) {
			if (child == p) continue;
			dfs(child, nd);
		}
	};
	dfs(1, 0);

	for (int j = 1; j < upperD; ++j) {
	    for (int i = 2; i <= N; ++i) {
	    	parent[i][j] = parent[parent[i][j - 1]][j - 1];
	    }
    }
}

int getLCA(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	int dV = depth[v];

	for (int i = upperD; ~--i;) {
		if (depth[parent[u][i]] >= dV) {
			u = parent[u][i];
		}
	}

	if (u == v) 
		return u;

	for (int i = upperD; ~--i;) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	return parent[u][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	makeSPT();

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		cout << getLCA(u, v) << '\n';
	}
}