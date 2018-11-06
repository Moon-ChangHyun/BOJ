#include<cstdio>
#define MOD 1000000

int n;
int dp[1001][2][3];

int f(int day, bool doneL, int contA) {
	if (!day)
		return 1;
	int& ret = dp[day][doneL][contA];
	if (ret != -1)
		return ret;
	ret = f(day - 1, doneL, 0); // 출석
	if (doneL) {
		if (contA != 2)
			ret = (ret + f(day - 1, true, contA + 1)) % MOD; // +결석
	}
	else {
		ret = (ret + f(day - 1, true, 0)) % MOD; // +지각
		if (contA != 2)
			ret = (ret + f(day - 1, false, contA + 1)) % MOD; // + 결석

	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j != 2; ++j)
			for (int k = 0; k != 3; ++k)
				dp[i][j][k] = -1;
	printf("%d", f(n, false, 0));
}