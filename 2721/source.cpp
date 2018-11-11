#include<cstdio>
int main() {
	int T;
	for (scanf("%d", &T); ~--T; ) {
		int n;
		scanf("%d", &n);
		int a = (n * (n + 1) >> 1);
		int b = ((n + 2) * (n + 3) >> 1);
		printf("%d\n", (a * b) >> 1);
	}
}