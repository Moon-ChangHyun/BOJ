#include<cstdio>
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		if (!(n%i)) --k;
		if (!k) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
}