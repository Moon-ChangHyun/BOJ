// 228ms, 2808KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int N, K, D;
	cin >> N >> K >> D;
	vector<pair<int,int>> data(N + 1);// 실력, 지식
	for (int i = 1; i <= N; ++i)
	{
		int M, d;
		cin >> M >> data[i].first;
		for (int j = 0; j < M; ++j)
		{
			int x;
			cin >> x;
			data[i].second |= (1 << x);
		}
	}
	sort(data.begin(), data.end());

	int l = 1, r = 1, ans = 0;
	vector<int> counts(K + 1);
	while (true)
	{
		while (true)
		{
			for (int i = 1; i <= K; ++i)
				if (data[r].second & (1 << i))
					++counts[i];
			if (++r > N || data[r].first - data[l].first > D)
				break;
		}

		int sumCnt = 0, interCnt = 0;
		for (int i = 1; i <= K; ++i)
		{
			if (counts[i]) ++sumCnt;
			if (r - l == counts[i]) ++interCnt;
		}
		ans = max(ans, (r - l) * (sumCnt - interCnt));
		if (r > N) break;
		while (true)
		{
			for (int i = 1; i <= K; ++i)
				if (data[l].second & (1 << i))
					--counts[i];
			if (data[r].first - data[++l].first <= D)
				break;
		}
	}
	std::cout << ans;
}