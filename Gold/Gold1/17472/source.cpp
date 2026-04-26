// 0ms, 2032KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

constexpr int INF = 987654;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

struct disjointSet {
	int cnt;
	disjointSet(int sz) : parent(sz), rank(sz, 1), cnt(sz) {
		for (int i = 0; i < sz; ++i)
			parent[i] = i;
	}
	int find(int u)
	{
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	bool merge(int u, int v)
	{
		u = find(u), v = find(v);
		if (u == v) return false;
		if (rank[u] < rank[v])
			swap(u, v);
		parent[v] = u;
		if (rank[u] == rank[v])
			++rank[u];
		--cnt;
		return true;
	}
private:
	vector<int> parent, rank;
};

int N, M, cnt;
vector<int> edgePos[7][4];
vector<vector<int>> map;
vector<vector<bool>> visit;
int adj[7][7];

void getEdgePos(int y, int x)
{
	visit[y][x] = true;
	map[y][x] = cnt;
	int pos = y * M + x;
	if (y)
	{
		if (map[y - 1][x])
		{
			if (!visit[y - 1][x])
				getEdgePos(y - 1, x);
		}
		else
			edgePos[cnt][0].push_back(pos);
	}
	if (x < M - 1)
	{
		if (map[y][x + 1])
		{
			if (!visit[y][x + 1])
				getEdgePos(y, x + 1);
		}
		else
			edgePos[cnt][1].push_back(pos);	
	}
	if (y < N - 1)
	{
		if (map[y + 1][x])
		{
			if (!visit[y + 1][x])
				getEdgePos(y + 1, x);
		}
		else
			edgePos[cnt][2].push_back(pos);
	}
	if (x)
	{
		if (map[y][x - 1])
		{
			if (!visit[y][x - 1])
				getEdgePos(y, x - 1);
		}
		else
			edgePos[cnt][3].push_back(pos);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M;
	map.resize(N, vector<int>(M));
	visit.resize(N, vector<bool>(M));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
			map[i][j] *= -1;
		}
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (map[i][j] && !visit[i][j]) {
				++cnt;
				getEdgePos(i, j);
			}

	for (int i = 1; i <= cnt; ++i)
	{
		for (int j = 1; j <= cnt; ++j)
			adj[i][j] = INF;
		adj[i][i] = 0;
	}

	for (int i = 1; i <= cnt; ++i)
	{
		for (int k = 0; k < 4; ++k)
		{
			for (auto pos : edgePos[i][k])
			{
				int y = pos / M, x = pos % M;
				int dist = 0;
				while (true)
				{
					y += dy[k], x += dx[k];
					if (y < 0 || y >= N || x < 0 || x >= M)
						break;
					int other = map[y][x];
					if (other)
					{
						if (other != i && dist >= 2)
							adj[i][other] = min(adj[i][other], dist);
						break;
					}
					++dist;
				}
			}
		}
	}

	vector<pair<int, pair<int, int>>> bridges; //<길이,<섬1,섬2>>

	for (int i = 2; i <= cnt; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (adj[i][j] < INF)
			{
				bridges.emplace_back(adj[i][j], make_pair(i, j));
			}
		}
	}
	
	sort(bridges.begin(), bridges.end());

	disjointSet ds(cnt + 1);
	int ret = 0;

	for (auto& bridge : bridges)
	{
		if (ds.merge(bridge.second.first, bridge.second.second))
		{
			ret += bridge.first;
			if (ds.cnt == 2)
				break;
		}
	}

	cout << (ds.cnt == 2 ? ret : -1);
}