#include<cstdio>
int n, i, x, A[1001], C[1001]; int main() { for (scanf("%d", &n); ++i <= n; scanf("%d", A + i)); for (; ~--i; ++C[i])for (x = i; ++x <= n;)if (A[i] < A[x] & C[i] < C[x])C[i] = C[x]; printf("%d", C[0] - 1); }