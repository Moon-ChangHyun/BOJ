#include<cstdio>
int f(int a, int b) {
	if (b > a / 2)
		return f(a, a - b);
	return 1 + b * (a - b);
}
int main() {
	int T;
	for (scanf("%d", &T); ~--T;) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", f(n, m));
	}
}