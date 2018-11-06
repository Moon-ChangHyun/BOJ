#include<cstdio>
#include<bitset>
#include<array>
#include<algorithm>
using namespace std;
int N, M, K;
array<bitset<100>, 100> map;
array<bitset<100>, 100> visit;
int dfs(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) return 0;
	if (visit[y][x] || !map[y][x]) return 0;
	visit[y][x] = true;
	int ret = 1;
	ret += dfs(y - 1, x);
	ret += dfs(y, x - 1);
	ret += dfs(y + 1, x);
	ret += dfs(y, x + 1);
	return ret;
}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i != N; ++i)
		for (int j = 0; j != M; ++j) {
			map[i][j] = false;
			visit[i][j] = false;
		}
	for (int i = 0; i != K; ++i) {
		int y, x;
		scanf("%d%d", &y, &x);
		map[y - 1][x - 1] = true;
	}
	int ret = 0;
	for (int i = 0; i != N; ++i)
		for (int j = 0; j != M; ++j)
			ret = max(ret, dfs(i, j));
	printf("%d", ret);
}