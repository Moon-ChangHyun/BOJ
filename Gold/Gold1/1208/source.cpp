// 12ms, 16740KB

#include<cstdio>

constexpr int bias = 2000000;
int N, S, mid, arr[40];
long long ans;
int pSumCnt[4000001]; //-200만~200만

void f(int idx, int sum)
{
	if(idx == mid)
	{
		++pSumCnt[sum + bias];
		return;
	}
	f(idx + 1, sum);
	f(idx + 1, sum + arr[idx]);
}

void g(int idx, int sum)
{
	if(idx == N)
	{
		auto toFind = S - sum + bias;
		if (0 <= toFind && toFind <= 4000000)
			ans += pSumCnt[S - sum + bias];
		return;
	}
	g(idx + 1, sum);
	g(idx + 1, sum + arr[idx]);
}

int main()
{
	scanf("%d%d", &N, &S);
	mid = (N >> 1);
	for(int i = 0; i < N; ++i)
		scanf("%d", arr + i);
	f(0, 0);
	g(mid, 0);
	if (S == 0) --ans;
	printf("%lld", ans);
}