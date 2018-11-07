#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n, rain;
vector<vector<bool>> visit;
vector<vector<int>> map;

void dfs(int y, int x) {
	visit[y][x] = true;
	if (y && rain < map[y - 1][x] && !visit[y - 1][x]) dfs(y - 1, x);
	if (x && rain < map[y][x - 1] && !visit[y][x - 1]) dfs(y, x - 1);
	if (y < n - 1 && rain < map[y + 1][x] && !visit[y + 1][x]) dfs(y + 1, x);
	if (x < n - 1 && rain < map[y][x + 1] && !visit[y][x + 1]) dfs(y, x + 1);
}

int main() {
	scanf("%d", &n);
	map.resize(n);
	visit.resize(n);
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != n; ++j) {
			int x;
			scanf("%d", &x);
			map[i].push_back(x);
		}
	}
	int ans = 0, cnt;
	while (rain < 100) {
		cnt = 0;
		for (auto& iter : visit) {
			iter.assign(n, false);
		}
		for (int i = 0; i != n; ++i) {
			for (int j = 0; j != n; ++j) {
				if (rain < map[i][j] && !visit[i][j]) {
					dfs(i, j);
					++cnt;
				}
			}
		}
		ans = max(ans, cnt);
		++rain;
	}
	printf("%d", ans);
}