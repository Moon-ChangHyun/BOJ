#include <cstdio>
#include <vector>
class DisjointSet {
public:
	DisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i != n; ++i) parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) {
			u ^= v;
			v ^= u;
			u ^= v;
		}
		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
private:
	std::vector<int> parent;
	std::vector<int> rank;
};

int main() {
	int n, m, op, a, b;
	scanf("%d%d", &n, &m);
	auto djs = DisjointSet(n + 1);
	for (int i = 0; i != m; ++i) {
		scanf("%d%d%d", &op, &a, &b);
		if (op)
			printf("%s\n", djs.find(a) == djs.find(b) ? "YES" : "NO");
		else
			djs.merge(a, b);
	}
}