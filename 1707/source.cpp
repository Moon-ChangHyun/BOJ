#include<cstdio>
#include<vector>
using namespace std;
class DisjointSet {
public:
	DisjointSet(int n) : parent(n), rival(n, -1) {
		for (int i = 0; i != n; ++i) parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	bool setRival(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return false;
		if (rival[u] != -1)
			if (rival[v] != -1) {
				parent[rival[v]] = u;
				parent[v] = rival[u];
			}
			else
				parent[v] = rival[u];
		else if (rival[v] != -1)
			parent[u] = rival[v];
		else {
			rival[u] = v;
			rival[v] = u;
		}
		return true;
	}
private:
	std::vector<int> parent;
	std::vector<int> rival;
};
int main() {
	int k, v, e, a, b, i;
	bool isBipartite;
	for (scanf("%d", &k); ~--k;) {
		scanf("%d%d", &v, &e);
		DisjointSet ds(v + 1);
		isBipartite = true;
		for (i = 0; i != e; ++i) {
			scanf("%d%d", &a, &b);
			if (isBipartite && !ds.setRival(a, b))
				isBipartite = false;
		}
		printf("%s\n", isBipartite ? "YES" : "NO");
	}
}