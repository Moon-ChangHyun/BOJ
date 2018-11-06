#include<cstdio>
#include<algorithm>
int f(int n) {
	int a, b;
	if (n < 2) return 0;
	a = f(n / 2) + (n & 1);
	b = f(n / 3) + n % 3;
	return 1 + std::min(a, b);
}
main() {
	int n;
	scanf("%d", &n);
	printf("%d", f(n));
}