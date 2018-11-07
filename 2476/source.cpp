#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n, a, b, c, m = 0, k;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == b)
			if (b == c)	k = 10000 + a * 1000;
			else k = 1000 + a * 100;
		else if (b == c || a == c) k = 1000 + c * 100;
		else k = 100 * max(a, max(b, c));
		m = max(m, k);
	}
	printf("%d", m);
}