#include <cstdio>
int main() {
	int	A[31], B[31];
	A[0] = B[1] = 1;
	A[1] = B[0] = 0;
	int n;
	scanf("%d", &n);
	if (n > 1) {
		for (int i = 2; i <= n; ++i) {
			A[i] = A[i - 2] + 2 * B[i - 1];
			B[i] = A[i - 1] + B[i - 2];
		}
	}
	printf("%d", A[n]);
}