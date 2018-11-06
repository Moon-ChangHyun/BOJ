#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;
bool adj[1001][1001];
bool visit[1001];
int N, M, V;
void DFS(int v) {
	visit[v] = true;
	printf("%d ", v);
	for (int next = 1; next <= N; ++next)
		if (adj[v][next] && !visit[next])
			DFS(next);
}
int main() {
	int a, b;
	scanf("%d%d%d", &N, &M, &V);
	for (int i = 0; i != M; ++i) {
		scanf("%d%d", &a, &b);
		adj[a][b] = adj[b][a] = true;
	}
	DFS(V);
	printf("\n");
	memset(visit, 0, N + 1);
	visit[V] = true;
	queue<int> q;
	q.push(V);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		printf("%d ", front);
		for (int next = 1; next <= N; ++next) {
			if (adj[front][next] && !visit[next]) {
				q.push(next);
				visit[next] = true;
			}
		}
	}
}