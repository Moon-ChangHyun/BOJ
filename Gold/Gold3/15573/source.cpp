// 1004ms, 96572KB

#include<iostream>
#include<vector>
using namespace std;
int n, m, k;
vector<vector<int>> mine;
vector<vector<bool>> visit;

int dfs(int y, int x, int D) {
	if(y < 0 || y >= n || x < 0 || x >= m || visit[y][x]) return 0;
	visit[y][x] = true;
	if(mine[y][x] > D) return 0;
	int ret = 1;
	ret += dfs(y - 1, x, D);
	ret += dfs(y + 1, x, D);
	ret += dfs(y, x - 1, D);
	ret += dfs(y, x + 1, D);
	return ret;
}

bool canOver(int D) {
	int get = 0;
	for(int i = 0; i != n; ++i)
		for(int j = 0; j != m; ++j)
			visit[i][j] = false;
	for(int j = 0; j != m; ++j)
		get += dfs(0, j, D);
	for(int i = 0; i != n; ++i) {
		get += dfs(i, 0, D);
		get += dfs(i, m - 1, D);
	}
	return get >= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	mine.resize(n, vector<int>(m));
	visit.resize(n, vector<bool>(m));
	for(int i = 0; i != n; ++i)
		for(int j = 0; j != m; ++j)
			cin >> mine[i][j];
	int lo = 0, hi = 1000000;
	while(lo + 1!= hi) {
		int mid = (lo + hi) >> 1;
		if(canOver(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi;
}