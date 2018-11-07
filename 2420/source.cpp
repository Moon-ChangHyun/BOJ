#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	long long N, M;
	scanf("%lld%lld", &N, &M);
	printf("%lld", (long long)abs(N - M));
}