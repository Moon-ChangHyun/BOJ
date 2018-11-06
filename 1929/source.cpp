#include <cstdio>
#include <bitset>
using namespace std;
int main() {
	bitset<1000001> notPrime;
	notPrime[0] = notPrime[1] = true;
	for (int i = 2; i <= 1000; ++i) {
		if (notPrime[i]) continue;
		for (int j = i * i; j <= 1000000; j += i) notPrime[j] = true;
	}
	int n, m, ret = 0;
	scanf("%d%d", &n, &m);
	for (int i = n; i <= m; ++i) {
		if (!notPrime[i]) printf("%d\n", i);
	}
}