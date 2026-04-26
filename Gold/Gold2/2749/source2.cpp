// 4ms, 1116KB

#include <cstdio>
int main() {
	int fibo[3] { 0,1 };
	long long n;
	scanf("%lld", &n);
	n %= 1500000;
	for (int i = 2; i <= n; ++i)
		fibo[i % 3] = (fibo[(i - 1) % 3] + fibo[(i - 2) % 3]) % 1000000;
	printf("%d", fibo[n % 3]);
}