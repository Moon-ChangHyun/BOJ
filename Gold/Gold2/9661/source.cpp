// 0ms, 1116KB

#include<cstdio>
int main() {
	long long N;
	scanf("%lld", &N);
	N %= 5;
	if(N == 0 || N == 2)
		printf("CY");
	else
		printf("SK");
}