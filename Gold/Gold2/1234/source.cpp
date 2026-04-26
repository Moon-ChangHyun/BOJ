// 12ms, 81688KB

#include<cstdio>
using namespace std;
using uc = unsigned char;
using ll = long long;

ll combi[101][101];
ll dp[10][101][101][101];

ll func(uc k, uc r, uc g, uc b)
{
	if (k == 0) return 1LL;
	ll& ret = dp[k - 1][r][g][b];
	if (ret != -1)
		return ret;
	ret = 0;
	if (k % 3 == 0)
	{
		uc unit = k / 3;
		if (r >= unit && g >= unit && b >= unit)
			ret += func(k - 1, r - unit, g - unit, b - unit) * combi[k][unit] * combi[k - unit][unit];
	}
	if (!(k & 1))
	{
		uc unit = k >> 1;
		ll kCombi = combi[k][unit];
		if (r >= unit && g >= unit)
			ret += func(k - 1, r - unit, g - unit, b) * kCombi;
		if (r >= unit && b >= unit)
			ret += func(k - 1, r - unit, g, b - unit) * kCombi;
		if (g >= unit && b >= unit)
			ret += func(k - 1, r, g - unit, b - unit) * kCombi;
	}
	if (r >= k)
		ret += func(k - 1, r - k, g, b);
	if (g >= k)
		ret += func(k - 1, r, g - k, b);
	if (b >= k)
		ret += func(k - 1, r, g, b - k);
	return ret;
}

int main()
{
	for (int i = 0; i <= 100; ++i)
	{
		combi[i][0] = 1;
		for (int j = 1; j <= i; ++j)
		{
			combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
		}
	}

	int N, R, G, B;
	scanf("%d%d%d%d", &N, &R, &G, &B);
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= R; ++j)
			for (int k = 0; k <= G; ++k)
				for (int l = 0; l <= B; ++l)
					dp[i][j][k][l] = -1;

	printf("%lld", func(N, R, G, B));
}