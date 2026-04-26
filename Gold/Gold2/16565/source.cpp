// 0ms, 1124KB

#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

constexpr int MOD = 10007;

int N, combi[53][53];
int dp[14][53];

int func(int num, int r)
{
	if (r < 0) return 0;
	if (num == 14) return r == 0;
	int& ret = dp[num][r];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; ++i)
		ret = (ret + (combi[4][i] * func(num + 1, r - i)) % MOD) % MOD;
	return ret;
}

int main()
{
	scanf("%d", &N);
	combi[0][0] = 1;
	for (int i = 1; i <= 52; ++i)
	{
		combi[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % MOD;
	}
	for (int i = 0; i < 14; ++i)
		for (int j = 0; j <= N; ++j)
			dp[i][j] = -1;
	printf("%d", (combi[52][N] - func(1, N) + MOD) % MOD);
}