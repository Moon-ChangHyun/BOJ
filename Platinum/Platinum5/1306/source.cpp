// 552ms, 119328KB

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n, m, l;
vector<vector<int>> upper;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	l = 1 + (int)ceil(log2(m));
	upper.assign(n, vector<int>(l));
	for (int i = 0; i < n; ++i)
		cin >> upper[i][0];
	for (int j = 1; j < l; ++j)
	{
		int e = n - (1 << (j - 1));
		for (int i = 0; i < e; ++i)
			upper[i][j] = max(upper[i][j - 1], upper[i + (1 << (j - 1))][j - 1]);
	}
	
	int len = 1 << (l - 1), e = l - 1;
	for (int i = m - 1; i + m <= n; ++i)
		cout << max(upper[i - m + 1][e], upper[i + m - len][e]) << ' ';
}