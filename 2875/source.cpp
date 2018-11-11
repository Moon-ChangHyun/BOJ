#include<cstdio>
#include<cmath>
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	while (k && n < (m << 1)) {
		--k;
		--m;
	}
	while (k && n != (m << 1)) {
		--k;
		--n;
	}
	if (n < (m << 1))
		m = (n >> 1);
	m -= std::ceil(k / 3.0);
	printf("%d", m);
}