#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class disjointSet
{
private:
	vector<int> parent, rank, size;
public:
	disjointSet(int num) : parent(num), rank(num, 1) {
		for (int i = 0; i != num; ++i)
			parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u])
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
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ret = 0;
	cin >> n;
	disjointSet ds(n);
	vector<pair<int, int>> xn(n), yn(n), zn(n);
	for (int i = 0; i != n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		xn[i] = { x, i };
		yn[i] = { y, i };
		zn[i] = { z, i };
	}
	sort(xn.begin(), xn.end());
	sort(yn.begin(), yn.end());
	sort(zn.begin(), zn.end());
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 1; i < n; ++i) {
		pq.push({ -(xn[i].first - xn[i - 1].first), {xn[i].second, xn[i - 1].second} });
		pq.push({ -(yn[i].first - yn[i - 1].first), {yn[i].second, yn[i - 1].second} });
		pq.push({ -(zn[i].first - zn[i - 1].first), {zn[i].second, zn[i - 1].second} });
	}
	while (!pq.empty()) {
		auto edge = pq.top(); pq.pop();
		edge.first = -edge.first;
		if (ds.merge(edge.second.first, edge.second.second))
			ret += edge.first;
	}
	cout << ret;
}