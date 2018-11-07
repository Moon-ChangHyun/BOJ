#include<cstdio>
#include<set>
using namespace std;

bool arr[100][100];
int m, n, k;

void fill(int sX, int sY, int eX, int eY) {
	for (int i = sY; i != eY; ++i)
		for (int j = sX; j != eX; ++j)
			arr[i][j] = true;
}

int dfs(int y, int x) {
	arr[y][x] = true;
	int ret = 1;
	if (y && !arr[y - 1][x]) ret += dfs(y - 1, x);
	if (x && !arr[y][x - 1]) ret += dfs(y, x - 1);
	if (y < m - 1 && !arr[y + 1][x]) ret += dfs(y + 1, x);
	if (x < n - 1 && !arr[y][x + 1]) ret += dfs(y, x + 1);
	return ret;
}

int main() {
	scanf("%d%d%d", &m, &n, &k);
	for (int i = 0; i != k; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		fill(a, b, c, d);
	}
	multiset<int> ms;
	for (int i = 0; i != m; ++i) {
		for (int j = 0; j != n; ++j) {
			if (!arr[i][j]) {
				ms.insert(dfs(i, j));
			}
		}
	}
	printf("%d\n", ms.size());
	for (auto& iter : ms) {
		printf("%d ", iter);
	}
}
