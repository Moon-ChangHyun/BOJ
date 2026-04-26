// 12ms, 3892KB

#include<cstdio>
#include<vector>
using namespace std;
int N, M;
int dp[15][16384];
vector<int> adj[16384];

int func(int height, int bs) {
	if (height == 0)
		return bs == 0;
	int& ret = dp[height][bs];
	if (ret != -1) return ret;
	ret = 0;
	for (auto nbs : adj[bs]) {
		ret = (ret + func(height - 1, nbs)) % 9901;
	}
	return ret;
}

int curBs, nextBs;
void calcNextBs(int x) {
	if (x == M) {
		adj[curBs].push_back(nextBs);
		return;
	}
	if (curBs & (1 << x)) {
		calcNextBs(x + 1);
		return;
	}
	nextBs |= (1 << x);
	calcNextBs(x + 1);
	nextBs &= ~(1 << x);
	if (x + 1 < M && ((curBs & (1 << (x + 1))) == 0))
		calcNextBs(x + 2);
}

int main() {
	scanf("%d%d", &N, &M);
	int endBs = (1 << M);
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j < endBs; ++j)
			dp[i][j] = -1;
	for (curBs = 0; curBs < endBs; ++curBs) {
		nextBs = 0;
		calcNextBs(0);
	}
	printf("%d", func(N, 0));
}