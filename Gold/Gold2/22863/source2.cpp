// 2184ms, 205144KB

#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int N, sparse[50][1000001], S[1000001], P[1000001];
ll K;

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		cin >> S[i];
	for (int i = 1; i <= N; ++i)
		cin >> sparse[0][i];
	for (int j = 1; j < 50; ++j)
		for (int i = 1; i <= N; ++i)
			sparse[j][i] = sparse[j - 1][sparse[j - 1][i]];
	for (int i = 1; i <= N; ++i)
	{
		int a = i, x = 50;
		ll b = K, y = 1LL << 50;
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
	for (int i = 1; i <= N; ++i)
		cout << P[i] << ' ';
}