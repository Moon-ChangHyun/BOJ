// 180ms, 51612KB

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N, M;
vector<vector<int>> adj;

vector<int> eulerTour;
vector<int> depth;
vector<int> eulerOrder; //노드번호->오일러투어 인덱스

void dfs(int nd, int p, int d)
{
	eulerOrder[nd] = eulerTour.size();
	eulerTour.push_back(nd);
	depth.push_back(d);
	for (auto next : adj[nd])
	{
		if (next != p)
		{
			dfs(next, nd, d + 1);
			eulerTour.push_back(nd);
			depth.push_back(d);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	adj.resize(N + 1);
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int L = 2 * N - 1;
	int lgL = log2(L);
	eulerTour.reserve(L);
	depth.reserve(L);
	eulerOrder.resize(N + 1);
	dfs(1, 0, 0);

	vector<vector<pair<int,int>>> spt(L, vector<pair<int, int>>(lgL + 1));
	for (int i = 0; i < L; ++i)
		spt[i][0] = { depth[i], eulerTour[i] };
	
	for (int j = 1; j <= lgL; ++j)
	{
		for (int i = 0; i + (1 << j) <= L; ++i)
		{
			int rightStart = i + (1 << (j - 1));
			spt[i][j] = (spt[i][j - 1].first < spt[rightStart][j - 1].first ? spt[i][j - 1] : spt[rightStart][j - 1]);
		}
	}

	for (cin >> M; ~--M;)
	{
		int a, b;
		cin >> a >> b;
		a = eulerOrder[a];
		b = eulerOrder[b];
		if (a > b) {
			a ^= b;
			b ^= a;
			a ^= b;
		}
        else if (a == b)
        {
            cout << spt[a][0].second << '\n';
            continue;
        }
		int r = log2(b - a);
		auto& left = spt[a][r];
		auto& right = spt[b - (1 << r)][r];
		cout << (left.first < right.first ? left.second : right.second) << '\n';
	}
}