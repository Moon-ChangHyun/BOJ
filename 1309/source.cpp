#include <stdio.h>
int N, c[2][100000]; int f(bool b, int y) { int&r = c[b][y]; if (r)return r; if (y == N - 1) { if (b)return r = 2; return r = 3; }if (b)return r = (f(0, y + 1) + f(1, y + 1)) % 9901; return r = (f(0, y + 1) + 2 * f(1, y + 1)) % 9901; }int main() { scanf("%d", &N); printf("%d", f(0, 0)); }