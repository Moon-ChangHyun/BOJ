#include<cstdio>
long long dp[10][66];
long long func(int start, int len) {
	if (len == 1) return 1;
	long long& ret = dp[start][len];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = start; i < 10; ++i)
		ret += func(i, len - 1);
	return ret;
}
int main() {
	for (int i = 0; i != 10; ++i)
		for (int j = 0; j != 66; ++j)
			dp[i][j] = -1;
	int T;
	for (scanf("%d", &T); ~--T; ) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", func(0, n + 1));
	}
}