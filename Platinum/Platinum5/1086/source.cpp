// 504ms, 28936KB

#include<iostream>
#include<vector>
#include<string>

using namespace std;
using ll = long long;

int N, K, digits; //자리수
vector<string> v;
vector<int> inputNumMods; //v[i] % K
vector<int> tenPowMods; //10의 거듭제곱꼴 % K
vector<vector<ll>> dp;
ll factorial[16]{1};

int bigNumMod(const string& number)
{
	int result = 0;
	for (int i = 0; i < number.size(); ++i)
		result = (result * 10 + (number[i] - '0')) % K;
	return result;
}

ll func(int notVisit, int target, int len) 
{
	if (notVisit == 0)
		return target == 0;
	ll& ret = dp[notVisit][target];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < N; ++i)
	{
		if (notVisit & (1 << i))
		{
			int a = inputNumMods[i];
			int b = tenPowMods[len - v[i].size()];
			ret += func(notVisit & ~(1 << i), (target - ((a * b) % K) + K) % K, len - v[i].size());
		}
	}
	return ret;
}

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 1; i <= 15; ++i)
		factorial[i] = i * factorial[i - 1];
	cin >> N;
	v.resize(N);
	int L = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
		L += v[i].size();
	}
	cin >> K;
	inputNumMods.resize(N);
	for (int i = 0; i < N; ++i)
		inputNumMods[i] = bigNumMod(v[i]);
	tenPowMods.resize(L);
	tenPowMods[0] = 1 % K;
	for (int i = 1; i < L; ++i)
		tenPowMods[i] = (tenPowMods[i - 1] * 10) % K;
	dp.resize(1 << N, vector<ll>(K, -1));
	ll p = func((1 << N) - 1, 0, L);
	ll q = factorial[N];
	ll g = gcd(q, p);
	cout << p / g << '/' << q / g;
}