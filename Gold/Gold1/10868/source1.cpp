// 56ms, 8672KB

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int spt[17][100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> spt[0][i];
	for (int i = 1; i < 17; ++i)
	{
		int len = 1 << i;
		if (len > N) break;
		for (int j = 0; j < N; ++j)
			spt[i][j] = min(spt[i - 1][j], spt[i - 1][j + (len >> 1)]);
	}
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		int ex = log2(b - a + 1);
		cout << min(spt[ex][a], spt[ex][b + 1 - (1 << ex)]) << '\n';
	}
}