#include<cstdio>
int main() {
	int S, K;
	long long ret = 1;
	for (scanf("%d%d", &S, &K); K; --K) {
		int tmp = S / K;
		ret *= tmp;
		S -= tmp;
	}
	printf("%lld", ret);
}