#include<cstdio>
#include<bitset>
using namespace std;
int main() {
	bitset<2000001> bs;
	int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 0; i != n; ++i) {
		int x;
		scanf("%d", &x);
		for (int k = x; k <= c; k += x)
			bs[k] = true;
	}
	printf("%d", (int)bs.count());
}