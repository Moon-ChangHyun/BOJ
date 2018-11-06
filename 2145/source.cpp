#include<cstdio>

int func(int num) {
	while (num / 10 != 0) {
		int x = num;
		int sum = 0;
		while (x) {
			sum += x % 10;
			x /= 10;
		}
		num = sum;
	}
	return num;
}

int main() {
	int n;
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		printf("%d\n", func(n));
	}
}