#include<cstdio>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	a *= b;
	for (int i = 0; i != 5; ++i) {
		scanf("%d", &b);
		printf("%d ", b - a);
	}
}