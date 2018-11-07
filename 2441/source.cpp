#include <iostream>
int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i != n; ++i) {
		int j = 0;
		for (; j != i; ++j) printf(" ");
		for (; j != n; ++j) printf("*");
		printf("\n");
	}
}