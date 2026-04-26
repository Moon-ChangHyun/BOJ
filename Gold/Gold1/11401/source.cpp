// 32ms, 1116KB

#include<cstdio>
#define MOD 1000000007

long long pow(long long a, long long b) {
	if(b == 0)
		return 1;
	if(b % 2)
		return (a * pow(a, b - 1)) % MOD;
	else {
		long long half = pow(a, b >> 1);
		return (half * half) % MOD;
	}
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	if(n < (k << 1))
		k = n - k;
	long long t1 = 1, t2 = 1;
	for(int i = 2; i <= n; ++i)
		t1 = (t1 * i) % MOD;
	for(int i = 2; i <= k; ++i)
		t2 = (t2 * i) % MOD;
	for(int i = 2; i <= n - k; ++i)
		t2 = (t2 * i) % MOD;
	printf("%lld", (t1 * pow(t2, MOD - 2)) % MOD);
}