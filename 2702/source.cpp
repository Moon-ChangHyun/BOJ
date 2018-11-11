#include<cstdio>
int gcd(int p, int q) {
	return q ? gcd(q, p % q) : p;
}
int main() {
	int t, a, b, g;
	for (scanf("%d", &t); ~--t;) {
		scanf("%d%d", &a, &b);
		g = a > b ? gcd(a, b) : gcd(b, a);
		printf("%d %d\n", a * b / g, g);
	}
}