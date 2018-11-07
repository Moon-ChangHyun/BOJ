#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = n; ~--i;) {
		for (int j = n - 1 - i; j != 0; --j) printf(" ");
		for (int j = 0; j != i; ++j) printf("*");
		printf("*");
		for (int j = 0; j != i; ++j) printf("*");
		printf("\n");
	}
}