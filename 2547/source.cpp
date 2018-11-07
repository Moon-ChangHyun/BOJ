#include<cstdio>
int main() {
	int T;
	for (scanf("%d", &T); ~--T; ) {
		int N;
		scanf("%d", &N);
		long long ret = 0;
		for (int i = 0; i != N; ++i) {
			long long x;
			scanf("%lld", &x);
			ret += x % N;
		}
		ret %= N;
		printf("%s\n", ret ? "NO" : "YES");
	}
}