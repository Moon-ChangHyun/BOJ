// 0ms, 1112KB

#include<cstdio>
#include<algorithm>

using namespace std;
using ll = long long;

int main()
{
	ll A, B;
	scanf("%lld%lld", &A, &B);
	ll diff = B - A + 1;
	ll ret = 0;
	int bit = 0;
	while (true)
	{
		ll range = 1LL << (bit + 1);
		ll Q = diff >> (bit + 1);
		ll R = diff - (Q << (bit + 1));
		ll AR = A - ((A >> (bit + 1)) << (bit + 1));
		
		ret += (Q << bit);

		ll D = max(range >> 1, AR);
		ll U = AR + R;
		ret += U <= range ? max(0LL, U - D) : range - D + max(0LL, U - range - (range >> 1));
		if ((1LL << ++bit) > B) break;
	}
	printf("%lld", ret);
}