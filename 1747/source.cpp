#include<cstdio>
#include<cmath>
using namespace std;

int powerTen[8] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

int overPalindrom(int num) {
	int a = num;
	int b = 0;
	int n = 0;
	while (num) {
		++n;
		b *= 10;
		b += num % 10;
		num /= 10;
	}
	num = a;
	n >>= 1;
	b %= powerTen[n];
	a /= powerTen[n];
	a *= powerTen[n];
	a += b;
	if (num <= a)
		return a;
	else {
		a /= powerTen[n];
		++a;
		a *= powerTen[n];
		return overPalindrom(a);
	}
}

bool isPrime(int num) {
	int end = sqrt(num);
	for (int i = 2; i <= end; ++i)
		if (num % i == 0) return false;
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("2");
		return 0;
	}
	n = overPalindrom(n);
	while (!isPrime(n)) {
		n = overPalindrom(n + 1);
	}
	printf("%d", n);
}