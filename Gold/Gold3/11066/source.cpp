// 560ms, 2096KB

#include<cstdio>
#include<algorithm>
using namespace std;
int dp[501][501];
int pSum[501];
int K;
int func(int first, int last) {
	int& ret = dp[first][last];
	if(ret != 987654321) return ret;
	for(int mid = first; mid != last; ++mid)
		ret = min(ret, func(first, mid) + func(mid + 1, last));
	ret += pSum[last] - pSum[first - 1];
	return ret;
}

int main() {
	int T;
	for(scanf("%d", &T); ~--T; ) {		
		scanf("%d", &K);
		for(int i = 1; i <= K; ++i) {
			int file;
			scanf("%d", &file);
			pSum[i] = pSum[i - 1] + file;
		}
		for(int i = 1; i <= K; ++i)
			for(int j = i + 1; j <= K; ++j)
				dp[i][j] = 987654321;
		printf("%d\n", func(1, K));
	}
}