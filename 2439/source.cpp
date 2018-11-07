#include <iostream>
int main() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		int j = 0;
		for (; j != n - i; ++j) printf(" ");
		for (; j != n; ++j) printf("*");
		printf("\n");
	}
}