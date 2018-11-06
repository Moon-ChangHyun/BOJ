#include <cstdio>
#include <cmath>
#include <bitset>
using namespace std;
int main() {
	bitset<1001> notPrime;
	notPrime[0] = notPrime[1] = true;
	int end = int(sqrt(1000));
	for (int i = 2; i <= end; ++i) {
		if (notPrime[i]) continue;
		for (int j = i * i; j <= 1000; j += i) notPrime[j] = true;
	}
	int n, ret = 0, num;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		scanf("%d", &num);
		if (!notPrime[num]) ++ret;
	}
	printf("%d", ret);
}