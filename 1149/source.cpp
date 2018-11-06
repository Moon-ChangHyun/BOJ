#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int m[1001][3], c[2][3], n, i;
	bool b = false;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%d%d%d", &m[i][0], &m[i][1], &m[i][2]);
	for (i = 0; i != 3; ++i)
		c[0][i] = m[n][i];
	for (i = n - 1; i > 0; --i) {
		c[!b][0] = m[i][0] + min(c[b][1], c[b][2]);
		c[!b][1] = m[i][1] + min(c[b][0], c[b][2]);
		c[!b][2] = m[i][2] + min(c[b][0], c[b][1]);
		b = !b;
	}
	printf("%d", min(c[b][0], min(c[b][1], c[b][2])));
}