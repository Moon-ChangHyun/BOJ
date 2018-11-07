#include<cstdio>
#include<algorithm>
using namespace std;
int arr[1000], c[1000][2][31];
int t, w;
int f(int x, bool p, int r) {
	if (r < 0 || x == t) return 0;
	int& ret = c[x][p][r];
	if (~ret) return ret;
	ret = (arr[x] == p + 1) ? 1 : 0;
	return ret += max(f(x + 1, p, r), f(x + 1, !p, r - 1));
}
int main() {
	scanf("%d%d", &t, &w);
	for (int i = 0; i != t; ++i) scanf("%d", arr + i);
	for (int i = 0; i != t; ++i)
		for (int j = 0; j != 2; ++j)
			for (int k = 0; k <= w; ++k)
				c[i][j][k] = -1;
	printf("%d", max(f(0, 0, w), f(0, 1, w - 1)));
}