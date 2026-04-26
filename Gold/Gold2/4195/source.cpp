// 160ms, 20092KB

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class disjointSet
{
private:
	vector<int> parent, rank, size;
public:
	disjointSet(int num) : parent(num), rank(num, 1), size(num, 1) {
		for (int i = 0; i != num; ++i)
			parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u])
			return u;
		return parent[u] = find(parent[u]);
	}
	int merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return size[u];
		if (rank[u] < rank[v]) {
			u ^= v;
			v ^= u;
			u ^= v;
		}
		parent[v] = u;
		if (rank[u] == rank[v]) ++rank[u];
		size[u] += size[v];
		return size[u];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	for (cin >> T; ~--T; ) {
		int F, idx = 0;
		cin >> F;
		map<string, int> m;
		disjointSet ds((F << 1) + 1);
		for (int i = 0; i < F; ++i) {
			string name1, name2;
			cin >> name1 >> name2;
			auto& id1 = m[name1];
			auto& id2 = m[name2];
			if (!id1) id1 = ++idx;
			if (!id2) id2 = ++idx;
			cout << ds.merge(id1, id2) << '\n';
		}
	}
}