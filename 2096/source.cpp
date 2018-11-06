#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<array<int, 3>, 100001> c;
array<array<char, 3>, 100001> map;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j != 3; ++j)
			scanf("%d", &map[i][j]);
	for (int j = 0; j != 3; ++j) {
		map[0][j] = 0;
		c[n][j] = map[n][j];

	}
	for (int i = n - 1; i >= 0; --i) {
		c[i][0] = map[i][0] + max(c[i + 1][0], c[i + 1][1]);
		c[i][1] = map[i][1] + max(c[i + 1][0], max(c[i + 1][1], c[i + 1][2]));
		c[i][2] = map[i][2] + max(c[i + 1][1], c[i + 1][2]);
	}
	printf("%d ", c[0][1]);
	for (int i = n - 1; i >= 0; --i) {
		c[i][0] = map[i][0] + min(c[i + 1][0], c[i + 1][1]);
		c[i][1] = map[i][1] + min(c[i + 1][0], min(c[i + 1][1], c[i + 1][2]));
		c[i][2] = map[i][2] + min(c[i + 1][1], c[i + 1][2]);
	}
	printf("%d", c[0][1]);
}