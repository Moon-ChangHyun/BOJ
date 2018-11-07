#include<cstdio>
int main() {
	int n, i = 0;
	for (scanf("%d", &n); ++i <= n; printf("\n"))
		for (int j = 0; j != i; ++j) printf("*");
	for (--i; ~--i; printf("\n"))
		for (int j = 0; j != i; ++j) printf("*");
}