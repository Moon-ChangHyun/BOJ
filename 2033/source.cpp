#include<cstdio>
int main() {
	int N, cmp = 1;
	scanf("%d", &N);
	while (true) {
		if (N <= cmp * 10) break;
		int tmp = (N / cmp) % 10;
		N -= tmp * cmp;
		if (tmp >= 5)
			N += cmp * 10;
		cmp *= 10;
	}
	printf("%d", N);
}