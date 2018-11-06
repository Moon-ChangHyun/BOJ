#include<cstdio>
int main() {
	int n;
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		int ret = 1;
		while (n) {
			int x = n % 10;
			n /= 10;
			if (x == 1) ret += 2;
			else if (x == 0) ret += 4;
			else ret += 3;
			++ret;
		}
		printf("%d\n", ret);
	}
}