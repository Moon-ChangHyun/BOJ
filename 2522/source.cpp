#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i != n; ++i) {
		for (int j = n - i; j != 0; --j) printf(" ");
		for (int j = 0; j != i; ++j) printf("*");
		printf("\n");
	}
	for (int i = 0; i != n; ++i) printf("*");
	printf("\n");
	for (int i = n - 1; i != 0; --i) {
		for (int j = n - i; j != 0; --j) printf(" ");
		for (int j = 0; j != i; ++j) printf("*");
		printf("\n");
	}
}