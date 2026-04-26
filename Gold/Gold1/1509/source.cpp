// 68ms, 27292KB

#include<iostream>
#include<string>
#include<cmath>
#include<bitset>

using namespace std;

int n, dp[2500][2500];
bitset<2500> isPalindrome[2500];
string str;

int func(int l, int r)
{
	int& ret = dp[l][r];
	if (ret) return ret;
	ret = 987654321;
	for (int i = l + 1; i <= r; ++i)
		if (isPalindrome[l][i - 1])
			ret = min(ret, 1 + func(i, r));
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> str;
	n = str.size();
	for (int i = 0; i < n; ++i)
		isPalindrome[i][i] = true;
	for (int l = 2; l <= n; ++l)
	{
		for (int i = 0; i <= n - l; ++i)
		{
			int j = i + l - 1;
			if (str[i] != str[j])
				isPalindrome[i][j] = false;
			else if (l == 2)
				isPalindrome[i][j] = true;
			else
				isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			dp[i][j] = isPalindrome[i][j];
	cout << func(0, n - 1);
}