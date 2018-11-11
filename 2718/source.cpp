#include<cstdio>
int main() {
	int t, A[1001], B[1001], C[1001];
	A[0] = A[1] = C[1] = 1;
	B[0] = B[1] = C[0] = 0;
	for (int i = 2; i <= 1000; ++i) {
		A[i] = 2 * C[i - 1] + B[i - 2] + 2 * A[i - 2] + A[i - 1];
		B[i] = A[i - 2] + B[i - 2];
		C[i] = A[i - 1] + C[i - 1];
	}
	for (scanf("%d", &t); ~--t; ) {
		int x;
		scanf("%d", &x);
		printf("%d\n", A[x]);
	}
}