#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n, m, a = 1001, b = 1001;
	scanf("%d%d", &n, &m);
	for (int i = 0; i != m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		a = min(a, x);
		b = min(b, y);
	}
	int pn = n / 6, rem = n % 6;
	if (rem && rem * b > a)
		printf("%d", min(n * b, (pn + 1) * a));
	else
		printf("%d", min(n * b, pn * a + rem * b));
}