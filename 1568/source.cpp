#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	long long n, ret = 0;
	scanf("%lld", &n);
	while (n) {
		long long k = (sqrt(1 + (n << 3)) - 1) / 2.0;
		ret += k;
		n -= ((k * (k + 1)) >> 1);
	}
	printf("%lld", ret);
}