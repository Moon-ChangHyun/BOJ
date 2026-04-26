// 108ms, 3188KB

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

constexpr int MOD = 1000000007;

long long pow2(int e) {
	if (e == 0) return 1;
	if (e & 1) {
		return (2 * pow2(e - 1)) % MOD;
	}
	else {
		auto half = pow2(e >> 1);
		return (half * half) % MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> arr(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	for (int i = 1; i <= N; ++i)
		arr[i] = ((long long)arr[i] + arr[i - 1]) % MOD;
	int ret = 0;
	for (int l = 2; l <= N; ++l) {
		int a = (arr[N] + MOD - arr[l - 1]) % MOD;
		int b = arr[N - l + 1];
		ret = (ret + (((a + MOD - b) % MOD) * pow2(l - 2)) % MOD) % MOD;
	}
	cout << ret;
}