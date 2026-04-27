// 0ms, 1192KB

#include<cstdio>
#include<algorithm>
using namespace std;
int N, M;
int cost[100], memory[100];
int dp[2][10001];
int main() {
	scanf("%d%d", &N, &M);
    int sz = 1 + 100 * N;
	for(int i = 0; i != N; ++i)
		scanf("%d", memory + i);
	for(int i = 0; i != N; ++i)
		scanf("%d", cost + i);
	int ret = cost[N - 1];
    while(ret < sz)
        dp[(N - 1) & 1][ret++] = memory[N - 1];
    for(int i = N - 1; ~--i; ) {
		for(int j = 0; j < sz; ++j){
			dp[i & 1][j] = dp[(i + 1) & 1][j];
            if(j >= cost[i])
                dp[i & 1][j] = max(dp[i & 1][j], memory[i] + dp[(i + 1) & 1][j - cost[i]]);
        }
    }
	ret = 0;
	while(dp[0][ret] < M) ++ret;
	printf("%d", ret);
}