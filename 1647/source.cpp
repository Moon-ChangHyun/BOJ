#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class disjointSet {
public:
	disjointSet(int num) : parent(num), rank(num, 0) {
		for (int i = 0; i != num; ++i)
			parent[i] = i;
	}
	int find(int u) {
		if (parent[u] == u)
			return u;
		return parent[u] = find(parent[u]);
	}
	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return false;
		if (rank[u] < rank[v]) {
			u ^= v;
			v ^= u;
			u ^= v;
		}
		parent[v] = u;
		if (rank[u] == rank[v]) ++rank[u];
		return true;
	}
private:
	vector<int> parent;
	vector<int> rank;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<int, pair<int, int>>> edge;
	int ret = 0, N, M, mx = 0;
	cin >> N >> M;
	edge.reserve(M);
	for (int i = 0; i != M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({ w, {u, v} });
	}
	sort(edge.begin(), edge.end());
	disjointSet ds(N + 1);
	for (int i = 0; i != M; ++i) {
		auto& e = edge[i];
		if (ds.merge(e.second.first, e.second.second)) {
			ret += e.first;
			mx = max(mx, e.first);
		}
	}
	ret -= mx;
	cout << ret;
}