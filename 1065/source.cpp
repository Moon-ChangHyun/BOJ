#include <cstdio>
bool f(int x) {
	int a = x % 10;
	x /= 10;
	int b = x % 10;
	x /= 10;
	int d = b - a;
	while (x) {
		a = b;
		b = x % 10;
		x /= 10;
		if (d != b - a)
			return false;
	}
	return true;
}
int main() {
	int n, ret = 0;
	scanf("%d", &n);
	if (n < 100)
		printf("%d", n);
	else {
		ret = 99;
		for (int i = 100; i <= n; ++i)
			ret += f(i);
		printf("%d", ret);
	}
}