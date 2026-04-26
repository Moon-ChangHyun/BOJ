// 104ms, 33420KB

#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int N;
vector<int> A;
vector<ll> pSum;
vector<vector<ll>> dp;

ll IOI(int, int);

ll JOI(int left, int right) {
	if (left == right) return A[left];
	ll& ret = dp[left][right];
	if (ret != -1) return ret;
	ll sum = left < right ? pSum[right + 1] - pSum[left] : pSum[N] - (pSum[left] - pSum[right + 1]);
	ll selLeft = IOI((left + 1) % N, right);
	ll selRight = IOI(left, (right + N - 1) % N);
	return ret = sum - min(selLeft, selRight);
}

ll IOI(int left, int right) {
	if (left == right) return A[left];
	ll sum = left < right ? pSum[right + 1] - pSum[left] : pSum[N] - (pSum[left] - pSum[right + 1]);
	if (A[left] > A[right])
		return sum - JOI((left + 1) % N, right);
	return sum - JOI(left, (right + N - 1) % N);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	A.resize(N);
	pSum.resize(N + 1);
	dp.assign(N, vector<ll>(N, -1));
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		pSum[i + 1] = pSum[i] + A[i];
	}
	if (N == 1) {
        cout << A[0];
        return 0;
    }
	ll ans = 2'000'000'000'001;
	for (int first = 0; first < N; ++first)
		ans = min(ans, IOI((first + 1) % N, (first + N - 1) % N));
	ans = pSum[N] - ans;
	cout << ans;
}