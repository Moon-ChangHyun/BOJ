// 780ms, 7176KB

#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> coin(100);
vector<int> cnt(100);
vector<vector<char>> dp;

char func(int idx, int remain) {
	if (remain == 0) return 1;
	if (remain < 0 || idx == n) return 0;
	char& ret = dp[idx][remain];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= cnt[idx]; ++i)
		ret |= func(idx + 1, remain - i * coin[idx]);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	for (int t = 3; ~--t;) {
		int sum = 0;
		cin >> n;
		coin.resize(n);
		cnt.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> coin[i] >> cnt[i];
			sum += coin[i] * cnt[i];
		}
		if (sum & 1) {
			cout << 0 << '\n';
			continue;
		}
		sum >>= 1;
		dp.assign(n, vector<char>(sum + 1, -1));
		auto ans = func(0, sum);
		cout << (ans == 1) << '\n';
	}
}