#include<cstdio>
int main() {
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	printf("%d\n%d\n%d\n%d", n1 * (n2 % 10), n1 * ((n2 % 100) / 10), n1 * ((n2 % 1000) / 100), n1*n2);
}