#include<cstdio>
#include<bitset>
using namespace std;
bitset<10001> notPrime;
int main() {
	notPrime[0] = notPrime[1] = true;
	for (int i = 2; i <= 100; ++i) {
		if (notPrime[i]) continue;
		for (int j = i * i; j <= 10000; j += i) notPrime[j] = true;
	}
	int n, m, min, s;
	scanf("%d%d", &n, &m);
	int i = n;
	for (; i <= m; ++i)
		if (!notPrime[i]) {
			min = i;
			break;
		}
	if (i > m) printf("-1");
	else {
		s = min;
		for (++i; i <= m; ++i)
			if (!notPrime[i]) s += i;
		printf("%d\n%d", s, min);
	}
}