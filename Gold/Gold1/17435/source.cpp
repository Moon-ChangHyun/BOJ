// 212ms, 17644KB

#include<iostream>

using namespace std;

int m, spt[200001][20];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m;
	for (int i = 1; i <= m; ++i)
		cin >> spt[i][0];

	for (int j = 1; j < 20; ++j)
		for (int i = 1; i <= m; ++i)
			spt[i][j] = spt[spt[i][j - 1]][j - 1];
	
	int Q;
	for (cin >> Q; ~--Q;)
	{
		int n, x;
		cin >> n >> x;
		for (int j = 20; ~--j;)
		{
			if ((1 << j) <= n)
			{
				x = spt[x][j];
				n -= (1 << j);
			}
		}
		cout << x << '\n';
	}
}