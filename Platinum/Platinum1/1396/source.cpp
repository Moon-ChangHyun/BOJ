// 428ms, 21992KB

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class disjointSet {
public:
	disjointSet(int sz) : parent(sz + 1), size(sz + 1, 1), rank(sz + 1, 0) {
		for (int i = 0; i <= sz; ++i) parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		if (rank[u] < rank[v]) {
			u ^= v;
			v ^= u;
			u ^= v;
		}
		parent[v] = u;
		if (rank[u] == rank[v]) {
			++rank[u];
		}
		size[u] += size[v];
	}
	vector<int> size; //집합의 크기
private:
	vector<int> parent;
	vector<int> rank;
};

map<int, pair<int, int>> edges; // 간선번호(가중치), {정점1, 정점2}
pair<int, int> querys[100000];
int lo[100000], hi[100000]; // (,]
vector<int> midCache[100000]; //mid값이 인덱스인 쿼리 번호들
int cAnswer[100000], vAnswer[100000]; //온도 답, 정점 수 답
int N, M, Q;

void pSearch() {
	disjointSet ds(N);
	int i = 0;
	for (auto iter = edges.begin(); iter != edges.end(); ++iter, ++i) {
		int k = iter->first;
		int u = iter->second.first;
		int v = iter->second.second;
		ds.merge(u, v);
		for (auto qn : midCache[i]) {
			int a = ds.find(querys[qn].first);
			int b = ds.find(querys[qn].second);
			if (a == b) {
				hi[qn] = i;
				cAnswer[qn] = k;
				vAnswer[qn] = ds.size[a];
			}
			else {
				lo[qn] = i;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	disjointSet dsFull(N);
	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[w] = { u, v };
		dsFull.merge(u, v);
	}

	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int x, y;
		cin >> x >> y;
		querys[i] = { x, y };
		lo[i] = -1;
		hi[i] = -1;
		int a = dsFull.find(x);
		int b = dsFull.find(y);
		if (a == b) {
			hi[i] = M - 1;
			cAnswer[i] = edges.crbegin()->first;
			vAnswer[i] = dsFull.size[a];
		}
	}
	
	while (true) {
		for (int i = 0; i < M; ++i)
			midCache[i].clear();
		bool allClear = true;
		for (int i = 0; i < Q; ++i) {
			if (lo[i] + 1 < hi[i]) {
				midCache[(lo[i] + hi[i]) >> 1].push_back(i);
				allClear = false;
			}
		}
		if (allClear) break;
		pSearch();
	}

	for (int i = 0; i < Q; ++i) {
		if (hi[i] == -1)
			cout << "-1\n";
		else
			cout << cAnswer[i] << ' ' << vAnswer[i] << '\n';
	}
}