// 32ms, 5984KB

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
using ll = long long;

int totalPrice;
vector<bool> isPrime;
int N, cnt[10001];
vector<pair<int, int>> candy;
vector<ll> dp;

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		++cnt[x];
		totalPrice += x;
	}
	
	if (totalPrice <= 1)
	{
		cout << 0;
		return 0;
	}

	isPrime.assign(totalPrice + 1, true);
	isPrime[0] = isPrime[1] = false;
	int sqrtTP = sqrt(totalPrice);
	for (int i = 2; i <= sqrtTP; ++i)
	{
		for (int j = i * i; j <= totalPrice; j += i)
			isPrime[j] = false;
	}

	candy.reserve(N);
	for (int i = 0; i <= 10000; ++i)
		if (cnt[i] > 0)
			candy.emplace_back(i, cnt[i]);

	dp.assign(totalPrice + 1, 0);
	dp[0] = 1 + cnt[0];
	
	int ps = 0;
	for (auto& c : candy)
	{
		if (c.first == 0) continue;
		for (int m = ps; ~m; --m)
		{
			for (int i = 1; i <= c.second; ++i)
			{
				int next = m + i * c.first;
				if (next > totalPrice) break;
				dp[next] += dp[m];
			}
		}
		ps += c.first * c.second;
	}

	ll ret = 0;
	for (int i = 0; i <= totalPrice; ++i)
		if (isPrime[i])
			ret += dp[i];
	cout << ret;
}