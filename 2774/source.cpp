#include<cstdio>
int S, T, X; int main() { for (scanf("%d", &T); ~--T; S = 0) { scanf("%d", &X); while (X) { S |= 1 << (X % 10); X /= 10; }printf("%d\n", __builtin_popcount(S)); } }