#include<cstdio>
int main() {
	int a, b, n, ret;
	scanf("%d%d%d", &a, &b, &n);
	for (int i = 0; i <= n; ++i) {
		ret = a / b;
		a %= b;
		a *= 10;
	}
	printf("%d", ret);
}