#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
bool adj[101][101];
int dist[101][101], n, m;
int main() {
	int a, b;
	scanf("%d%d", &n, &m);

	for (int i = 0; i != m; ++i) {
		scanf("%d%d", &a, &b);
		adj[a][b] = true;
		adj[b][a] = true;
	}

	for (int i = 1; i <= n; ++i) {
		vector<bool> visit(n + 1, false);
		queue<pair<int, int>> q;
		visit[i] = true;
		q.push({ i, 0 });
		while (!q.empty()) {
			int cur = q.front().first;
			int dst = q.front().second;
			dist[i][cur] = dst;
			q.pop();
			for (int next = 1; next <= n; ++next) {
				if (adj[cur][next] && !visit[next]) {
					visit[next] = true;
					q.push({ next,  dst + 1 });
				}
			}
		}
	}

	int min = 987654321;
	int minP = -1;
	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (int j = 1; j <= n; ++j)
			sum += dist[i][j];
		if (sum < min) {
			min = sum;
			minP = i;
		}
	}
	printf("%d", minP);
}