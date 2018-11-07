#include <stdio.h>
using namespace std;
int n, k, coins[100], c[10001], num, i, j;
int main() {
	c[0] = 1;
	scanf("%d%d", &n, &k);
	for (i = 0; i != n; ++i)
		scanf("%d", coins + i);
	for (i = 0; i != n; ++i) {
		for (j = k; j != 0; --j) {
			num = 1;
			while (num*coins[i] <= j)
				c[j] += c[j - (num++) * coins[i]];
		}
	}
	printf("%d", c[k]);
}