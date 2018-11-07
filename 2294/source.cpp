#include<cstdio>
#include<algorithm>
using namespace std;

int n, k, coins[100], dp[100][10001];

int f(int p, int r) {
	if (r < 0) return 987654321;
	if (r == 0) return 0;
	if (p == n) return 987654321;
	int& ret = dp[p][r];
	if (ret) return ret;
	return ret = min(1 + f(p, r - coins[p]), f(p + 1, r));
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i != n; ++i)
		scanf("%d", coins + i);
	int ans = f(0, k);
	if (ans >= 987654321) ans = -1;
	printf("%d", ans);
}