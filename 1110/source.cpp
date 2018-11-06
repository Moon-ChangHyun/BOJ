#include <iostream>
int main() {
	int n;
	scanf("%d", &n);
	int t = n;
	int i = 0;
	while (true) {
		int ten = t / 10;
		int one = t % 10;
		t = (ten + one) % 10 + one * 10;
		++i;
		if (n == t) break;
	}
	printf("%d", i);
}