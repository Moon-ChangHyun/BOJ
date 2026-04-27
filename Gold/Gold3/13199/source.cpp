// 12ms, 1116KB

#include<cstdio>
#include<cmath>
int main() {
	int T;
	for (scanf("%d", &T); ~--T;) {
		int p, m, f, c;
		scanf("%d%d%d%d", &p, &m, &f, &c);
		int coupon = c * (m / p);
		int s = (coupon ? (int)floor((coupon - c) / (double)(f - c)): 0);
		int d = coupon / f;
		printf("%d\n", s - d);
	}
}