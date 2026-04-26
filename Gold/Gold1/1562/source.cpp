// 0ms, 5152KB

#include<cstdio>

constexpr int all = (1 << 10) - 1;
constexpr int MOD = 1000000000;
int N, dp[101][10][all + 1];

int func(int len, int prev, int visit)
{
	int& ret = dp[len][prev][visit];
	if (ret != -1) return ret;	
	if (len == 0)
		return visit == all;
	ret = 0;
	if (prev != 0)
		ret = (ret + func(len - 1, prev - 1, visit | (1 << (prev - 1)))) % MOD;
	if (prev != 9)
		ret = (ret + func(len - 1, prev + 1, visit | (1 << (prev + 1)))) % MOD;
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i <= N; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k <= all; ++k)
				dp[i][j][k] = -1;
	int ans = 0;
	for (int i = 1; i <= 9; ++i)
		ans = (ans + func(N - 1, i, (1 << i))) % MOD;
	printf("%d", ans);
}