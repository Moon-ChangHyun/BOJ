// 72ms, 3984KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct disjointSet {
	vector<int> grpNum;
	vector<int> rank;
	disjointSet(int num) : grpNum(num), rank(num) {
		for (int i = 0; i < num; ++i) {
			grpNum[i] = i;
		}
	}

	int find(int u) {
		if (grpNum[u] == u) return u;
		return grpNum[u] = find(grpNum[u]);
	}

	void merge(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return;
		if (rank[u] < rank[v])
			swap(u, v);
		grpNum[v] = u;
		if (rank[u] == rank[v]) ++rank[u];
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, Q;
	cin >> N >> Q;
	vector<pair<int, int>> logs(N);
	for (int i = 0; i < N; ++i) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		logs[i] = { x1, x2 };
	}
	vector<int> orderedLogNum(N);
	for (int i = 0; i < N; ++i)
		orderedLogNum[i] = i;
	
	sort(orderedLogNum.begin(), orderedLogNum.end(), [&logs](int a, int b) {
		return logs[a] < logs[b];
		});
	disjointSet ds(N);
	int prev = 0;
	for (int i = 1; i < N; ++i) {
		auto& curLog = orderedLogNum[i];
		auto& prevLog = orderedLogNum[prev];
		if (logs[curLog].second <= logs[prevLog].second)
			ds.merge(prevLog, curLog);
		else {
			if (logs[prevLog].second >= logs[curLog].first)
				ds.merge(prevLog, curLog);
			prev = i;
		}
	}

	for (int q = 0; q < Q; ++q) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		cout << (ds.find(a) == ds.find(b) ? '1' : '0') << '\n';
	}
}