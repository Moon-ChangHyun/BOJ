// 412ms, 22492KB

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int K, N, M, aps[1001], bps[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin >> K >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> aps[i];
		aps[i] += aps[i - 1];
	}
	for (int i = 1; i <= M; ++i)
	{
		cin >> bps[i];
		bps[i] += bps[i - 1];
	}
	int ret = 0;
	map<int, int> cnt;
	for (int i = 2; i <= N; ++i)
	{
		for (int j = i; j <= N; ++j)
		{
			int val = aps[j] - aps[i - 1];
			if (val == K)
				++ret;
			else if (val < K)
				++cnt[val];
			val = aps[N] - val;
			if (val == K)
				++ret;
			else if (val < K)
				++cnt[val];
		}
	}
	if (aps[N] == K)
		++ret;
	else if (aps[N] < K)
		++cnt[aps[N]];

	for (int i = 2; i <= M; ++i)
	{
		for (int j = i; j <= M; ++j)
		{
			int val = bps[j] - bps[i - 1];
			if (val == K)
				++ret;
			else if (val < K)
			{
				auto it = cnt.find(K - val);
				if (it != cnt.end())
					ret += it->second;
			}
			val = bps[M] - val;
			if (val == K)
				++ret;
			else if (val < K)
			{
				auto it = cnt.find(K - val);
				if (it != cnt.end())
					ret += it->second;
			}
		}
	}
	if (bps[M] == K)
		++ret;
	else if (bps[M] < K)
		ret += cnt[K - bps[M]];
	cout << ret;
}