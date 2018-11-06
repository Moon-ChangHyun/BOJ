#include<cstdio>
#include<algorithm>
int A, B; int main() { for (scanf("%d"); ~scanf("%d%d", &A, &B); printf("%d\n", A*B / std::__gcd(A, B))); }