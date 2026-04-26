// 0ms, 1196KB

#include<cstdio>
long long factorialDp[21];
long long funcDp[21][21];
long long combiDp[21][21];
long long ansDp[21][21][21];

long long factorial(int num) {
	long long& ret = factorialDp[num];
	if(ret) return ret;
	return ret = num * factorial(num - 1);
}

long long combi(int num, int sel) {
	if(sel > num) return 0;
	long long& ret = combiDp[num][sel];
	if(ret) return ret;
	if((sel << 1) > num)
		return ret = combi(num, num - sel);
	if(sel == 1)
		return ret = num;
	else if(sel == 0)
		return ret = 1;
	return ret = combi(num - 1, sel - 1) + combi(num - 1, sel);
}

long long func(int num, int view) {
	if(num == view) return 1;
	if(view == 0) return 0;
	long long& ret = funcDp[num][view];
	if(ret) return ret;
	for(int i = view; i <= num; ++i)
		ret += combi(num - 1, i - 1) * func(i - 1, view - 1) * factorial(num - i);
	return ret;
}

long long getAns(int num, int lView, int rView) {
	long long& ret = ansDp[num][lView][rView];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = lView; i <= num - rView + 1; ++i)
		ret += combi(num - 1, i - 1) * func(i - 1, lView - 1) * func(num - i, rView - 1);
	return ret;
}

int main() {
	factorialDp[0] = 1;
	for(int i = 0; i <= 20; ++i)
		for(int j = 0; j <= 20; ++j)
			for(int k = 0; k <= 20; ++k)
				ansDp[i][j][k] = -1;
	int T;
	for(scanf("%d", &T); ~--T; ) {
		int n, l, r;
		scanf("%d%d%d", &n, &l, &r);
		printf("%lld\n", getAns(n, l, r));
	}
}