#include<cstdio>
int main() {
	int N, M, E, ret = 0;
	scanf("%d%d", &N, &M);
	E = N * M;
	for (int i = 1; i < E; ++i)
		if (i % N == 0 && i % M) ++ret;
	printf("%d", ret);
}