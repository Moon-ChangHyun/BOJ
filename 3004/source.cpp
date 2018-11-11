#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	int a = n >> 1;
	int b;
	if (n % 2) b = a + 1;
	else b = a;
	printf("%d", (a + 1) * (b + 1));
}