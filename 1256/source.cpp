#include<cstdio>
#include<algorithm>
using namespace std;
char str[201];
int idx, dp[201][101];

int combi(int total, int select) {
	if (total < select) return 0;
	if (!select) return 1;
	int& ret = dp[total][select];
	if (ret) return ret;
	if (ret = dp[total][total - select]) return ret;
	return ret = min(1000000001, combi(total - 1, select) + combi(total - 1, select - 1));
}

void func(int n, int m, int k) {
	if (n == 0 && m == 0) return;
	int skip = combi(n + m - 1, m);
	if (skip >= k) {
		str[idx++] = 'a';
		func(n - 1, m, k);
	}
	else {
		str[idx++] = 'z';
		func(n, m - 1, k - skip);
	}
}

int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	if (combi(N + M, N) < K)
		printf("-1");
	else {
		func(N, M, K);
		printf("%s", str);
	}
}