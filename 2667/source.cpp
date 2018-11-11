#include<cstdio>
#include<set>
using namespace std;
int n;
bool map[25][25], visit[25][25];
int dfs(int y, int x) {
	if (!map[y][x] || visit[y][x]) return 0;
	visit[y][x] = true;
	int ret = 1;
	if (y) ret += dfs(y - 1, x);
	if (x) ret += dfs(y, x - 1);
	if (y != n - 1) ret += dfs(y + 1, x);
	if (x != n - 1) ret += dfs(y, x + 1);
	return ret;
}
int main() {
	multiset<int> s;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != n; ++j)
			map[i][j] = getchar() - '0';
		getchar();
	}
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != n; ++j) {
			int x = dfs(i, j);
			if (x) s.insert(x);
		}
	}
	printf("%d\n", s.size());
	for (auto iter : s)
		printf("%d\n", iter);
}