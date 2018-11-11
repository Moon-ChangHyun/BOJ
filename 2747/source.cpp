#include<cstdio>
int i, n, f[3]{ 0,1 };
int main() { scanf("%d", &n); for (i = 1; ++i <= n; f[i % 3] = f[(i + 1) % 3] + f[(i + 2) % 3]); printf("%d", f[n % 3]); }