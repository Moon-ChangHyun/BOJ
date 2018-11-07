#include<cstdio>
bool adj[501][501];
int N, M, ret;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i != M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u][v] = true;
	}
	for (int i = 1; i <= N; ++i)
		adj[i][i] = true;
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if (adj[i][j] || adj[i][k] && adj[k][j])
					adj[i][j] = true;
	for (int i = 1; i <= N; ++i) {
		bool know = true;
		for (int j = 1; j <= N; ++j)
			if (!adj[i][j] && !adj[j][i]) {
				know = false;
				break;
			}
		ret += know;
	}
	printf("%d", ret);
}