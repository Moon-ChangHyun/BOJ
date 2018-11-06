#include<iostream>
int cache[31][31];
int bridge(int n, int m) {
	if (n == 1) return m;
	int& ret = cache[n][m];
	if (ret) return ret;
	n--;
	for (int i = m-1; i != n-1; --i)
		ret += bridge(n , i);
	return ret;
}
int main() {
	int T, N, M;
	scanf("%d", &T);
	for (int i = 0; i != T; ++i) {
		scanf("%d%d", &N, &M);
		printf("%d\n", bridge(N, M));
	}
}