// 0ms, 2292KB

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

struct disjointSet {
	vector<int> parent, rank, size;
	disjointSet(int sz) : parent(sz), rank(sz), size(sz, 1) {
		for (int i = 0; i < sz; ++i)
			parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	int merge(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return size[u];
		if (rank[u] < rank[v])
			swap(u, v);
		parent[v] = u;
		if (rank[u] == rank[v])
			++rank[u];
		return size[u] += size[v];
	}
};

int main()
{
	ios::sync_with_stdio(false);
	int N, total = 0;
	cin >> N;
	multimap<int, pair<int, int>> edges;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < N; ++j) {
			if (s[j] != '0')
			{
				int dist = s[j];
				if (dist >= 'a') dist -= 96;
				else dist -= 38;
				edges.emplace(dist, make_pair(i, j));
				total += dist;
			}
		}
	}
	
	disjointSet ds(N);
	int sum = 0;
	for (auto& edge : edges) {
		int dist = edge.first;
		int i = edge.second.first;
		int j = edge.second.second;
		if (i == j || ds.find(i) == ds.find(j)) continue;
		sum += dist;
		if (ds.merge(i, j) == N)
			break;
	}
	if (ds.size[ds.find(0)] == N)
		cout << total - sum;
	else
		cout << -1;
}