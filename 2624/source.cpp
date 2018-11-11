#include<iostream>
#include<vector>
using namespace std;
int T, K;
vector<int> price, cnt;
vector<vector<int>> dp;
int func(int idx, int change) {
	if (change == 0) return 1;
	if (change < 0 || idx >= K) return 0;
	int& ret = dp[idx][change];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= cnt[idx]; ++i)
		ret += func(idx + 1, change - price[idx] * i);
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T >> K;
	price.resize(K);
	cnt.resize(K);
	dp.resize(K, vector<int>(T + 1, -1));
	for (int i = 0; i != K; ++i)
		cin >> price[i] >> cnt[i];
	cout << func(0, T);
}