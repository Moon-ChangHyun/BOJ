// 0ms, 2024KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> parent;
vector<vector<int>> adj;

int getMinforwardingTime(int nd) {
	vector<int> childResults;
	for (auto next : adj[nd]) {
		if (next == parent[nd]) continue;
		childResults.emplace_back(getMinforwardingTime(next));
	}
	if (childResults.empty()) return 0;

	sort(childResults.begin(), childResults.end(), greater<>());

	int ret = 0;
	for (int i = 0; i < childResults.size(); ++i) {
		ret = max(ret, i + 1 + childResults[i]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	adj.resize(N);
	parent.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> parent[i];
	for (int i = 1; i < N; ++i) {
		adj[i].push_back(parent[i]);
		adj[parent[i]].push_back(i);
	}
	cout << getMinforwardingTime(0);
}