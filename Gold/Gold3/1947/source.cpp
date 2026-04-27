// 4ms, 1112KB

#include<cstdio>

using ll = long long;
constexpr int MOD = 1000000000;
int dpA[2], dpB[2] = {0, 1};

int main()
{
	int N;
	scanf("%d", &N);
	for (ll i = 2; i <= N; ++i)
	{
		dpA[i & 1] = ((i - 1) * (dpB[(i - 1) & 1])) % MOD;
		dpB[i & 1] = ((i - 1) * dpB[(i - 1) & 1] + dpA[(i - 1) & 1]) % MOD;
	}
	printf("%d", dpA[N & 1]);
}