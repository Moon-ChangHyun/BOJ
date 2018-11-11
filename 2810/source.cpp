#include<cstdio>
int main() {
	char str[51];
	int n, ret = 0;
	scanf("%d%s", &n, str);
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'L')
			++i;
		++ret;
	}
	printf("%d", n < ++ret ? n : ret);
}