// 8ms, 1420KB

#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;
using ll = long long;

int main() {
	vector<bool> isPrime(1000001, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= 1000; ++i)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= 1000000; j += i)
			isPrime[j] = false;
	}
	ll mn, mx;
	scanf("%lld%lld", &mn, &mx);
	int ret = mx - mn + 1;
	vector<bool> determine(ret, true);
	for (int i = 2; ; ++i)
	{
		if (!isPrime[i]) continue;
		ll pns = (ll)i * i;
		if (pns > mx) break;
		for (ll j = pns * ((mn + pns - 1)/pns); j <= mx; j += pns)
		{
			if (determine[j - mn]) --ret;
			determine[j - mn] = false;
		}
	}
	printf("%d", ret);
}