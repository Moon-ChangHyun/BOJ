// 0ms, 2028KB

#include<iostream>
#include<limits>

using namespace std;
using ll = long long;

ll dp[1001];

int main()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= 1000; ++i)
	{
		dp[i] = numeric_limits<ll>::max();
		for (int j = 0; j < min(i, 63); ++j)
		{
			ll x = 1 + ((dp[i - j - 1] + (1LL << j) - 1) << 1);
			if (x > 0 && dp[i] > x)
				dp[i] = x;
		}
	}
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, cnt = 0;
	while (cin >> n) {
		cout << "Case " << ++cnt << ": " << dp[n] << '\n';
	}
}