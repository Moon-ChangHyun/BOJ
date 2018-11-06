#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, arr[1000][1000], cache[1000][1000][3];
int f(int y, int x, int d) {
	int& ret = cache[y][x][d];
	if (ret != -987654321)
		return ret;
	ret = f(y + 1, x, 0);
	switch (d) {
	case 0:
		if (x > 0)
			ret = max(ret, f(y, x - 1, 2));
		if (x < m - 1)
			ret = max(ret, f(y, x + 1, 1));
		break;
	case 1:
		if (x < m - 1)
			ret = max(ret, f(y, x + 1, 1));
		break;
	case 2:
		if (x > 0)
			ret = max(ret, f(y, x - 1, 2));
	}
	return ret += arr[y][x];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != m; ++j) {
			scanf("%d", &arr[i][j]);
			for (int k = 0; k != 3; ++k)
				cache[i][j][k] = -987654321;
		}
	}
	cache[n - 1][m - 1][0] = arr[n - 1][m - 1];
	for (int j = m - 2; j >= 0; --j) {
		cache[n - 1][j][0] = cache[n - 1][j + 1][0] + arr[n - 1][j];
	}
	printf("%d", f(0, 0, 0));
}