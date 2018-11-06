#include<cstdio>
int main() {
	long long n, i, num, ret = 0;
	scanf("%lld", &n);
	for (i = 1, num = 1; (num *= 10) <= n; ++i)
		ret += (num - num / 10) * i;
	ret += i * (1 + n - (num / 10));
	printf("%lld", ret);
}