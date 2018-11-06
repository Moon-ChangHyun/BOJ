#include<cstdio>
int main() {
	long long N, ret = 0;
	scanf("%lld", &N);
	for (int a = 0; a < N; ++a)
		ret += N * a + a;
	printf("%lld", ret);
}