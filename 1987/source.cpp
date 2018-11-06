#include<cstdio>
#include<algorithm>
char map[20][20];
bool visit[26];
using namespace std;
int r, c;
int dfs(int y, int x) {
	if (visit[map[y][x] - 'A']) return 0;
	visit[map[y][x] - 'A'] = true;
	int ret = 0;
	if (y) ret = max(ret, dfs(y - 1, x));
	if (x) ret = max(ret, dfs(y, x - 1));
	if (y != r - 1) ret = max(ret, dfs(y + 1, x));
	if (x != c - 1) ret = max(ret, dfs(y, x + 1));
	visit[map[y][x] - 'A'] = false;
	return 1 + ret;
}

int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i != r; ++i)
		for (int j = 0; j != c; ++j)
			scanf(" %c", &map[i][j]);
	printf("%d", dfs(0, 0));
}