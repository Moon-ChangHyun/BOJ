#include<cstdio>
int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int ret = 0, mn = c * d;
	if (b * d < mn) {
		mn = b * d;
		ret = 1;
	}
	if (a * b < mn) {
		mn = a * b;
		ret = 2;
	}
	if (a * c < mn) {
		mn = a * c;
		ret = 3;
	}
	printf("%d", ret);
}