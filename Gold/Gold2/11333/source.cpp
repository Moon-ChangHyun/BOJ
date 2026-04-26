// 4ms, 1232KB

#include<cstdio>
#define mod 1000000007
int A[10001]{1, 0, 0};
int B[10001]{0, 1, 0};
int C[10001]{0, 0, 1};
int main() {
	int T;
	for(scanf("%d", &T); ~--T; ) {
		int N;
		scanf("%d", &N);
		for(int i = 3; i <= N; ++i) {
			A[i] = (A[i - 3] + (C[i - 1] << 1) % mod) % mod;
			B[i] = (A[i - 1] + B[i - 3]) % mod;
			C[i] = (B[i - 1] + C[i - 3]) % mod;
		}
		printf("%d\n", A[N]);
	}
}