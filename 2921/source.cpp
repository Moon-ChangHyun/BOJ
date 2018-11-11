#include<cstdio>
int main() {
	int n, ret = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= i; ++j)
			ret += i + j;
	printf("%d", ret);
}