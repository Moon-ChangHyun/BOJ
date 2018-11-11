#include<cstdio>
int main() {
	int n, m, j, ret = 0;
	scanf("%d%d%d", &n, &m, &j);
	int l = 1, r = m;
	for (int i = 0; i != j; ++i) {
		int x;
		scanf("%d", &x);
		if (x < l) {
			ret += l - x;
			l = x;
			r = l + m - 1;
		}
		else if (r < x) {
			ret += x - r;
			r = x;
			l = r - m + 1;
		}
	}
	printf("%d", ret);
}