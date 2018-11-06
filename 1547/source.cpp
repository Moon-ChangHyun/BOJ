#include <iostream>
int main() {
	int m, a, b;
	scanf("%d", &m);
	int ball = 1;
	for (int i = 0; i != m; ++i) {
		scanf("%d%d", &a, &b);
		if (a != b) {
			if (a == ball)
				ball = b;
			else if (b == ball)
				ball = a;
		}
	}
	printf("%d", ball);
}