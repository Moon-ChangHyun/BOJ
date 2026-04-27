// 0ms, 2028KB

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int n, cnt[10][12];
ll tenPow[12] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000 };
ll alphaSum[10];
vector<bool> canZero(10, true);

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		int e = str.size() - 1;
		for (int j = 0; j <= e; ++j)
			++cnt[str[j] - 'A'][e - j];
		canZero[str[0] - 'A'] = false;
	}
	vector<int> sortByVal;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 12; ++j)
			alphaSum[i] += cnt[i][j] * tenPow[j];
		if (alphaSum[i] > 0)
			sortByVal.push_back(i);
	}
	sort(sortByVal.begin(), sortByVal.end(), [](int a, int b) {
		return alphaSum[a] > alphaSum[b];
	});
	ll ans = 0;
	if (sortByVal.size() < 10) {
		int cur = 10;
		for (int x : sortByVal)
			ans += alphaSum[x] * --cur;
	}
	else
	{
		int zero, cur = 10;
		for (int i = 10; ~--i;)
		{
			if (canZero[sortByVal[i]]) {
				zero = sortByVal[i];
				break;
			}
		}
		for (int x : sortByVal)
		{
			if (x == zero) continue;
			ans += alphaSum[x] * --cur;
		}
	}
	cout << ans;
}