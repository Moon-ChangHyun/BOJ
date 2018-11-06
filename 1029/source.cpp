#include<cstdio>
#include<algorithm>
int n;
int adj[16][16], cache[10][16][1 << 15];

int dfs(int val, int pos, int visit) {
	int& ret = cache[val][pos][visit];
	if (ret)
		return ret;
	for (int next = 1; next <= n; ++next) {
		if (adj[pos][next] >= val && !(visit & 1 << (next - 1)))
			ret = std::max(ret, dfs(adj[pos][next], next, (visit | (1 << (next - 1)))));
	}
	return ret += 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%1d", &adj[i][j]);
		}
	}
	printf("%d", dfs(0, 1, 1));
}