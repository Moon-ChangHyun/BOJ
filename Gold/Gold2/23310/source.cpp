// 16ms, 2544KB

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;
using ll = long long;

constexpr ll inf = 987654321987654;
int N, M, L;
vector<ll> X, ans;
vector<int> firstSkip;

ll func(ll lo, ll hi)
{
	if (hi <= 0)
	{
		if (hi == 0)
			return lo < hi;
		return 0;
	}
	if (lo < 0)
		return hi / L + 1;
	return (hi / L) - (lo / L);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M;
	L = lcm(N, M);
	X.resize(N + 1);
	ans.resize(N + 1, inf);
	for (int i = 1; i <= N; ++i)
		cin >> X[i];
	firstSkip.resize(N + 1);
	for (int i = M; i <= L; i += M)
		firstSkip[i % N] = i;
	firstSkip[N] = firstSkip[0];
	for (int i = 1; i <= N; ++i)
	{
		ll left = -1;
		ll right = (X[i] - 1) * N + i;
		if (firstSkip[i] == 0)
		{
			ans[i] = right;
			continue;
		}
		//(left,right]에 firstSkip + L의 배수가 몇개인가?
		// ->(left - firstSkip, right - firstSkip]에 L의 배수(0이상)가 몇개인가?
		ll q = func(left - firstSkip[i], right - firstSkip[i]);
		if (q == X[i]) continue;

		while (q > 0)
		{
			left = right;
			right += q * N;
			q = func(left - firstSkip[i], right - firstSkip[i]);
		}
		ans[i] = right;
	}
	ll maxAns = inf;
	int ansIdx = -1;
	for (int i = 1; i <= N; ++i)
	{
		if (ans[i] < maxAns)
		{
			maxAns = ans[i];
			ansIdx = i;
		}
	}
	cout << ansIdx;
}