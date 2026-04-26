// 328ms, 99676KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int dp[50][500000];
vector<int> v;

int func(int idx, int diff) {
	if (idx == N)
		return diff == 0 ? 0 : -2;
	
	int& ret = dp[idx][diff];
	if (ret != -1)
		return ret;
		
	ret = -2;
	int temp = func(idx + 1, diff);
	if (temp != -2)
		ret = max(ret, temp);
	temp = func(idx + 1, diff + v[idx]);
	if (temp != -2)
		ret = max(ret, temp);
	if (diff > 0) {
		if (v[idx] > diff) {
			temp = func(idx + 1, v[idx] - diff);
			if (temp != -2)
				ret = max(ret, diff + temp);
		}
		else {
			temp = func(idx + 1, diff - v[idx]);
			if (temp != -2)
				ret = max(ret, v[idx] + temp);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	v.resize(N);
	for (auto& x : v) {
		cin >> x;
	}
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 500000; ++j)
			dp[i][j] = -1;
			
	int ans = func(0, 0);
	if (ans == 0)
		cout << -1;
	else
		cout << ans;
}