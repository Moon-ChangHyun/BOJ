// 412ms, 9804KB

#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
public:
	DisjointSet(int n) : parent(n + 1), rival(n + 1, 0) {
		for (int i = 0; i <= n; ++i) parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	bool setRival(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return false;
		if (rival[u])
			if (rival[v]) {
				parent[rival[v]] = u;
				parent[v] = rival[u];
			}
			else
				parent[v] = rival[u];
		else if (rival[v])
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
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
    cin >> n >> m;
	DisjointSet ds(n);
	bool ret = true;
	for(int i = 0; i != m; ++i) {
		int x, y;
		cin >> x >> y;
		if(ret && !ds.setRival(x, y))
			ret = false;
	}
    cout << (ret ? "POSSIBLE" : "IMPOSSIBLE");
}