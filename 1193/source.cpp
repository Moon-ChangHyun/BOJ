#include<cstdio>
int main() {
	int X, n = 1;
	int c, p;
	scanf("%d", &X);
	while (n*(n + 1) / 2 < X) ++n;
	X -= 1 + (n - 1)*n / 2;
	if (n % 2) {
		c = n - X;
		p = 1 + X;
	}
	else {
		c = 1 + X;
		p = n - X;
	}
	printf("%d/%d", c, p);
}