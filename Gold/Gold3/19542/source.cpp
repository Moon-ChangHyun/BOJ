// 56ms, 10476KB

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visit;
vector<int> depth;
int N, S, D;

int calcDepth(int p)
{
	visit[p] = true;
	int& d = depth[p];
	for (auto next : adj[p]) {
		if (!visit[next]) {
			d = max(d, calcDepth(next));
		}
	}
	return d += 1;
}

int dfs(int p) {
	visit[p] = true;
	int ret = 1;
	for (auto next : adj[p]) {
		if (!visit[next] && depth[next] > D) {
			ret += dfs(next);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> S >> D;
	adj.resize(N + 1);
	visit.resize(N + 1);
	depth.resize(N + 1);
	for (int i = 1; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	calcDepth(S);
	for (int i = 1; i <= N; ++i)
		visit[i] = false;
	cout << dfs(S) * 2 - 2;
}