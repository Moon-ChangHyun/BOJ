#include<cstdio>
int N, M, f[41] = { 1, 1 };
int main() {
	for (int i = 2; i <= 40; ++i)
		f[i] = f[i - 1] + f[i - 2];
	scanf("%d%d", &N, &M);
	int ret = 1, start = 1;
	for (int i = 0; i != M; ++i) {
		int x;
		scanf("%d", &x);
		ret *= f[x - start];
		start = x + 1;
	}
	ret *= f[N + 1 - start];
	printf("%d", ret);
}