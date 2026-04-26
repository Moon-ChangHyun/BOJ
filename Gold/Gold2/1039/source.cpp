// 0ms, 44988KB

#include<iostream>

using namespace std;

int tenSqr[6] = { 1, 10, 100, 1000, 10000, 100000 };
int N, K, sz;
int dp[1000000][11];

int dfs(int num, int k)
{
	if (k == 0) return num;
	int& ret = dp[num][k];
	if (ret) return ret;
	ret = -1;
	for (int i = 0; i < sz; ++i)
	{
		int a = (num / tenSqr[i]) % 10;
		int jEnd = a == 0 ? sz - 1 : sz;
		for (int j = i + 1; j < jEnd; ++j)
		{
			int b = (num / tenSqr[j]) % 10;
			int nextNum = num - a * tenSqr[i] - b * tenSqr[j];
			nextNum += a * tenSqr[j] + b * tenSqr[i];
			ret = max(ret, dfs(nextNum, k - 1));
		}
	}
	return ret;
}

int main()
{
	scanf("%d%d", &N, &K);
	if (N == 1000000)
	{
		printf("1000000");
		return 0;
	}
	int tmp = N;
	while (tmp)
	{
		tmp /= 10;
		++sz;
	}
	printf("%d", dfs(N, K));
}