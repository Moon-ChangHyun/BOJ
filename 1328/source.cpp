#include<cstdio>
#define MOD 1000000007
long long factorialDp[101];
long long funcDp[101][101];
long long combiDp[101][101];

long long factorial(int num) {
	long long& ret = factorialDp[num];
	if (ret) return ret;
	return ret = (num * factorial(num - 1)) % MOD;
}

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
		ret = (ret + (((combi(num - 1, i - 1) * func(i - 1, view - 1)) % MOD) * factorial(num - i)) % MOD) % MOD;
	return ret;
}

int getAns(int num, int lView, int rView) {
	int ret = 0;
	for (int i = lView; i <= num - rView + 1; ++i)
		ret = (ret + (((combi(num - 1, i - 1) * func(i - 1, lView - 1)) % MOD) * func(num - i, rView - 1)) % MOD) % MOD;
	return ret;
}

int main() {
	factorialDp[0] = 1;
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	printf("%d\n", getAns(n, l, r));
}