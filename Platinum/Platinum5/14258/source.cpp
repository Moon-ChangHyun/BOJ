// 468ms, 36420KB

#include<iostream>
#include<vector>
#include<map>

using namespace std;
using ll = long long;

const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

struct disjointSet
{
	int L;
	vector<int> parent;
	vector<int> rank;
	vector<int> groupVal;
	ll groupValSum = 0;

	disjointSet(vector<int>&& vals) : L(vals.size()), parent(L), rank(L, 0), groupVal(move(vals)) {
		for (int i = 0; i < L; ++i)
			parent[i] = i;
	}

	int find(int u)
	{
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v)
	{
		u = find(u); v = find(v);
		if (u == v) return;
		if (rank[u] < rank[v])
			swap(u, v);

		groupValSum -= groupVal[u];
		groupValSum -= groupVal[v];
		parent[v] = u;
		groupVal[u] ^= groupVal[v];
		groupValSum += groupVal[u];
		if (rank[u] == rank[v])
			++rank[u];
	}
};

multimap<int, int> idx;

int n, m, board[1000][1000];
bool checked[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	vector<int> val(n * m); //idx to val
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
			int d1Idx = i * m + j;
			idx.emplace(board[i][j], d1Idx);
			val[d1Idx] = board[i][j];
		}
	}

	disjointSet ds(move(val));

	ll ret = 0;
	int prev = 1000001;

	for (auto rIter = idx.crbegin(); rIter != idx.crend(); ++rIter)
	{
		if (prev != rIter->first)
		{
			ret = max(ret, ds.groupValSum);
			prev = rIter->first;
		}
		int y = rIter->second / m;
		int x = rIter->second % m;

		checked[y][x] = true;
		ds.groupValSum += board[y][x];
		for (int k = 0; k < 4; ++k)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (checked[ny][nx])
				ds.merge(rIter->second, ny * m + nx);
		}
	}
	ret = max(ret, ds.groupValSum);
	cout << ret;
}