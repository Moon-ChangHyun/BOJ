// 16ms, 16752KB

//뤼카의 정리
#include<cstdio>
int combi[2001][2001];
int main()
{
	long long n, k;
	int p;
	scanf("%lld%lld%d", &n, &k, &p);

	for (int i = 0; i <= p; ++i)
		combi[i][0] = 1;
	for (int i = 1; i <= p; ++i)
		for (int j = 1; j <= i; ++j)
			combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % p;
	int ans = 1;
	while (n || k)
	{
		int ni = n % p;
		int ki = k % p;
		ans = (ans * combi[ni][ki]) % p;
		n /= p;
		k /= p;
	}
	printf("%d", ans);
}