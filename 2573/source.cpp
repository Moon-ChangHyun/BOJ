#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<bool>> visit;

void aging() {
	vector<vector<int>> tmp(N, vector<int>(M));
	for (int i = 0; i != N; ++i) {
		for (int j = 0; j != M; ++j) {
			tmp[i][j] = map[i][j];
			if (map[i][j] != 0) {
				int cnt = 0;
				cnt += (map[i - 1][j] == 0);
				cnt += (map[i + 1][j] == 0);
				cnt += (map[i][j - 1] == 0);
				cnt += (map[i][j + 1] == 0);
				tmp[i][j] = max(0, map[i][j] - cnt);
			}
		}
	}
	map = move(tmp);
}

void dfs(int y, int x) {
	visit[y][x] = true;
	if (map[y - 1][x] > 0 && !visit[y - 1][x]) dfs(y - 1, x);
	if (map[y][x - 1] > 0 && !visit[y][x - 1]) dfs(y, x - 1);
	if (map[y + 1][x] > 0 && !visit[y + 1][x]) dfs(y + 1, x);
	if (map[y][x + 1] > 0 && !visit[y][x + 1]) dfs(y, x + 1);
}

int main() {
	int ret = 0;
	scanf("%d%d", &N, &M);
	map.resize(N, vector<int>(M));
	visit.resize(N, vector<bool>(M, false));
	for (int i = 0; i != N; ++i)
		for (int j = 0; j != M; ++j)
			scanf("%d", &map[i][j]);
	int cnt;
	while (true) {
		aging();
		++ret;
		cnt = 0;
		for (int i = 0; i != N; ++i)
			for (int j = 0; j != M; ++j)
				visit[i][j] = false;
		for (int i = 0; i != N; ++i) {
			for (int j = 0; j != M; ++j) {
				if (map[i][j] > 0 && !visit[i][j]) {
					dfs(i, j);
					++cnt;
				}
			}
		}
		if (cnt == 0) {
			printf("0");
			break;
		}
		if (cnt > 1) {
			printf("%d", ret);
			break;
		}
	}
}