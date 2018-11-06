#include <cstdio>
#include <vector>
#include <functional>
using namespace std;
int c[500][500];
int main() {
	int M, N, t;
	scanf("%d%d", &M, &N);
	vector<vector<int>> map(M, vector<int>(N));
	for (int i = 0; i != M; ++i)
		for (int j = 0; j != N; ++j) {
			scanf("%d", &map[i][j]);
			c[i][j] = -1;
		}
	c[M - 1][N - 1] = 1;
	function<int(int, int)> f = [&](int y, int x) {
		int& ret = c[y][x];
		if (ret != -1)
			return ret;
		ret = 0;
		if (y > 0 && map[y - 1][x] < map[y][x])
			ret += f(y - 1, x);
		if (x < N - 1 && map[y][x + 1] < map[y][x])
			ret += f(y, x + 1);
		if (y < M - 1 && map[y + 1][x] < map[y][x])
			ret += f(y + 1, x);
		if (x > 0 && map[y][x - 1] < map[y][x])
			ret += f(y, x - 1);
		return ret;
	};
	printf("%d", f(0, 0));
}