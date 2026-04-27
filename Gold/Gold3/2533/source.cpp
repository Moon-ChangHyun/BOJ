// 1120ms, 74332KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
vector<int> parent, dpA, dpB;
vector<vector<int>> adj;

int getB(int);

int getA(int node) { // node가 얼리어답터 아닌 경우
	int& ret = dpA[node];
	if (ret != -1) return ret;
	ret = 0;
	for (auto next : adj[node]) {
		if (next == parent[node]) continue;
		parent[next] = node;
		ret += getB(next);
	}
	return ret;
}

int getB(int node) { //node가 얼리어답터인 경우
	int& ret = dpB[node];
	if (ret) return ret;
	ret = 1;
	for (auto next : adj[node]) {
		if (next == parent[node]) continue;
		parent[next] = node;
		ret += min(getA(next), getB(next));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	dpA.resize(N + 1, -1);
	dpB.resize(N + 1);
	parent.resize(N + 1);
	adj.resize(N + 1);
	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << min(getA(1), getB(1));
}