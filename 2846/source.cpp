#include<cstdio>
int n, r, s, p, c;
int main() {
	scanf("%d%d", &n, &p);
	for (int i = 1; i != n; ++i) {
		scanf("%d", &c);
		if (p >= c) {
			r = r > s ? r : s;
			s = 0;
		}
		else
			s += c - p;
		p = c;
	}
	printf("%d", r > s ? r : s);
}