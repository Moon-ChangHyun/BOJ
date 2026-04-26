// 0ms, 1112KB

#include<cstdio>

using ll = long long;

int zeroPadding[11] = { 0,0,10,110,1110,11110,111110,1111110,11111110,111111110,1111111110 };
ll cnt[10], cntInBlock[10] = { 0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000 },
tenSqr[11] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000 };


int getL(int n) //자리수 - 1 리턴
{
	if (n == 0) return -1;
	int l = 0;
	while (tenSqr[l] <= n) ++l;
	return --l;
}

void func(int n)
{
	if (n == 0) return;

	int L = getL(n);
	int K = n / tenSqr[L];
	ll block = K * cntInBlock[L];

	//[0..0 , k-1 0..0)
	for (int i = 0; i < 10; ++i)
		cnt[i] += block;
	for (int i = 0; i < K; ++i)
		cnt[i] += tenSqr[L];

	//[k 0..0 , kx..x]
	int nextN = n - K * tenSqr[L];
	int nL = getL(nextN);
	cnt[0] += (L - 1 - nL) * (nextN + 1);
	cnt[K] += nextN + 1;
	func(nextN);
}

int main()
{
	int n;
	scanf("%d", &n);
	func(n);
	cnt[0] -= zeroPadding[getL(n) + 1];
	--cnt[0]; //1부터 시작
	for (int i = 0; i < 10; ++i)
		printf("%lld ", cnt[i]);
}