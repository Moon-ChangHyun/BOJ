// 244ms, 79368KB

#include<cstdio>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;
using ll = long long;

ll ret;
map<int, int> cube;

bool func(int l, int w, int h)
{
	int x = min({ l, w, h });
	if (x == 0) return true;
	if (cube.empty()) return false;
	auto iter = cube.upper_bound(x);
	if (iter == cube.begin()) return false;
	iter = prev(iter, 1);
	x = iter->first;
	int y = min({ l / x, w / x, h / x });
	y = min(y, (int)floor(pow(iter->second, 1 / 3.0)));
	int z = x * y;
	ll remove = (ll)y * y * y;
	ret += remove;
	if ((iter->second -= remove) == 0)
		cube.erase(iter);
	if (!func(l - z, z, z))
		return false;
	if (!func(z, w - z, z))
		return false;
	if (!func(l - z, w - z, z))
		return false;
	if (!func(l, w, h - z))
		return false;
	return true;
}

int main()
{
	int L, W, H, N;
	scanf("%d%d%d%d", &L, &W, &H, &N);
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		cube.emplace_hint(cube.end(), (1 << a), b);
	}
	if (func(L, W, H))
		printf("%lld", ret);
	else
		printf("-1");
}