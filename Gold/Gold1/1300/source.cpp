// 36ms, 1116KB

#include<cstdio>
#include<algorithm>

using namespace std;
using ll = long long;

int N, k;

bool func(ll x)
{
    ll cnt = 0;
    int i = x / N;
    cnt += i * (ll)N;
    int iMax = min((ll)N, x);
    for (;++i <= iMax;)
        cnt += x / i;
    return cnt >= k;
}

int main()
{
    scanf("%d%d", &N, &k);
    if (k == 1)
    {
        printf("1");
        return 0;
    }
    ll lo = 1, hi = N * (ll)N;
    while (lo + 1 != hi)
    {
        ll mid = (lo + hi) >> 1;
        if (func(mid))
            hi = mid;
        else
            lo = mid;
    }
    printf("%lld", hi);
}