// 60ms, 1388KB

#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

class disjointSet {
public:
	disjointSet(int sz) : parent(sz + 1), dist(sz + 1, 0) {
		for (int i = 0; i <= sz; ++i) parent[i] = i;
	}
	pair<int, int> find(int u) {
		pair<int&, int&> res = { parent[u], dist[u] };
		if (u == parent[u]) return res;
		auto res2 = find(parent[u]);
		res.first = res2.first;
		res.second += res2.second;
		return res;
	}
	void merge(int u, int v) {
		auto rootV = find(v);
		if (u == rootV.first) return;
		parent[u] = rootV.first;
		dist[u] = rootV.second + abs(v - u) % 1000;
	}
private:
	vector<int> parent;
	vector<int> dist;
};

int main() {
	int T;
	for (scanf("%d", &T); ~--T; ) {
		int N;
		scanf("%d", &N);
		disjointSet ds(N);
		while (true) {
			char op;
			scanf(" %c", &op);
			if (op == 'O') break;
			else if (op == 'E') {
				int u;
				scanf("%d", &u);
				printf("%d\n", ds.find(u).second);
			}
			else {
				int u, v;
				scanf("%d%d", &u, &v);
				ds.merge(u, v);
			}
		}
	}
}