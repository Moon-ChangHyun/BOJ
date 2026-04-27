// 4ms, 8924KB

#include<cstdio>

using namespace std;

constexpr int MOD = 1000000003;
int N, K, dp[2][1000][1000];

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i)
	{
		dp[0][i][0] = 1;
		dp[1][i][0] = 1;
	}
	dp[0][1][1] = 1;
	for (int i = 2; i < N; ++i)
		for (int j = 1; j <= i; ++j)
			for (int k = 0; k < 2; ++k)
				dp[k][i][j] = (dp[k][i - 1][j] + dp[k][i - 2][j - 1]) % MOD;
	int ret = (dp[0][N - 1][K] + dp[1][N - 2][K - 1]) % MOD;
	printf("%d", ret);
}