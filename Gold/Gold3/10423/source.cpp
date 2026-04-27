// 32ms, 3196KB

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct disjointSet {
	vector<int> grpNum;
	vector<int> rank;
	vector<bool> hasGen;
	
	disjointSet(vector<bool>&& gen) : grpNum(gen.size()), rank(gen.size()), hasGen(move(gen)) {
		for (int i = 0; i < grpNum.size(); ++i)
			grpNum[i] = i;
	}

	int find(int u) {
		if (grpNum[u] == u) return u;
		return grpNum[u] = find(grpNum[u]);
	}

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v || hasGen[u] && hasGen[v]) return false;
		if (rank[u] < rank[v]) swap(u, v);
		grpNum[v] = u;
		if (rank[u] == rank[v]) ++rank[u];
		hasGen[u] = hasGen[u] || hasGen[v];
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;

	vector<bool> hasGen(N + 1);
	for (int i = 0; i < K; ++i) {
		int x;
		cin >> x;
		hasGen[x] = true;
	}

	disjointSet ds(move(hasGen));

	vector<pair<int, pair<int, int>>> link; // <비용, <u, v>>
	link.reserve(M);
	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		link.emplace_back(w, make_pair(u, v));
	}
	sort(link.begin(), link.end());

	int cnt = K, ret = 0;
	auto iter = link.begin();
	while (cnt < N) {
		if (ds.merge(iter->second.first, iter->second.second)) {
			++cnt;
			ret += iter->first;
		}
		++iter;
	}
	cout << ret;
}