#include<cstdio>
#include<array>
#include<bitset>
using namespace std;
array<bitset<50>, 50> visit, map;
int T, N, M, K;
bool dfs(int y, int x) {
	if (!map[y][x] || visit[y][x]) return false;
	visit[y][x] = true;
	if (y) dfs(y - 1, x);
	if (x) dfs(y, x - 1);
	if (y != N - 1) dfs(y + 1, x);
	if (x != M - 1) dfs(y, x + 1);
	return true;
}
int main() {
	scanf("%d", &T);
	for (int t = 0; t != T; ++t) {
		scanf("%d%d%d", &M, &N, &K);
		for (int i = 0; i != N; ++i)
			for (int j = 0; j != M; ++j)
				map[i][j] = visit[i][j] = false;
		for (int i = 0; i != K; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			map[y][x] = true;
		}
		int ret = 0;
		for (int i = 0; i != N; ++i)
			for (int j = 0; j != M; ++j)
				if (dfs(i, j)) ++ret;
		printf("%d\n", ret);
	}
}