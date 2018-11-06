#include<cstdio>
int f(int a, int b, int c) {
	if (b == 0) return 1 % c;
	if (b % 2)
		return (a%c * (long long)f(a, b - 1, c)) % c;
	else {
		long long half = f(a, b / 2, c);
		return (half*half) % c;
	}
}
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d", f(a, b, c));
}