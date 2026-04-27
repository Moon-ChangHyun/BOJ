// 0ms, 1240KB

#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class disjointSet {
public:
	disjointSet(int sz) : parent(sz + 1), rank(sz + 1, 0) {
		for (int i = 1; i <= sz; ++i)
			parent[i] = i;
	}
	int find(int u) {
		if (parent[u] == u) return u;
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
		if (rank[u] == rank[v])
			++rank[u];
		return true;
	}
private:
	vector<int> parent;
	vector<int> rank;
};

int main() {
	int n;
	double ret = 0;
	scanf("%d", &n);
	vector<pair<float, float>> points(n);
	for (auto& point : points) {
		scanf("%f%f", &point.first, &point.second);
	}
	vector<pair<double, pair<int, int>>> edges;
	edges.reserve(n * (n - 1) / 2);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			double dist = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
			edges.push_back({ dist, {i + 1, j + 1} });
		}
	}
	sort(edges.begin(), edges.end());
	auto ds = disjointSet(n);
	for (auto& edge : edges) {
		if (ds.merge(edge.second.first, edge.second.second))
			ret += sqrt(edge.first);
	}
	printf("%f", ret);
}