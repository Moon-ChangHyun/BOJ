#include<cstdio>
int main() {
	int N, ret = 2;
	scanf("%d", &N);
	for (int i = 0; i != N; ++i)
		ret += (1 << i);
	printf("%d", ret * ret);
}