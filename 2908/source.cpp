#include<cstdio>
int main() {
	int a, b, ca = 0, cb = 0;
	scanf("%d%d", &a, &b);
	while (a) {
		ca *= 10;
		ca += a % 10;
		a /= 10;
	}
	while (b) {
		cb *= 10;
		cb += b % 10;
		b /= 10;
	}
	printf("%d", ca > cb ? ca : cb);
}
