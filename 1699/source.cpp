#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n, dp[100001];

int func(int num) {
	int& ret = dp[num];
	if (ret != 987654321) return ret;
	ret = 987654321;
	int end = sqrt(num);
	for (int i = 1; i <= end; ++i)
		ret = min(ret, func(i * i) + func(num - i * i));
	return ret;
}

int main() {
	fill(dp, dp + 100000, 987654321);
	for (int i = 1; i != 317; ++i)
		dp[i * i] = 1;
	scanf("%d", &n);
	printf("%d", func(n));
}