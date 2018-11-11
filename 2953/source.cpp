#include <cstdio>
int main() {
	int a = 0, b = 0, n;
	for (int i = 0; i != 5; ++i) {
		int s = 0;
		for (int j = 0; j != 4; ++j) {
			scanf("%d", &n);
			s += n;
		}
		if (s > b) {
			a = i + 1;
			b = s;
		}
	}
	printf("%d %d", a, b);
}