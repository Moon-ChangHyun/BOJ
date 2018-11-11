#include<cstdio>
int main() {
	int money[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
	int C, K;
	scanf("%d%d", &C, &K);
	K = money[K];
	printf("%d", (int)((C / (double)K) + 0.5) * K);
}