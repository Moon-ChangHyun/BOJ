#include<cstdio>
int f(int n, int y, int x) {
	if (n == 1)
		return (y << 1) + x;
	int ret = 0, half = 1 << (n - 1), box = half * half;
	bool overhHf, overvHf;
	overvHf = half <= y;
	overhHf = half <= x;
	if (overvHf)
		ret += box * (overhHf ? 3 : 2);
	else
		ret += box * (overhHf ? 1 : 0);
	ret += f(n - 1, y % half, x % half);
	return ret;
}
int main() {
	int N, r, c;
	scanf("%d%d%d", &N, &r, &c);
	printf("%d", f(N, r, c));
}