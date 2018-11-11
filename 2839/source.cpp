#include<cstdio>
int main() {
	int n, x = 0, ret;
	scanf("%d", &n);
	while (true) {
		if (n < 0) {
			ret = -1;
			break;
		}
		if (n % 5 == 0) {
			ret = x + n / 5;
			break;
		}
		n -= 3;
		++x;
	}
	printf("%d", ret);
}