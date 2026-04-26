// 0ms, 1112KB

#include<cstdio>
int main() {
	int t, x, A[22], C[22], B[22];
	A[0] = A[1] = B[1] = C[1] = 1;
	B[0] = C[0] = 0;
	for (int i = 2; i < 22; ++i) {
		A[i] = A[i - 1] + 2 * B[i - 1] + C[i - 1] + A[i - 2];
		B[i] = A[i - 1] + B[i - 1];
		C[i] = A[i - 1] + C[i - 2];
	}
	for (scanf("%d", &t); ~--t; ) {
		scanf("%d", &x);
		printf("%d\n", A[x]);
	}
}