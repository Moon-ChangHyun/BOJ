#include<cstdio>
int N, K;
int dp[201][201];
int f(int a, int b) {
	if (a < 0)
		return 0;
	if (b == 1)
		return 1;
	int& ret = dp[a][b];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i <= N; ++i)
		ret = (ret + f(a - i, b - 1)) % 1000000000;
	return ret;
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i <= N; ++i)
		for (int j = 0; j <= K; ++j)
			dp[i][j] = -1;
	printf("%d", f(N, K));
}