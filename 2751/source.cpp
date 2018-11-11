#include<cstdio>
#include<bitset>
using namespace std;
int main() {
	bitset<2000001> bs;
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		scanf("%d", &x);
		bs[x + 1000000] = true;
	}
	for (int i = 0; i != 2000001; ++i)
		if (bs[i])
			printf("%d\n", i - 1000000);
}