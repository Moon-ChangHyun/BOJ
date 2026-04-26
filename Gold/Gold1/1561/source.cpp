// 4ms, 2180KB

#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int n, m;
vector<int> runningTime;

ll func(ll lastEnter)
{
	ll cnt = 0;
	for (auto x : runningTime)
		cnt += 1 + lastEnter / x;
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	runningTime.resize(m);
	for (auto& x : runningTime)
		cin >> x;

	ll lastEnter;
	if (n <= m) lastEnter = 0;
	else
	{
		ll lo = 0, hi = n * 30LL;
		while (lo + 1 != hi)
		{
			ll mid = (lo + hi) >> 1;
			if (func(mid) >= n)
				hi = mid;
			else
				lo = mid;
		}
		lastEnter = hi;
	}

	int remain = n - (lastEnter ? func(lastEnter - 1) : 0);
	int i = 0;
	for (; i < m; ++i)
		if (lastEnter % runningTime[i] == 0)
			if (--remain == 0)
				break;
	cout << i + 1;
}