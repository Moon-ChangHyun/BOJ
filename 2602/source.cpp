#include<cstdio>
char str[21], ad[2][101];
int cache[20][2][101];
int f(int index, bool y, int x) {
	if (!str[index]) return 1;
	int& ret = cache[index][y][x];
	if (ret) return ret;
	for (int i = x; ad[y][i]; ++i)
		if (ad[y][i] == str[index])
			ret += f(index + 1, !y, i + 1);
	return ret;
}
int main() {
	scanf("%s %s %s", str, ad[0], ad[1]);
	printf("%d", f(0, 0, 0) + f(0, 1, 0));
}