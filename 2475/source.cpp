#include<cstdio>
int r, n;
int main() {
	for (int i = 0; i != 5; ++i) {
		scanf("%d", &n);
		r += n * n;
	}
	printf("%d", r % 10);
}