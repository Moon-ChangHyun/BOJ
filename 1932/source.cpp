#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, c[500], t[500][500];
	scanf("%d", &n);
	for (int i = 0; i != n; ++i)
		for (int j = 0; j <= i; ++j)
			scanf("%d", &t[i][j]);
	for (int j = 0; j != n; ++j)
		c[j] = t[n - 1][j];
	for (int i = n - 2; i >= 0; --i)
		for (int j = 0; j <= i; ++j)
			c[j] = t[i][j] + max(c[j], c[j + 1]);
	printf("%d", c[0]);
}