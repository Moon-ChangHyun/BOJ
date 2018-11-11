#include<cstdio>
int main() {
	int n, i = 0, x, A[201], C[201]{ 0 };
	for (scanf("%d", &n); ++i <= n; scanf("%d", A + i));
	for (; ~--i; ++C[i])
		for (x = i; ++x <= n;)
			if (A[i] < A[x] & C[i] < C[x])
				C[i] = C[x];
	printf("%d", n + 1 - C[0]);
}