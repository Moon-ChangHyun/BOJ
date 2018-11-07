#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; true; ++i) {
		if (n <= 1 + 3 * i*(i - 1)) {
			printf("%d", i);
			break;
		}
	}
}