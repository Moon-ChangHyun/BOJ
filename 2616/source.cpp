#include<cstdio>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;
int n, m;
vector<int> psum;
array<vector<int>, 3> dp;
int func(int st, int idx) {
	if (st == 0) return 0;
	if (idx + st * m - 1 > n) return -9876543621;
	int& ret = dp[st - 1][idx];
	if (ret != -1) return ret;
	return ret = max(psum[idx + m - 1] - psum[idx - 1] + func(st - 1, idx + m), func(st, idx + 1));
}
int main() {
	scanf("%d", &n);
	psum.resize(n + 1);
	psum[0] = 0;
	for (int i = 0; i != 3; ++i)
		dp[i].resize(n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		psum[i] = psum[i - 1] + x;
	}
	scanf("%d", &m);
	printf("%d", func(3, 1));
}