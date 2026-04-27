// 168ms, 3076KB

#include<cstdio>
#include<algorithm>
using namespace std;
long long dp[501][501];
int r[501], c[501];
long long func(int first, int last) {
	if(first == last)
		return 0;
	long long& ret = dp[first][last];
	if(ret != 987654321987) return ret;
	for(int mid = first; mid != last; ++mid)
		ret = min(ret, func(first, mid) + func(mid + 1, last) + r[first] * c[mid] * c[last]);
	return ret;
}
int main() {
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d%d", r + i, c + i);
	for(int i = 0; i <= N; ++i)
		for(int j = 0; j <= N; ++j)
			dp[i][j] = 987654321987;
	printf("%lld", func(1, N));
}
