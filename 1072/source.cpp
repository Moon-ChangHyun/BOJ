#include<cstdio>
#include<cmath>
using namespace std;

long long getPercent(long long total, long long win) {
	return win * 100 / total;
}

int main() {
	while (true) {
		long long x, y, z, ld, hd;
		if (scanf("%lld%lld", &x, &y) == EOF) break;
		z = getPercent(x, y);
		if (z >= 99) printf("-1\n");
		else {
			ld = 0;
			hd = (long long)ceil(99 * x - 100 * y);
			while (ld + 1 != hd) {
				long long mid = (ld + hd) >> 1;
				if (getPercent(x + mid, y + mid) > z) hd = mid;
				else ld = mid;
			}
			printf("%lld\n", hd);
		}
	}
}