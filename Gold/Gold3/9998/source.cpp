// 140ms, 6708KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int N, halfN;
vector<ll> Y, D;

ll needTask(ll mid) //중앙 블럭 수
{
	ll ret = 0;
	int counter = halfN;
	for (int i = 0; i < halfN; ++i) //감소
	{
		ll cri = mid + counter--;
		ret += abs(cri - Y[i]);
		ret += abs(cri - D[i]);
	}
	for (int i = halfN; i < N; ++i) //증가
	{
		ll cri = mid + counter++;
		ret += abs(cri - Y[i]);
		ret += abs(cri - D[i]);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	halfN = N >> 1;
	Y.resize(N);
	D.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> Y[i];
	for (int i = 0; i < N; ++i)
		cin >> D[i];
	ll lo = 0, hi = 1'000'000'000'000 - halfN;
	while (hi - lo > 2)
	{
		ll aab = ((lo << 1) + hi) / 3; //내림
		ll abb = (lo + (hi << 1)); //올림
		if (abb % 3)
			abb = abb / 3 + 1;
		else
			abb = abb / 3;

		if (needTask(aab) > needTask(abb))
			lo = aab;
		else
			hi = abb;
	}
	cout << min({ needTask(lo), needTask(lo + 1), needTask(hi) });
}