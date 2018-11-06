#include<cstdio>
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int e = b > d ? gcd(b, d) : gcd(d, b);
	int f = b * d / e;
	int g = a * d / e + c * b / e;
	int h = g > f ? gcd(g, f) : gcd(f, g);
	printf("%d %d", g / h, f / h);
}