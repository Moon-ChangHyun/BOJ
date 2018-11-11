#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", !(n % 400) || (!(n % 4) && n % 100) ? 1 : 0);
}