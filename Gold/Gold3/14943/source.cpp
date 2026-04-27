// 12ms, 1112KB

#include<cstdio>
int main() {
	long long ret = 0;
	int N, sum = 0;
	scanf("%d", &N);
	for(int i = 0; i != N; ++i) {
		int L;
		scanf("%d", &L);
		ret += sum > 0 ? sum : -sum;
		sum += L;
	}
	printf("%lld", ret);
}