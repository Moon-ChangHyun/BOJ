// 32ms, 47316KB

#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int N, L;
int cnt[6];
ll dp[6][6][11][11][11][11][11];

ll func(int prev2, int prev1, int idx)
{
	if (idx == L) return 1;
	ll& ret = dp[prev2][prev1][cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (cnt[i] && i != prev1 && i != prev2)
		{
			--cnt[i];
			ret += func(prev1, i, idx + 1);
			++cnt[i];
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> cnt[i];
		L += cnt[i];
	}
	for (int i = 0; i <= N; ++i)
		for (int j = 0; j <= N; ++j)
			for (int a = 0; a <= cnt[1]; ++a)
				for (int b = 0; b <= cnt[2]; ++b)
					for (int c = 0; c <= cnt[3]; ++c)
						for (int d = 0; d <= cnt[4]; ++d)
							for (int e = 0; e <= cnt[5]; ++e)
								dp[i][j][a][b][c][d][e] = -1;
	cout << func(0, 0, 0);
}