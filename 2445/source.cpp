#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i != n; ++i) {
		for (int j = 0; j != i; ++j) printf("*");
		for (int j = (n - i) * 2; j != 0; --j) printf(" ");
		for (int j = 0; j != i; ++j) printf("*");
		printf("\n");
	}
	for (int i = n * 2; i != 0; --i) printf("*");
	printf("\n");
	for (int i = n - 1; i != 0; --i) {
		for (int j = 0; j != i; ++j) printf("*");
		for (int j = (n - i) * 2; j != 0; --j) printf(" ");
		for (int j = 0; j != i; ++j) printf("*");
		printf("\n");
	}
}