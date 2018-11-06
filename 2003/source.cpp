#include<cstdio>
using namespace std;
unsigned int a[10001];
int n, m, ret;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		unsigned int x;
		scanf("%u", &x);
		a[i] = a[i - 1] + x;
	}
	int lo = 0, hi = 1;
	while (true) {
		int diff = a[hi] - a[lo];
		if (hi == n) {
			if (diff <= m) {
				if (diff == m)
					++ret;
				break;
			}
			++lo;
		}
		else {
			if (diff <= m) {
				if (diff == m)
					++ret;
				++hi;
			}
			else {
				++lo;
			}
		}
	}
	printf("%d", ret);
}