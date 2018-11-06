#include<cstdio>
int main() {
	long long s, a, b, c, r;
	scanf("%lld", &s);
	a = 1;
	c = s + 1;
	b = (a + c) / 2;
	s *= 2;
	while (true) {
		if (a == b) {
			r = a;
			break;
		}
		if (b*(b + 1) <= s) {
			a = b;
			b = (a + c) / 2;
		}
		else {
			c = b;
			b = (a + c) / 2;
		}
	}
	printf("%lld", r);
}