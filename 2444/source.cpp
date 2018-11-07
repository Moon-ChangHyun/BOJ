#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		for (int j = n - 1 - i; j != 0; --j) printf(" ");
		for (int j = 1 + 2 * i; j != 0; --j) printf("*");
		printf("\n");
	}
	for (int i = n; --i;) {
		for (int j = n - i; j != 0; --j) printf(" ");
		for (int j = i * 2 - 1; j != 0; --j) printf("*");
		printf("\n");
	}
}