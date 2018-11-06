#include<cstdio>
#include<cmath>
int main() {
	int t;
	for (scanf("%d", &t); ~--t; ) {
		int x, y;
		scanf("%d%d", &x, &y);
		int d = y - x;
		int m = ceil(sqrt(d));
		printf("%d\n", d < m * m - m + 1 ? 2 * m - 2 : 2 * m - 1);
	}
}