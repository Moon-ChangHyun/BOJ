#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n, w, sel[1002], dp[1002][1002];
short y[1002], x[1002];
inline int dist(int idx1, int idx2) {
	return abs(y[idx1] - y[idx2]) + abs(x[idx1] - x[idx2]);
}
int main() {
	scanf("%d%d", &n, &w);
	for (int i = 2; i <= w + 1; ++i)
		scanf("%hd%hd", y + i, x + i);
	y[0] = x[0] = 1;
	y[1] = x[1] = n;
	sel[0] = 0;
	sel[1] = 1;
	for (int j = 0; j <= w; ++j)
		dp[w + 1][j] = 0;
	for (int i = w + 1; --i; )
		for (int j = -1; ++j < i; )
			dp[i][j] = min(dist(i + 1, i) + dp[i + 1][j], dist(i + 1, j) + dp[i + 1][i]);
	printf("%d\n", dp[1][0]);
	int idx1 = 1, idx2 = 0;
	while (idx1 <= w) {
		if (dp[idx1][idx2] == dist(idx1 + 1, idx1) + dp[idx1 + 1][idx2])
			sel[idx1 + 1] = sel[idx1];
		else {
			sel[idx1 + 1] = 1 - sel[idx1];
			idx2 = idx1;
		}
		printf("%d\n", 1 + sel[++idx1]);
	}
}