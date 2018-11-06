#include<cstdio>

int powerTen[8] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

bool isCopyNum(int num) {
	int sqr = num * num;
	int org = num;
	int jari = 0;
	while (org) {
		org /= 10;
		++jari;
	}
	sqr %= powerTen[jari];
	return sqr == num;
}

int main() {
	int T;
	for (scanf("%d", &T); ~--T; ) {
		int N;
		scanf("%d", &N);
		printf("%s\n", isCopyNum(N) ? "YES" : "NO");
	}
}