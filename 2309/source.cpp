#include<cstdio>
#include<array>
#include<algorithm>
using namespace std;
int main() {
	int n = 0, d1, d2;
	array<int, 9> c;
	for (int i = 0; i != 9; ++i) {
		scanf("%d", &c[i]);
		n += c[i];
	}
	n -= 100;
	for (d1 = 0; d1 != 8; ++d1) {
		for (d2 = d1 + 1; d2 != 9; ++d2) {
			if (c[d1] + c[d2] == n) {
				c[d1] = c[d2] = 0;
				sort(c.begin(), c.end());
				for (int i = 2; i != 9; ++i) printf("%d\n", c[i]);
				return 0;
			}
		}
	}
}