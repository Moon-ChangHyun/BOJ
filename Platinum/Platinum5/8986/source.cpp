// 24ms, 2412KB

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
using ll = long long;

int N;
vector<int> X;

ll diffSum(ll K) //K는 인접 전봇대 간격
{
	ll ret = 0;
	for (int i = 0; i < N; ++i)
		ret += abs(K * i - X[i]);
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	X.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> X[i];

	//인접간격 [lo, hi]
	unsigned lo = 1, hi = 0;
	for (int i = 1; i < N; ++i)
		hi = max(hi, (unsigned)(X[i] - X[i - 1]));

	while (hi - lo > 2)
	{
		unsigned aab = ((lo << 1) + hi) / 3; //내림
		unsigned abb = ((lo + (hi << 1)) + 2) / 3; //올림
		if (diffSum(aab) > diffSum(abb))
			lo = aab;
		else
			hi = abb;
	}

	cout << min({ diffSum(lo), diffSum(lo + 1), diffSum(hi) });
}