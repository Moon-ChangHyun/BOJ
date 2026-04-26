// 440ms, 40532KB

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, k, board[2001][2001], dist[2001][2001];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

class disjointSet {
public:
    int connected;
	disjointSet(int n) : connected(0), parent(n), rank(n, 1) {
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
        ++connected;
	}
private:
	std::vector<int> parent;
	std::vector<int> rank;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ret = 0;
	cin >> n >> k;
	disjointSet ds(k + 1);
	queue<pair<int, int>> q;
	for(int i = 1; i <= k; ++i) {
		int y, x;
		cin >> y >> x;
		board[y][x] = i;
		q.push({y, x});
		for(int dir = 0; dir != 4; ++dir) {
			int ny = y + dy[dir], nx = x + dx[dir];
			if(ny <= 0 || nx <= 0 || ny > n || nx > n)
				continue;
			if(board[ny][nx])
				ds.merge(board[y][x], board[ny][nx]);
		}
	}
	while(ds.connected != k - 1) {
		int y = q.front().first, x = q.front().second;
		q.pop();
		for(int dir = 0; dir != 4; ++dir) {
			int ny = y + dy[dir], nx = x + dx[dir];
			if(ny <= 0 || nx <= 0 || ny > n || nx > n)
				continue;
			if(board[ny][nx] == 0) {
				board[ny][nx] = board[y][x];
				q.push({ny, nx});
				dist[ny][nx] = dist[y][x] + 1;
				ret = max(ret, dist[ny][nx]);
				for(int iDir = 0; iDir != 4; ++iDir) {
					int nny = ny + dy[iDir], nnx = nx + dx[iDir];
					if(nny <= 0 || nnx <= 0 || nny > n || nnx > n)
						continue;
					if(board[nny][nnx] && board[y][x] != board[nny][nnx])
						ds.merge(board[ny][nx], board[nny][nnx]);
				}
			}
		}
	}
	cout << ret;
}