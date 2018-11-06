#include<cstdio>
#include<algorithm>
using namespace std;
int n, arr[500][500], c[500][500];
int f(int y, int x) {
	int& ret = c[y][x];
	if (ret) return ret;
	if (y != n - 1 && arr[y][x] < arr[y + 1][x])
		ret = max(ret, f(y + 1, x));
	if (y && arr[y][x] < arr[y - 1][x])
		ret = max(ret, f(y - 1, x));
	if (x != n - 1 && arr[y][x] < arr[y][x + 1])
		ret = max(ret, f(y, x + 1));
	if (x && arr[y][x] < arr[y][x - 1])
		ret = max(ret, f(y, x - 1));
	return ++ret;
}
int main() {
	int ret = 0;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != n; ++j)
			scanf("%d", &arr[i][j]);
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != n; ++j)
			ret = max(ret, f(i, j));
	printf("%d", ret);
}