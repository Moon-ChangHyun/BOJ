#include <cstdio>
#include <algorithm>
using namespace std;
int n, stairs[300], cache[299][2];
int f(int p, bool oneStep) {
	if (p == n) return -987654321;
	if (p == n - 1) return stairs[n - 1];
	int& ret = cache[p][oneStep];
	if (ret) return ret;
	if (oneStep) return ret = stairs[p] + f(p + 2, false);
	return ret = stairs[p] + max(f(p + 1, true), f(p + 2, false));
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i != n; ++i)
		scanf("%d", stairs + i);
	printf("%d", max(f(0, false), f(1, false)));
}