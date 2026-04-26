// 0ms, 1276KB

#include<cstdio>

constexpr int MOD = 1'000'000'007;
long long factorial[101];
long long funcDp[101][101];
long long combiDp[101][101];

long long combi(int num, int sel) {
	if (sel > num) return 0;
	long long& ret = combiDp[num][sel];
	if (ret) return ret;
	if ((sel << 1) > num)
		return ret = combi(num, num - sel);
	if (sel == 1)
		return ret = num;
	else if (sel == 0)
		return ret = 1;
	return ret = (combi(num - 1, sel - 1) + combi(num - 1, sel)) % MOD;
}

long long func(int num, int view) {
	if (num == view) return 1;
	if (view == 0) return 0;
	long long& ret = funcDp[num][view];
	if (ret) return ret;
	for (int i = view; i <= num; ++i)
		ret = (ret + (((combi(num - 1, i - 1) * func(i - 1, view - 1)) % MOD) * factorial[num - i]) % MOD) % MOD;
	return ret;
}

int main() {
	factorial[0] = 1;
	for (int i = 1; i <= 100; ++i)
		factorial[i] = factorial[i - 1] * i % MOD;
	int n, l, r, ans = 0;
	scanf("%d%d%d", &n, &l, &r);
	for (int i = l; i <= n - r + 1; ++i)
		ans = (ans + (((combi(n - 1, i - 1) * func(i - 1, l - 1)) % MOD) * func(n - i, r - 1)) % MOD) % MOD;
	printf("%d\n", ans);
}