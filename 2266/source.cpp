#include<cstdio>
short dp[501][2];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= n; ++i)
		dp[i][1] = i;
	for (int j = 2; j <= k; ++j) {
		for (int i = 1; i <= n; ++i) {
			int a = (i - 1) >> 1;
			int b = i - 1 - a;
			for (; dp[a][(j + 1) % 2] > dp[b][j % 2]; --a, ++b);
			dp[i][j % 2] = dp[b][j % 2] + 1;
		}
	}
	printf("%d", dp[n][k % 2]);
}