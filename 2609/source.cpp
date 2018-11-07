#include<cstdio>
int f(int a, int b) { return b ? f(b, a%b) : a; }int main() { int a, b, g; scanf("%d%d", &a, &b); g = a > b ? f(a, b) : f(b, a); printf("%d %d", g, a*b / g); }