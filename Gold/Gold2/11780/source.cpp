// 32ms, 2100KB

#include<iostream>
#include<vector>
using namespace std;

constexpr int INF = 987654321;
int n, m, adj[101][101], via[101][101];

void reconstruct(int u, int v, vector<int>& path) {
	if (!via[u][v]) {
		path.push_back(u);
		if (u != v)
			path.push_back(v);
	}
	else {
		int w = via[u][v];
		reconstruct(u, w, path);
		path.pop_back();
		reconstruct(w, v, path);
	}
}

vector<int> shortestPath(int u, int v) {
	vector<int> path;
	if (u != v && adj[u][v] < INF)
		reconstruct(u, v, path);
	return move(path);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			adj[i][j] = INF;
	for (int i = 1; i <= n; ++i)
		adj[i][i] = 0;
	for (int i = 0; i != m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (adj[a][b] > c)
			adj[a][b] = c;
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					via[i][j] = k;
					adj[i][j] = adj[i][k] + adj[k][j];
				}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << (adj[i][j] < INF ? adj[i][j] : 0) << ' ';
		cout << '\n';
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			vector<int> path = shortestPath(i, j);
			if (path.size() == 1)
				cout << "0\n";
			else {
				cout << path.size() << ' ';
				for (auto iter : path) cout << iter << ' ';
				cout << '\n';
			}
		}
	}
}