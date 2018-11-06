#include<cstdio>
int main() {
	int N;
	unsigned long long y = 0, m = 0;
	for (scanf("%d", &N); ~--N; ) {
		long long a;
		scanf("%lld", &a);
		y += (1 + (a / 30)) * 10;
		m += (1 + (a / 60)) * 15;
	}
	if (y == m) printf("Y M %llu", y);
	else if (y < m) printf("Y %llu", y);
	else printf("M %llu", m);
}