// 128ms, 6184KB

#include<vector>
#include<iostream>
using namespace std;

int N, M, K;

vector<vector<int>> adj;
vector<bool> visit;
vector<int> groupVal;
vector<int> groupSize;
vector<int> candy;
vector<int> dp;

pair<int, int>& operator+=(pair<int, int>& a, const pair<int, int>& b) {
	a.first += b.first;
	a.second += b.second;
	return a;
}

pair<int, int> dfs(int nd) {
	visit[nd] = true;
	pair<int, int> ret = { 1, candy[nd] };
	for (auto next : adj[nd]) {
		if (!visit[next]) 
			ret += dfs(next);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	candy.resize(N);
	visit.resize(N);
	adj.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> candy[i];
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	groupSize.reserve(N + 1);
	groupVal.reserve(N + 1);
	for (int i = 0; i < N; ++i) {
		if (!visit[i]) {
			auto res = dfs(i);
			if (res.first < K) {
				groupSize.push_back(res.first);
				groupVal.push_back(res.second);
			}
		}
	}
	M = groupSize.size();
	dp.resize(K + 1);

	groupVal.push_back(0);
	groupSize.push_back(0);
	for (int j = M; ~--j; )
		for (int i = 0; i < K; ++i)
			if (i + groupSize[j] < K)
				dp[i] = max(dp[i], groupVal[j] + dp[i + groupSize[j]]);
	cout << dp[0];
}