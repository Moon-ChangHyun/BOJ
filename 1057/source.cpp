#include<cstdio>
int main() {
	int N, a, b, ret = 0;
	scanf("%d%d%d", &N, &a, &b);
	while (true) {
		++ret;
		N >>= 1;
		a = (a + 1) >> 1;
		b = (b + 1) >> 1;
		if (a == b) break;
	}
	printf("%d", ret);
}