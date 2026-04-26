// 1168ms, 95772KB

#include<iostream>
#include<vector>

using namespace std;
using ll = long long;
constexpr int MAX_N = 1000000;

int N, sparse[20][MAX_N + 1], G[MAX_N + 1], S[MAX_N + 1], P[MAX_N + 1];
ll K;

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		cin >> S[i];
	for (int i = 1; i <= N; ++i)
		cin >> sparse[0][i];
	for (int i = 1; i < 20; ++i)
		for (int j = 1; j <= N; ++j)
			sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
	
	vector<int> cycleSize(1);
	cycleSize.reserve(N + 1);
	int g = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (G[i]) continue;
		int sz = 1;
		G[i] = ++g;
		for (int j = sparse[0][i]; i != j; j = sparse[0][j])
		{
			G[j] = g;
			++sz;
		}
		cycleSize.push_back(sz);
	}

	for (int i = 1; i <= N; ++i)
	{
		int cs = cycleSize[G[i]];
		int a = i, b = K % cs;
		if (b == 0)
		{
			P[i] = S[i];
		}
		else
		{
			int x = 20, y = 1 << 20;
			while (b)
			{
				while (b < y)
				{
					--x;
					y >>= 1;
				}
				b -= y;
				a = sparse[x][a];
			}
			P[a] = S[i];
		}
	}
	for (int i = 1; i <= N; ++i)
		cout << P[i] << ' ';
}