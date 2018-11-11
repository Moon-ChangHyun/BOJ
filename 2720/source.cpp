#include<cstdio>
int main() {
	int T;
	for (scanf("%d", &T); ~--T;) {
		int C, x;
		scanf("%d", &C);
		x = 0;
		while (x * 25 <= C) ++x;
		printf("%d ", --x);
		C -= x * 25;
		x = 0;
		while (x * 10 <= C) ++x;
		printf("%d ", --x);
		C -= x * 10;
		x = 0;
		while (x * 5 <= C) ++x;
		printf("%d ", --x);
		C -= x * 5;
		printf("%d\n", C);
	}
}