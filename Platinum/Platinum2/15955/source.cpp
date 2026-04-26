// 352ms, 23144KB

#include<iostream>
#include<vector>
#include<functional>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int n, q;
int dst, hp;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> edge;//{cost, {num, num}}
vector<pair<pair<int, int>, pair<int, int>>> query;//{{hp, num}, {src, dst}}
vector<bool> answer;
vector<pair<int, int>> pointXN, pointYN, pointXY;

class DisjointSet {
public:
	DisjointSet(int n) : parent(n), rank(n, 1){
		for (int i = 0; i != n; ++i) parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	pointXN.resize(n);
	pointYN.resize(n);
	pointXY.resize(n + 1);
	query.resize(q);
	answer.resize(q);
	DisjointSet ds(n + 1);
	for(int i = 1; i <= n; ++i) {
		cin >> pointXY[i].first >> pointXY[i].second;
		pointXN[i - 1] = {pointXY[i].first, i};
		pointYN[i - 1] = {pointXY[i].second, i};
	}
	sort(pointXN.begin(), pointXN.end());
	sort(pointYN.begin(), pointYN.end());
	for(int i = 0; i < n - 1; ++i) {
		int ds = abs(pointXN[i].first - pointXN[i + 1].first);
		edge.push({ds, {pointXN[i].second, pointXN[i + 1].second}});
		ds = abs(pointYN[i].first - pointYN[i + 1].first);
		edge.push({ds, {pointYN[i].second, pointYN[i + 1].second}});
	}
	for(int i = 0; i != q; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		query[i] = {{c, i}, {a, b}};
	}
	sort(query.begin(), query.end());
	for(auto it : query) {
		while(!edge.empty()) {
			int cost = edge.top().first;
			auto nodes = edge.top().second;
			if(it.first.first < cost) break;
			edge.pop();
			ds.merge(nodes.first, nodes.second);
		}
		answer[it.first.second] = (ds.find(it.second.first) == ds.find(it.second.second));
	}
	for(int i = 0; i != q; ++i)
		cout << (answer[i] ? "YES\n" : "NO\n");
}