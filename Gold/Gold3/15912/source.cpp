// 0ms, 1112KB

#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int N, W[1000], E[1000], maxW[1000], maxE[1000];
	long long dp[1001];
	scanf("%d", &N);
	dp[N] = 0;
	for (int i = 0; i != N; ++i)
		scanf("%d", W + i);
	for (int i = 0; i != N; ++i)
		scanf("%d", E + i);
	for (int idx = N; ~--idx;) {
		maxW[idx] = W[idx];
		maxE[idx] = E[idx];
		dp[idx] = dp[idx + 1] + (long long)E[idx] * W[idx];
		for (int e = idx + 1; e < N; ++e) {
			maxW[e] = max(maxW[e - 1], W[e]);
			maxE[e] = max(maxE[e - 1], E[e]);
			dp[idx] = min(dp[idx], (long long)maxW[e] * maxE[e] + dp[e + 1]);
		}
	}
	printf("%lld", dp[0]);
}