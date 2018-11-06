#include <cstdio>
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", (long long)(1 + 1.5*n*n + 2.5*n) % 45678);
}