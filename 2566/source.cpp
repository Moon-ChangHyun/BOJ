#include<cstdio>
int main() {
	int t, r, c, m = 0;
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			scanf("%d", &t);
			if (t > m) {
				m = t;
				r = i;
				c = j;
			}
		}
	}
	printf("%d\n%d %d", m, r, c);
}