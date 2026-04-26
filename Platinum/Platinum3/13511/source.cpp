// 252ms, 66200KB

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N, M;
vector<vector<pair<int,int>>> adj;
vector<int> depth;
vector<long long> dist;
vector<int> eulerTour; //오일러 투어 순서
vector<vector<int>> binAnc; //binParent[i][j] = i번 노드의 2^j번째 조상
vector<int> eulerTourIdx; //노드번호->오일러투어인덱스
vector<vector<pair<int, int>>> spt;
vector<int> path; //탐색중 경로

void dfs(int nd, int p, long long l)
{
	depth[nd] = path.size();
	path.push_back(nd);
	dist[nd] = l;
	eulerTourIdx[nd] = eulerTour.size();
	eulerTour.push_back(nd);

	for (int i = 1; i <= depth[nd]; i <<= 1)
	{
		int anc = *(path.rbegin() + i);
		binAnc[nd].push_back(anc);
	}

	for (auto& next : adj[nd])
	{
		if (next.first == p) continue;
		dfs(next.first, nd, l + next.second);
		eulerTour.push_back(nd);
	}
	path.pop_back();
}

int lca(int u, int v)
{
	if (u == v) return u;
	u = eulerTourIdx[u];
	v = eulerTourIdx[v];
	if (u > v)
	{
		u ^= v;
		v ^= u;
		u ^= v;
	}
	int r = log2(v - u);
	auto& left = spt[u][r];
	auto& right = spt[v - (1 << r)][r];
	return left.first < right.first ? left.second : right.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	adj.resize(N + 1);
	for (int i = 1; i < N; ++i)
	{
		int u, v, x;
		cin >> u >> v >> x;
		adj[u].emplace_back(v, x);
		adj[v].emplace_back(u, x);
	}
	depth.resize(N + 1, -1);
	dist.resize(N + 1, -1);
	binAnc.resize(N + 1);
	eulerTourIdx.resize(N + 1, -1);
	path.reserve(N);
	int L = 2 * N - 1;
	int lgL = log2(L);
	eulerTour.reserve(L);
	dfs(1, 0, 0);
	spt.resize(L, vector<pair<int, int>>(lgL + 1));
	for (int i = 0; i < L; ++i)
		spt[i][0] = { depth[eulerTour[i]], eulerTour[i] };
	for (int j = 1; j <= lgL; ++j)
	{
		for (int i = 0; i + (1 << j) <= L; ++i)
		{
			int rightStart = i + (1 << (j - 1));
			spt[i][j] = (spt[i][j - 1].first < spt[rightStart][j - 1].first ? spt[i][j - 1] : spt[rightStart][j - 1]);
		}
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int op, u, v, k;
		cin >> op >> u >> v;
		int anc = lca(u, v);
		if (op == 1)
		{
			cout << dist[u] + dist[v] - 2 * dist[anc] << '\n';
		}
		else
		{
			cin >> k;
			--k;
			int lh = depth[u] - depth[anc];
			if (k > lh)
			{
				k = depth[u] + depth[v] - 2 * depth[anc] - k;
				u = v;
			}
			for (int j = 17; ~--j ;)
			{
				if ((1 << j) <= k)
				{
					u = binAnc[u][j];
					k -= (1 << j);
				}
			}
			cout << u << '\n';
		}
	}
}