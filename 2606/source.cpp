#include<cstdio>
bool visit[101], adj[101][101];
int n, m;
int dfs(int a) {
	if (visit[a]) return 0;
	visit[a] = true;
	int ret = 1;
	for (int i = 1; i <= n; ++i) {
		if (adj[a][i]) {
			ret += dfs(i);
		}
	}
	return ret;
}

int main() {
	int x, y;
	scanf("%d%d", &n, &m);
	for (int i = 0; i != m; ++i) {
		scanf("%d%d", &x, &y);
		adj[x][y] = true;
		adj[y][x] = true;
	}
	printf("%d", dfs(1) - 1);
}