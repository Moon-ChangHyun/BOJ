#include<cstdio>
int main() { int n, i = 2, c[31]{ 1,1,3 }; for (scanf("%d", &n); ++i <= n;)c[i] = c[i - 1] + 2 * c[i - 2]; printf("%d", (n % 2 ? (c[n] + c[n / 2]) / 2 : c[n / 2 - 1] + (c[n] + c[n / 2]) / 2)); }